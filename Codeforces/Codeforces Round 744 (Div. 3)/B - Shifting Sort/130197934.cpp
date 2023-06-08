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
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,k,n,t,a[55],b[55];
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i],b[i]=a[i];
        sort(b+1,b+n+1);
        vector<pair<int,int>>ans;
        for(i=n;i;i--)
        {
            if(a[i] != b[i])
            {
                for(j=i-1;j  &&  a[j] != b[i];j--);
                ans.emplace_back(j,i);
                for(k=j;k<i;k++)a[k]=a[k+1];
            }
        }
        cout << (int)ans.size() << '\n';
        for(auto [x,y] : ans)cout << x << ' ' << y << " 1\n";
    }
    return 0;
}