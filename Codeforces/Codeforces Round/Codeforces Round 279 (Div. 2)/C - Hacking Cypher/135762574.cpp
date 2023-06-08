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
const int N=1e6+5;
const int mod=998244353;
char s[N];
ll v[N],pw[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll cur=0;
    int a,b,i,j,n;
    cin >> s+1 >> a >> b;
    n=strlen(s+1);
    for(i=1;i<=n;i++)v[i]=(v[i-1]*10+s[i]-'0')%a;
    pw[n]=1;
    for(i=n-1;i;i--)pw[i]=(pw[i+1]*10)%b;
    for(i=n;i  && s[i] == '0';i--);
    for(i--;i;i--)
    {
        cur=(pw[i+1]*(s[i+1]-'0')+cur)%b;
        if(!v[i]  &&  !cur)
        {
            cout << "YES\n";
            for(j=1;j<=i;j++)cout << s[j];
            cout << '\n';
            for(j=i+1;j<=n;j++)cout << s[j];
            return 0;
        }
    }
    cout << "NO";
    return 0;
}