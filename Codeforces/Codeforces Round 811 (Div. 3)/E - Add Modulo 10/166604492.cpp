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
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int n;cin >> n;
        vector<int>cnt(20, 0);
        set<int>st;
        for(int i=0;i<n;i++)
        {
            int x;cin >> x;
            if(x & 1)x += x%10;
            ++cnt[x%20], st.insert(x);
        }
        if((cnt[0] == n  ||  cnt[10] == n)  &&  (int)st.size() == 1)cout << "YES\n";
        else if(cnt[2]+cnt[4]+cnt[8]+cnt[16] == n)cout << "YES\n";
        else if(cnt[6]+cnt[12]+cnt[14]+cnt[18] == n)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
