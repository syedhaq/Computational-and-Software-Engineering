#include <iostream>
#include <math.h>
#include <cfloat>
#include "head.h"
#include <fenv.h>
#include <limits>
#include <ctime>
using namespace std;
//TODO Execution time

clock_t begin_time=clock();
int ShortOverflow(short x)
{

    for(exponent=0; x>=0; exponent++)
    {

//increment each bit until x becomes negative
        x=x+pow(2,exponent);

    }
    return exponent;

}

int LongOverflow(long x)
{

    for(exponent=0; x>=0; exponent++)
    {

//increment each bit until x becomes negative
        x=x+pow(2,exponent);

    }
    return exponent;

}

int floatOverflow(float x)
{

    for(int exponent=0; x>=0; exponent++)
    {

        x=pow(2,exponent);
        if (!IsPositiveFinitefloat(x))
        {
            return exponent;
        }

    }

}

int doubleOverflow(double x)
{

    for (int exponent=0; x>=0; exponent++)
    {
        x=pow(2,exponent);
        if(!IsPositiveFiniteNumber(x))
        {
            return exponent;
        }

    }


}

float fpOverflowfactorial()
{

//compute factorial until quotient ceases to be one
    for(int i=1; !foundOverflow; i++)
    {
        result*=i;

        quotient=result;
        for(int j=i; j>0; j--)
        {
            quotient=quotient/j;
        }
        if(quotient!=1)
        {
            //found overflow
            foundOverflow=true;
            cout<<"Overflow found at:"<<result<<",factorial: "<<i<<endl;
        }

    }

}

float fpOverflowfactorialdbl()
{

//compute factorial until quotient ceases to be one
    for(int i=1; !foundOverflowdbl; i++)
    {
        resultdbl*=i;

        quotientdbl=resultdbl;
        for(int j=i; j>0; j--)
        {
            quotientdbl=quotientdbl/j;
        }
        if(quotientdbl!=1)
        {
            //found overflow
            foundOverflowdbl=true;
            cout<<"Overflow(double) found at:"<<resultdbl<<",factorial: "<<i<<endl;
        }

    }

}

int infTest()
{


//cout<<1/0<<endl; This causes program to terminate

//1/x

    if((1/inf)!=0 || (1/ninf)!=0)
    {
        cout<<"Error:1/inf is not equal zero"<<endl;


    }

//sin(x) should return NaN
    if(IsNumber(sin(inf)) || IsNumber(sin(ninf)))
    {
        cout<<"Error:sin(inf) is not equal NaN"<<endl;


    }

//exp(x) should return inf
    if(IsPositiveFiniteNumber(exp(inf)) || exp(ninf)!=0 )
    {
        cout<<"Error:exp(infinity) does not equal inf"<<endl;

    }

//Check operations for inf

    if(!IsPositiveFiniteNumber(inf+inf)&& IsNumber(inf-inf) && !IsPositiveFiniteNumber(inf*inf) && IsNumber(inf/inf))
    {
        cout<<"Error in floating point operation"<<endl;



    }

//All tests completed successfully
    return 1;

}

int nantest()
{

//Generate nan to use
    double nan=inf/inf;

//test sin nan

    if (IsNumber(sin(nan)))
    {
        cout<<"Error:sin(nan) leads to a number"<<endl;

    }
//test 1/nan
    if (IsNumber(1/nan))
    {
        cout<<"Error:1/nan leads to a number"<<endl;

    }

//NaN operations
    if(IsNumber(nan+nan)&& IsNumber(nan-nan) && IsNumber(nan*nan) && IsNumber(nan/nan))
    {
        cout<<"Error in nan operation"<<endl;



    }

    return 1;
}
int sftLandTst()
{
//Generate denormalized number
    double x=1,y;

//Smallest normalized
    x=x*pow(2,-1022);
    y=x*pow(2,-1);

//start dividing by two to investigate underflow

    for(int i=1; (!cosx && !xsuby &&!xdivy)||i>=2000; i++)
    {

        x=x/2;


        if(((1-cos(x))/x)!=0)
        {
            cout<<"(1-cos(x)/x) is not zero at x:2^"<<-1022-i<<endl;
            cosx=true;

        }

        if((y-x)==y)
        {
            cout<<"y-x is equal y at x:2^"<<-1022-i<<endl;
            xsuby=true;


        }

        if((x/y)==0)
        {
            cout<<"x/y equals zero at x:2^"<<-1022-i<<endl;
            xdivy=true;
        }

    }
    return 1;

}

int sgnzero()
{

//Negative zero
//double nzero=1/-DBL_MAX;
    double nzero=1/ninf;


    if(IsNumber(log (nzero)))
    {
        cout<<"Error:log(0-) is not NaN"<<endl;
        cout<<(log (nzero))<<endl;

    }

    if(IsNegativeFiniteNumber(log(1/inf)))
    {
        cout<<"Error:log(0+) is not negative infinite"<<endl;
        cout<<log(1/inf)<<endl;

    }

    if(sinxseries(nzero)!=1)
    {
        cout<<"Error:sin(x)/x is not 1"<<endl;
    }

    if((sin(nzero)/nzero)!=1)
    {
        cout<<"Error:sin(x)/x (Direct approach) is not 1"<<endl;
        cout<<sin(nzero)/(nzero)<<endl;
    }

    return 1;



}
int main()
{
//Test for short overflow
    exponent=ShortOverflow(start);
    cout<<"Testing short overflow..."<<endl;
    cout<<"Maximum exponent for short:"<<exponent-1<<endl;
    cout<<"Completed, execution time:"<< (clock()-begin_time)/double(CLOCKS_PER_SEC)*1000<<endl;

    begin_time=clock();
//Test for long overflow
    exponent=LongOverflow(start);
    cout<<"Testing long overflow..."<<endl;
    cout<<"Maximum exponent for long:"<<exponent-1<<endl;

    cout<<"Completed, execution time:"<< (clock()-begin_time)/double(CLOCKS_PER_SEC)*1000<<endl;

    begin_time=clock();
//Test for float overflow
    exponent=floatOverflow(start);
    cout<<"Testing for float overflow..."<<endl;
    cout<<"Maximum exponent for float:"<<exponent-1<<endl;
    cout<<"Completed, execution time:"<< (clock()-begin_time)/double(CLOCKS_PER_SEC)*1000<<endl;

    begin_time=clock();
//Test for float factorial
    cout<<"Testing float overflow (factorial)..."<<endl;
    fpOverflowfactorial();
    cout<<"Completed, execution time:"<< (clock()-begin_time)/double(CLOCKS_PER_SEC)*1000<<endl;

    begin_time=clock();
//Test for double overflow
    exponent=doubleOverflow(start);
    cout<<"Testing for double overflow"<<endl;
    cout<<"Maximum exponent for double:"<<exponent-1<<endl;
    cout<<"Completed, execution time:"<< (clock()-begin_time)/double(CLOCKS_PER_SEC)*1000<<endl;

    begin_time=clock();
//Test for double overflow(factorial)
    cout<<"Testing double overflow(factorial)"<<endl;
    fpOverflowfactorialdbl();
    cout<<"Completed, execution time:"<< (clock()-begin_time)/double(CLOCKS_PER_SEC)*1000<<endl;

    begin_time=clock();
//Test for INF and NINF operations

    cout<<"Testing for INF and NINF operations..."<<endl;
    infTest();
    cout<<"Completed, execution time:"<< (clock()-begin_time)/double(CLOCKS_PER_SEC)*1000<<endl;

    begin_time=clock();
//Check nanoperation
    cout<<"Checking for nan rules..."<<endl;
    nantest();
    cout<<"Completed, execution time:"<< (clock()-begin_time)/double(CLOCKS_PER_SEC)*1000<<endl;

    begin_time=clock();
//Check underflow
    cout<<"Checking for soft landing rules..."<<endl;
    sftLandTst();
    cout<<"Completed, execution time:"<< (clock()-begin_time)/double(CLOCKS_PER_SEC)*1000<<endl;

    begin_time=clock();

//Check signed zero
    cout<<"Checking for signed zero..."<<endl;
    sgnzero();
    cout<<"Completed, execution time:"<< (clock()-begin_time)/double(CLOCKS_PER_SEC)*1000<<endl;

}

