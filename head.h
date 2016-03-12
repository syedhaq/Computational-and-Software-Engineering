#ifndef head_h
#define head_h
#include <limits>
int start=1; //starting point for overflows
int exponent;//max exponent before overflow
double inf=INFINITY;
double ninf=-INFINITY;
float result=1; //multiplication result for factorial
bool foundOverflow=false;
int quotient=1;

double resultdbl=1; //multiplication result for factorial
bool foundOverflowdbl=false;
int quotientdbl=1;

//These are for underflow operations
bool cosx=false,xsuby=false,xdivy=false;

bool IsNumber(double x);
bool IsPositiveFiniteNumber(double x);
bool IsPositiveFinitefloat(float x);
bool positiveInfTest(double x);
double sinxseries(double x);
bool IsNegativeFiniteNumber(double x);

#endif
