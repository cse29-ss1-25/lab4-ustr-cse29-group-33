#include <stdio.h>
#include <string.h>
#include "ustr.h"

int main() {
    char input[256];
    while(fgets(input, sizeof(input), stdin)) {
        // Remove newline character if present
        char str1[256];
	char str2[256];

	UStr s1 = new_ustr(str1);
	UStr s2 = new_ustr(str2);
	UStr result = concat(s1, s2);

	printf("Result: '%s' [codepoints: %d, bytes: %d, ascii: %d]\n",
               result.contents, result.codepoints, result.bytes, result.is_ascii);
	size_t l = strlen(input);
        if (l > 0 && input[l - 1] == '\n') {
            input[l - 1] = '\0';
        }

        free_ustr(result);
        free_ustr(s2);
        free_ustr(s1);
    }
    return 0;
   
}
