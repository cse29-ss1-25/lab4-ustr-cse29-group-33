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
	// TODO: implement this

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
	// TODO: implement this

}

/*
Given a string s, return s reversed. 

Example: reverse("apples🍎 and bananas🍌") = "🍌sananab dna 🍎selppa")
*/
UStr reverse(UStr s) {
	// TODO: implement this

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

// Adding main funct for testing
/*int main() {
    UStr s1 = new_ustr("Hello, ");
    UStr s2 = new_ustr("world!");
    UStr result1 = concat(s1, s2);

    print_ustr(s1);
    printf("\n");
    print_ustr(s2);
    printf("\n");
    printf("Result of Concat: ");
    print_ustr(result1);
    printf("\n");

    return 0;
}
*/
