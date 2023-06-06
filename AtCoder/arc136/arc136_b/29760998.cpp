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
const int mod=998244353;

const int sz = 5e3+5;

int a[sz],b[sz],cntA[sz],cntB[sz];

void Update(int i,bool b)
{
    while(i < sz)
    {
        if(b)cntB[i]++;
        else cntA[i]++;
        i += (i & -i);
    }
}

int Query(int i,bool b)
{
    int ans=0;
    while(i)
    {
        if(b)ans += cntB[i];
        else ans += cntA[i];
        i -= (i & -i);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int dist=0,i,invA=0,invB=0,n;
    cin >> n;
    for(i=0;i<n;i++)cin >> a[i], ++cntA[a[i]];
    for(i=0;i<n;i++)cin >> b[i], ++cntB[b[i]];
    for(i=1;i<sz;i++)
    {
        if(cntA[i] != cntB[i])
        {
            cout << "No";
            return 0;
        }
        if(cntA[i])++dist;
    }
    if(dist < n)cout << "Yes";
    else
    {
        for(i=1;i<sz;i++)cntA[i]=cntB[i]=0;
        for(i=0;i<n;i++)invA += Query(a[i]-1, 0), Update(a[i], 0);
        for(i=0;i<n;i++)invB += Query(b[i]-1, 1), Update(b[i], 1);
        if(invA%2 == invB%2)cout << "Yes";
        else cout << "No";
    }
    return 0;
}