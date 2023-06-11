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
const int M=2e5+5;
const int N=5e6+5;
const int mod=998244353;
ll p;
int op(int a, int b)
{
    return (1ll * a * b) % p;
}
inline int log2Up(int n) {
    int res = 0;
    while ((1 << res) < n) {
        res++;
    }
    return res;
}
class SqrtTree {
    private:
        int n, lg;
        vector<int> v;
        vector<int> clz;
        vector<int> layers;
        vector<int> onLayer;
        vector< vector<int> > pref;
        vector< vector<int> > suf;
        vector< vector<int> > between;
        void build(int layer, int lBound, int rBound) {
            if (layer >= (int)layers.size()) {
                return;
            }
            int bSzLog = (layers[layer]+1) >> 1;
            int bCntLog = layers[layer] >> 1;
            int bSz = 1 << bSzLog;
            int bCnt = 0;
            for (int l = lBound; l < rBound; l += bSz) {
                bCnt++;
                int r = min(l + bSz, rBound);
                pref[layer][l] = v[l];
                for (int i = l+1; i < r; i++) {
                    pref[layer][i] = op(pref[layer][i-1], v[i]);
                }
                suf[layer][r-1] = v[r-1];
                for (int i = r-2; i >= l; i--) {
                    suf[layer][i] = op(v[i], suf[layer][i+1]);
                }
                build(layer+1, l, r);
            }
            for (int i = 0; i < bCnt; i++) {
                int ans = 0;
                for (int j = i; j < bCnt; j++) {
                    int add = suf[layer][lBound + (j << bSzLog)];
                    ans = (i == j) ? add : op(ans, add);
                    between[layer][lBound + (i << bCntLog) + j] = ans;
                }
            }
        }
    public:
        inline int query(int l, int r) {
            if (l == r) {
                return v[l];
            }
            if (l + 1 == r) {
                return op(v[l], v[r]);
            }
            int layer = onLayer[clz[l ^ r]];
            int bSzLog = (layers[layer]+1) >> 1;
            int bCntLog = layers[layer] >> 1;
            int lBound = (l >> layers[layer]) << layers[layer];
            int lBlock = ((l - lBound) >> bSzLog) + 1;
            int rBlock = ((r - lBound) >> bSzLog) - 1;
            int ans = suf[layer][l];
            if (lBlock <= rBlock) {
                ans = op(ans, between[layer][lBound + (lBlock << bCntLog) + rBlock]);
            }
            ans = op(ans, pref[layer][r]);
            return ans;
        }
        SqrtTree(const vector<int>& v)
            : n((int)v.size()), lg(log2Up(n)), v(v), clz(1 << lg), onLayer(lg+1) {
            clz[0] = 0;
            for (int i = 1; i < (int)clz.size(); i++) {
                clz[i] = clz[i >> 1] + 1;
            }
            int tlg = lg;
            while (tlg > 1) {
                onLayer[tlg] = (int)layers.size();
                layers.push_back(tlg);
                tlg = (tlg+1) >> 1;
            }
            for (int i = lg-1; i >= 0; i--) {
                onLayer[i] = max(onLayer[i], onLayer[i+1]);
            }
            pref.assign(layers.size(), vector<int>(n));
            suf.assign(layers.size(), vector<int>(n));
            between.assign(layers.size(), vector<int>(1 << lg));
            build(0, 0, n);
        }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        ll n,q;cin >> n >> p >> q;
        vector<int>a(n);
        for(int &x : a)cin >> x;
        vector<int>b((q/64)+2);
        for(int &x : b)cin >> x;
        SqrtTree sqrtTree(a);
        int ans=0,l=0,r=0;
        for(int i=0;i<q;i++)
        {
            if(i%64 == 0)l=(b[i/64]+ans)%n, r=(b[i/64+1]+ans)%n;
            else l=(l+ans)%n, r=(r+ans)%n;
            if(l > r)swap(l, r);
            ans=(sqrtTree.query(l, r) + 1) % p;
        }
        cout << ans << '\n';
    }
    return 0;
}