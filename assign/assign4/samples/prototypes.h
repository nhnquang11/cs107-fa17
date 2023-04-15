#ifndef prototypes_h
#define prototypes_h

#include <stddef.h>

void insert(const void *base, size_t *p_nelem, size_t width, void *p, const void *key);
void *bsearch(const void *key, const void *base, size_t nmemb, size_t width,
                    int (*compar)(const void *, const void *));
void *binsert(const void *key, void *base, size_t *p_nelem, size_t width, int (*compar)(const void *, const void *));


#endif
