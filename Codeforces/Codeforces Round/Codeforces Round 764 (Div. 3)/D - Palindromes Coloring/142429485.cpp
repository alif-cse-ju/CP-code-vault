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
const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int ans,k,l,odd,t;
    cin >> t;
    while(t--)
    {
        ans=odd=0;
        cin >> l >> k >> s;
        vector<int>cnt(26, 0);
        for(char &c : s)++cnt[c-'a'];
        for(int it : cnt)ans += it/2, odd += it%2;
        odd += 2*(ans%k), ans /= k, ans *= 2;
        if(odd >= k)++ans;
        cout << ans << '\n';
    }
    return 0;
}