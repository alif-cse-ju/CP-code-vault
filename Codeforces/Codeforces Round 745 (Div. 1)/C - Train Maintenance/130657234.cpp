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
const int N=1e6+5;
const int mod=1e9+9;
const int magic = 450;
int Start[M],aG[M],aS[magic][magic],X[M],Y[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,k,m,n,op,x,ans=0,cur=0;
    cin >> n >> m;
    for(i=1;i<=n;i++)cin >> X[i] >> Y[i];
    for(i=0;i<m;i++)
    {
        cin >> op >> k;
        if(op == 1)x=1,Start[k]=i;
        else
        {
            x=-1;
            if((i-1-Start[k]) % (X[k]+Y[k]) < X[k])--cur;
        }
        ans += x;
        if(X[k]+Y[k] < magic)
        {
            aS[X[k]+Y[k]][Start[k] % (X[k]+Y[k])] += x;
            aS[X[k]+Y[k]][(Start[k]+X[k]) % (X[k]+Y[k])] -= x;
        }
        else
        {
            for(ll it=Start[k];it<m;it+=X[k]+Y[k])aG[it] += x;
            for(ll it=Start[k]+X[k];it<m;it+=X[k]+Y[k])aG[it] -= x;
        }
        cur += aG[i];
        for(int it=2;it<magic;it++)cur += aS[it][i%it];
        cout << ans-cur << '\n';
    }
    return 0;
}