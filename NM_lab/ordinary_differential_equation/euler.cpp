#include <iostream>

#define f(x,y) x+y

using namespace std;

int main()
{
    float x0,y0,x1,y1,xn,h,slope;
    int n;
    cout<<"Enter x0, y0 and xn and number of steps: ";
    cin>>x0>>y0>>xn>>n;
    h = (xn-x0)/n;
    for(int i=0;i<n;i++)
    {
        slope = f(x0,y0);
        y1 = y0+h*slope;
        y0 = y1;
        x0 = x0+h;
    }
    cout<<y1;
    return 0;
}