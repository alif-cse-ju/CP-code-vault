#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<bitset>
#include<unordered_map>
#include<time.h>
#include<cstdlib>
#include <chrono>
#include <random>
typedef long long ll;
typedef unsigned long long ull;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma comment(linker, "/STACK:36777216") //hdu 扩栈
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
#define re register
#define umap(a) (a).reserve(1024);(a).max_load_factor(0.25);
using namespace std;
typedef pair<int,ll> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=500005;
const ll Mod=1000000007;
//const ll Mod=998244353;
 ll a[maxn],pos[maxn];
 int main()
{
    int t;
    int n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<=2*n+5;i++)
            pos[i]=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            pos[a[i]]=i;
        }
        int sum=0;
        int j;
        for(int i=1;i<=n;i++)
        {
            for(j=1;j*a[i]<=2*n;j++)
            {
                if(pos[j]>i&&a[i]*j==i+pos[j])
                {
                    sum++;
                }
            }
        }
        cout<<sum<<endl;
            }
            return 0;
}