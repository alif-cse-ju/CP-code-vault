#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
int l,pos;
char s[15];
ll a[M],sum[M];
void Create(int i)
{
    if(i > l)
    {
        ll tmp=0;
        for(i=1;i<=l;i++)tmp=tmp*10+s[i]-'0';
        a[++pos]=tmp;
        sum[pos]=sum[pos-1]+a[pos];
        return;
    }
    if(i <= (l+1)/2)
    {
        for(int j=(i == 1);j<10;j++)
        {
            s[i]=(char)('0'+j);
            Create(i+1);
        }
    }
    else
    {
        s[i]=s[l-i+1];
        Create(i+1);
    }
}
void PreCal()
{
    int i;
    for(i=1;i<10;i+=2)l=i,Create(1);
    a[++pos]=1e10+1;
    sum[pos]=sum[pos-1]+a[pos];
}
long long BigMod(long long val,long long pow)
{
    long long res = 1;
    val = val % mod;
    while(pow > 0)
    {
        if(pow & 1)res = (res*val) % mod;
        pow = pow >> 1;
        val = (val*val) % mod;
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int l,r,q;
    PreCal();
    cin >> q;
    while(q--)
    {
        cin >> l >> r;
        cout << BigMod(a[l],sum[r]-sum[l]) << '\n';
    }
    return 0;
}