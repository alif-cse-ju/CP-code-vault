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

const int M=2e5+5;
const int N=1e6+5;
const int mod=1e9+7;

int Check(const int& x,const int& y)
{
    if(x%3 != y%3)return 1e9;
    return max(x,y);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans,a,b,c,t;
    cin >> t;
    while(t--)
    {
        cin >> a >> b >> c;
        ans=INT_MAX;
        ans=min(ans,Check(b,c));
        ans=min(ans,Check(a,c));
        ans=min(ans,Check(a,b));
        if(ans > 1e8)ans=-1;
        cout << ans << '\n';
    }
    return 0;
}
//1173
