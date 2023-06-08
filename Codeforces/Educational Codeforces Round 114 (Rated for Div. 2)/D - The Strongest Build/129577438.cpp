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
const int M=2e5+5;
const int N=4e6+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,k,m,mx,n,sum;
    vector<vector<int>>a,b;
    vector<int>ans,_last,tmp;
    cin >> n;
    a.resize(n);
    _last.resize(n);
    for(i=0;i<n;i++)
    {
        cin >> k;
        a[i].resize(k);
        for(j=0;j<k;j++)cin >> a[i][j];
    }
    cin >> m;
    b.resize(m);
    for(i=0;i<m;i++)
    {
        k=n;
        b[i].resize(k);
        for(j=0;j<k;j++)cin >> b[i][j], --b[i][j];
    }
    sort(b.begin(),b.end());
    for(i=0;i<n;i++)_last[i]=(int)a[i].size()-1;
    if(!binary_search(b.begin(),b.end(),_last))
    {
        for(int it : _last)cout << it+1 << ' ';
        return 0;
    }
    mx=-1;
    ans.resize(n);
    tmp.resize(n);
    for(i=0;i<m;i++)
    {
        tmp=b[i],sum=0;
        for(j=0;j<n;j++)sum += a[j][tmp[j]];
        for(j=0;j<n;j++)
        {
            if(tmp[j])
            {
                --tmp[j];
                if(!binary_search(b.begin(),b.end(),tmp)  &&  sum+a[j][tmp[j]]-a[j][tmp[j]+1] > mx)mx=sum+a[j][tmp[j]]-a[j][tmp[j]+1], ans=tmp;
                ++tmp[j];
            }
        }
    }
    for(i=0;i<n;i++)cout << ans[i]+1 << ' ';
    return 0;
}