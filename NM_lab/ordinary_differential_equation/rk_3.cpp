#include <iostream>

#define f(x,y) x+y

using namespace std;

int main()
{
    float x0,y0,xn,h,y1,k1,k2,k3;
    int n;
    cout<<"Enter x0,y0,xn,n: ";
    cin>>x0>>y0>>xn>>n;
    h = (xn-x0)/n;
    for(int i=0;i<n;i++)
    {
        k1 = h*(f(x0,y0));
        k2 = h*(f((x0+h/2),(y0+k1/2)));
        k3 = h*(f((x0+h),(y0+2*k2-k1)));
        y1 = y0 + (k1+4*k2+k3)/6;
        y0 = y1;
        x0 = x0+h;
    }
    cout<<y1;
    return 0;
}