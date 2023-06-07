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

const int M=2e5+5;

int a[M],cnt[M],xr[M],pre[M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;cin >> n >> q;
    map<int,int>mp[2];
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        cnt[i]=cnt[i-1]+(a[i]>0), xr[i]=(xr[i-1]^a[i]), mp[i&1][xr[i]]=i;
        if(mp[1-(i&1)].find(xr[i]) != mp[1-(i&1)].end())pre[i]=mp[1-(i&1)][xr[i]];
    }
    while(q--)
    {
        int l,r;cin >> l >> r;
        if(xr[r]^xr[l-1])cout << "-1\n";
        else if(cnt[r] == cnt[l-1])cout << "0\n";
        else if((r-l+1) & 1)cout << "1\n";
        else
        {
            if(!a[l]  ||  !a[r])cout << "1\n";
            else if(pre[r] >= l)cout << "2\n";
            else cout << "-1\n";
        }
    }
    return 0;
}
