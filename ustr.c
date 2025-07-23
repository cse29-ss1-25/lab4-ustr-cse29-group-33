#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ustr.h"
#include "pset1.h"

/*
Initializes a new UStr with contents
*/


UStr new_ustr(char* contents) {
	int32_t bytes = strlen(contents);
	int32_t codepoints = utf8_strlen(contents);
	uint8_t all_ascii = bytes == codepoints;
	char* contents_copy = malloc(bytes + 1);
	strcpy(contents_copy, contents);
	UStr s = {
		codepoints,
		bytes,
		all_ascii,
		contents_copy
	};
	return s;
}

/*
Returns length of string
*/
int32_t len(UStr s) {
	return s.codepoints;
}

/*
Returns a substring of str, starting at index start (inclusive) 
and ending at index end (exclusive).

Returns an empty string on invalid range.
*/
UStr substring(UStr s, int32_t start, int32_t end) {
<<<<<<< HEAD
	 // TODO: implement this
    if (start < 0) {
        return new_ustr("");
    }
    if (end > s.codepoints) {
        return new_ustr("");
    }
    if (start >= end) {
        return new_ustr("");
    }
    int byte_index = 0;
    int cp_index = 0;
    int start_byte = 0;
    int end_byte = 0;

    while (s.contents[byte_index] != '\0') {
        if (cp_index == start) {
            start_byte = byte_index;
        }
        if (cp_index == end) {
            end_byte = byte_index;
            break;
        }

        int size = utf8_codepoint_size(s.contents[byte_index]);
        byte_index = byte_index + size;
        cp_index = cp_index + 1;

    }
    if (end_byte == 0) {
        end_byte = byte_index;
    }

    int length = end_byte - start_byte;
    char *new_str = malloc(length + 1);
    int i = 0;
    while (i < length) {
        new_str[i] = s.contents[start_byte + i];
        i = i + 1;
    }
    new_str[length] = '\0';
    UStr result = new_ustr(new_str);
    free(new_str);
    return result;
=======
	// TODO: implement this
>>>>>>> 78e431f9eb2785fbd98ddf8522a924d8893af269
}


/*
Given 2 strings s1 and s2, returns a string that is the result of 
concatenating s1 and s2. 
*/
UStr concat(UStr s1, UStr s2) {
	// TODO: implement this
	int32_t new_byte = s1.bytes + s2.bytes;
	int32_t new_cp = s1.codepoints + s2.codepoints;
	uint8_t is_all_ascii = s1.is_ascii && s2.is_ascii;

	char* new_contents = malloc(new_byte + 1);

	if (new_contents == NULL) {
		return (UStr){0, 0, 1, NULL};
	}

	memcpy(new_contents, s1.contents, s1.bytes);
	memcpy(new_contents + s1.bytes, s2.contents, s2.bytes);

	UStr result = {
		new_cp,
		new_byte,
		is_all_ascii,
		new_contents
	};
	return result;
}

/*
Given a string s and an index, return a string with the character at index 
removed from the original string. 

Returns the original string if index is out of bounds.
*/
UStr removeAt(UStr s, int32_t index) {
<<<<<<< HEAD
	// TODO: implement this
 
=======
	// checking for out of bounds index 
	if (index < 0 || index >= len(s)) return s;
	
	int current = 0; 
	int byte = 0;

	while (current < index) {
		byte += utf8_codepoint_size((uint8_t)s.contents[byte]);
		current++;
	}

	int remove_size = utf8_codepoint_size((uint8_t)s.contents[byte]);
	int new_length = s.bytes - remove_size;

	char* new_contents = malloc(new_length + 1);
	memcpy(new_contents, s.contents, byte);
	memcpy(new_contents + byte, s.contents + byte + remove_size, s.bytes - byte - remove_size);
	new_contents[new_length] = '\0';
	free_ustr(s);

	UStr result = new_ustr(new_contents);
	free(new_contents);
	return result;

>>>>>>> 78e431f9eb2785fbd98ddf8522a924d8893af269
}

/*
Given a string s, return s reversed. 

Example: reverse("apples🍎 and bananas🍌") = "🍌sananab dna 🍎selppa")
*/
UStr reverse(UStr s) {
<<<<<<< HEAD
	// TODO: implement this
  
=======
	int cp_len = s.codepoints;
	char* reversed_contents = malloc(s.bytes + 1);
	int reversed_index = 0;

	for (int i = cp_len - 1; i >= 0; i--) {
		int byte_index = bi_of_cpi(s.contents, i);
		int size = utf8_codepoint_size(s.contents[byte_index]);

		memcpy(&reversed_contents[reversed_index], &s.contents[byte_index], size);
		reversed_index += size;
	}
	reversed_contents[reversed_index] = '\0';


	UStr result = new_ustr(reversed_contents);
	free(reversed_contents);

	return result;
>>>>>>> 78e431f9eb2785fbd98ddf8522a924d8893af269

}


void print_ustr(UStr s) {
	printf("%s [codepoints: %d | bytes: %d]", s.contents, s.codepoints, s.bytes);
}

void free_ustr(UStr s) {
	if (s.contents != NULL) {
		free(s.contents);
		s.contents = NULL;
	}
}
<<<<<<< HEAD

// Adding main funct for testing
//int main() {
   // UStr s1 = new_ustr("Hello, ");
    //UStr s2 = new_ustr("world!");
    //UStr result1 = concat(s1, s2);

    //print_ustr(s1);
    //printf("\n");
    //print_ustr(s2);
    //printf("\n");
    //printf("Result of Concat: ");
    //print_ustr(result1);
    //printf("\n");

    //return 0;
//}
=======
>>>>>>> 78e431f9eb2785fbd98ddf8522a924d8893af269
