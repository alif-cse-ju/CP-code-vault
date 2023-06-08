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
const int M=2e5+5;
const int N=1e6+5;
const int mod=1e9+7;
char s[M];
int a[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool ok;
    int i,lb,lr,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i];
        cin >> s+1;
        vector<int>red,blue;
        for(i=1;i<=n;i++)
        {
            if(s[i] == 'B')blue.emplace_back(a[i]);
            else red.emplace_back(a[i]);
        }
        sort(blue.begin(),blue.end());
        sort(red.begin(),red.end());
        ok=1, lb=(int)blue.size(), lr=(int)red.size();
        for(i=0;i<lb;i++)ok &= (blue[i] >= (i+1));
        for(i=0;i<lr;i++)ok &= (red[i] <= (lb+i+1));
        if(ok)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}