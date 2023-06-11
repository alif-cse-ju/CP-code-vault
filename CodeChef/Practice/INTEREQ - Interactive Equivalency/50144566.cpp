#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k.
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=1e6+5;
const int mod=998244353;
int a[105];
vector<int>idx;
int Ask(int l,int r,int cur)
{
    int x;
    cout << "? " << r-l+2 << ' ';
    for(int i=l-1;i<r;i++)cout << idx[i] << ' ';
    cout << cur << endl;
    cin >> x;
    return x;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,l,m,n,r,t,q,x;
    a[1]=1;
    cin >> t;
    while(t--)
    {
        cin >> n >> q;
        idx.clear();
        idx.emplace_back(1);
        for(i=2;i<=n;i++)
        {
            l=1,r=(int)idx.size();
            x=Ask(l,r,i);
            if(x == 1)a[i]=++r,idx.emplace_back(i);
            else
            {
                while(l < r)
                {
                    m=(l+r) >> 1;
                    x=Ask(l,m,i);
                    if(x == 2)r=m;
                    else l=m+1;
                }
                a[i]=a[idx[l-1]];
            }
        }
        cout << "!";
        for(i=1;i<=n;i++)cout << ' ' << a[i];
        cout << endl;
        cin >> x;
        if(x == -1)return 0;
    }
    return 0;
}