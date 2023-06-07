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

const int M=4e5+5;
const int N=2e6+5;
const int mod=1e9+7;

char a[M],b[M];
int n,sum[M],updatePos[M];

void Update(int i,int v)
{
    while(i <= n)sum[i]+=v, i+=(i & -i);
}

int Query(int i)
{
    int ans=0;
    while(i)ans+=sum[i], i-=(i & -i);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        cin >> a+1 >> b+1;
        n=strlen(a+1);
        for(int i=1;i<=n;i++)sum[i]=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i] != b[i])Update(i, 1);
        }
        int tt,q;cin >> tt >> q;
        for(int i=1;i<=q;i++)
        {
            if(i > tt  &&  updatePos[i])
            {
                int p=updatePos[i];
                if(a[p] != b[p])Update(p, 1);
            }
            updatePos[i+tt]=0;
            int op;cin >> op;
            if(op == 1)
            {
                int p;cin >> p;
                updatePos[i+tt]=p;
                if(a[p] != b[p])Update(p, -1);
            }
            else if(op == 2)
            {
                int x1,x2,y1,y2;cin >> x1 >> y1 >> x2 >> y2;
                if(a[y1] != b[y1])Update(y1, -1);
                if(a[y2] != b[y2])Update(y2, -1);

                if(x1 == x2)
                {
                    if(x1 == 1)swap(a[y1], a[y2]);
                    else swap(b[y1], b[y2]);
                }
                else
                {
                    if(x1 == 1)swap(a[y1], b[y2]);
                    else swap(a[y2], b[y1]);
                }

                if(a[y1] != b[y1])Update(y1, 1);
                if(a[y2] != b[y2])Update(y2, 1);
            }
            else
            {
                int ans=Query(n);
                if(!ans)cout << "YES\n";
                else cout << "NO\n";
            }
        }
    }
    return 0;
}
///
