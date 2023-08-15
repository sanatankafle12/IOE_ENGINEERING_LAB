#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float sum_x=0,sum_y=0,sum_xx=0,sum_xy=0,d1,d2,d3,x,y,a,b;
    int n;
    cout<<"Enter the no of datas: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter x and y respectively: ";
        cin>>x>>y;
        sum_x+=x;
        sum_y+=y;
        sum_xx+=x*x;
        sum_xy+=x*y;
    }
    d1 = sum_y*sum_xx-sum_xy*sum_x;
    d2 = n*sum_xx-sum_x*sum_x;
    d3 = n*sum_xy-sum_x*sum_y;
    a = d1/d2;
    b = d3/d2;
    cout<<"The curve y = "<<a<<"+"<<b<<"x";
    return 0;
}