#include <dirent.h>
#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/* Given a filetype, return whether it is a directory. */
bool is_dir(int filetype)
{
    return filetype == DT_DIR;
}

/* Given a pointer to an entry, return whether it is a folder. */
int is_fold(const struct dirent *entry){
  return is_dir(entry->d_type);//non POSIX
}

/* Given a pointer to an entry, return whether it is a file. */
int is_file(const struct dirent *entry){
  return !is_fold(entry);
}

/* Checks whether a given entry is hidden. */
int wi_dot(const struct dirent *entry){
  return (entry->d_name)[0] == '.';
}

/* Checks whether a given entry is normal (starting without a dot). */
int wo_dot(const struct dirent *entry){
  return !wi_dot(entry);
}

/* Checks whether a folder is normal (starting without a dot). */
int fold_wo_dot(const struct dirent *entry){
  return wo_dot(entry) && is_fold(entry);
}

/* Checks whether a file is normal (starting without a dot). */
int file_wo_dot(const struct dirent *entry){
  return wo_dot(entry) && is_file(entry);
}

/* Compare two entries by their name (case insensitive). */
int dir_comp(const struct dirent **a, const struct dirent **b){
  return strcasecmp((*a)->d_name, (*b)->d_name);
}

/* Lists files and folders sorted by name in the given dir. Option:
 *     - show_all: including hidden entries starting with '.'
 *     - sort_by_type: the output is sorted to list entries that are
 *       directories first, followed by non-directories.
 */
void ls(const char *dir, bool show_all, bool sort_by_type)
{  
    struct dirent **namelist[2] = { NULL, NULL };
    int ret[] = { -2, -2 };

    if (show_all && sort_by_type) {
        ret[0] = scandir(dir, &namelist[0], is_fold, dir_comp);
        ret[1] = scandir(dir, &namelist[1], is_file, dir_comp);
    } else if (!show_all && sort_by_type) {
        ret[0] = scandir(dir, &namelist[0], fold_wo_dot, dir_comp);
        ret[1] = scandir(dir, &namelist[1], file_wo_dot, dir_comp);
    } else if (show_all && !sort_by_type) {
        ret[0] = scandir(dir, &namelist[0], NULL, dir_comp);
    } else if (!show_all && !sort_by_type) { 
        ret[0] = scandir(dir, &namelist[0], wo_dot, dir_comp);
    }

    for (int i = 0; i < 2; ++i) {
        if (ret[i] == -1) {
            printf("myls: cannot access '%s': No such file or directory\n", dir);
            continue;
        } 

        if (ret[i] == -2 || namelist[i] == NULL)
            continue;
        
        for (int j = 0; j < ret[i]; ++j) {
            struct dirent *entry = namelist[i][j];
            if (is_fold(entry)) 
                printf("%s/\n", entry->d_name);
            else 
                printf("%s\n", entry->d_name);
            free(entry);
        }
        free(namelist[i]);
    }   
}

int main(int argc, char *argv[])
{
    bool show_all = false;
    bool dirs_first = false;

    int opt;
    while ((opt = getopt(argc, argv, "az")) != -1) {
        switch (opt) {
            case 'a': show_all = true; break;
            case 'z': dirs_first = true; break;
            default: exit(1);
        }
    }
    if (optind < argc -1) {
        for (int i = optind; i < argc; i++) {
            printf("%s:\n", argv[i]);
            ls(argv[i], show_all, dirs_first);
            printf("\n");
        }
    } else {
        ls(optind == argc -1? argv[optind] : ".", show_all, dirs_first);
    }
    return 0;
}
