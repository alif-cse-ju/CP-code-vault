#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
#define PI acos(-1)
#define ll long long
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=3e5+5;
const int N=2e6+5;
const int mod=1e9+7;
const int sz = 5e3+5;
ll sum[sz];
tuple<int,int,int>a[sz];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin >> n;
    for(int i=1;i<=n;i++)
    {
        int x,y;cin >> x >> y;
        a[i]=make_tuple(y,i,x);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+get<2>(a[i]);
        if(sum[i] > get<0>(a[i]))
        {
            cout << "*";
            exit(0);
        }
    }
    for(int i=1;i<n;i++)
    {
        int id,idReal=INT_MAX;
        ll mn=get<0>(a[i])-sum[i];
        for(int j=i+1;j<=n;j++)
        {
            if(get<1>(a[j]) < get<1>(a[i])  &&  get<2>(a[j]) <= mn)
            {
                if(get<1>(a[j]) < idReal)id=j, idReal=get<1>(a[j]);
            }
            mn=min(mn, get<0>(a[j])-sum[j]);
        }
        if(idReal == INT_MAX)continue;
        for(int j=id;j>i;j--)swap(a[j], a[j-1]);
        for(int j=1;j<=n;j++)sum[j]=sum[j-1]+get<2>(a[j]);
    }
    for(int i=1;i<=n;i++)cout << get<1>(a[i]) << ' ';
    return 0;
}