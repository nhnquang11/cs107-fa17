#include "samples/prototypes.h"
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>

// You wrote this as an exercise in lab2! Grab the code from your lab checkoff sheet
// at https://cs107.stanford.edu/cgi-bin/lab2
const char *get_env_value(const char *envp[], const char *varname)
{
    for (size_t i = 0; envp[i] != NULL; ++i) {
        // String containing varname is found
        if (strstr(envp[i], varname) != NULL) {
            char *eqPtr = strchr(envp[i], '=');
            if (eqPtr != NULL && (eqPtr - envp[i] == strlen(varname))) {
                return ++eqPtr; // value of the env
            }
        }
    }
    return NULL;
}


// This main is incomplete. It sketches the expected behavior for the case when
// mywhich is invoked with no arguments. You are to first read and understand 
// this code, work out how to change/extend to suit your needs, and finally add
// comments to document your strategy.

int main(int argc, char *argv[], const char *envp[])
{
    // Use the env var MYPATH for the seach path
    const char *searchpaths = get_env_value(envp, "MYPATH");
    // If no such var exists, fall back to PATH
    if (searchpaths == NULL)
        searchpaths = get_env_value(envp, "PATH");

    // Print the list of dirs searched if no arguments invoked.
    if (argc == 1) {
        char dir[PATH_MAX+1];
        const char *remaining = searchpaths;
        
        printf("Directories in search path:\n");
        // Extract and print out each directory
        while (scan_token(&remaining, ":", dir, sizeof(dir))){
            printf("%s\n", dir);
        }
    } else {
        --argc;
        ++argv;

        // Loop through each argument
        for (int i = 0; i < argc; ++i) {
            // Decide which mode to search
            int wildcard_search = argv[i][0] == '+' ? 1 : 0;
            char dir[PATH_MAX + 1];
            const char *remaining = searchpaths;

            // Loop through each directory and print out the path of
            // exe file if exists.
            while (scan_token(&remaining, ":", dir, sizeof(dir))) {
                 DIR *dp = opendir(dir);
                 if (dp == NULL) continue;

                 struct dirent *entry;
                 while ((entry = readdir(dp)) != NULL) {
                     // Wildcard mode: argument is a substring of
                     // the exe file
                     if (wildcard_search && strstr(entry->d_name, argv[i] + 1)!=NULL) {
                         printf("%s/%s\n", dir, entry->d_name);
                     }
                     // Normal mode: argument exactly matches the exe file
                     else if (!wildcard_search && strcmp(entry->d_name, argv[i])==0) {
                         printf("%s/%s\n", dir, entry->d_name);
                     }
                 }
                 closedir(dp);
            }
        }        
    }
    return 0;
}
