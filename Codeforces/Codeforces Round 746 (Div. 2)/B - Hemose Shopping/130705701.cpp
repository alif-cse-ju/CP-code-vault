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
const int M=1e5+5;
const int N=1e6+5;
const int mod=1e9+7;
int a[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,k,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(i=1;i<=n;i++)cin >> a[i];
        if(k <= n/2)cout << "YES\n";
        else
        {
            deque<int>dq;
            for(i=1;i+k<=n;i++)
            {
                dq.emplace_back(a[i]);
                dq.emplace_back(a[i+k]);
            }
            sort(dq.begin(),dq.end());
            for(i=1;i+k<=n;i++)a[i]=dq.front(),dq.pop_front();
            for(i=n;!dq.empty();i--)a[i]=dq.back(),dq.pop_back();
            for(i=2;i<=n;i++)
            {
                if(a[i] < a[i-1])break;
            }
            if(i <= n)cout << "NO\n";
            else cout << "YES\n";
        }
    }
    return 0;
}