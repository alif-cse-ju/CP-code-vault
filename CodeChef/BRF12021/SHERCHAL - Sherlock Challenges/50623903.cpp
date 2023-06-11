#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k.
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=1e6+5;
const int mod=998244353;
int Check(const string& s,char c)
{
    int cnt=0;
    for(char it : s)cnt+=it == c;
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int ans,l,t;
    cin >> t;
    while(t--)
    {
        cin >> l >> s;
        ans=INT_MAX;
        ans=min(ans,Check(s,'s'));
        ans=min(ans,Check(s,'h'));
        ans=min(ans,Check(s,'e'));
        ans=min(ans,Check(s,'r'));
        ans=min(ans,Check(s,'l'));
        ans=min(ans,Check(s,'o'));
        ans=min(ans,Check(s,'c'));
        ans=min(ans,Check(s,'k'));
        cout << ans << '\n';
    }
    return 0;
}