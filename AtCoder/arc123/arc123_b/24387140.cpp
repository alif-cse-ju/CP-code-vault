#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long

template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,x,ans=0;
    multiset<int>A,B,C;
    cin >> n;
    for(i=0;i<n;i++)cin >> x,A.insert(x);
    for(i=0;i<n;i++)cin >> x,B.insert(x);
    for(i=0;i<n;i++)cin >> x,C.insert(x);
    for(int a : A)
    {
        auto itB=B.upper_bound(a);
        if(itB == B.end())
        {
            cout << ans;
            return 0;
        }
        int b=*(itB);
        auto itC=C.upper_bound(b);
        if(itC == C.end())
        {
            cout << ans;
            return 0;
        }
        ++ans;
        B.erase(itB),C.erase(itC);
    }
    cout << ans;
    return 0;
}
