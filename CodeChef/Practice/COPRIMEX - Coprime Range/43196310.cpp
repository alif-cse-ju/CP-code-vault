#include<bits/stdc++.h>
using namespace std;
const int N=1e7+5;
const int mod=1e9+7;
int lp[N];
vector<int>prime;
void Sieve()
{
    int i,j,l=0;
    for(i=2;i<N;i++)
    {
        if(!lp[i])
        {
            lp[i]=i,++l;
            prime.emplace_back(i);
        }
        for(j=0;j<l  &&  prime[j] <= lp[i]  &&  i*prime[j]<N;j++)lp[i*prime[j]]=prime[j];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Sieve();
    int t,l,r;
    cin >> t;
    while(t--)
    {
        cin >> l >> r;
        auto it=upper_bound(prime.begin(),prime.end(),r);
        cout << *(it) << '\n';
    }
    return 0;
}
//