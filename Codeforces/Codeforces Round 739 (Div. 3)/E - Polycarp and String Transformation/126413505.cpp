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
string init,rmv;
bool Solve()
    string s;
    cin >> s;
    rmv="";
    bool mark[26]={0};
    vector<int>pos[26];
    int l=(int)s.size();
    for(int i=l-1;i>=0;i--)
    {
        if(!mark[s[i]-'a'])rmv+=s[i];
        mark[s[i]-'a']=1;
        pos[s[i]-'a'].emplace_back(i);
    }
    reverse(rmv.begin(),rmv.end());
    int lrmv=(int)rmv.size(),linit=0;
    for(int i=0;i<lrmv;i++)
    {
        if((int)pos[rmv[i]-'a'].size()%(i+1))return 0;
        linit+=(int)pos[rmv[i]-'a'].size()/(i+1);
    }
    init="";
    set<pair<int,char>>st;
    int cnt[26]={0};
    for(int i=0;i<linit;i++)
    {
        init+=s[i];
        ++cnt[s[i]-'a'];
        st.insert({i,s[i]});
    }
    for(int i=0;i<lrmv;i++)
    {
        if((int)pos[rmv[i]-'a'].size()/(i+1) != cnt[rmv[i]-'a'])return 0;
        pos[rmv[i]-'a'].clear();
    }
    for(int i=0;i<linit;i++)pos[s[i]-'a'].emplace_back(i);
    string dhon="";
    for(char c : rmv)
    {
        for(auto [i,cc] : st)dhon+=cc;
        for(int i : pos[c-'a'])st.erase({i,c});
    }
    return (dhon == s);
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        if(Solve())cout << init << ' ' << rmv << '\n';
        else cout << "-1\n";
    }
    return 0;
}