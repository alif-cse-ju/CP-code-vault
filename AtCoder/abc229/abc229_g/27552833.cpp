#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long

template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=2e5+5;
const int N=5e6+5;
const int mod=1e9+7;

char s[M];
ll b[M],k;
int a[M],ln;

bool Check(const int& dhon)
{
    ll v;
    int pos;
    for(int i=dhon;i<=ln;i++)
    {
        pos=i-dhon+(dhon+1)/2;
        v=b[i]-b[pos]-1ll*(i-pos)*a[pos] + 1ll*(pos-i+dhon)*a[pos]-b[pos]+b[i-dhon];
        if(v <= k)return 1;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cnt=0,i,l,m,r;
    cin >> s+1 >> k;
    ln=strlen(s+1);
    for(i=1;i<=ln;i++)
    {
        if(s[i] == 'Y')a[++cnt]=i-cnt, b[cnt]=b[cnt-1]+a[cnt];
    }
    if(cnt < 2)cout << cnt;
    else
    {
        l=1,ln=r=cnt;
        while(l <= r)
        {
            m=(l+r) >> 1;
            if(Check(m))l=m+1;
            else r=m-1;
        }
        cout << l-1;
    }
    return 0;
}
