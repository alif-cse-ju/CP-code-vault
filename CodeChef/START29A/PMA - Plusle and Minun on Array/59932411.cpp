#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
#define PI acos(-1)
#define ll long long
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll sum;
    int i,n,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<int>odd,even;
        for(i=1;i<=n;i++)
        {
            cin >> x;
            if(i & 1)odd.emplace_back(abs(x));
            else even.emplace_back(abs(x));
        }
        sort(odd.begin(),odd.end());
        sort(even.begin(),even.end());
        if(odd[0] < even.back())swap(odd[0], even.back());
        sum=0;
        for(int it : odd)sum += it;
        for(int it : even)sum -= it;
        cout << sum << '\n';
    }
    return 0;
}