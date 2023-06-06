#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long

template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;

const int sz = 505;

pair<int,int>p[sz];
int a[sz],k,n,pre[sz],suf[sz];

bool Check(const int& v)
{
    int l=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]%v == 0)continue;
        ++l, p[l].first=a[i]%v, p[l].second=v-p[l].first;
    }
    if(!l)return 1;
    pre[0]=suf[l+1]=0;
    sort(p+1,p+l+1);
    for(int i=1;i<=l;i++)pre[i]=pre[i-1]+p[i].first;
    for(int i=l;i;i--)suf[i]=suf[i+1]+p[i].second;
    for(int i=1;i<l  &&  pre[i]<=k;i++)
    {
        if(pre[i] == suf[i+1])return 1;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    int ans=0, sum=0;
    for(int i=1;i<=n;i++)cin >> a[i], sum+=a[i];
    for(int i=1;i*i<=sum;i++)
    {
        if(sum%i == 0)
        {
            if(Check(i))ans=max(ans, i);
            if(Check(sum/i))
            {
                cout << sum/i;
                return 0;
            }
        }
    }
    cout << ans;
    return 0;
}