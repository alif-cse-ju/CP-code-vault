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
const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;
int a[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,l,n,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<int>odd,even;
        for(i=0;i<n;i++)
        {
            cin >> x;
            if(x & 1)odd.emplace_back(x);
            else even.emplace_back(x);
        }
        l=(int)odd.size();
        for(i=1;i<l  &&  odd[i] >= odd[i-1];i++);
        if(i >= l)
        {
            l=(int)even.size();
            for(i=1;i<l  &&  even[i] >= even[i-1];i++);
            if(i >= l)cout << "Yes\n";
            else cout << "No\n";
        }
        else cout << "No\n";
    }
    return 0;
}