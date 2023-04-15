File: readme.txt
Author: Quang Nguyen 
----------------------

1. Code study: gets
    a. warning: 'gets' is deprecated
       warning: the 'gets' function is dangerous and should not be used.
    b. apple_gets only prints out the warning message the first time clients use it.
    c. No. Because the size passed in fgets is INT_MAX, which can result in
       overflowing the buffer.
    d. 17 characters. Problem report:
       *** stack smashing detected ***; terminated
       Aborted (core dumped)

2. Code study: calloc and realloc
    a. Overflow
    b. # bytes allocated, rounded up to the nearest multiple of 8.
    c. No. If *wp = 0, not spending time on assignment is faster.
    d. Speed
    e. Because the function needs to free the old pointer and the 
       old pointer is passed by value.
    f. oldptr is freed whenever newptr is malloc'd.

