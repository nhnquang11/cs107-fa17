#include "samples/prototypes.h"
#include <error.h>
#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_LINE_LEN 4096
#define MIN_NLINES 100

typedef int (*cmp_fn_t)(const void *p, const void *q);

int cmp_pstr(const void *p, const void *q) {
    return strcmp(*(char **)p, *(char **)q);
}

int cmp_pstr_len(const void *p, const void *q)
{
    size_t p_sz = strlen(*(char **)p);
    size_t q_sz = strlen(*(char **)q);

    if (p_sz < q_sz) return -1;
    else if (p_sz > q_sz) return 1;

    return cmp_pstr(p, q);
}

int cmp_pstr_numeric(const void *p, const void *q)
{
    int ip = atoi(*(char **)p);
    int iq = atoi(*(char **)q);

    if (ip < iq) return -1;
    else if (ip == iq) return 0;
    return 1;
}

void reverse_lines(char **lines, size_t nlines){
    int i = 0; 
    int j = nlines - 1;

    while (i < j) {
        char *tmp = lines[i];
        lines[i] = lines[j];
        lines[j] = tmp;
        ++i;
        --j;
    }
}

void print_lines(char **lines, size_t nlines){
    for (int i = 0; i < nlines; ++i) {
        printf("%s", lines[i]);
    }
}

void free_lines(char **lines, size_t nlines){
    for (int i = 0; i < nlines; ++i) {
        free(lines[i]);
    }
    free(lines);
}

void sort_lines(FILE *fp, cmp_fn_t cmp, bool uniq, bool reverse)
{
    char line[MAX_LINE_LEN];
    size_t maxlines = MIN_NLINES;
    char **lines = calloc(maxlines, sizeof(char *));
    size_t nlines = 0;

    /* Reads fp */
    while (ungetc(getc(fp), fp) != EOF) {
        assert(fgets(line, maxlines, fp) != NULL);
        lines[nlines] = strdup(line);
        ++nlines;
        if (nlines == maxlines) {
            maxlines *= 2;
            lines = realloc(lines, maxlines * sizeof(char *));
            assert(lines != NULL);
        }
    }

    /* Handles flags */
    if (uniq) {
        char **lines_uniq = calloc(nlines, sizeof(char *));
        size_t nlines_uniq = 0;
        for (int i = 0; i < nlines; ++i) {
            char **added = binsert(&lines[i], lines_uniq, &nlines_uniq, 
                                sizeof(char *), cmp);
            assert(strcmp(*added, lines[i]) == 0);
        }
        qsort(lines_uniq, nlines_uniq, sizeof(char *), cmp);
        if (reverse) reverse_lines(lines_uniq, nlines_uniq);
        print_lines(lines_uniq, nlines_uniq);
        free(lines_uniq);
    } else {
        qsort(lines, nlines, sizeof(char *), cmp);
        if (reverse) reverse_lines(lines, nlines);
        print_lines(lines, nlines);
    }
    free_lines(lines, nlines);
}

int main(int argc, char *argv[])
{
    cmp_fn_t cmp = cmp_pstr;
    bool uniq = false, reverse = false;

    int opt;
    while ((opt = getopt(argc, argv, "lnru")) != -1) {
        switch (opt) {
            case 'l': cmp = cmp_pstr_len; break;
            case 'n': cmp = cmp_pstr_numeric; break;
            case 'r': reverse = true; break;
            case 'u': uniq = true; break;
            default: exit(1);
        }
    }

    FILE *fp = stdin;
    if (optind < argc) {
        fp = fopen(argv[optind], "r");
        if (fp == NULL) error(1, 0, "%s: no such file", argv[optind]);
    }
    sort_lines(fp, cmp, uniq, reverse);
    fclose(fp);
    return 0;
}
