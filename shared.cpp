#include <iostream>
#include <cfloat>
#include <math.h>
bool IsNumber(double x)
{
    // This looks like always be true,
// but false is returned if x is NaN
    return (x == x);
}

bool IsPositiveFiniteNumber(double x)
{
    // Separate handling of INF and NINF
    // DBL_MAX is defined in float.h or math.h
    return (x <= DBL_MAX);
}

bool IsNegativeFiniteNumber(double x)
{
//catches negative infinity

    return (x >=-DBL_MAX);


}
bool IsPositiveFinitefloat(float x)
{
    // Separate handling of INF and NINF
    // DBL_MAX is defined in float.h or math.h
    return (x <= FLT_MAX);
}

//Series to generate sin x/x
double sinxseries(double x)
{
    double result=1;
    double pisq=pow(M_PI,2);
    for(int i=1; i<=50; i++)
    {
        result=result*(1-(pow(x,2)/(pow(i,2)*pisq)));

    }
    return result;
}







