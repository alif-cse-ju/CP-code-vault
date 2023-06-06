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

int P[M],posQ[M];

int len;
vector<int>v,ans;

int FindCeilIndex(int l,int r,int val)
{
    int m;
    while(r-l > 1)
    {
        m=l+((r-l) >> 1);
        if(ans[m] >= val)r=m;
        else l=m;
    }
    return r;
}

void FindLIS()
{
    if(v.empty())return;
    len=1;
    ans.emplace_back(v[0]);
    int i,l=(int)v.size();
    for(i=1; i<l; i++)
    {
        if(v[i] < ans[0])ans[0]=v[i];
        else if(v[i] > ans[len-1])
        {
            ans.emplace_back(v[i]);
            len++;
        }
        else if(v[i] != ans[len-1])ans[FindCeilIndex(-1,len-1,v[i])]=v[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,n,x;
    cin >> n;
    for(i=1;i<=n;i++)cin >> P[i];
    for(i=1;i<=n;i++)cin >> x, posQ[x]=i;
    for(i=1;i<=n;i++)
    {
        vector<int>vv;
        for(j=P[i];j<=n;j+=P[i])vv.emplace_back(posQ[j]);
        sort(vv.begin(),vv.end());
        while(!vv.empty())v.emplace_back(vv.back()), vv.pop_back();
    }
    FindLIS();
    cout << (int)ans.size();
    return 0;
}