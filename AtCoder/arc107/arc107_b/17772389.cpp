#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    long long i,k,n,ans=0;
    cin >> n >> k;
    for(i=2;i<=2*n;i++)
    {
        if(i-k >= 2  &&  i-k <= 2*n)ans+=min(i-1,2*n-i+1) * min(i-k-1,2*n-i+k+1);
    }
    cout << ans;
    return 0;
}