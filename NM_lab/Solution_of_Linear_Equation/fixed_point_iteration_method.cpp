#include <iostream>
#include <cmath>

using namespace std;

#define f(x) sin(x)+3*x-2
#define g(x) (-sin(x)+2)/3

int main()
{
    float x1,fx,x0;
    cout<<"Enter initial value";
    cin>>x0;
    do
    {
        x1 = g(x0);
        x0 = x1;
        fx = f(x1);
    }while(fabs(fx)>0.0001);
    cout<<x1;
    return 0;
}
