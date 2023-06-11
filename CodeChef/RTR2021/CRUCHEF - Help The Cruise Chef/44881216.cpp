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
int a,cnt[N];
vector<int>v;
bool Check(int num)
{
    int ans=0;
    for(int it : v)ans+=it/num;
    return ans >= a;
}
int main()
{
    FAST();
    int i,l,m,r,x,ans=0;
    cin >> a;
    while(cin >> x)++cnt[x];
    for(i=1;i<N;i++)
    {
        if(cnt[i])v.emplace_back(cnt[i]);
    }
    l=0,r=N;
    while(l <= r)
    {
        m=(l+r) >> 1;
        if(Check(m))ans=m,l=m+1;
        else r=m-1;
    }
    cout << ans;
    return 0;
}