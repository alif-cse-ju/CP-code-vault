#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,k,n,t,ans,cur,weight[1002];
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(i=1;i<=n;i++)cin >> weight[i];
        ans=cur=0;
        for(i=1;i<=n;i++)
        {
            if(weight[i] > k)break;
            if(cur+weight[i] <= k)cur+=weight[i];
            else ++ans,cur=weight[i];
        }
        if(i <= n)cout << "-1\n";
        else cout << ++ans << '\n';
    }
    return 0;
}