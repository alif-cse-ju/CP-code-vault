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
const int N=1e6+5;
const int mod=1e9+7;
int n;
set<int>st[6];
bool Check(int& x,int& y)
    set<int>dhon;
    for(int it : st[x])dhon.insert(it);
    for(int it : st[y])dhon.insert(it);
    return (int)dhon.size() == n;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool ok;
    int i,j,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<6;i++)st[i].clear();
        for(i=1;i<=n;i++)
        {
            for(j=1;j<6;j++)
            {
                cin >> x;
                if(x)st[j].insert(i);
            }
        }
        ok=0;
        for(i=1;i<5 && !ok;i++)
        {
            if((int)st[i].size() < n/2)continue;
            for(j=i+1;j<6;j++)
            {
                if((int)st[j].size() >= n/2)
                {
                    if(Check(i,j))
                    {
                        ok=1;
                        cout << "YES\n";
                        break;
                    }
                }
            }
        }
        if(!ok)cout << "NO\n";
    }
    return 0;
}