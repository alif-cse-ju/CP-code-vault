#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=3e5+5;
const int N=2e6+5;
const int mod=1e9+7;
char s[M];
int sum[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int l;cin >> l >> s+1;
        int mn=0,mx=0,id;
        l += l;
        for(int i=1;i<=l;i++)
        {
            sum[i] = sum[i-1];
            if(s[i] == '(')++sum[i];
            else --sum[i];
            mn=min(mn, sum[i]);
            if(sum[i] > mx)mx=sum[i],id=i;
        }
        if(!mn)cout << "0\n";
        else
        {
            int firstNeg=0, lastNeg;
            for(int i=1;i<=l;i++)
            {
                if(sum[i] < 0)
                {
                    if(!firstNeg)firstNeg=i;
                    lastNeg=i;
                }
            }
            int lPos=0,lVal=0,rPos=l,rVal=0;
            for(int i=1;i<firstNeg;i++)
            {
                if(sum[i] > lVal)lVal=sum[i], lPos=i;
            }
            for(int i=lastNeg+1;i<=l;i++)
            {
                if(sum[i] > rVal)rVal=sum[i], rPos=i;
            }
            bool ok=1;
            for(int i=firstNeg;i<=lastNeg  &&  ok;i++)
            {
                if(sum[i] > lVal+rVal)ok=0;
            }
            if(ok)cout << "1\n" << lPos+1 << ' ' << rPos << '\n';
            else cout << "2\n1 " << id << '\n' << id+1 << ' ' << l << '\n';
        }
    }
    return 0;
}