#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL)
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
int main()
    FAST();
    int i,j,n,t,x,a[102],sum[102]={0};
    cin >> t;
    while(t--)
    {
        cin >> n >> x;
        for(i=1;i<=n;i++)cin >> a[i],sum[i]=sum[i-1]+a[i];
        for(i=1;i<=n  &&  sum[i]!=x;i++);
        if(i == n)cout << "NO\n";
        else
        {
            vector<int>ans;
            for(j=1;j<=n;j++)ans.emplace_back(a[j]);
            if(i < n)swap(ans[i-1],ans[i]);
            cout << "YES\n";
            for(int it : ans)cout << it << ' ';
            cout << '\n';
        }
    }
    return 0;