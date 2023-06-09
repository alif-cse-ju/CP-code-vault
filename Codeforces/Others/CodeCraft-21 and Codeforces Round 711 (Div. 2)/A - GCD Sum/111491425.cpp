#include<bits/stdc++.h>
using namespace std;
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=998244353;
bool Solve(long long n)
    long long m=n,sum=0;
    while(m)
    {
        sum+=m%10;
        m/=10;
    }
    return __gcd(n,sum) > 1;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    long long i,n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=n; ;i++)
        {
            if(Solve(i))
            {
                cout << i << '\n';
                break;
            }
        }
    }
    return 0;
}
//