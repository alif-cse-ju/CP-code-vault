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

const int M=5e5+5;
const int N=2e6+5;
const int mod=998244353;

bool leaf[M];
int Link[M],Next[M][26],numberOfNodes;

void InsertWord(string &s)
{
    int len = (int)s.size(), now = 0;
    for(int i=0; i<len; i++)
    {
        if(!Next[now][s[i]-'a']) Next[now][s[i]-'a'] = ++numberOfNodes;
        now = Next[now][s[i]-'a'];
    }
    leaf[now] = 1;
}

void PushLinks()
{
    Link[0] = -1;
    queue<int> q; q.emplace(0);
    while(!q.empty())
    {
        int u = q.front(); q.pop();
        for(int ch=0;ch<26;ch++)
        {
            int v = Next[u][ch];
            if(!v)continue;
            int j = Link[u];

            while(j != -1 && !Next[j][ch]) j = Link[j];
            if(j != -1) Link[v] = Next[j][ch], leaf[v] |= leaf[Next[j][ch]];
            else Link[v] = 0;

            q.emplace(v);
        }
    }
}

int ans;

void Traverse(string &s)
{
    int len = (int)s.size(), now = 0;
    for(int i = 0; i < len; i++)
    {
        while(now != -1 && !Next[now][s[i]-'a']) now = Link[now];
        if(now != -1)now = Next[now][s[i]-'a'];
        else now = 0;
        if(leaf[now])++ans, now = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;cin >> s;
    int n; cin >> n;
    while(n--)
    {
        string p; cin >> p;
        InsertWord(p);
    }
    PushLinks(), Traverse(s);
    cout << ans;
    return 0;
}