#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
 using namespace std;
using namespace __gnu_pbds;
 template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
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
 int a[202],cnt[202],lMax[202],rMax[202];
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,jj,k,l,m,n,p,t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(i=1;i<=n;i++)cnt[i]=0;
        for(i=1;i<=n;i++)cin >> a[i], ++cnt[a[i]];
        for(i=1;i<=n;i++)
        {
            if(cnt[i] > k)break;
        }
        if(i <= n)
        {
            cout << "-1\n";
            continue;
        }
        vector<int>ans;
        sort(a+1,a+n+1);
        for(i=1;i<=k;i++)ans.emplace_back(a[i]);
        for(i=k+1;i<=n;i++)
        {
            l=i-1;
            vector<int>tmp;
            for(j=0;j<=i;j++)lMax[i]=rMax[i]=0;
            for(j=0;j<l;j++)
            {
                m=0;
                for(jj=j;jj;jj--)
                {
                    if(ans[jj-1] <= ans[j])m=max(m,lMax[jj]);
                }
                lMax[j+1]=m+1;
            }
            for(j=l-1;j>=0;j--)
            {
                m=0;
                for(jj=j+2;jj<i;jj++)
                {
                    if(ans[jj-1] >= ans[j])m=max(m,rMax[jj]);
                }
                rMax[j+1]=m+1;
            }
            p=-1,m=0;
            for(j=l;j;j--)
            {
                if(j < l  &&  ans[j] >= a[i])m=max(m,rMax[j+1]);
                if(lMax[j]+m+1 <= k)
                {
                    p=j-1;
                    break;
                }
            }
            for(j=0;j<=p;j++)tmp.emplace_back(ans[j]);
            tmp.emplace_back(a[i]);
            for(j=p+1;j<l;j++)tmp.emplace_back(ans[j]);
            ans=tmp;
        }
        for(int it : ans)cout << it << ' ';
        cout << '\n';
    }
    return 0;
}