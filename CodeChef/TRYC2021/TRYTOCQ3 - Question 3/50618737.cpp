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
const int M=1e4+5;
const int N=1e6+5;
const int mod=998244353;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    bool flag;
    int i,l,t,cnt[26],L[26],R[26];
    cin >> t;
    while(t--)
    {
        cin >> l >> s;
        memset(L,0,sizeof(L));
        memset(R,-1,sizeof(R));
        memset(cnt,0,sizeof(cnt));
        for(i=0;i<l;i++)
        {
            ++cnt[s[i]-'A'];
            R[s[i]-'A']=i+1;
            if(!L[s[i]-'A'])L[s[i]-'A']=i+1;
        }
        flag=1;
        for(i=0;i<26;i++)flag &= ((R[i]-L[i]+1) == cnt[i]);
        if(flag)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}