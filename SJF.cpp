#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    // The code is written assuming that the arrival time for all the processes is the same
    cout<<"Number of processes : ";
    int n,a,b,burst=0;
    cin>>n;
    vector<int> m(n);
    // Using maps to take the input as the map keys are by default sorted so we won't need to sort the input according to the burst time afterwards
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the Burst time : ";
        cin>>m[i];
    }
    sort(m.begin(),m.end());
    // Declaring a 2D vector of 3 X n. 
    // The 1st row denotes the Response Time (RT), 2nd row denotes the Wait Time (WT), and the 3rd row denotes the Turn Around Time (TAT)
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
