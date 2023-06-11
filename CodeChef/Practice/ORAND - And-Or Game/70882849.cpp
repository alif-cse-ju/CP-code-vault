#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
#define AND 1
#define OR 2
#define XOR 3
template<typename T>
struct FWHT
{
    void wht(T io[], const int& n, const int& flag)
    {
        for(int k=1; k<n; k<<=1)
        {
            for(int i=0, m=(k << 1); i<n; i+=m)
            {
                for(int j=0; j<k; j++)
                {
                    T x=io[i+j], y=io[i+j+k];
                    if(flag == AND)io[i+j] = x+y;
                    else if(flag == OR)io[i+j+k] = x+y;
                    else io[i+j] = x+y, io[i+j+k] = x-y;
                }
            }
        }
    }
    void iwht(T io[], const int& n, const int& flag)
    {
        for(int k=1; k<n; k<<=1)
        {
            for(int i=0, m=(k << 1); i<n; i+=m)
            {
                for(int j=0; j<k; j++)
                {
                    T x=io[i+j], y=io[i+j+k];
                    if(flag == AND)io[i+j] = x-y;
                    else if(flag == OR)io[i+j+k] = y-x;
                    else io[i+j] = (x+y) >> 1, io[i+j+k] = (x-y) >> 1;
                }
            }
        }
    }
    void convolute(T a[], T b[], const int& n, const int& flag)
    {
        wht(a,n,flag);
        for(int i=0; i<n; i++)a[i]=(1ll*a[i]*b[i]);
        iwht(a,n,flag);
    }
};
FWHT<int>T;
const int MX = (1 << 20);
int a[MX],b[MX],A[MX],B[MX],ans[MX];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int m,n;cin >> n >> m;
        int mx=0;
        for(int i=0;i<n;i++)cin >> a[i], mx=max(mx, a[i]);
        for(int i=0;i<m;i++)cin >> b[i], mx=max(mx, b[i]);
        int msb=32-__builtin_clz(mx), sz=(1 << msb);
        for(int i=0;i<sz;i++)ans[i]=A[i]=B[i]=0;
        for(int i=0;i<n;i++)A[a[i]]=1;
        for(int i=0;i<m;i++)B[b[i]]=1;
        A[0]=ans[0]=B[sz-1]=1;
        T.wht(A,sz,OR), T.wht(B,sz,AND);
        for(int i=0;i<msb;i++)
        {
            T.convolute(ans,A,sz,OR);
            for(int i=0;i<sz;i++)ans[i]=min(ans[i],1);
            T.convolute(ans,B,sz,AND);
            for(int i=0;i<sz;i++)ans[i]=min(ans[i],1);
        }
        int cnt=0;
        for(int i=0;i<sz;i++)cnt += (ans[i] > 0);
        cout << cnt << '\n';
    }
    return 0;
}