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
{
    FAST();
    bool mark[20];
    long long x,a[20],lcm;
    int i,j,k,l,n,t,ans,bal,_and;
    cin >> t;
    while(t--)
    {
        cin >> n >> k >> x;
        for(i=0;i<n;i++)cin >> a[i],mark[i]=0;
        if(k == n)
        {
            cout << n << '\n';
            continue;
        }
        map<long long,int>mp;
        vector<pair<long long,int>>v;
        l=(1 << n);
        for(i=1;i<l;i++)
        {
            lcm=1;
            for(j=0;j<n  &&  lcm <= x;j++)
            {
                if((i >> j) & 1)lcm=(lcm*a[j])/__gcd(lcm,a[j]);
            }
            if(lcm <= x  &&  j == n)mp[lcm] |= i;
        }
        for(auto it : mp)v.emplace_back(it);
        sort(v.begin(),v.end());
        l=(int)v.size();
        for(i=0;i<l;i++)
        {
            if(__builtin_popcount(v[i].second) > k)
            {
                bal=v[i].second;
                for(j=0;j<n;j++)
                {
                    if((bal >> j) & 1)mark[j]=1;
                }
                for(j=i+1;j<l;j++)
                {
                    _and=(bal & v[j].second);
                    if(_and)v[j].second ^= _and;
                }
            }
        }
        ans=0;
        for(i=0;i<n;i++)ans+=(!mark[i]);
        cout << ans << '\n';
    }
    return 0;
}