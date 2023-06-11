#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
#define PI acos(-1)
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e6+5;
const int mod=1e9+7;
bool mark[N];
int cnt[N],_xr[N];
void Sieve()
{
    int i,j;
    cnt[2]=1;
    for(i=3;i<N;i+=2)
    {
        if(!mark[i])
        {
            cnt[i]=1;
            if(i < 2e3)
            {
                for(j=i*i;j<N;j+=2*i)mark[j]=1;
            }
        }
    }
    for(i=1;i<N;i++)cnt[i]+=cnt[i-1],_xr[i]=_xr[i-1] ^ i;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Sieve();
    int l,m,n,r,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        l=1,r=N-5;
        while(l <= r)
        {
            m=(l+r) >> 1;
            if(cnt[m] >= n)r=m-1;
            else l=m+1;
        }
        cout << _xr[r+1] << '\n';
    }
    return 0;
}