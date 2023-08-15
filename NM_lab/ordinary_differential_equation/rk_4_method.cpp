
#include <iostream>

#define f(x,y) (y*y-x*x)/(y*y+x*x)

using namespace std;

int main()
{
    float k1,k2,k3,k4,xn,x0,y0,h,y1,k;
    int n;
    cout<<"Enter x0,y0,n,xn: ";
    cin>>x0>>y0>>n>>xn;
    h = (xn-x0)/n;
    for(int i=0;i<n;i++)
    {
        k1 = h*(f(x0,y0));
        k2 = h*(f((x0+h/2),(y0+k1/2)));
        k3 = h*(f((x0+h/2),(y0+k2/2)));
        k4 = h*(f((x0+h),(y0+k3)));
        k = (k1+2*k2+2*k3+k4)/6.0;
        y1 = y0+k;
        y0 = y1;
        x0 = x0+h;
    }
    cout<<y1;
    return 0;
}

