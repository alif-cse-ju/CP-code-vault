#include<bits/stdc++.h>
using namespace std;     
const int K = 18;
struct node
    long long sum, pref, suff, ans;
        node(const node& l, const node& r)
    {                                                                                          
        sum = l.sum + r.sum;
        pref = max(l.pref, l.sum + r.pref);
        suff = max(r.suff, r.sum + l.suff);
        ans = max(max(l.ans, r.ans), l.suff + r.pref);
    }
    node(int x)
    {
        sum = x;
        pref = suff = ans = max(x, 0);
    }
    node() {};
int a[1 << K];
vector<node> tree[2 << K];  
void build(int v, int l, int r)
    tree[v].resize(r - l);
    if(l == r - 1)
    {
        tree[v][0] = node(a[l]);  
    }
    else
    {
        int m = (l + r) / 2;
        build(v * 2 + 1, l, m);
        build(v * 2 + 2, m, r);
        for(int i = 0; i < m - l; i++)
        {
            tree[v][i] = node(tree[v * 2 + 1][i], tree[v * 2 + 2][i]);
            tree[v][i + (m - l)] = node(tree[v * 2 + 2][i], tree[v * 2 + 1][i]);    
        }
    }
}
 int main()
{            
    int n;
    scanf("%d", &n);
    int m = (1 << n);
    for(int i = 0; i < m; i++)
    {
        scanf("%d", &a[i]);
    }
    build(0, 0, m);
    int q;
    scanf("%d", &q);
    int cur = 0;
    for(int i = 0; i < q; i++)
    {
        int x;
        scanf("%d", &x);
        cur ^= (1 << x);
        printf("%lld\n", tree[0][cur].ans);
    }
}