#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

#include "defines.h"
#include "Stack.h"

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

	Stack_t operationStack;
	stack_ctor(&operationStack);

	Stack_t outputStack;
	stack_ctor(&outputStack);

	uint8_t i;
	for (i = 0; i < strlen(infixNotation); i++) {
		if (isdigit(infixNotation[i]) == TRUE) {
			stack_push(&outputStack, infixNotation[i]);
		} else {
			switch (infixNotation[i]) {
				case '(': {
					stack_push(&operationStack, infixNotation[i]);
					break;
				}
				case ')': {

					while (stack_top(&operationStack) != '(') {
						stack_push(&outputStack, stack_top(&operationStack));
						stack_pop(&operationStack);
					}

					//To pop the open Bracket '('
					stack_pop(&operationStack);

					break;
				}

				case '+':
				case '-':
				case '/':
				case '*': {

					if (stack_isEmpty(&operationStack) == TRUE || stack_top(&operationStack) == '(') {
						stack_push(&operationStack, infixNotation[i]);
					} else {

						if (has_higher_precedence(infixNotation[i], stack_top(&operationStack)) == FALSE) {
							stack_push(&outputStack, stack_top(&operationStack));
							stack_pop(&operationStack);
						}

						stack_push(&operationStack, infixNotation[i]);
					}
					break;
				}

				default: {
					// INVALID INPUT
				}
			}

		}
#if LOG == TRUE
		printf("%c\t", infixNotation[i]);
		stack_print(&operationStack);
		stack_print(&outputStack);
		printf("\n");
#endif
	}

	while (stack_isEmpty(&operationStack) == FALSE) {
		stack_push(&outputStack, stack_top(&operationStack));
		stack_pop(&operationStack);

#if LOG == TRUE
		printf("\t");
		stack_print(&operationStack);
		stack_print(&outputStack);
		printf("\n");
	}
#endif

	stack_get_string(&outputStack, postfixNotation);
}


uint8_t evaluatePostfix(char *postfixNotation) {
	Stack_t resultStack;
	stack_ctor(&resultStack);

	uint8_t operand1;
	uint8_t operand2;
	uint8_t result;

	uint8_t j;
	for (j = 0; j < strlen(postfixNotation); j++) {
		if (isdigit(postfixNotation[j]) == TRUE) {
			stack_push(&resultStack, postfixNotation[j] - '0');
		} else {
			operand1 = stack_top(&resultStack);
			stack_pop(&resultStack);

			operand2 = stack_top(&resultStack);
			stack_pop(&resultStack);

			switch (postfixNotation[j]) {
				case '+': {
					result = operand2 + operand1;
					break;
				}
				case '-': {
					result = operand2 - operand1;
					break;
				}
				case '*': {
					result = operand2 * operand1;
					break;
				}
				case '/': {
					result = operand2 / operand1;
					break;
				}
			}

			stack_push(&resultStack, result);

		}
	}


	uint8_t rtnValue = stack_top(&resultStack);

	return rtnValue;
}


