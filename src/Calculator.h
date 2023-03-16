/*
 * Calculator.h
 *
 *  Created on: Mar 16, 2023
 *      Author: Master
 */

#ifndef CALCULATOR_H_
#define CALCULATOR_H_


void infixToPostfix(char *infixNotation, char *postfixNotation);
uint8_t evaluatePostfix(char *postfixNotation);


#endif /* CALCULATOR_H_ */
