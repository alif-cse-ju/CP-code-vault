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

const int M=1e5+5;
const int N=1e6+5;
const int mod=1e9+7;

int a[M],cnt[M];

///Prefix Part

int preDP[M],preMaxLen[M];

void UpdatePre(int i,int v)
{
    while(i < M)preMaxLen[i]=max(preMaxLen[i], v), i+=(i & -i);
}

int QueryPre(int i)
{
    int ans=0;
    while(i)ans=max(ans, preMaxLen[i]), i-=(i & -i);
    return ans;
}

///Prefix Part

///Suffix Part

int sufDP[M],sufMaxLen[M];

void UpdateSuf(int i,int v)
{
    while(i)sufMaxLen[i]=max(sufMaxLen[i], v), i-=(i & -i);
}

int QuerySuf(int i)
{
    int ans=0;
    while(i < M)ans=max(ans, sufMaxLen[i]), i+=(i & -i);
    return ans;
}

///Suffix Part

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin >> n;
    for(int i=1;i<=n;i++)cin >> a[i];

    for(int i=1;i<=n;i++)
    {
        int l=QueryPre(a[i]-1);
        preDP[i]=l+1, UpdatePre(a[i], preDP[i]);
    }

    for(int i=n;i;i--)
    {
        int l=QuerySuf(a[i]+1);
        sufDP[i]=l+1, UpdateSuf(a[i], sufDP[i]);
    }

    int lis=0;
    for(int i=1;i<=n;i++)lis=max(lis, preDP[i]);

    map<pair<int,int>,int>cnt;
    for(int i=1;i<=n;i++)++cnt[{preDP[i], sufDP[i]}];

    for(int i=1;i<=n;i++)
    {
        if(preDP[i]+sufDP[i] != lis+1)cout << '1';
        else
        {
            if(cnt[{preDP[i], sufDP[i]}] == 1)cout << '3';
            else cout << '2';
        }
    }
    return 0;
}