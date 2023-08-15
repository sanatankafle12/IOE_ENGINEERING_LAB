#include <iostream>
#include <cmath>

using namespace std;

#define f(x) exp(x)-3*x

int main()
{
    float x1,x2,a,b,xn;
    float E = 0.00001;
    cout<<"Enter initial Guesses: "<<endl;
    cin>>x1>>x2;
    if(f(x1)*f(x2)>0)
    {
        cout<<"Non convergernt";
        exit(1);
    }
    if(f(x1)<0)
    {
        a = x1;
        b = x2;
    }
    else
    {
        a = x2;
        b = x1;
    }
    do{
    xn = (a+b)/2;
    if(f(xn)>0)
    {
        b = xn;
    }
    else
    {
        a = xn;
    }
    }while(fabs((b-a)/a)>E);
    cout<<(xn+a)/2;
    return 0;
}