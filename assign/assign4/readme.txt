File: readme.txt
Author: Quang Nguyen 
----------------------

1. Code study: scandir
    a. The continue statement skips the current iteration of the loop and
       continues with the next iteration.
    b. Because when the first time realloc is called, names is NULL.
    c. Because we want to assign the return value of realloc to names if 
       and only if the return value is not NULL, else we break the loop.
    d. ENOMEM  Not enough space/cannot allocate memory.
    e. warning: passing argument 4 of 'qsort' from incompatible pointer 
       type.
    f. Because sel works on a pointer to a dirent, whereas qsort works on an 
       array of pointers to dirents.
       
3. Code study: bsearch
    a. If all the parameters are correct, p cannot not go out of bound, so 
       there is no overflow.
    b. ((char *)found - (char *)arr) / width
    c. The program will still halt, however it might go astray. It can
       return a false negative but it cannot return a false positive.

4. Code study: void* blues
    a. Output:
           correct call max = 0x55443322
           incorrect call #1 max = 0xfffff
           incorrect call #2 max = 0x44
           incorrect call #3 max = 0x900000
       Reason: 
           incorrect call #1: only the least significant byte is compared.
           incorrect call #2: only the 3 lsbs of the first integer are compared.
           incorrect call #3: the addresses are compared so the third argument
                              comes out on top.
    b. The first parameter of bsearch should be a pointer to a string 
       instead of a char.
    c. When comparing the key to an element of the array, the former is fed
       to compar as the first parameter, and the latter the second.
