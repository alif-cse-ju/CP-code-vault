#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int n,a[1000002];
int Solve(int x)
    int i,cur=0,mx=0;
    for(i=1;i<=n;i++)
    {
        cur+=x*a[i];
        mx=max(mx,cur);
        if(cur < 0)cur=0;
    }
    return mx;
int main()
    FAST();
    int i,ans,sum=0;
    char s[1000002],t[1000002];
    cin >> n >> s+1 >> t+1;
    for(i=1;i<=n;i++)
    {
        if(s[i] != t[i])
        {
            if(s[i] == '1')a[i]=-1;
            else a[i]=1;
            sum+=a[i];
        }
    }
    if(sum != 0)cout << "-1";
    else
    {
        ans=max(Solve(1),Solve(-1));
        cout << ans;
    }
    return 0;
}