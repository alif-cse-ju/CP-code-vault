#pragma GCC optimize("Ofast")

#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <chrono>
#include <random>
#include <vector>
#include <climits>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

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
const int N=2e6+5;
const int mod=1e9+7;

const int mx = 5e5+5;

struct SuffixAutomata
{
    int last, sz;
    ll occur[mx+mx];
    struct node
    {
        int len,link,next[26];
    } aut[mx+mx];
    void init(int n)//must call before insert
    {
        for(int i=0;i<=n+n;i++) memset(aut[i].next,0,sizeof(aut[i].next));
        last=sz=0, aut[0].link=-1;
    }
    int Con(char c)
    {
        return c-'a';
    }
    void Insert(int c, const int& v)
    {
        int now=++sz;
        aut[now].len=aut[last].len+1;
        occur[now]=v;
        int p,q,cl;
        for(p=last; p!=-1&&!aut[p].next[c]; p=aut[p].link)aut[p].next[c]=now;
        if(p==-1)aut[now].link=0;
        else
        {
            q=aut[p].next[c];
            if(aut[p].len+1==aut[q].len)aut[now].link=q;
            else
            {
                cl=++sz;
                aut[cl].len=aut[p].len+1;
                aut[cl].link=aut[q].link;
                memcpy(aut[cl].next,aut[q].next,sizeof(aut[cl].next));
                for( ; p!=-1&&aut[p].next[c]==q; p=aut[p].link)aut[p].next[c]=cl;
                aut[now].link=aut[q].link=cl;
            }
        }
        last=now;
    }
    void Insert(string& s, const int& v)
    {
        for(char x:s)Insert(Con(x), v);
    }
    vector<int>_tree[mx+mx];
    void makeTree()
    {
        for(int i=1;i<=sz;i++) _tree[aut[i].link].emplace_back(i);
    }
    void dfs(int nd)
    {
        for(auto x:_tree[nd]) dfs(x), occur[nd]+=occur[x];
    }
} sam;

string s[M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin >> n;
    sam.init(5e5);
    for(int i=1;i<=n;i++)cin >> s[i];
    for(int i=1;i<=n;i++)
    {
        int c;cin >> c;
        sam.Insert(s[i], c), sam.last=0;
    }
    sam.makeTree(), sam.dfs(0);
    ll ans=0;
    for(int i=1;i<=sam.sz;i++)
    {
        if(sam.aut[sam.aut[i].link].len < sam.aut[i].len)ans=max(ans, 1ll*sam.occur[i]*sam.aut[i].len);
    }
    cout << ans;
    return 0;
}
