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

const int M=2e5+5;
const int N=1e6+5;
const int mod=1e9+7;

char s[M];
int k,len,cnt[M];

bool Check(const int& dhon)
{
    for(int i=dhon;i<=len;i++)
    {
        if(cnt[i]-cnt[i-dhon] <= k)return 1;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,l,m,r;
    cin >> s+1 >> k;
    len=strlen(s+1);
    for(i=1;i<=len;i++)
    {
        cnt[i]=(s[i] == '.');
        cnt[i] += cnt[i-1];
    }
    l=1,r=len;
    while(l <= r)
    {
        m=(l+r) >> 1;
        if(Check(m))l=m+1;
        else r=m-1;
    }
    cout << l-1;
    return 0;
}
