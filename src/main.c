/*
 ============================================================================
 Name        : Calculator.c
 Author      : Ahmed
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "main.h"


int main(void) {


	char infixNotation[BUFFER_SIZE];
	memset(infixNotation, 0, BUFFER_SIZE);
	strcpy(infixNotation, "1111/2" );


	char postfixNotation[BUFFER_SIZE];
	memset(postfixNotation, 0, BUFFER_SIZE);

	infixToPostfix(infixNotation, postfixNotation);
	COMPLEX value = evaluatePostfix(postfixNotation);

	printf("%s=", infixNotation);
	PrintComplex(&value);

	return 0;
}
