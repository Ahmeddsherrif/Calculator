#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>
#include <string.h>

#include "Utilities.h"
#include "Complex.h"

COMPLEX stringToComplex(const char *inputString) {
	COMPLEX returnedComplexNumber;
	DestroyComplex(&returnedComplexNumber);

	if (strcmp(inputString, "j") == 0) {
		returnedComplexNumber.imaginary = 1;
	} else if (strcmp(inputString, "-j") == 0) {
		returnedComplexNumber.imaginary = -1;
	}

	else {
		char *endptr;
		double num = strtod(inputString, &endptr);

		if (*endptr == 'j') {
			returnedComplexNumber.imaginary = num;
		} else {
			returnedComplexNumber.real = num;
		}
	}

	return returnedComplexNumber;
}

/* Creation */
//Add your code here
COMPLEX CreateComplex(double real, double imaginary) {
	COMPLEX returnedComplexNumber;

	returnedComplexNumber.real = real;
	returnedComplexNumber.imaginary = imaginary;

	return returnedComplexNumber;
}
// End of your code 

/* Destruction */
//Add your code here
void DestroyComplex(CPTR complex) {
	complex->real = 0;
	complex->imaginary = 0;
}
// End of your code 

/* Addition */
//Add your code here
COMPLEX AddComplex(CPTR first, CPTR second) {
	COMPLEX returnedComplexNumber;

	returnedComplexNumber.real = first->real + second->real;
	returnedComplexNumber.imaginary = first->imaginary + second->imaginary;

	return returnedComplexNumber;
}
// End of your code 

/* Subtraction */
//Add your code here
COMPLEX SubtractComplex(CPTR first, CPTR second) {
	COMPLEX returnedComplexNumber;

	returnedComplexNumber.real = first->real - second->real;
	returnedComplexNumber.imaginary = first->imaginary - second->imaginary;

	return returnedComplexNumber;
}
// End of your code 

/* Multiplication */
//Add your code here
COMPLEX MultiplyComplex(CPTR first, CPTR second) {
	COMPLEX returnedComplexNumber;

	returnedComplexNumber.real = (first->real * second->real) - (first->imaginary * second->imaginary);
	returnedComplexNumber.imaginary = (first->real * second->imaginary) + (first->imaginary * second->real);

	return returnedComplexNumber;
}
// End of your code 

/* Conjugate */
//Add your code here
COMPLEX ConjugateComplex(CPTR complex) {
	COMPLEX returnedComplexNumber;

	returnedComplexNumber.real = complex->real;
	returnedComplexNumber.imaginary = (-1) * (complex->imaginary);

	return returnedComplexNumber;
}
// End of your code 

/* Division */
//Add your code here
COMPLEX DivideComplex(CPTR first, CPTR second) {

	COMPLEX secondCONJ = ConjugateComplex(second);

	COMPLEX numerator = MultiplyComplex(first, &secondCONJ);
	COMPLEX denominator = MultiplyComplex(second, &secondCONJ);
	double scalerValue = denominator.real;

	COMPLEX returnedComplexNumber;
	if (scalerValue != 0.0) {
		returnedComplexNumber.real = (numerator.real) / scalerValue;
		returnedComplexNumber.imaginary = (numerator.imaginary) / scalerValue;
	} else {
		// return a zero complex number if it is invalid
		DestroyComplex(&returnedComplexNumber);
	}

	return returnedComplexNumber;
}
// End of your code 




void complexToString(CPTR complex, char *complexString) {
	char complexStringBuffer[MAX_NUMBER_LENGTH];
	memset(complexStringBuffer, 0, MAX_NUMBER_LENGTH);

	char realStringBuffer[MAX_NUMBER_LENGTH];
	memset(realStringBuffer, 0, MAX_NUMBER_LENGTH);

	char imaginaryStringBuffer[MAX_NUMBER_LENGTH];
	memset(imaginaryStringBuffer, 0, MAX_NUMBER_LENGTH);

	if (complex->real != 0.0) {
		doubleToString(complex->real, realStringBuffer);
		strcat(complexStringBuffer, realStringBuffer);
	}
	// Check to see if the sign is positive or negtive to add it to the print status

	if (complex->imaginary != 0.0) {

		if (complex->imaginary > 0 && complex->real != 0.0) {
			strcat(complexStringBuffer, "+");
		}

		else {
			// DO NOTHING
		}

		if (complex->imaginary == 1) {
			strcat(complexStringBuffer, "J");
		}

		else if (complex->imaginary == -1) {
			strcat(complexStringBuffer, "-J");
		}

		else {
			doubleToString(complex->imaginary, imaginaryStringBuffer);
			strcat(complexStringBuffer, imaginaryStringBuffer);
			strcat(complexStringBuffer, "J");
		}
	}

	strcpy(complexString, complexStringBuffer);
}

/* Printing */
//Add your code here
void PrintComplex(CPTR complex) {

	char complexStringBuffer[MAX_NUMBER_LENGTH];
	memset(complexStringBuffer, 0, MAX_NUMBER_LENGTH);

	complexToString(complex, complexStringBuffer);

	printf("%s", complexStringBuffer);

}

// End of your code 
