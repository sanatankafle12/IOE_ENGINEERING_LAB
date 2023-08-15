#include <iostream>
#include <cmath>

using namespace std;

#define f(x) x*x*x-4*x+1
#define g(x) 3*x*x+4

int main()
{
    float fx,gx,x0,x1;
    cout<<"Enter the initial guess: ";
    cin>>x0;
    x1 = x0;
    do
    {
        x0 = x1;
        fx = f(x0);
        gx = g(x0);
        x1 = x0 - fx/gx;
    }while(fabs((x1-x0)/x1)>0.0001);
    cout<<x1;
    return 0;
}