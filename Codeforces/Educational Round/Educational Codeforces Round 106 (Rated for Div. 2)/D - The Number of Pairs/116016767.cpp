#include<bits/stdc++.h>
using namespace std;
const int N=2e7+5;
int mark[N];
long long cnt[N];
void PreCal()
    int i,j,k,rt=sqrt(N);
    mark[1]=1;
    for(i=2;i<N;i+=2)mark[i]=2;
    for(i=3; i<N; i+=2)
    {
        if(!mark[i])
        {
            mark[i]=i;
            if(i <= rt)
            {
                for(j=i*i,k=2*i; j<N; j+=k)
                {
                    if(!mark[j])mark[j]=i;
                }
            }
        }
    }
    cnt[1]=1;
    for(i=2;i<N;i++)
    {
        cnt[i]=cnt[i/mark[i]];
        if(mark[i] != mark[i/mark[i]])cnt[i]*=2ll;
    }
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    long long a,b,i,n,x,y,ans;
    PreCal();
    cin >> t;
    while(t--)
    {
        ans=0;
        cin >> a >> b >> x;
        for(i=1; i*i<=x; i++)
        {
            if(x%i == 0)
            {
                y=i,n=x/y+b;
                if(n%a == 0)ans+=cnt[n/a];
                y=x/i;
                if(y != i)
                {
                    n=x/y+b;
                    if(n%a == 0)ans+=cnt[n/a];
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}