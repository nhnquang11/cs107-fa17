File: readme.txt
Author: Quang Nguyen
----------------------

1. Code study: atoi
   a. A single digit character is converted to its numeric value by taking the
      difference between its ASCII value and '0'.
   b. By the cascading property of switch, it advances s past that char in the
      case '+'.
   c. Because INT_MIN = -INTMAX - 1.
   d. atoi(" $5"); -> the function advances s to the character '$' and returns
                      -n = 0.
      atoi("12:34") -> the function advances s to the character ':' and returns
                       -n = 12.
      atoi("-2147483649") -> the function advances s through all the string,
                             returns n = 2147483647 as a result of underflow
                             wrapping around INT_MIN = -2147483648.
      atoi(&num) = 2 -> the function returns 2 because of receiving a pointer
                        to an integer 2 as an argument which evaluates to
                        the charater '2'.
      atoi(num) -> Segmentation fault (core dumped). The function cannot access
                   memory at address 0x32 which is the conversion from the
                   input num = 50.

2. Code sudy: strtok
   a. Because the way it is implemented, strtok declares the local variable p
      as static so that its lifetime is the entire run of the program. This
      means that if clients want to parse the same string, they must pass str
      as NULL all the calls except the first one.
   b. The error message is: initializer element is not constant. Static
      variables are allocated at compile time, whereas non-static variables are
      allocated at run time.
   c. The test in line (5) evaluates to true when s and p point at the end of
      the string.
   d. The function will advance s to the null terminator '\0'.
   e. Line (12) sets the end delimiter of a token as a null terminator '\0',
      then advances p one char further.

4. Code study: opendir/readdir
   a. 255
   b. 32816 bytes

