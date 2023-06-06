#pragma GCC optimize("Ofast")

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

const int M=3e5+5;
const int N=2e6+5;
const int mod=1e9+7;

int a[12][12];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int h1,w1;cin >> h1 >> w1;
    for(int i=0;i<h1;i++)
    {
        for(int j=0;j<w1;j++)cin >> a[i][j];
    }
    vector<int>v;
    int h2,w2;cin >> h2 >> w2;
    for(int i=0;i<h2;i++)
    {
        for(int j=0;j<w2;j++)
        {
            int x;cin >> x;
            v.emplace_back(x);
        }
    }
    int l1=(1 << h1), l2=(1 << w1);
    for(int i=0;i<l1;i++)
    {
        if(h1-__builtin_popcount(i) == h2)
        {
            for(int j=0;j<l2;j++)
            {
                if(w1-__builtin_popcount(j) == w2)
                {
                    int cnt=0;
                    bool ok=1;
                    for(int ii=0;ii<h1  &&  ok;ii++)
                    {
                        if(!((i >> ii) & 1))
                        {
                            for(int jj=0;jj<w1  &&  ok;jj++)
                            {
                                if(!((j >> jj) & 1))
                                {
                                    if(a[ii][jj] == v[cnt])++cnt;
                                    else ok=0;
                                }
                            }
                        }
                    }
                    if(ok)
                    {
                        cout << "Yes";
                        return 0;
                    }
                }
            }
        }
    }
    cout << "No";
    return 0;
}
