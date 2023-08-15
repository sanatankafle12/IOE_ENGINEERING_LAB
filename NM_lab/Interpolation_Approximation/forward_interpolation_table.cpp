#include <iostream>

using namespace std;

int main()
{
    float x[100],y[100][100];
    int n;
    cout<<"Enter the no of datas: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the value of x and y: ";
        cin>>x[i]>>y[i][0];
    } 
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            y[j][i] = y[j+1][i-1]-y[j][i-1];
        }
    }
    for(int i = 0; i < n; i++)
    {
        cout << x[i];
    for(int j = 0; j < n-i ; j++)
    {
        cout << "\t" << y[i][j];
    }
        cout << endl;
    }
    return 0;
}