#include<bits/stdc++.h>
using namespace std;
const int M=2e5+5;
const int N=1e7+5;
const int mod=1e9+7;
bool mark[N];
vector<long long>primes;
void Sieve()
    long long i,j,k;
    primes.emplace_back(2);
    for(i=3;i<N;i+=2)
    {
        if(!mark[i])
        {
            primes.emplace_back(i);
            for(j=i*i,k=2*i;j<N;j+=k)mark[j]=1;
        }
    }
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long x,y;
    int k,n,t,ans,cnt;
    Sieve();
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        ans=1;
        set<long long>st;
        while(n--)
        {
            cin >> x;
            y=1;
            for(long long it : primes)
            {
                if(it*it > x)break;
                if(x%it == 0)
                {
                    cnt=0;
                    while(x%it == 0)++cnt,x/=it;
                    if(cnt & 1)y*=it;
                }
            }
            if(x > 1)y*=x;
            if(st.find(y) != st.end())++ans,st.clear();
            st.insert(y);
        }
        cout << ans << '\n';
    }
    return 0;
}
//