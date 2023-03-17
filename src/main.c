/*
 ============================================================================
 Name        : Calculator.c
 Author      : Ahmed Sherif Mohamed
 Version     :
 Copyright   : 
 Description : Software Version of Complex Number Calculator
 ============================================================================
 */

#include "main.h"

int main(int argc, char* argv[]) {

	char infixNotation[BUFFER_SIZE];
	char complexStringBuffer[MAX_NUMBER_LENGTH];

	LOG = FALSE;

	if(argc == 2 && strcmp(argv[1],"-L") == 0){
		LOG = TRUE;
	}

	while (1) {
		memset(infixNotation, 0, BUFFER_SIZE);
		memset(complexStringBuffer, 0, MAX_NUMBER_LENGTH);

		printf("Enter Expression: ");
		scanf("%s", infixNotation);

		if (strcmp(infixNotation, "KILL") == 0) {
			break;
		}

		calculate(infixNotation, complexStringBuffer);

		printf("= %s\n\n", complexStringBuffer);
	}

	return 0;
}
