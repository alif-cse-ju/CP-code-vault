#include<bits/stdc++.h>

using namespace std;

#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

LL cnt[100005];

int main()
{
    FAST();
    int i,n,q;
    LL x,y,z,ans=0;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> x;
        ans+=x,++cnt[x];
    }
    cin >> q;
    while(q--)
    {
        cin >> x >> y;
        z=cnt[x];
        ans+=(y-x)*z;
        cnt[x]=0,cnt[y]+=z;
        cout << ans << '\n';
    }
    return 0;
}
