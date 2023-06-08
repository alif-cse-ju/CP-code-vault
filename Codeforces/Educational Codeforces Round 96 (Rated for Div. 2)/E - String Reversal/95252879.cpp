#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
 using namespace std;
using namespace __gnu_pbds;
 const int N=2e5+5;
char s[N];
int ans[N];
vector<int>pos[30];
 template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,l;
    long long cnt=0;
    cin >> l >> s+1;
    for(i=1;i<=l;i++)pos[s[i]-'a'].emplace_back(i);
    for(i=l;i>0;i--)
    {
        ans[i]=pos[s[l-i+1]-'a'].back();
        pos[s[l-i+1]-'a'].pop_back();
    }
    ordered_set<int>ost;
    for(i=1;i<=l;i++)
    {
        auto it=ost.order_of_key(ans[i]);
        cnt+=(int)ost.size()-it;
        ost.insert(ans[i]);
    }
    cout << cnt;
    return 0;
}