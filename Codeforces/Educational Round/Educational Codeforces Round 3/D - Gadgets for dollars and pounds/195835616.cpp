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
const int M=3e5+5;
const int N=2e6+5;
const int mod=1e9+7;
 ll dol[M],pou[M],pDol[N],pPou[N],qDol[M],qPou[M],iDol[M],iPou[M];
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    dol[0]=pou[0]=1e13;
     int k,m,n; ll s;cin >> n >> m >> k >> s;
    for(int i=1;i<=n;i++)
    {
        cin >> dol[i];
        if(dol[i] < dol[i-1])pDol[dol[i]]=i;
        else dol[i]=dol[i-1];
    }
    for(int i=1;i<=n;i++)
    {
        cin >> pou[i];
        if(pou[i] < pou[i-1])pPou[pou[i]]=i;
        else pou[i]=pou[i-1];
    }
     vector<pair<ll,int>>vDol, vPou;
    for(int i=1;i<=m;i++)
    {
        int t,c;cin >> t >> c;
        if(t == 1)vDol.emplace_back(c,i);
        else vPou.emplace_back(c,i);
    }
    sort(vDol.begin(), vDol.end()), sort(vPou.begin(), vPou.end());
     int cDol=0, cPou=0;
    for(auto [v,i] : vDol)qDol[++cDol]=v, iDol[cDol]=i;
    for(auto [v,i] : vPou)qPou[++cPou]=v, iPou[cPou]=i;
     int l=1,r=n;
    while(l <= r)
    {
        int m=(l+r) >> 1;
        ll lagbe=0;
        int cnt=0, D=1, P=1;
        while(cnt < k)
        {
            ++cnt;
            if(P > cPou  ||  (D <= cDol  &&  qDol[D]*dol[m] <= qPou[P]*pou[m]))lagbe+=qDol[D]*dol[m], ++D;
            else lagbe+=qPou[P]*pou[m], ++P;
        }
        if(lagbe <= s)r=m-1;
        else l=m+1;
    }
    int ans=r+1;
    if(ans > n)cout << "-1";
    else
    {
        cout << ans << '\n';
        int cnt=0, D=1, P=1;
        while(cnt < k)
        {
            ++cnt;
            if(P > cPou  ||  (D <= cDol  &&  qDol[D]*dol[ans] <= qPou[P]*pou[ans]))cout << iDol[D] << ' ' << pDol[dol[ans]] << '\n', ++D;
            else cout << iPou[P] << ' ' << pPou[pou[ans]] << '\n', ++P;
        }
    }
    return 0;
}