#ifndef _prototypes_h
#define _prototypes_h

#include <stdbool.h>
#include <stddef.h>

bool scan_token(const char **p_input, const char *delimiters,
                char buf[], size_t buflen);

#endif
