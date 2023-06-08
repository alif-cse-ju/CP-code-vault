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
const int mod=1e9+7;
 int a[M];
struct Data
{
    ll sum;
    int mnIdx,mnVal,mxIdx,mxVal;
} segTree[4*M];
 void Merge(Data& x, Data& y,Data& z)
{
    x.sum=y.sum + z.sum;
     if(y.mnVal <= z.mnVal)x.mnIdx=y.mnIdx, x.mnVal=y.mnVal;
    else x.mnIdx=z.mnIdx, x.mnVal=z.mnVal;
     if(z.mxVal >= y.mxVal)x.mxIdx=z.mxIdx, x.mxVal=z.mxVal;
    else x.mxIdx=y.mxIdx, x.mxVal=y.mxVal;
}
 void Build(int nodeNum,int l,int r)
{
    if(l == r)
    {
        segTree[nodeNum].mnIdx=segTree[nodeNum].mxIdx=l;
        segTree[nodeNum].sum=segTree[nodeNum].mnVal=segTree[nodeNum].mxVal=0;
        return;
    }
    int m=(l+r) >> 1;
    Build(2*nodeNum,l,m), Build(2*nodeNum+1,m+1,r);
    Merge(segTree[nodeNum], segTree[2*nodeNum], segTree[2*nodeNum+1]);
}
 void Update(int nodeNum,int start,int end,int id,int v)
{
    if(start == end)
    {
        segTree[nodeNum].mnIdx=segTree[nodeNum].mxIdx=id;
        segTree[nodeNum].sum=v-id, segTree[nodeNum].mnVal=segTree[nodeNum].mxVal=v;
        return;
    }
    int m=(start+end) >> 1;
    if(id <= m)Update(2*nodeNum,start,m,id,v);
    else Update(2*nodeNum+1,m+1,end,id,v);
    Merge(segTree[nodeNum], segTree[2*nodeNum], segTree[2*nodeNum+1]);
}
 Data Query(int nodeNum,int start,int end,int l,int r)
{
    if(start >= l  &&  end <= r)return segTree[nodeNum];
    int m=(start+end) >> 1;
    if(r <= m)return Query(2*nodeNum,start,m,l,r);
    if(l > m)return Query(2*nodeNum+1,m+1,end,l,r);
    Data x,y,z;
    y=Query(2*nodeNum,start,m,l,r), z=Query(2*nodeNum+1,m+1,end,l,r);
    Merge(x,y,z);
    return x;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int n;cin >> n;
        Build(1,1,n);
        for(int i=1;i<=n;i++)cin >> a[i];
        for(int i=1;i<=n;i++)
        {
            int cur=a[i];
            do
            {
                Data tmp=Query(1,1,n,1,cur);
                if(!tmp.mnVal)
                {
                    Update(1,1,n,tmp.mnIdx,cur);
                    break;
                }
                if(tmp.mxVal > cur)Update(1,1,n,tmp.mxIdx,cur), cur=tmp.mxVal;
                else break;
            }
            while(true);
            cout << Query(1,1,n,1,n).sum << ' ';
        }
        cout << '\n';
    }
    return 0;
}