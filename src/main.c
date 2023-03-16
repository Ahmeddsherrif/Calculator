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


int main(void) {
	char infixNotation[BUFFER_SIZE];
	memset(infixNotation, 0, BUFFER_SIZE);
	strcpy(infixNotation, "1111/2+3j*(5j/33j)" );

	char complexStringBuffer[MAX_NUMBER_LENGTH];
	memset(complexStringBuffer, 0, MAX_NUMBER_LENGTH);

	calculate(infixNotation, complexStringBuffer);

	printf("%s=%s",infixNotation, complexStringBuffer);

	return 0;
}
