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
const int mod=998244353;
int a[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        for(int i=1;i<=n;i++)cin >> a[i];
        int ans=-1,l=n,r=0;
        for(int i=1,j;i<=n;i++)
        {
            if(!a[i])continue;
            deque<int>dq1,dq2;
            int cnt2=0, cntMinus=0;
            for(j=i;j<=n;j++)
            {
                if(!a[j])break;
                dq1.emplace_back(a[j]);
                dq2.emplace_back(a[j]);
                if(a[j] < 0)++cntMinus;
                if(abs(a[j]) == 2)++cnt2;
            }
            if(cntMinus%2 == 0)
            {
                if(cnt2 > ans)ans=cnt2, l=i-1, r=n-j+1;
            }
            else
            {
                int cntF=cnt2, cntR=cnt2;
                while(true)
                {
                    int x=dq1.front(); dq1.pop_front();
                    if(abs(x) == 2)--cntF;
                    if(x < 0)break;
                }
                if(cntF > ans)ans=cntF, r=n-j+1, l=j-(int)dq1.size()-1;
                 while(true)
                {
                    int x=dq2.back(); dq2.pop_back();
                    if(abs(x) == 2)--cntR;
                    if(x < 0)break;
                }
                if(cntR > ans)ans=cntR, l=i-1, r=n-l-(int)dq2.size();
            }
            i=j;
        }
        cout << l << ' ' << r << '\n';
    }
    return 0;
}