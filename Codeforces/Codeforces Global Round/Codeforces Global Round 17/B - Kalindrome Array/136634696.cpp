#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
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
const int M=2e5+5;
const int N=1e6+5;
const int mod=998244353;
int a[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool ok;
    int i,l,n,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i];
        ok=1;
        for(i=1;i<=n;i++)ok &= (a[i] == a[n-i+1]);
        if(ok)cout << "YES\n";
        else
        {
            deque<int>dq,dq2,dq3;
            for(i=1;i<=n;i++)dq.emplace_back(a[i]);
            while((int)dq.size() > 1  &&  dq.front() == dq.back())dq.pop_front(), dq.pop_back();
            if(dq.empty()  ||  (int)dq.size() == 1)ok=1;
            else
            {
                x=dq.back();
                l=(int)dq.size();
                for(i=0;i<l;i++)
                {
                    if(dq[i] != x)dq2.emplace_back(dq[i]);
                }
                ok=1,l=(int)dq2.size();
                for(i=0;i<l;i++)
                {
                    if(dq2[i] != dq2[l-i-1])
                    {
                        ok=0;
                        break;
                    }
                }
                if(!ok)
                {
                    x=dq.front();
                    l=(int)dq.size();
                    for(i=0;i<l;i++)
                    {
                        if(dq[i] != x)dq3.emplace_back(dq[i]);
                    }
                    ok=1,l=(int)dq3.size();
                    for(i=0;i<l;i++)
                    {
                        if(dq3[i] != dq3[l-i-1])
                        {
                            ok=0;
                            break;
                        }
                    }
                }
            }
            if(ok)cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}