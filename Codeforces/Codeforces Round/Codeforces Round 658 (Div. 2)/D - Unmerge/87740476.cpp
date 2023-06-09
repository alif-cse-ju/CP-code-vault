#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
vector<int>v;
int n,dp[4002][4002];
int DP(int cur,int sum)
    if(cur == v.size())
    {
        if(sum == n)return 1;
        return 0;
    }
    if(dp[cur][sum] >= 0)return dp[cur][sum];
    return dp[cur][sum]=(DP(cur+1,sum) | DP(cur+1,sum+v[cur]));
int main()
    FAST();
    int i,j,t,x,mx;
    cin >> t;
    while(t--)
    {
        mx=0;
        cin >> n;
        vector<int>pos;
        for(i=1;i<=2*n;i++)
        {
            cin >> x;
            if(x > mx)
            {
                mx=x;
                pos.emplace_back(i);
            }
        }
        v.clear();
        pos.emplace_back(2*n+1);
        for(i=1;i<pos.size();i++)v.emplace_back(pos[i]-pos[i-1]);
        for(i=0;i<v.size();i++)
        {
            for(j=0;j<=2*n;j++)dp[i][j]=-1;
        }
        if(DP(0,0))cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}