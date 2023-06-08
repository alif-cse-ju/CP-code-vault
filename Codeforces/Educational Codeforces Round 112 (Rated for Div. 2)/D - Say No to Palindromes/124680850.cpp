#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k.
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
char s[N];
int cnt[N][4][3];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a1,a2,a3,ans,b1,b2,b3,c1,c2,c3,i,j,k,l,q,r;
    cin >> l >> q >> s+1;
    for(i=1;i<=l;i+=3)cnt[i][1][s[i]-'a']=1;
    for(i=2;i<=l;i+=3)cnt[i][2][s[i]-'a']=1;
    for(i=3;i<=l;i+=3)cnt[i][3][s[i]-'a']=1;
    for(i=2;i<=l;i++)
    {
        for(j=1;j<4;j++)
        {
            for(k=0;k<3;k++)cnt[i][j][k]+=cnt[i-1][j][k];
        }
    }
    while(q--)
    {
        cin >> l >> r;
        a1=cnt[r][1][0]-cnt[l-1][1][0];
        a2=cnt[r][2][0]-cnt[l-1][2][0];
        a3=cnt[r][3][0]-cnt[l-1][3][0];
         b1=cnt[r][1][1]-cnt[l-1][1][1];
        b2=cnt[r][2][1]-cnt[l-1][2][1];
        b3=cnt[r][3][1]-cnt[l-1][3][1];
         c1=cnt[r][1][2]-cnt[l-1][1][2];
        c2=cnt[r][2][2]-cnt[l-1][2][2];
        c3=cnt[r][3][2]-cnt[l-1][3][2];
         ans=INT_MAX,l=r-l+1;
        ans=min(ans,l-a1-b2-c3);
        ans=min(ans,l-a1-b3-c2);
        ans=min(ans,l-a2-b1-c3);
        ans=min(ans,l-a2-b3-c1);
        ans=min(ans,l-a3-b1-c2);
        ans=min(ans,l-a3-b2-c1);
         cout << ans << '\n';
    }
    return 0;
}