#include<bits/stdc++.h>
using namespace std;
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=5e2+5;
const int N=2e5+5;
const int mod=1e9+7;
int k[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int a,b,i,j,n;
    priority_queue<pair<int,pair<int,int>>>pq;
    cin >> n;
    for(i=1;i<=n;i++)cin >> k[i];
    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            if(k[i] >= k[j])pq.push({k[i]-k[j],{i,j}});
            else pq.push({k[j]-k[i],{j,i}});
        }
    }
    while(!pq.empty())
    {
        a=pq.top().second.first;
        b=pq.top().second.second;
        pq.pop();
        cout << "? " << a << ' ' << b << endl;
        cin >> s;
        if(s == "Yes")
        {
            cout << "! " << a << ' ' << b << endl;
            return 0;
        }
    }
    cout << "! 0 0" << endl;
    return 0;
}
//