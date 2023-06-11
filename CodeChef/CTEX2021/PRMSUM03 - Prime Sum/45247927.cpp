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
bool mark[M];
vector<int>prime;
void Sieve()
{
    int i,j;
    prime.emplace_back(2);
    for(i=3; ;i+=2)
    {
        if(!mark[i])
        {
            prime.emplace_back(i);
            if((int)prime.size() == 1000)break;
            for(j=i*i;j<M;j+=2*i)mark[j]=1;
        }
    }
}
int main()
{
    FAST();
    int i,n;
    long long ans=0;
    Sieve();
    cin >> n;
    for(i=0;i<n;i++)ans+=prime[i];
    cout << ans;
    return 0;
}