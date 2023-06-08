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
char s[15];
int ans,k,l;
bool paichi;
void Dhon(int idx,int cur,int mask,bool smaller)
    if(__builtin_popcount(mask) > k)return;
    if(idx > l)
    {
        ans=cur,paichi=1;
        return;
    }
    if(smaller)
    {
        for(int i=0;i<10  &&  !paichi;i++)Dhon(idx+1,cur*10+i,mask | (1 << i),1);
    }
    else
    {
        Dhon(idx+1,cur*10+(s[idx]-'0'),mask | (1 << (s[idx]-'0')),0);
        for(int i=s[idx]-'0'+1;i<10  &&  !paichi;i++)Dhon(idx+1,cur*10+i,mask | (1 << i),1);
    }
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> s+1 >> k;
        l=strlen(s+1),paichi=0;
        Dhon(1,0,0,0);
        cout << ans << '\n';
    }
    return 0;
}