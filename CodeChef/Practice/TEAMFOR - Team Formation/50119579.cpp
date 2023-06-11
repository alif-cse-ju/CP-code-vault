#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k.
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=1e6+5;
const int mod=998244353;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a,b;
    int i,l,t,cntA,cntB,cntAB;
    cin >> t;
    while(t--)
    {
        cin >> l >> a >> b;
        cntA=cntB=cntAB=0;
        for(i=0;i<l;i++)
        {
            if(a[i] == '1'  &&  b[i] == '1')++cntAB;
            else if(a[i] == '1')++cntA;
            else if(b[i] == '1')++cntB;
        }
        cout << min(l/2,cntAB+min(cntA,cntB)) << '\n';
    }
    return 0;
}