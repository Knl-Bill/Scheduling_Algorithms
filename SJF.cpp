#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    cout<<"Number of processes : ";
    int n,a,b,burst=0;
    cin>>n;
    vector<int> m(n);
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the Burst time : ";
        cin>>m[i];
    }
    sort(m.begin(),m.end());
    vector<vector<int>> v(3,vector<int>(n));
    int count = 0,k=0;
    for(int i=0;i<n;i++)
    {
        v[0][i] = v[1][i] = count;
        v[2][i] = v[1][i] + m[i];
        count+=m[i];
    }
    for(int i=0;i<n;i++)
    {
        cout<<"P"<<(i+1)<<"  ";
    }
    cout<<"\n";
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<v[i][j]<<"   ";
        }
        cout<<"\n";
    }
    return 0;
}