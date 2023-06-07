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

const int M=1e5+5;
const int N=2e6+5;
const int mod=1e9+7;

int A[M],B[M],AA[M],BB[M],A0[M],B0[M],A1[M],B1[M],len[M],newLen[M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    for(int tc=1;tc<=t;tc++)
    {
        int n;cin >> n, len[1]=n;
        for(int i=1;i<=n;i++)cin >> A[i];
        for(int i=1;i<=n;i++)cin >> B[i];
        int ans=0, grpCnt=1, last;
        for(int i=29;i>=0;i--)
        {
            bool ok=1;
            last=0;
            for(int j=1;j<=n;j++)AA[j]=A[j], BB[j]=B[j];
            for(int j=1;j<=grpCnt  &&  ok;j++)
            {
                int cnt1=0, cnt2=0;
                for(int k=1;k<=len[j];k++)
                {
                    int x=AA[++last], y=BB[last];
                    cnt1 += ((x >> i) & 1), cnt2 += ((y >> i) & 1);
                }
                ok=((cnt1+cnt2) == len[j]);
            }
            if(ok)
            {
                ans += (1 << i), last=0;
                int grpCntTmp=0, newLast=0;
                for(int j=1;j<=grpCnt;j++)
                {
                    int i0=0, i1=0, j0=0, j1=0;
                    for(int k=1;k<=len[j];k++)
                    {
                        int x=AA[++last], y=BB[last];
                        if((x >> i) & 1)A1[++i1]=x;
                        else A0[++i0]=x;
                        if((y >> i) & 1)B1[++j1]=y;
                        else B0[++j0]=y;
                    }
                    if(!i0)
                    {
                        ++grpCntTmp, newLen[grpCntTmp]=i1;
                        for(int k=1;k<=i1;k++)A[++newLast]=A1[k], B[newLast]=B0[k];
                    }
                    else if(!i1)
                    {
                        ++grpCntTmp, newLen[grpCntTmp]=i0;
                        for(int k=1;k<=i0;k++)A[++newLast]=A0[k], B[newLast]=B1[k];
                    }
                    else
                    {
                        ++grpCntTmp, newLen[grpCntTmp]=i1;
                        for(int k=1;k<=i1;k++)A[++newLast]=A1[k], B[newLast]=B0[k];
                        ++grpCntTmp, newLen[grpCntTmp]=i0;
                        for(int k=1;k<=i0;k++)A[++newLast]=A0[k], B[newLast]=B1[k];
                    }
                }
                grpCnt = grpCntTmp;
                for(int j=1;j<=grpCnt;j++)len[j]=newLen[j];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
