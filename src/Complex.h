#ifndef _COMPLEX_H_
#define _COMPLEX_H_

struct complex {
	double real;
	double imaginary;
};

typedef struct complex COMPLEX, *CPTR;

COMPLEX CreateComplex(double real, double imaginary);
void DestroyComplex(CPTR complex);
COMPLEX AddComplex(CPTR first, CPTR second);
COMPLEX SubtractComplex(CPTR first, CPTR second);
COMPLEX MultiplyComplex(CPTR first, CPTR second);
COMPLEX ConjugateComplex(CPTR complex);
COMPLEX DivideComplex(CPTR first, CPTR second);
void PrintComplex(CPTR complex);
COMPLEX stringToComplex(const char *inputString);

#endif //_COMPLEX_H_