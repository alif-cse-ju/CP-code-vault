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
const int M=1e3+5;
const int N=1e6+5;
const int mod=1e9+7;
ll ans;
int m,n,dpUpor[M][M],dpBam[M][M],mark[M][M];
void Update(int i,int j)
    if(i > n  ||  j > m)return;
    int bam,upor;
    if(!mark[i][j])bam=dpUpor[i][j-1]+1, upor=dpBam[i-1][j]+1;
    else bam = upor = 0;
    if(dpUpor[i][j] == upor  &&  dpBam[i][j] == bam)return;
    ans += bam-dpBam[i][j] + upor-dpUpor[i][j];
    dpBam[i][j]=bam, dpUpor[i][j]=upor;
    Update(i+1,j), Update(i,j+1);
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,q,tmp;
    cin >> n >> m >> q;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            dpBam[i][j]=dpUpor[i][j-1]+1;
            dpUpor[i][j]=dpBam[i-1][j]+1;
            ans += dpBam[i][j]+dpUpor[i][j];
        }
    }
    tmp=m*n;
    while(q--)
    {
        cin >> i >> j;
        mark[i][j]=1-mark[i][j];
        if(mark[i][j])--tmp;
        else ++tmp;
        Update(i,j);
        cout << ans-tmp << '\n';
    }
    return 0;
}