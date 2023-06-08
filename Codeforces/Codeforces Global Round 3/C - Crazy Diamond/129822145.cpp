#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k.
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=3e5+5;
const int N=4e6+5;
const int mod=1e9+7;
int a[M],pos[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,p;
    cin >> n;
    for(i=1;i<=n;i++)cin >> a[i],pos[a[i]]=i;
    vector<pair<int,int>>ans;
    for(i=1;i<=n;i++)
    {
        if(a[i] == i)continue;
        else if(abs(i-pos[i])*2 >= n)
        {
            ans.emplace_back(i,pos[i]);
        }
        else if(i > n/2)
        {
            ans.emplace_back(1,i);
            ans.emplace_back(1,pos[i]);
            ans.emplace_back(1,i);
        }
        else if(n/2 <= n-pos[i])
        {
            ans.emplace_back(i,n);
            ans.emplace_back(pos[i],n);
            ans.emplace_back(i,n);
        }
        else
        {
            ans.emplace_back(i,n);
            ans.emplace_back(1,n);
            ans.emplace_back(1,pos[i]);
            ans.emplace_back(1,n);
            ans.emplace_back(i,n);
        }
        p=pos[i],a[p]=a[i],pos[a[i]]=p;
    }
    cout << (int)ans.size() << '\n';
    for(auto [x,y] : ans)cout << x << ' ' << y << '\n';
    return 0;
}