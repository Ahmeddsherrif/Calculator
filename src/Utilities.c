/*
 * Utilities.c
 *
 *  Created on: Mar 17, 2023
 *      Author: Master
 */

#include <stdint.h>


#include "Utilities.h"


void doubleToString(double num, char *str) {
	int32_t num_int = (int32_t) num;
	double num_frac = num - num_int;
	uint8_t i = 0;
	uint8_t precision = PRECISION_CONFIG;

	// Convert the integer part to a string
	while (num_int > 0) {
		str[i++] = (num_int % 10) + '0';
		num_int /= 10;
	}
	if (i == 0) {
		str[i++] = '0';
	}
	str[i] = '\0';

	// Reverse the integer string
	uint8_t j = 0;
	char temp;
	while (j < i / 2) {
		temp = str[j];
		str[j] = str[i - j - 1];
		str[i - j - 1] = temp;
		j++;
	}

	// Add the decimal point and fractional part to the string
	if (precision > 0) {
		str[i++] = '.';
		while (precision-- > 0) {
			num_frac *= 10.0;
			str[i++] = ((uint32_t) num_frac % 10) + '0';
		}
	}
	str[i] = '\0';
}

