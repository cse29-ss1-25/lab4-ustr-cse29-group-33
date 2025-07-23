#include <stdio.h>
#include <string.h>
#include "ustr.h"

int main() {
    char input[256];	
    while(fgets(input, sizeof(input), stdin)) {
	size_t l = strlen(input);
	if (l > 0 && input[l - 1] == '\n') {
		input[l - 1] = '\0';
	}



	UStr s = new_ustr(input);
	UStr r = removeAt(s, 2);
        print_ustr(r); 
	free_ustr(r);
    }

    return 0;
}
