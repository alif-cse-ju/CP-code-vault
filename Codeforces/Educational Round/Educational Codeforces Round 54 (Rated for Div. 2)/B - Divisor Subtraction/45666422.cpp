#include<bits/stdc++.h>
using namespace std;
bool mark[1000010];
void sieve()
    int i,j;
    for(i=3; i<1000; i+=2)
    {
        if(mark[i] == 0)
        {
            for(j=i*i; j<1000000; j+=2*i)
            {
                mark[j]=1;
            }
        }
    }
int main()
    sieve();
    long long int n,i,flag=0,cnt=0;
    cin >> n;
    if(n%2 == 0)
    {
        cnt=n/2;
    }
    else if(n<1000000 && mark[n] == 0)
    {
        cnt=1;
    }
    else
    {
        for(i=3;i<=sqrt(n);i+=2)
        {
            if(mark[i]==0 && n%i==0)
            {
                flag=1;
                n=n-i;
                cnt++;
                break;
            }
        }
        if(flag == 0)
        {
            cnt=1;
        }
        else
        {
            cnt+=n/2;
        }
    }
    cout << cnt << endl;
    return 0;
}