#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
const int mod=1e9+7;
long long phi[N];
void EulerPhi()
{
    int i,j;
    phi[1]=1;
    for(i=2;i<N;i++)phi[i]=i-1;
    for(i=2;i<N;i++)
    {
        for(j=2*i;j<N;j+=i)phi[j]-=phi[i];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,k,n,t;
    long long x;
    EulerPhi();
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        if(k > n)cout << "0\n";
        else
        {
            x=phi[n/k];
            cout << (x*(x-1))/2 << '\n';
        }
    }
    return 0;
}