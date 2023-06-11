#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;
int a[M],k;
bool Check(const int& n)
{
    int cur=0,i,kk=k,need;
    for(i=n;i;i--)
    {
        need=(cur+a[i])%10;
        if(!need)continue;
        need=10-need;
        if(need > kk)return 0;
        kk-=need, cur+=need;
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int i,l,m,n,r,t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k >> s;
        for(i=0;i<n;i++)a[i+1]=s[i]-'0';
        l=0, r=n;
        while(l <= r)
        {
            m=(l+r) >> 1;
            if(Check(m))l=m+1;
            else r=m-1;
        }
        cout << l-1 << '\n';
    }
    return 0;
}