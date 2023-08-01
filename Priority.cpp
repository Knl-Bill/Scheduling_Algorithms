#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main()
{
    int n,a,b;
    cout<<"Enter the number of processes : ";
    cin>>n;
    map<int,int> m;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the Priority and the Burst Time : ";
        cin>>a>>b;
        m[a] = b;
    }
    vector<vector<int>> v(3,vector<int>(n,0));
    int check = 0,k=0;
    for(auto i : m)
    {
        v[k][0] = check; // Response Time 
        v[k][1] = check; // Waiting Time. WT will be the same as the RT in this case
        v[k][2] = v[k][1] + i.second; // Turn Around Time(TAT) = Waiting Time +  Burst Time
        check += v[k][2];
        k+=1;
    }
    for(int i=0;i<n;i++)
    {
        cout<<"P"<<(i+1)<<" ";
    }
    cout<<"\n";
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<v[j][i]<<"   ";
        }
        cout<<"\n";
    }
    return 0;
}