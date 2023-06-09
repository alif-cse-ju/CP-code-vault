#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int a[105],ans[105];
void Solve(int l,int r,int par)
    if(l > r)return;
    int i,mx=-1,idx;
    for(i=l;i<=r;i++)
    {
        if(a[i] > mx)mx=a[i],idx=i;
    }
    ans[idx]=ans[par]+1;
    Solve(l,idx-1,idx);
    Solve(idx+1,r,idx);
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ans[0]=-1;
    int i,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)
        {
            cin >> a[i];
            ans[i]=0;
        }
        Solve(1,n,0);
        for(i=1;i<=n;i++)cout << ans[i] << ' ';
        cout << '\n';
    }
    return 0;
}
//