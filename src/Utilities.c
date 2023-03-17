/*
 * Utilities.c
 *
 *  Created on: Mar 17, 2023
 *      Author: Master
 */

#include <stdint.h>
#include <stdio.h>


#include "Utilities.h"


void doubleToString(double num, char *str) {
	sprintf(str, "%.*f", PRECISION_CONFIG, num);
}

