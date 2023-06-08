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
const int N=1e6+5;
const int mod=1e9+7;
char s[M];
int n,sum[M];
void Update(int i,int v)
    while(i <= n)sum[i] += v, i+=(i & -i);
int Query(int i)
    int ans=0;
    while(i)ans += sum[i], i-=(i & -i);
    return ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string ss;
    int i,q,x;
    cin >> n >> q >> s+1;
    for(i=1;i+2<=n;i++)
    {
        if(s[i] == 'a'  &&  s[i+1] == 'b'  &&  s[i+2] == 'c')Update(i,1);
    }
    while(q--)
    {
        cin >> i >> ss;
        if(s[i] == 'a')
        {
            if(i <= n-2  &&  s[i+1] == 'b'  &&  s[i+2] == 'c')Update(i,-1);
        }
        else if(s[i] == 'b')
        {
            if(i > 1  &&  s[i-1] == 'a'  &&  i < n  &&  s[i+1] == 'c')Update(i-1,-1);
        }
        else
        {
            if(i > 2  &&  s[i-2] == 'a'  &&  s[i-1] == 'b')Update(i-2,-1);
        }
        s[i]=ss[0];
        if(s[i] == 'a')
        {
            if(i <= n-2  &&  s[i+1] == 'b'  &&  s[i+2] == 'c')Update(i,1);
        }
        else if(s[i] == 'b')
        {
            if(i > 1  &&  s[i-1] == 'a'  &&  i < n  &&  s[i+1] == 'c')Update(i-1,1);
        }
        else
        {
            if(i > 2  &&  s[i-2] == 'a'  &&  s[i-1] == 'b')Update(i-2,1);
        }
        cout << Query(n) << '\n';
    }
    return 0;
}