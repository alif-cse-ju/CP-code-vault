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
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int n;cin >> n;
        map<int,vector<int>>mp;
        for(int i=1;i<=n;i++)
        {
            int x;cin >> x;
            mp[x].emplace_back(i);
        }
        int A,L,R,mx=0;
        for(auto [x,v] : mp)
        {
            vector<int>vv;
            vv.emplace_back(1);
            int l=(int)v.size();
            for(int i=1;i<l;i++)vv.emplace_back(vv[i-1]-(v[i]-v[i-1])+2);
            ordered_set<pair<int,int>>ost;
            if(!mx)mx=1, A=x, L=R=v.back();
            ost.insert({vv.back(),v.back()}), v.pop_back(), vv.pop_back();
            while(!v.empty())
            {
                auto [val,i]=*(--ost.end());
                if(val > vv.back()  &&  val-vv.back()+1 > mx)mx=val-vv.back()+1, A=x, L=v.back(), R=i;
                ost.insert({vv.back(),v.back()}), v.pop_back(), vv.pop_back();
            }
        }
        cout << A << ' ' << L << ' ' << R << '\n';
    }
    return 0;
}