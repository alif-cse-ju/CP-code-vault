#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
const int MX=1e7+5;
int factor[MX];
bitset<MX>mark;
vector<int>primes;
void Sieve()
    for(int i=2;i<MX;i++)
    {
        if(!mark[i])
        {
            factor[i]=i;
            primes.emplace_back(i);
        }
        for(int p : primes)
        {
            if((LL)i*p >= MX)break;
            factor[i*p]=p;
            mark[i*p]=true;
            if(i%p == 0)break;
        }
    }
int main()
    FAST();
    Sieve();
    int i,n,x,y,z;
    cin >> n;
    vector<int>a(n,-1),b(n,-1);
    for(i=0;i<n;i++)
    {
        cin >> x;
        y=1,z=factor[x];
        while(x%z == 0)x/=z,y*=z;
        if(x > 1)a[i]=x,b[i]=y;
    }
    for(i=0;i<n;i++)cout << a[i] << ' ';
    cout << '\n';
    for(i=0;i<n;i++)cout << b[i] << ' ';
    return 0;
}