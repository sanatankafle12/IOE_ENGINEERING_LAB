#include <iostream>

using namespace std;

int main()
{
    int n;
    float array_x[100],array_y[100],x,sum=0.0,product = 1.0;
    cout<<"Enter the number of datas: ";
    cin>>n;
    cout<<"\nEnter the x values: ";
    for(int i=0;i<n;i++)
    {
        cin>>array_x[i];
    }
    cout<<"\nEnter the y values: ";
    for(int i=0;i<n;i++)
    {
        cin>>array_y[i];
    }
    cout<<"\nEnter the value to find: ";
    cin>>x;
    for(int i=0;i<n;i++)
    {
        product = 1.0;
        for(int j=0;j<n;j++)
        {
            if(i!=j)
            {
                product *= ((x-array_x[j])/(array_x[i]-array_x[j]));
            }
        }
        sum+=(product*array_y[i]);
    }
    cout<<sum;
    return 0;
}
