#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=5e6+5;
const int mod=1e9+7;
int a[M];
deque<int>pos[M];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans,tmp,i,k,n,t,x,y;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(i=1;i<=n;i++)cin >> a[i], pos[a[i]].emplace_back(i);
        a[0]=a[1], a[n+1]=a[n];
        for(ans=0,i=2;i<=n;i++)ans += (a[i] != a[i-1]);
        for(i=1;i<=k;i++)
        {
            tmp=ans;
            while(!pos[i].empty())
            {
                x=pos[i].front(), pos[i].pop_front();
                tmp-=(a[x] != a[x-1]), y=x;
                while(!pos[i].empty()  &&  pos[i].front()-1 == y)y=pos[i].front(), pos[i].pop_front();
                if(a[y+1] != i)--tmp;
                if(y < n  &&  x > 1)tmp += (a[y+1] != a[x-1]);
            }
            cout << tmp << ' ';
        }
        cout << '\n';
    }
    return 0;
}