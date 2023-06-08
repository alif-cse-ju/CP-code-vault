#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
int a[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,q,x,y;
    multiset<int>difs;
    ordered_set<int>points;
    cin >> n >> q;
    for(i=1; i<=n; i++)
    {
        cin >> a[i];
        points.insert(a[i]);
    }
    sort(a+1,a+n+1);
    for(i=2; i<=n; i++)difs.insert(a[i]-a[i-1]);
    cout << *(--points.end())-*(points.begin())-(difs.empty() ? 0 : *(--difs.end())) << '\n';
    while(q--)
    {
        cin >> x >> y;
        if(!x)
        {
            i=points.order_of_key(y);
            if(i)
            {
                x=*(points.find_by_order(i-1));
                difs.erase(difs.find(y-x));
            }
            if(i+1 < n)
            {
                x=*(points.find_by_order(i+1));
                difs.erase(difs.find(x-y));
            }
            if(i  &&  i+1 < n)difs.insert(x-*(points.find_by_order(i-1)));
            --n;
            points.erase(points.find_by_order(i));
        }
        else
        {
            ++n;
            points.insert(y);
            i=points.order_of_key(y);
            if(i)
            {
                x=*(points.find_by_order(i-1));
                difs.insert(y-x);
            }
            if(i+1 < n)
            {
                x=*(points.find_by_order(i+1));
                difs.insert(x-y);
            }
            if(i  &&  i+1 < n)difs.erase(difs.find(x-*(points.find_by_order(i-1))));
        }
        if((int)difs.size() < 2)cout << "0\n";
        else cout << *(--points.end())-*(points.begin())-*(--difs.end()) << '\n';
    }
    return 0;
}