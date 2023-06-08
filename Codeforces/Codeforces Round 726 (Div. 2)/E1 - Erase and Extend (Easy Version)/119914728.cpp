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
const int N=5e5+5;
const int mod=1e9+7;
char s[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,k,l,pt=1,sz=1;
    string ans,tmp;
    cin >> l >> k >> s+1;
    for(i=2;i<=l;i++)
    {
        if(pt > sz)pt=1;
        if(s[pt] < s[i])break;
        else if(s[pt] > s[i])sz=i,pt=1;
        else ++pt;
    }
    for(i=1;i<=sz;i++)tmp+=s[i];
    while((int)ans.size() < k)ans+=tmp;
    while((int)ans.size() > k)ans.pop_back();
    cout << ans;
    return 0;
}