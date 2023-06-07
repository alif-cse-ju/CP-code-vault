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
int l,sum[M];
char a[M],b[M];
vector<int>pos[26];
void Update(int i)
    while(i <= l)++sum[i], i+=(i & -i);
int Query(int i)
    int ans=0;
    while(i)ans += sum[i], i-=(i & -i);
    return ans;
ll Check()
{
    int i,j,x,y;
    ll ans=LLONG_MAX, sum=0;
    for(i=1;i<=l;i++)
    {
        for(j=0,y=INT_MAX;j<b[i]-'a';j++)
        {
            if(!pos[j].empty())x=pos[j].back()+Query(l)-Query(pos[j].back())-i, y=min(x,y);
        }
        if(y < INT_MAX)ans=min(ans, sum+y);
        if(!pos[b[i]-'a'].empty())sum += pos[b[i]-'a'].back()+Query(l)-Query(pos[b[i]-'a'].back())-i, Update(pos[b[i]-'a'].back()), pos[b[i]-'a'].pop_back();
        else break;
    }
    return ans;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll ans;
    int i,t;
    cin >> t;
    while(t--)
    {
        cin >> l >> a+1 >> b+1;
        for(i=0;i<26;i++)pos[i].clear();
        for(i=1;i<=l;i++)pos[a[i]-'a'].emplace_back(i), sum[i]=0;
        for(i=0;i<26;i++)reverse(pos[i].begin(),pos[i].end());
        ans=Check();
        if(ans == LLONG_MAX)ans=-1;
        cout << ans << '\n';
    }
    return 0;
}