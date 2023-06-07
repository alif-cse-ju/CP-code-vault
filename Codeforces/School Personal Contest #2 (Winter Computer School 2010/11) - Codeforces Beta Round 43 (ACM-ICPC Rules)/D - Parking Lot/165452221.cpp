#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long

template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;

tuple<int,int,int>cars[105];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int b,f,l,m=0,n;cin >> l >> b >> f >> n;
    cars[++m]=make_tuple(-b,-b,0), cars[++m]=make_tuple(l+f,l+f,0);
    for(int id=1;id<=n;id++)
    {
        int t,len;cin >> t >> len;
        if(t == 1)
        {
            bool ok=0;
            for(int i=2;i<=m;i++)
            {
                if(get<1>(cars[i-1])+b+f+len <= get<0>(cars[i]))
                {
                    ok=1;
                    for(int j=m;j>=i;j--)cars[j+1]=cars[j];
                    cars[i]=make_tuple(get<1>(cars[i-1])+b, get<1>(cars[i-1])+b+len, id);
                    cout << get<1>(cars[i-1])+b << '\n', ok=1, ++m;
                    break;
                }
            }
            if(!ok)cout << "-1\n";
        }
        else
        {
            for(int i=1;i<=m;i++)
            {
                if(get<2>(cars[i]) == len)
                {
                    for(int j=i;j<m;j++)cars[j]=cars[j+1];
                    --m;
                    break;
                }
            }
        }
    }
    return 0;
}