#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k.
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
int a[M],b[M];
vector<int>ans[2];
int Check(const int& n)
{
    int i;
    for(i=1;i<=n;i++)
    {
        ans[0][i-1]=(a[i]+ans[0][i-1])%n;
        ans[1][i-1]=(a[i]+ans[1][i-1])%n;
    }
    for(i=0;i<n;i++)
    {
        if(ans[0][i] != ans[1][i])return (ans[1][i] < ans[0][i]);
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,mn,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i];
        for(i=1;i<=n;i++)cin >> b[i];
        mn=INT_MAX;
        vector<int>v;
        for(i=1;i<=n;i++)
        {
            if((a[1]+b[i])%n < mn)
            {
                v={i};
                mn=(a[1]+b[i])%n;
            }
            else if((a[1]+b[i])%n == mn)v.emplace_back(i);
        }
        i=-1;
        ans[0].clear();
        ans[1].clear();
        for(int it : v)
        {
            ++i;
            for(j=it;j<=n;j++)ans[i].emplace_back(b[j]);
            for(j=1;j<it;j++)ans[i].emplace_back(b[j]);
        }
        if(!i)
        {
            for(i=1;i<=n;i++)cout << (a[i]+ans[0][i-1])%n << ' ';
        }
        else
        {
            j=Check(n);
            for(int it : ans[j])cout << it << ' ';
        }
        cout << '\n';
    }
    return 0;
}