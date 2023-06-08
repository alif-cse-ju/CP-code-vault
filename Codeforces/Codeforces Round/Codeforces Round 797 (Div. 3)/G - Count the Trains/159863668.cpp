#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
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
int a[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int m,n;cin >> n >> m;
        for(int i=1;i<=n;i++)cin >> a[i];
        ordered_set<tuple<int,int,int>>ost;
        for(int i=1;i<=n;)
        {
            int j;
            for(j=i;j<=n  &&  a[j] >= a[i];j++);
            ost.insert(make_tuple(j-1,i,a[i]));
            i=j;
        }
        while(m--)
        {
            int k,d;cin >> k >> d;
            a[k] -= d;
            int id=ost.order_of_key(make_tuple(k,0,0));
            auto [r,l,v]=*(ost.find_by_order(id));
            if(v <= a[k])
            {
                cout << (int)ost.size() << ' ';
                continue;
            }
            int mxR=r;
            vector<tuple<int,int,int>>vec;
            vec.emplace_back(make_tuple(r,l,v));
            for(int i=id+1;i<(int)ost.size();i++)
            {
                auto [r1,l1,v1]=*(ost.find_by_order(i));
                if(v1 < a[k])break;
                vec.emplace_back(make_tuple(r1,l1,v1));
                mxR=r1;
            }
            while(!vec.empty())ost.erase(ost.find_by_order(ost.order_of_key(vec.back()))), vec.pop_back();
            if(l < k)ost.insert(make_tuple(k-1,l,v));
            ost.insert(make_tuple(mxR,k,a[k]));
            cout << (int)ost.size() << ' ';
        }
        cout << '\n';
    }
    return 0;
}