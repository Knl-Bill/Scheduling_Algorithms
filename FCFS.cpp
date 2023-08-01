#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main()
{
    map<int,int> m;
    cout<<"Number of processes : ";
    int n,a,b,burst=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the Arrival time : ";
        cin>>a;
        cout<<"Enter the Burst time : ";
        cin>>b;
        burst+=b;
        m.insert({a,b});
    }
    vector<vector<int>> v(3,vector<int>(n));
    int count = 0,k=0;
    for(auto i:m)
    {
        if(count<i.first)
            v[0][k] = 0;
        else
            v[0][k] = count - i.first;
        v[1][k] = v[0][k];
        v[2][k] = v[1][k] + i.second;
        k++;
        count += i.second;
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