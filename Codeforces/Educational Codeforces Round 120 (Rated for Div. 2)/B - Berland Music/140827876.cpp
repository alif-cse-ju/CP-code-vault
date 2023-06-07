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
char s[M];
int a[M],ans[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,m,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i];
        cin >> s+1;
        vector<pair<int,int>>taken,notTaken;
        for(i=1;i<=n;i++)
        {
            if(s[i] == '1')taken.emplace_back(a[i],i);
            else notTaken.emplace_back(a[i],i);
        }
        sort(taken.begin(),taken.end());
        sort(notTaken.begin(),notTaken.end());
        m=n;
        while(!taken.empty())ans[taken.back().second]=m--, taken.pop_back();
        while(!notTaken.empty())ans[notTaken.back().second]=m--, notTaken.pop_back();
        for(i=1;i<=n;i++)cout << ans[i] << ' ';
        cout << '\n';
    }
    return 0;
}