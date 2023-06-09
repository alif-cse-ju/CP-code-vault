#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t[N],x[N],y[N],ans[N],maxAns[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j,n,r;
    x[0]=y[0]=1;
    cin >> r >> n;
    for(i=1;i<=n;i++)
    {
        cin >> t[i] >> x[i] >> y[i];
        ans[i]=INT_MIN;
        for(j=max(0,i-(r << 1));j<i;j++)
        {
            if(abs(x[i]-x[j])+abs(y[i]-y[j]) <= t[i]-t[j])ans[i]=max(ans[i],ans[j]+1);
        }
        if(i > (r << 1))ans[i]=max(ans[i],maxAns[i-(r << 1)]+1);
        maxAns[i]=max(ans[i],maxAns[i-1]);
    }
    cout << maxAns[n];
    return 0;