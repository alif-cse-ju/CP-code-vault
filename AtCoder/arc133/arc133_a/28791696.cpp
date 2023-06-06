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

int a[M],b[M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,x;
    cin >> n;
    for(i=1;i<=n;i++)cin >> a[i], b[i]=a[i];
    sort(b+1,b+n+1);
    if(b[1] == b[n])return 0;
    for(i=1;i<=n  &&  a[i] == b[i];i++);
    if(i > n)
    {
        for(i=1;i<=n  &&  a[i] != a[n];i++)cout << a[i] << ' ';
    }
    else
    {
        for(i=2;i<=n;i++)
        {
            if(a[i] < a[i-1])
            {
                x=a[i-1];
                break;
            }
        }
        for(i=1;i<=n;i++)
        {
            if(a[i] != x)cout << a[i] << ' ';
        }
    }
    return 0;
}