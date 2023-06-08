#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL)
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=3e5+5;
const int mod=1e9+7;
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key (k) : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
int main()
    FAST();
    int i,n,q,x,y,cnt=1;
    cin >> n >> q;
    set<int>pos[52];
    ordered_set<int>ost;
    for(i=1;i<=n;i++)
    {
        cin >> x;
        ost.insert(i);
        pos[x].insert(i);
    }
    while(q--)
    {
        cin >> x;
        y=*(pos[x].begin());
        cout << ost.order_of_key(y)+1 << ' ';
        ost.erase(y);
        pos[x].erase(y);
        ost.insert(--cnt);
        pos[x].insert(cnt);
    }
    return 0;
}