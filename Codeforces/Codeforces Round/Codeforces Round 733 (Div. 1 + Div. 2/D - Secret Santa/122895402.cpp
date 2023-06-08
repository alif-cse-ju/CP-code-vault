#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
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
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
bool mark[N];
int a[N],b[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,l,n,t,ans;
    cin >> t;
    while(t--)
    {
        ans=0;
        cin >> n;
        set<int>st;
        for(i=1;i<=n;i++)
        {
            cin >> a[i];
            st.insert(i);
            b[i]=mark[i]=0;
        }
        for(i=1;i<=n;i++)
        {
            if(!mark[a[i]])
            {
                b[i]=a[i];
                mark[a[i]]=1;
                st.erase(a[i]);
            }
        }
        for(i=1;i<=n;i++)
        {
            if(!b[i])
            {
                b[i]=*(st.begin());
                st.erase(st.begin());
            }
        }
        vector<int>v;
        for(i=1;i<=n;i++)
        {
            if(i == b[i])v.emplace_back(i);
        }
        l=(int)v.size();
        for(i=1;i<l;i+=2)swap(b[v[i-1]],b[v[i]]);
        if(l & 1)
        {
            if(l > 1)swap(b[v[0]],b[v.back()]);
            else
            {
                for(i=1;i<=n;i++)
                {
                    if(a[v[0]] == b[i])
                    {
                        swap(b[i],b[v[0]]);
                        break;
                    }
                }
            }
        }
        for(i=1;i<=n;i++)ans+=(a[i] == b[i]);
        cout << ans << '\n';
        for(i=1;i<=n;i++)cout << b[i] << ' ';
        cout << '\n';
    }
    return 0;
}