#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k.
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e3+5;
const int N=2e5+5;
const int mod=1e9+7;
bool ache[26];
vector<int>ans;
set<int>adj[30];
vector<string>v[M];
int indeg[30],color[30];
void Check(const string& a,const string& b)
    int i,la=(int)a.size(),lb=(int)b.size();
    for(i=0;i<min(la,lb)  &&  a[i] == b[i];i++);
    if(i < la  &&  i < lb)
    {
        ++indeg[b[i]-'a'];
        adj[a[i]-'a'].insert(b[i]-'a');
    }
    else if(i < la)
    {
        cout << "IMPOSSIBLE";
        exit(0);
    }
}
 bool DFS(int x)
{
    if(color[x])return color[x] == 2;
    color[x]=1;
    bool ok=1;
    for(int y : adj[x])ok &= DFS(y);
    color[x]=2;
    ans.emplace_back(x);
    return ok;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int i,j,k,l,n,p;
    cin >> n >> k;
    for(i=0;i<n;i++)
    {
        cin >> p;
        for(j=0;j<k;j++)cin >> s,v[p].emplace_back(s);
    }
    vector<string>vv;
    for(i=0;i<n;i++)
    {
        for(string s : v[i])
        {
            vv.emplace_back(s);
            for(char c : s)ache[c-'a']=1;
        }
    }
    l=(int)vv.size();
    for(i=1;i<l;i++)Check(vv[i-1],vv[i]);
    for(i=l=0;i<26;i++)
    {
        if(ache[i])
        {
            ++l;
            if(!indeg[i])adj[26].insert(i);
        }
    }
    bool ok=DFS(26);
    if(!ok)cout << "IMPOSSIBLE";
    else
    {
        ans.pop_back();
        reverse(ans.begin(),ans.end());
        if((int)ans.size() != l)cout << "IMPOSSIBLE";
        else for(int it : ans)cout << (char)(it+'a');
    }
    return 0;
}