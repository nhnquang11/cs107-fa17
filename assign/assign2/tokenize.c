#include "samples/prototypes.h"
#include <error.h>
#include <stdio.h>
#include <string.h>

void test_scan_token(const char *delim, const char *input, const char *result, size_t buf_size) {
    char buf[buf_size];
    const char* remaining = input;
    printf("Testing on inputs: delimiters=\"%s\", str=\"%s\"\n", delim, input);
    printf("Using scan_token: { ");
    while (scan_token(&remaining, delim, buf, sizeof(buf))) {
        printf("\"%s\" ", buf);
    }
    printf("}\n");
    
    printf("Result          : { %s}\n", result);
    printf("\n");
}

int main(int argc, char *argv[])
{
    printf("------------------------ Testing ------------------------\n");
    const size_t buf_size = 10;
    printf("Testing scan token...\n");
    printf("Buffer size = %zu...\n", buf_size);
    printf("\n");

    // Try empty string;
    test_scan_token("-", "", "", buf_size);

    // Try one letter string
    test_scan_token("-", "a", "\"a\" ", buf_size);

    // Try string containing only delimiters
    test_scan_token("-+*/", "--++**//", "", buf_size);

    // Try simple string delimited by hyphens
    test_scan_token("-", "writing-test-cases-is-boring",
                    "\"writing\" \"test\" \"cases\" \"is\" \"boring\" ", buf_size);

    // Try comlex string with multiple-character delim and tokens not
    // fitting in buf
    test_scan_token("-+", "++frizziness-+-hypercomplex++quizzifications-+-",
                    "\"frizzines\" \"s\" \"hypercomp\" \"lex\" \"quizzific\" \"ations\" ", buf_size);

    printf("-------------------- End of testing --------------------\n\n");

    if (argc < 3) error(1, 0, "Missing argument(s). Please supply delimiters and string to tokenize.");

    const char *delim = argv[1];
    const char *input = argv[2];

    char copy[strlen(input)+1];
    strcpy(copy, input);       // make copy, strtok is going to destroy it

    printf("Using strtok:     { ");
    for (char *token = strtok(copy, delim); token != NULL; token = strtok(NULL, delim)) {
        printf("\"%s\" ", token);
    }
    printf("}\n");

    char buf[10];
    const char *remaining = input;
    printf("Using scan_token: { ");
    while (scan_token(&remaining, delim, buf, sizeof(buf))) {
        printf("\"%s\" ", buf);
    }
    printf("}\n");

    return 0;
}
