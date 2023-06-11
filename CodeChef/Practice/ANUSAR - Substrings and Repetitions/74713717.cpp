#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=4e5+5;
const int N=2e6+5;
const int mod=1e9+7;
// len -> largest string length of the corresponding endpos-equivalent class
// link -> longest suffix that is another endpos-equivalent class.
// firstpos -> 1 indexed end position of the first occurrence of the largest string of that node
// minlen(v) -> smallest string of node v = len(link(v)) + 1
// terminal nodes -> store the suffixes
struct SuffixAutomaton
{
    struct node
    {
        int len, link, firstpos, nxt[26];
    };
    int sz, last;
    vector<ll> dp;
    vector<node> st;
    vector<int> terminal;
    vector<vector<int>> g;
    SuffixAutomaton() {}
    SuffixAutomaton(const int& n)
    {
        g.resize(2 * n);
        st.resize(2 * n);
        dp.resize(2 * n, -1);
        terminal.resize(2 * n, 0);
        st[0].link = -1;
        memset(st[0].nxt,0,sizeof(st[0].nxt));
        sz = last = st[0].len = st[0].firstpos = 0;
    }
    void Extend(char c)
    {
        int p = last;
        if(st[p].nxt[c-'a'])
        {
            int q = st[p].nxt[c-'a'];
            if(st[q].len == st[p].len + 1)
            {
                last = q;
                return;
            }
            int clone = ++sz;
            st[clone] = st[q];
            st[clone].len = st[p].len + 1;
            st[q].link = clone;
            last = clone;
            while(p != -1  &&  st[p].nxt[c-'a'] == q)
            {
                st[p].nxt[c-'a'] = clone;
                p = st[p].link;
            }
            return;
        }
        int cur = ++sz;
        st[cur].len = st[last].len + 1;
        st[cur].firstpos = st[cur].len;
        p = last;
        while(p != -1 && !st[p].nxt[c-'a'])
        {
            st[p].nxt[c-'a'] = cur;
            p = st[p].link;
        }
        if(p == -1)st[cur].link = 0;
        else
        {
            int q = st[p].nxt[c-'a'];
            if(st[p].len + 1 == st[q].len)st[cur].link = q;
            else
            {
                int clone = ++sz;
                st[clone] = st[q];
                st[clone].len = st[p].len + 1;
                while(p != -1 && st[p].nxt[c-'a'] == q)
                {
                    st[p].nxt[c-'a'] = clone;
                    p = st[p].link;
                }
                st[q].link = st[cur].link = clone;
            }
        }
        last = cur;
    }
    void BuildTree()
    {
        for(int i = 1; i <= sz; i++) g[st[i].link].emplace_back(i);
    }
    void Build(string &s)
    {
        for(auto x: s)
        {
            Extend(x);
            terminal[last] = 1;
        }
        BuildTree();
    }
    long long Cnt(int i)   //number of times i-th node occurs in the string
    {
        if(dp[i] != -1) return dp[i];
        long long ret = terminal[i];
        for (auto &x: g[i]) ret += Cnt(x);
        return dp[i] = ret;
    }
};
ll ans[M],baperDP[M];
vector<int>revAdj[M];
ll BaperDP(int n)
{
    if(!n)return 1;
    ll &curAns=baperDP[n];
    if(curAns > -1)return curAns;
    curAns=0;
    for(int x : revAdj[n])curAns += BaperDP(x);
    return curAns;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        string s; cin >> s;
        int n = s.size();
        SuffixAutomaton sa(n);
        sa.Build(s);
        for(int i=0;i<=n+n;i++)ans[i]=0, baperDP[i]=-1, revAdj[i].clear();
        for(int i=0;i<=sa.sz;i++)
        {
            for(int j=0;j<26;j++)
            {
                if(sa.st[i].nxt[j])revAdj[sa.st[i].nxt[j]].emplace_back(i);
            }
        }
        for(int i=1;i<=sa.sz;i++)ans[sa.Cnt(i)] += sa.Cnt(i) * BaperDP(i);
        for(int i=sa.sz;i;i--)ans[i] += ans[i+1];
        int q;cin >> q;
        while(q--)
        {
            int x;cin >> x;
            if(x > n)x=n+1;
            cout << ans[x] << '\n';
        }
    }
    return 0;
}
///ANUSAR