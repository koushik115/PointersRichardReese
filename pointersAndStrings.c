#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

size_t stringLength(char *string);

int main(void) {
	wchar_t wideCharacter;
	printf("%lu\n", sizeof(wideCharacter)); // Size is 4 bytes
	printf("%lu\n", sizeof(char)); // Size is 1 byte
	printf("%lu\n", sizeof('a')); // wth!! size is 4 bytes!
	
	/*
	char *tabHeader = "Sound";
	*tabHeader = 'L';   // This caused segmenation fault :( 
	printf("%s\n", tabHeader); 
	*/

	/* String Initialization */
	
	/* Initialization an array of char */
	char headerArray[] = "Media Player";

	/* Or
	 *
	 * char header[13];
	 * strcpy(header, "Media Player");
	 *
	 * header[0] = 'M''
	 * header[1] = 'e';
	 * ...
	 * header[12] = '\0';
	 *
	 * char header2[];
	 * header2 = "Media Player"; // Invalid!!!
	 *
	 */

	/* Initialization a pointer to char */
	char *headerPointer = (char *)malloc(strlen("Media Player") + 1); // Why not sizeof operator?? because sizeof opertator returns the sizeof
									  // any array or pointer, here sizeof works but if I have used some pointer
									  // then the sizeof will give the size of pointer not number of
									  // character literal!
	strcpy(headerPointer, "Media Player");

	/* Or
	 *
	 * *(headerPointer + 0) = 'M'
	 * *(headerPointer + 1) = 'e'
	 * ...
	 * *(headerPointer + 12) = '\0';
	 *
	 * char *headerPointer = "Media Player"; // If you try to modify this, your application will be cooked because the string is immutable
	 * 					 // and resides in .rodata section of the memory
	 * 
	 * char *prefix = '+';                   // This won't work as you '+' is a character which is nothing but an integer, you are assigning
	 * 					 // an integer to the character pointer, if you try to dereference it, you will be cooked again!
	 *
	 * char *prefix = (char *)malloc(2);
	 * *(prefix + 0) = '+';
	 * *(prefix + 1) = '\0';
	 *
	 */

	/* Initializng a string from statndard input */
	/*
	 *
	 * char *command;
	 * printf("Enter a command: ");
	 * scanf("%s", command);		// Here, the application wil get cooked again, as no memory is allocated to the command variable
	 *
	 *
	 */

	/* Summary of string placement */
	/*
	 * char *globalHeader = "Chapter";
	 * char globalArrayHeader[] = "Chapter";
	 *
	 * void displayHeader() {
	 *
	 * 	static char* staticHeader = "Chapter";
	 *	char* localHeader = "Chapter";
	 *	static char staticArrayHeader[] = "Chapter";
	 *	char localArrayHeader[] = "Chapter";
	 *	char *heapHeader = (char*)malloc(strlen(Chapter") + 1);
	 *	strcpy(heapHeader, "Chapter");
	 * }
	 */

	/* Standard String Operation: int strcmp(const char *s1, const char *s2) */
	char *command = (char *)malloc(16);
	printf("Enter a command: ");
	scanf("%s", command);
	if(strcmp(command, "Quit") == 0) {
		printf("The command was Quit\n");
	} else {
		printf("The command was not Quit\n");
	}

	/*
	 * char command[16];
	 * printf("Enter a Command: ");
	 * scanf("%s", command);
	 * if(command = "Quit") { // tf is this??, first, it does not perform a comparison, and second, this will result in syntax error
	 * 	.....		  // complaining about incompatible types. We cannot assign the address of a string to an array name
	 * }
	 *
	 *
	 * char command[16];
	 * printf("Enter a command: ");
	 * scanf("%s", command);
	 * if(command == "Quit") { // Who taught you C?? this will always be false as we are comparing two different address
	 * 	...
	 * }
	 *
	 */

	/* Copying Strings: char *strcpy(char *s1, const char *s2); */
	for(size_t count = 0; count < 30; count++) {

		char name[32];
		char *names[30];

		printf("Enter a name: ");
		scanf("%s", name);
		names[count] = (char *)malloc(strlen(name) + 1);
		strcpy(names[count], name);
		printf("%s\n", names[count]);
		free(names[count]);
	}

	/* Two pointers can reference the same string. When two pointers reference the same location, this is called aliasing.
	 * The assignment of one pointer to another does not result in the string being copied. Instead, it simply copies the string address
	 * char *pageHeader[300];
	 * pageHeader[12] = "Amorphous Compounds";
	 * pageHeader[13] = pageHeader[12]; // pageHeader[13] is an alias of pageHeader[12] and points to the same string literal pool
	 */

	/* Concatenation Strings: char *strcat(char *s1, const char *s2); */
	char *error = "ERROR: ";
	char *errorMessage = "Not enough memory";

	char *buffer = (char *)malloc(strlen(error) + strlen(errorMessage) + 1);
	strcpy(buffer, error);
	strcat(buffer, errorMessage);

	printf("%s\n", buffer); // ERROR: Not enough memory
	printf("%s\n", error);  // ERROR
	printf("%s\n", errorMessage); // Not enough memory
	
	char errorArray[] = "ERROR: ";
	char errorMessageArray[] = "Not enough memory";
	/*
	 * errorArray = strcat(errorArray, errorMessageArray); // Syntax error
	 * strcat(errorArray, errorMessageArray); // This will corrupt the stack frame
	 *
	 */

	char *path = "C:";
	char *currentPath = (char *)malloc(strlen(path) + 2);
	strcpy(currentPath, path);
	currentPath = strcat(currentPath, "\\");


	/* Passing Strings */
	/*
	 * Refer String Length function
	 */
	char simpleArray[] = "simple string";
	char *simplePtr = (char *)malloc(strlen("simple string") + 1);
	strcpy(simplePtr, "simple string");
	printf("%lu\n", stringLength(simplePtr));
	printf("%lu\n", stringLength(simpleArray));
	/* printf("%d\n", stringLength(&simpleArray)); */ // Redundant and unecessary
	printf("%lu\n", stringLength(&simpleArray[0]));
	/* We could have declared the formal parameter of the stringLength function using array notaion instead of pointer notaion
	 * The function body will remain same, this change will have no effect on how function is invoked and its behavious
	 *
	 */


	return 0;
}

size_t stringLength(char *string) {
	size_t length = 0;

	while(*(string++)) length++;

	return length; 
}
