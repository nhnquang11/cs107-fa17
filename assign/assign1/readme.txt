File: readme.txt
Author: Quang Nguyen
----------------------

1. The power of two
   a. One-hot encoding
   b. The minimum e.g. INT_MIN
   c. Consider x = 0b100..0 as a power of two. (x - 1) gives us 0b011..1, which means that ((x - 1) & x) = 0.
   d. The function returns true.

2. Finding the middle ground
   a. The substraction (high - low) can overflow.
      E.g. low = INT_MIN + 1, high = INT_MAX
           low + ((high - low) / 2) = INT_MIN != 0
   b. Breaks when sum of low and high is negative.
      E.g. low = -3, high = -1
           ((unsigned int)low + (unsigned int)high) >> 1 == INT_MAX - 1 != -2
   c. The first operand is the carry bits of ((low + high) / 2) and the second is ((low + high) / 2) without carry bits.

3. Ground zero
   a. ~0UL/UCHAR_MAX =  0x101010101010101
      ~0U/UCHAR_MAX = 0x1010101
      ~0L/UCHAR_MAX = 0x0
   b. Left shift by 7 is the same as multiplication by 0x80.
   c. For every byte, flip the most significant bit if 0. Borrow happends if a 0 exists.
   d. For every byte, flip the most significant bit. Zero the rest.
   e. Going from the least significant end to the most, if a byte is not 0, it evaluates to 0. Once a 0 byte shows up, it evaluates to non-zero, making the return 1.
   
