#include<bits/stdc++.h>
 using namespace std;
 long long Solve(vector<int>& v)
{
    if(v.size() == 1)return 0;
    int i,j;
    long long ans=LLONG_MAX,cnt;
    for(i=0;i<(int)v.size();i++)
    {
        cnt=0;
        for(j=0;j<(int)v.size();j++)cnt+=abs(v[i]-v[j]);
        ans=min(ans,cnt);
    }
    return ans;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j,m,n,t;
    long long ans,a[102][102];
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)cin >> a[i][j];
        }
        ans=0;
        for(i=1;i<=(n+1)/2;i++)
        {
            for(j=1;j<=(m+1)/2;j++)
            {
                vector<int>v;
                v.emplace_back(a[i][j]);
                if(j != m-j+1)v.emplace_back(a[i][m-j+1]);
                if(i != n-i+1)v.emplace_back(a[n-i+1][j]);
                if(i != n-i+1  &&  j != m-j+1)v.emplace_back(a[n-i+1][m-j+1]);
                ans+=Solve(v);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}