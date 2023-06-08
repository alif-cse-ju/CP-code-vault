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
const int M=2e5+5;
const int N=1e6+5;
const int mod=998244353;
int a[2025];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i];
        for(i=1;i<=n  &&  a[i]%2 == i%2;i++);
        if(i <= n)cout << "-1\n";
        else
        {
            vector<int>ans;
            for(i=n;i>1;i-=2)
            {
                if(a[i] == i  &&  a[i-1] == i-1)continue;
                for(j=1;j<i;j++)
                {
                    if(a[j] == i)break;
                }
                ans.emplace_back(j);
                reverse(a+1,a+j+1);
                for(j=1;j<i;j++)
                {
                    if(a[j] == i-1)break;
                }
                ans.emplace_back(j-1);
                reverse(a+1,a+j);
                ans.emplace_back(j+1);
                reverse(a+1,a+j+2);
                ans.emplace_back(3);
                swap(a[1],a[3]);
                ans.emplace_back(i);
                reverse(a+1,a+i+1);
            }
            cout << (int)ans.size() << '\n';
            for(int it : ans)cout << it << ' ';
            cout << '\n';
        }
    }
    return 0;
}