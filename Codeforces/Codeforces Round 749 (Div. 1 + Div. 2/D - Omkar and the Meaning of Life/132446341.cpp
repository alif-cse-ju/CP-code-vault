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
int ans[102];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cur,i,j,k,n,x;
    cin>> n;
    for(i=cur=n;i;i--)
    {
        if(!ans[i])
        {
            vector<pair<int,int>>v;
            for(j=2; ;j++)
            {
                cout << '?';
                for(k=1;k<=n;k++)
                {
                    if(i == k)cout << ' ' << j;
                    else cout << " 1";
                }
                cout << endl;
                cin >> x;
                if(!x  ||  x == i)
                {
                    ans[i]=cur-j+2, --cur;
                    for(auto [id,d] : v)ans[id]=ans[i]+d, --cur;
                    break;
                }
                else if(ans[x])
                {
                    ans[i]=ans[x]-j+2, --cur;
                    for(auto [id,d] : v)ans[id]=ans[i]+d, --cur;
                    break;
                }
                else v.emplace_back(x,j-1);
                if(j == cur)
                {
                    ans[i]=cur-j+1, --cur;
                    for(auto [id,d] : v)ans[id]=ans[i]+d, --cur;
                    break;
                }
            }
        }
    }
    cout << '!';
    for(i=1;i<=n;i++)cout << ' ' << ans[i];
    cout << endl;
    return 0;
}