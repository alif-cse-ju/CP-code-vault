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

const int sz = 3e3+5;

int a[sz],cnt[sz][sz],k,n;

void PreCal()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=3000;j++)cnt[i][j]=0;
        for(int j=1;j<=k;j++)cnt[i][a[i]/j]=1;
        for(int j=1;j<=3000;j++)cnt[i][j] += cnt[i][j-1];
    }
}

int Check(const int& m)
{
    for(int l=0;l+m<=3000;l++)
    {
        int r=l+m;
        bool pos=1;
        for(int i=1;i<=n  &&  pos;i++)
        {
            if(!l  &&  !cnt[i][r])pos=0;
            else if(l  &&  cnt[i][r] == cnt[i][l-1])pos=0;
        }
        if(pos)
        {
            //cout << l << ' ' << r << '\n';
            return 1;
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(int i=1;i<=n;i++)cin >> a[i];
        PreCal();
        int l=0,r=3000;
        while(l <= r)
        {
            int m=(l+r) >> 1;
            if(Check(m))r=m-1;
            else l=m+1;
        }
        cout << r+1 << '\n';
    }
    return 0;
}
