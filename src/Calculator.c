#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

#include "defines.h"
#include "Complex.h"
#include "Stack_char.h"
#include "Stack_complex.h"

uint8_t has_higher_precedence(char op1, char op2) {
	uint8_t rtnValue = FALSE;

	if ((op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-')) {
		rtnValue = TRUE;
	} else {
		rtnValue = FALSE;
	}

	return rtnValue;
}

void infixToPostfix(char *infixNotation, char *postfixNotation) {

	if (LOG == TRUE) {
		printf("\n");
	}

	StackChar_t operationStack;
	stack_char_ctor(&operationStack);

	StackChar_t outputStack;
	stack_char_ctor(&outputStack);

	uint8_t isNumberEnded = TRUE;
	uint8_t i;
	for (i = 0; i < strlen(infixNotation); i++) {
		if (isdigit(infixNotation[i]) == TRUE || infixNotation[i] == 'j' || infixNotation[i] == 'J' || infixNotation[i] == '.') {
			if (isNumberEnded == TRUE) {
				isNumberEnded = FALSE;
			}
			stack_char_push(&outputStack, infixNotation[i]);
		} else {

			if (isNumberEnded == FALSE) {
				isNumberEnded = TRUE;
				stack_char_push(&outputStack, '$');
			}

			switch (infixNotation[i]) {
				case '(': {
					stack_char_push(&operationStack, infixNotation[i]);
					break;
				}
				case ')': {

					while (stack_char_top(&operationStack) != '(') {
						stack_char_push(&outputStack, stack_char_top(&operationStack));
						stack_char_pop(&operationStack);
					}

					//To pop the open Bracket '('
					stack_char_pop(&operationStack);

					break;
				}

				case '+':
				case '-':
				case '/':
				case '*': {

					if (stack_char_isEmpty(&operationStack) == TRUE || stack_char_top(&operationStack) == '(') {
						stack_char_push(&operationStack, infixNotation[i]);
					} else {

						while (has_higher_precedence(infixNotation[i], stack_char_top(&operationStack)) == FALSE
								&& stack_char_isEmpty(&operationStack) == FALSE) {
							stack_char_push(&outputStack, stack_char_top(&operationStack));
							stack_char_pop(&operationStack);
						}

						stack_char_push(&operationStack, infixNotation[i]);
					}
					break;
				}

				default: {
					// INVALID INPUT
				}
			}

		}

		if (LOG == TRUE) {
			printf("%c\t", infixNotation[i]);
			stack_char_print(&operationStack);
			stack_char_print(&outputStack);
			printf("\n");
		}
	}

	if (isNumberEnded == FALSE) {
		isNumberEnded = TRUE;
		stack_char_push(&outputStack, '$');
	}

	while (stack_char_isEmpty(&operationStack) == FALSE) {
		stack_char_push(&outputStack, stack_char_top(&operationStack));
		stack_char_pop(&operationStack);

		if (LOG == TRUE) {
			printf("\t");
			stack_char_print(&operationStack);
			stack_char_print(&outputStack);
			printf("\n");
		}
	}

	if (LOG == TRUE) {
		printf("\n");
	}

	stack_char_get_string(&outputStack, postfixNotation);
}

#define COMPLEX_NUMBER_STRING_SIZE	10

COMPLEX evaluatePostfix(char *postfixNotation) {
	StackComplex_t resultStack;
	stack_complex_ctor(&resultStack);

	StackChar_t complexNumberStack;
	stack_char_ctor(&complexNumberStack);

	char complexNumberString[COMPLEX_NUMBER_STRING_SIZE];
	memset(complexNumberString, 0, COMPLEX_NUMBER_STRING_SIZE);

	COMPLEX operand1;
	COMPLEX operand2;
	COMPLEX result;

	uint8_t i;
	for (i = 0; i < strlen(postfixNotation); i++) {
		if (isdigit(postfixNotation[i]) == TRUE || postfixNotation[i] == 'j' || postfixNotation[i] == 'J' || postfixNotation[i] == '.') {
			stack_char_push(&complexNumberStack, postfixNotation[i]);
		} else if (postfixNotation[i] == '$') {
			stack_char_get_string(&complexNumberStack, complexNumberString);
			result = stringToComplex(complexNumberString);

			//Clear Number Buffers
			stack_char_ctor(&complexNumberStack);
			memset(complexNumberString, 0, COMPLEX_NUMBER_STRING_SIZE);

			stack_complex_push(&resultStack, result);
		} else {
			operand1 = stack_complex_top(&resultStack);
			stack_complex_pop(&resultStack);

			operand2 = stack_complex_top(&resultStack);
			stack_complex_pop(&resultStack);

			switch (postfixNotation[i]) {
				case '+': {
					result = AddComplex(&operand2, &operand1);
					break;
				}
				case '-': {
					result = SubtractComplex(&operand2, &operand1);
					break;
				}
				case '*': {
					result = MultiplyComplex(&operand2, &operand1);
					break;
				}
				case '/': {
					result = DivideComplex(&operand2, &operand1);
					break;
				}
			}

			if (LOG == TRUE) {
				printf("(");
				PrintComplex(&operand2);
				printf(") %c (", postfixNotation[i]);
				PrintComplex(&operand1);
				printf(") = ");
				PrintComplex(&result);
				printf("\n");
			}

			stack_complex_push(&resultStack, result);

		}
	}

	COMPLEX rtnValue = stack_complex_top(&resultStack);

	if (LOG == TRUE) {
		printf("\n");
	}

	return rtnValue;
}

void calculate(char *expression, char *evaluation) {

	char postfixNotation[BUFFER_SIZE];
	memset(postfixNotation, 0, BUFFER_SIZE);

	infixToPostfix(expression, postfixNotation);
	COMPLEX value = evaluatePostfix(postfixNotation);

	complexToString(&value, evaluation);
}

