#include<bits/stdc++.h>
using namespace std;
const int mx = 2e5 + 5;
struct node{
    int l, r, k, id, blk;
}qq[mx];
bool cmp(node a, node b){
    if(a.blk != b.blk)
        return a.l < b.l;
    return a.r < b.r;
}
int vis[mx], cnt[mx], blk;
int n, q, a[mx], b[mx], ans[mx];
inline void add(int x){
    vis[a[x]]++;
    cnt[vis[a[x]]]++;
}
inline void del(int x){
    cnt[vis[a[x]]]--;
    vis[a[x]]--;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc; cin >> tc; while(tc--){
        cin >> n >> q; blk = sqrt(n);
        for(int i=1; i<=n; i++)
            cin >> a[i], b[i] = a[i];
        sort(b+1, b+n+1);
        int m = unique(b+1, b+n+1) - b - 1;
        for(int i=1; i<=n; i++)
            a[i] = lower_bound(b+1, b+m+1, a[i]) - b;
        for(int i=1; i<=q; i++){
            cin >> qq[i].l >> qq[i].r >> qq[i].k;
            qq[i].id = i;
            qq[i].blk = qq[i].l / blk;
        }sort(qq+1, qq+q+1, cmp);
        int l = 1, r = 0;
        for(int i=1; i<=q; i++){
            while(r < qq[i].r) add(++r);
            while(r > qq[i].r) del(r--);
            while(l > qq[i].l) add(--l);
            while(l < qq[i].l) del(l++);
            ans[qq[i].id] = cnt[1] - cnt[qq[i].k+1];
        }
        for(int i=1; i<=q; i++)
            cout << ans[i] << "\n";
        for(int i=1; i<=n; i++)
            vis[i] = cnt[i] = 0;
    }
    return 0;
}