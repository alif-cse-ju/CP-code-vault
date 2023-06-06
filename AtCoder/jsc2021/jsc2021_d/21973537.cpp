#include<bits/stdc++.h>

using namespace std;

#define PI acos(-1)
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL)

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;

long long BigMod(long long val,long long pow)
{
    long long res = 1;
    val = val % mod;
    while(pow > 0)
    {
        if(pow & 1)res = (res*val) % mod;
        pow = pow >> 1;
        val = (val*val) % mod;
    }
    return res;
}

int main()
{
    FAST();
    long long n,p,ans;
    cin >> n >> p;
    ans=p-1;
    ans=(ans*BigMod(p-2,n-1))%mod;
    cout << ans;
    return 0;
}
