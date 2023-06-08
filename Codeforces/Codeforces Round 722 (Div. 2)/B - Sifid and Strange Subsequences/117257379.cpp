#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
#define PI acos(-1)
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,l,n,t,x,y,z;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<int>v;
        for(i=0,y=z=1e9;i<n;i++)
        {
            cin >> x;
            if(x <= 0)v.emplace_back(x);
            else y=min(x,y);
        }
        sort(v.begin(),v.end());
        l=(int)v.size();
        for(i=1;i<l;i++)z=min(z,v[i]-v[i-1]);
        cout << l+(l < n  &&  z >= y) << '\n';
    }
    return 0;
}