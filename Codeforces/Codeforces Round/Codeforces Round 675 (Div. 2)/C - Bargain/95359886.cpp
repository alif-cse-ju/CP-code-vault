#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
long long a[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int l;
    string s;
    long long i,ans=0,sum=0,temp,pw=1;
    cin >> s;
    l=s.size();
    for(i=0;i<l;i++)a[i]=s[i]-'0';
    for(i=l-1;i>=0;i--)
    {
        temp=((i*(i+1))/2)%mod;
        temp=(temp*pw+sum)%mod;
        sum=(sum+pw*(l-i))%mod;
        pw=(pw*10)%mod;
        ans=(ans+a[i]*temp)%mod;
    }
    cout << ans;
    return 0;