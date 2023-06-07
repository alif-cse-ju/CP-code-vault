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
int a[M],pre[M],suf[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int n;cin >> n;
        int preCnt=0,sufCnt=0;
        map<int,int>preMap,sufMap;
        ordered_set<int>prePos[n+1],sufPos[n+1];
        pre[0]=suf[n+1]=0;
        for(int i=1;i<=n;i++)cin >> a[i];
        for(int i=1;i<=n;i++)
        {
            pre[i]=pre[i-1]+a[i];
            if(preMap.find(pre[i]) == preMap.end())preMap[pre[i]]=++preCnt;
            prePos[preMap[pre[i]]].insert(i);
        }
        for(int i=n;i;i--)
        {
            suf[i]=suf[i+1]+a[i];
            if(sufMap.find(suf[i]) == sufMap.end())sufMap[suf[i]]=++sufCnt;
            sufPos[sufMap[suf[i]]].insert(i);
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(sufMap.find(pre[i]) == sufMap.end())continue;
            int l=i;
            if(sufPos[sufMap[pre[i]]].order_of_key(i+1) == (int)sufPos[sufMap[pre[i]]].size())continue;
            int r=*(sufPos[sufMap[pre[i]]].find_by_order(sufPos[sufMap[pre[i]]].order_of_key(i+1)));
            ans=max(ans, l+n-r+1);
        }
        cout << ans << '\n';
    }
    return 0;
}