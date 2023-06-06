#include <bits/stdc++.h>
using namespace std;

struct AC {
    static const int K = 26;
    struct node {
        int nxt[K], link, leaf, par; 
        char pch;
        node(int par = -1, char pch = '$') : par(par), pch(pch) {
            fill(begin(nxt), end(nxt), -1);
            leaf = false;
            link = -1;
        }
    };
    vector <node> t;
    vector <vector <int> > ad;
    vector <int> st, en, mp;
    int dt = 0;
    AC() {
        mp = vector <int> (1 << 8, 0);
        for(char ch = 'a'; ch <= 'z'; ++ch) mp[ch] = ch - 'a';
        t.resize(1);
    }
    int add(string str) {
        int ptr = 0;
        for(auto ch: str) {
            if(t[ptr].nxt[mp[ch]] < 0) {
                t[ptr].nxt[mp[ch]] = t.size();
                t.push_back(node(ptr, ch));
            }
            ptr = t[ptr].nxt[mp[ch]];
        }
        t[ptr].leaf = true;
        return ptr;
    }
    int get_link(int v) {
        if(t[v].link == -1) {
            t[v].link = (!v || !t[v].par) ? 0 : go(get_link(t[v].par), t[v].pch);
        }
        return t[v].link;
    }
    int go(int v, char ch) {
        if(t[v].nxt[mp[ch]] < 0) {
            t[v].nxt[mp[ch]] = !v ? 0 : go(get_link(v), ch);
        }
        return t[v].nxt[mp[ch]];
    }
    void dfs(int v, int z) {
        z = z | t[v].leaf;
        t[v].leaf = z;
        for(int u: ad[v]) 
            dfs(u, z);
    }
    void calc() {
        int k = t.size();
        st.resize(k);
        en.resize(k);
        ad.resize(k);
        for(int i = 1; i < k; i++) ad[get_link(i)].push_back(i);
        dfs(0, 0);
    }
 
}ac;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s; cin >> s;
    int n; cin >> n;

    for(int i = 1; i <= n; i++) {
        string t; cin >> t;
        ac.add(t);
    }

    ac.calc();

    int v = 0, ans = 0;

    for(auto ch: s) {
        v = ac.go(v, ch);
        if(v and ac.t[v].leaf) {
            ans++;
            v = 0;
        }
    }

    cout << ans << endl;
}