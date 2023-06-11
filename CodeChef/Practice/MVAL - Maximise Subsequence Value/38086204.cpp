#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long a[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    long long ans;
    int i,n,t,cnt,sz;
    cin >> t;
    while(t--)
    {
        cin >> n;
        ans=cnt=0;
        for(i=1;i<=n;i++)
        {
            cin >> a[i];
            if(a[i] > 0)++cnt,ans+=a[i];
        }
        vector<int>idx;
        for(i=1;i<=cnt;i++)
        {
            if(a[i] <= 0)idx.emplace_back(i);
        }
        sz=idx.size();
        for(i=cnt+1;i<=n  &&  sz;i++)
        {
            if(a[i] > 0)--sz,idx.emplace_back(i);
        }
        cout << ans << '\n';
        cout << idx.size();
        for(int x : idx)cout << ' ' << x;
        cout << '\n';
    }
    return 0;
}