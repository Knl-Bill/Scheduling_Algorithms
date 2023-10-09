#include <bits/stdc++.h>
using namespace std;
bool comparator(vector<int> &a, vector<int> &b)
{
    if(a[0] == b[0])
        return a[1] < b[1];
    return a[0] < b[0];
}
int main()
{
    int n;
    cout<<"Enter the number of processes : ";
    cin>>n;
    vector<vector<int>> v(n, vector<int> (6,0));
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the Arrival Time and Burst Time for P"<<(i+1)<<" : ";
        cin>>v[i][0]>>v[i][1];
    }
    sort(v.begin(), v.end(), comparator);
    map<int,int> sjf;
    int time = v[0][0];
    for(int i=0;i<n;i++)
    {
        if(v[i][0] > time and sjf.size() == 0)
            time += (v[i][0] - time);
        if(v[i][5] == 0)
            v[i][2] = v[i][3] = max((time - v[i][0]),0);
        int index = i;
        while(index < n and v[index][0] <= time)
        {
            if(v[i][5] == 0)
                sjf.insert({v[index][1], index});
            index++;
        }
        map<int,int> :: iterator it = sjf.begin();
        time += it->first;
        v[it->second][5] = 1;
        v[it->second][4] = v[it->second][1] + v[it->second][3];
        sjf.erase(it);
    }
    for(int i=0;i<n;i++)
    {
        cout<<"For P"<<(i+1)<<" : \n";
        cout<<"RT = "<<v[i][2]<<", WT = "<<v[i][3]<<", TAT = "<<v[i][4]<<"\n";
    }
    return 0;
}