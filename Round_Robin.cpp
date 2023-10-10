#include <bits/stdc++.h>
using namespace std;
bool comparator(vector<int> &a, vector<int> &b)
{
    return a[0] < b[0];
}
int main()
{
    cout<<"Enter the number of processes : ";
    int n;
    cin>>n;
    vector<vector<int>> v(n,vector<int> (5)); // 0th index is arrival time, 1st index is burst time, 2nd index is Response time and 3rd index is Wait time and 4th index is turn around time
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the Arrival time and Burst time for the process "<<(i+1)<<" : ";
        cin>>v[i][0]>>v[i][1];
        v[i][2] = v[i][3] = v[i][4] = 0;
    }
    sort(v.begin(),v.end(),comparator);
    int time = v[0][0], time_quantum = 2;
    vector<int> burst_time(n);
    for(int i=0;i<n;i++)
    {
        burst_time[i] = v[i][1];
    }
    while(1)
    {
        bool completed = 1;
        for(int i=0;i<n;i++)
        {
            if(v[i][0] <= time and burst_time[i] > 0)
            {
                completed = false;
                int exe = min(time_quantum,burst_time[i]);
                for(int j=0;j<n;j++)
                {
                    if(v[j][0] <= time and burst_time[j] == v[j][1])
                        v[j][2] = time - v[j][0];
                    if(v[j][0] > time)
                        break;
                    if(i!=j and v[j][0] <= time and burst_time[j] > 0)
                    {
                        v[j][3] += exe;
                    }
                }
                burst_time[i] -= exe;
                time += exe;
            }
        }
        if(completed)
            break;
    }
    for(int i=0;i<n;i++)
    {
        v[i][4] = v[i][1] + v[i][3];
        cout<<"For process p"<<(i+1)<<"\n";
        cout<<"RT = "<<v[i][2]<<" WT = "<<v[i][3]<<" TAT = "<<v[i][4]<<"\n";
    }
    return 0;
}