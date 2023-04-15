#include "samples/prototypes.h"
#include <string.h>

void insert(const void *base, size_t *p_nelem, size_t width, void *p, const void *key) {
    /* If the insert position is not at the end of the array, we have to shift
     * all the elements from the rhs of the insert position 1 position to the right
     * before doing the insertion. */
    if (p != (char *)base + (*p_nelem) * width) {
        void *curr = (char *)base + (*p_nelem - 1) * (width);
        while (curr != p) {
            memcpy((char *)curr + width, curr, width);
            curr = (char *)curr - width;
        }
        memcpy((char *)curr + width, curr, width); // handles fence-post problem
    }
    memcpy(p, key, width);
    *p_nelem += 1;
}

void *bsearch(const void *key, const void *base, size_t nmemb, size_t width,
                    int (*compar)(const void *, const void *))
{
    for (size_t nremain = nmemb; nremain != 0; nremain >>= 1) {
        void *p = (char *)base + (nremain >> 1) * width;
        int sign = compar(key, p);
        if (sign == 0)
            return p;
        if (sign > 0) {  /* key > p: move right */
            base = (char *)p + width;
            nremain--;
        }       /* else move left */
    }
    return NULL;
}

void *binsert(const void *key, void *base, size_t *p_nelem, size_t width, int (*compar)(const void *, const void *)) {
    void *found = bsearch(key, base, *p_nelem, width, compar);
    if (found) return found;
    
    /* If key is not in th array, find the position to input key into the array. */
    void *p = (char *)base + (*p_nelem) * width;
    for (int i = 0; i < *p_nelem; ++i) {
        void *ith_ptr = (char *)base + i * width;
        int cmp = compar(key, ith_ptr);
        if (cmp <= 0) {
            p = ith_ptr;
            break;
        }
    }
    /* Input the key to the appropriate position. */
    insert(base, p_nelem, width, p, key);
    return p;
}
