#include <iostream>
#include <cmath>

using namespace std;

#define f(x,y) y/(x*x+y*y)

int main()
{
    float x0,y0,y1,h,k1,k2,xn;
    int n;
    cout<<"Enter x0,y0,xn,n: ";
    cin>>x0>>y0>>xn>>n;
    h = (xn-x0)/n;
    for(int i=0;i<n;i++)
    {
        k1 = h*(f(x0,y0));
        k2 = h*(f((x0+h),(y0+k1)));
        y1 = y0 + (k1+k2)/2;
        y0 = y1;
        x0 = x0 + h;
    }
    cout<<y1;
    return 0;
}