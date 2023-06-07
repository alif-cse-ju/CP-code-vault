#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=1e6+5;
const int mod=998244353;
struct SuffixAutomaton
    struct node
    {
        int len, link, firstpos;
        map<char, int> nxt;
    };
    int sz, last;
    vector<node> st;
    SuffixAutomaton() {}
    SuffixAutomaton(int n)
    {
        st.resize(2 * n);
        st[0].link = -1;
        sz = last = st[0].len = st[0].firstpos = 0;
    }
    void Extend(char c)
    {
        int p = last;
        if(st[p].nxt.count(c))
        {
            int q = st[p].nxt[c];
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
            while(p != -1  &&  st[p].nxt[c] == q)
            {
                st[p].nxt[c] = clone;
                p = st[p].link;
            }
            return;
        }
        int cur = ++sz;
        st[cur].len = st[last].len + 1;
        st[cur].firstpos = st[cur].len;
        p = last;
        while(p != -1 && !st[p].nxt.count(c))
        {
            st[p].nxt[c] = cur;
            p = st[p].link;
        }
        if(p == -1)st[cur].link = 0;
        else
        {
            int q = st[p].nxt[c];
            if(st[p].len + 1 == st[q].len)st[cur].link = q;
            else
            {
                int clone = ++sz;
                st[clone] = st[q];
                st[clone].len = st[p].len + 1;
                while(p != -1 && st[p].nxt[c] == q)
                {
                    st[p].nxt[c] = clone;
                    p = st[p].link;
                }
                st[q].link = st[cur].link = clone;
            }
        }
        last = cur;
    }
    void Build(string &s)
    {
        for(auto x: s)Extend(x);
    }
};
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int cnt,cur,q;
    cin >> s;
    int n = s.size();
    SuffixAutomaton sa(n);
    sa.Build(s);
    cin >> q;
    while(q--)
    {
        cin >> s;
        cur=0,cnt=1;
        for(char c : s)
        {
            if(sa.st[cur].nxt[c])cur=sa.st[cur].nxt[c];
            else
            {
                ++cnt;
                if(sa.st[0].nxt[c])cur=sa.st[0].nxt[c];
                else
                {
                    cnt=-1;
                    break;
                }
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}