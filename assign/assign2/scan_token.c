#include "samples/prototypes.h"
#include <string.h>

bool scan_token(const char **p_input, const char *delimiters, char buf[], size_t buflen)
{
    if (**p_input == '\0') {
        return false;
    }
    
    // Advances the pointer to the first character not contained in delimiters
    *p_input += strspn(*p_input, delimiters);

    int span_length = strcspn(*p_input, delimiters);
    if (span_length == 0) {
        return false;
    }
    
    int token_length = buflen - 1 > span_length ? span_length : buflen - 1;

    strncpy(buf, *p_input, token_length);
    buf[token_length] = '\0';
    *p_input += token_length;
    return true;
}
