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

#define ll long long

const int M=3e5+5;

char s[M];
int a[M],len,segMin[4*M];

void Build(int nodeNum,int l,int r)
{
    if(l == r)
    {
        segMin[nodeNum]=l;
        return;
    }
    int m=(l+r) >> 1;
    Build(2*nodeNum,l,m), Build(2*nodeNum+1,m+1,r);
    if(a[segMin[2*nodeNum]] <= a[segMin[2*nodeNum+1]])segMin[nodeNum]=segMin[2*nodeNum];
    else segMin[nodeNum]=segMin[2*nodeNum+1];
}

int Query(int nodeNum,int start,int end,int l,int r)
{
    if(start >= l  &&  end <= r)return segMin[nodeNum];
    int m=(start+end) >> 1;
    if(r <= m)return Query(2*nodeNum,start,m,l,r);
    if(l > m)return Query(2*nodeNum+1,m+1,end,l,r);
    int id1=Query(2*nodeNum,start,m,l,r), id2=Query(2*nodeNum+1,m+1,end,l,r);
    if(a[id1] <= a[id2])return id1;
    return id2;
}

ll Solve(int l,int r)
{
    if(l > r)return 0;
    int m=Query(1,0,len,l,r);
    return 1ll*a[m]*(1ll*(r-m+1)*(m-l)+r-m)+Solve(l,m-1)+Solve(m+1,r);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        cin >> len >> s+1;
        for(int i=1;i<=len;i++)a[i]=a[i-1]+(s[i] == '(' ? 1 : -1);
        Build(1,0,len);
        ll ans=-Solve(0,len);
        sort(a,a+len+1);
        for(int i=1;i<=len;i++)ans += 1ll*i*a[i];
        cout << ans << '\n';
    }
    return 0;
}
