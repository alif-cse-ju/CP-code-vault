#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5 +5;
const ll mod = 1e9+7;
typedef pair<int,int> pii;
int a[N];
int cnt[N];
int cntcnt[N];
int p1 = 0;
struct query
    int l,r,idx;
int block;
bool comp1(query p,query q)
    if (p.l / block != q.l / block)
    {
        if(p.l==q.l)
            return p.r<q.r;
        return p.l < q.l;
    }
    return (p.l / block & 1) ? (p.r < q.r) : (p.r > q.r);
void Remove(int idx)
    int val = a[idx];
    cntcnt[ cnt[val] ]--;
    cnt[val]--;
    if(cnt[val])
    {
        cntcnt[ cnt[val] ]++;
    }
    while(cntcnt[p1]==0)
    {
        if(p1==0)
            break;
        p1--;
    }
 }
void add(int idx)
{
    int val = a[idx];
    if(cnt[val])
    {
        cntcnt[ cnt[val] ]--;
    }
    cnt[val]++;
    cntcnt[ cnt[val] ]++;
    p1 = max(p1, cnt[val] );
}
int get_answer(int l, int r)
{
    int len = r-l+1;
    int maxi = p1;
    int baki = len - maxi;
    if(baki  + 1 >=maxi)
    {
        return 1;
    }
    return (maxi - (baki+1)) + 1;
}
 void mos_algorithm(int n, vector<query>&queries)
{
    vector<int> answers(queries.size());
    block = (int)sqrt(n);
    sort(queries.begin(), queries.end(),comp1);
    int cur_l = 0;
    int cur_r = -1;
    for (query q : queries)
    {
        while (cur_l > q.l)
        {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r)
        {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l)
        {
            Remove(cur_l);
            cur_l++;
        }
        while (cur_r > q.r)
        {
            Remove(cur_r);
            cur_r--;
        }
        answers[q.idx] = get_answer(q.l, q.r);
    }
    for(int i:answers)
    {
        cout<<i<<"\n";
    }
}
 int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q;
    cin>>n>>q;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    vector<query>qq(q);
    for(int i=0; i<q; i++)
    {
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        query x;
        x.l = l;
        x.r = r;
        x.idx = i;
        qq[i] = x;
    }
    mos_algorithm(n,qq);
     return 0;
}
 