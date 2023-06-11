#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
const int N=1e6;
int n;
LL sum[N+2];
void Update(int i,LL val)
{
    while(i <= n)
    {
        sum[i]+=val;
        i+=i & (-i);
    }
}
LL Query(int i)
{
    LL ans=0;
    while(i > 0)
    {
        ans+=sum[i];
        i-=i & (-i);
    }
    return ans;
}
int main()
{
    FAST();
    string s;
    int i,q,l,r,x;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> x;
        Update(i,x);
    }
    cin >> q;
    while(q--)
    {
        cin >> s >> l >> r;
        if(s[1] == 'a')Update(r,l);
        else cout << Query(r)-Query(l-1) << '\n';
    }
    return 0;
}