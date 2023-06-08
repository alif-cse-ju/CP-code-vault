#pragma GCC optimize("Ofast")
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
const int M=5e5+5;
const int N=2e6+5;
const int mod=998244353;
const int sz = 105;
int a[sz],aa[sz],b[sz],bb[sz];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int n;cin >> n;
        for(int i=1;i<=n;i++)cin >> a[i], aa[i]=a[i];
        for(int i=1;i<=n;i++)cin >> b[i], bb[i]=b[i];
        sort(aa+1,aa+n+1), sort(bb+1,bb+n+1);
        vector<pair<int,int>>ans;
        for(int i=1;i<n;i++)
        {
            if(a[i] != aa[i])
            {
                int id;
                for(int j=i+1;j<=n;j++)
                {
                    if(a[j] == aa[i]  &&  a[j] != aa[j])
                    {
                        id=j;
                        break;
                    }
                }
                ans.emplace_back(i, id);
                swap(a[i], a[id]), swap(b[i], b[id]);
            }
        }
        for(int i=1;i<=n;)
        {
            int j;
            for(j=i+1;j<=n  &&  a[i] == a[j];j++);
            vector<pair<int,int>>v1,v2;
            for(int k=i;k<j;k++)
            {
                v1.emplace_back(b[k],k);
                v2.emplace_back(b[k],k);
            }
            sort(v2.begin(),v2.end());
            for(int k=0;k<(int)v1.size();k++)
            {
                if(v1[k].first != v2[k].first)
                {
                    for(int kk=k+1;kk<(int)v1.size();kk++)
                    {
                        if(v1[kk].first == v2[k].first)
                        {
                            ans.emplace_back(v1[k].second, v1[kk].second);
                            swap(v1[k], v1[kk]), swap(b[v1[k].second], b[v1[kk].second]), swap(v1[k].second, v1[kk].second);
                            break;
                        }
                    }
                }
            }
            i=j;
        }
        bool ok=1;
        for(int i=2;i<=n;i++)ok &= (a[i] >= a[i-1]), ok &= (b[i] >= b[i-1]);
        if(!ok)cout << "-1\n";
        else
        {
            cout << (int)ans.size() << '\n';
            for(auto [x,y] : ans)cout << x << ' ' << y << '\n';
        }
    }
    return 0;
}