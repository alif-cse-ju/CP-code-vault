#include<bits/stdc++.h>
using namespace std;
bool mark[1000010];
long long int cnt=0,loop,fl;
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
void anscnt(long long int n)
    if(n == 0)
    {
        return;
    }
    if(n%2 == 0)
    {
        cnt+=n/2;
        n=0;
    }
    else
    {
        fl=0;
        for(loop=3; loop<=sqrt(n); loop+=2)
        {
            if(mark[loop] == 0)
            {
                if(n%loop == 0)
                {
                    cnt++;
                    fl=1;
                    break;
                }
            }
        }
        if(fl == 0)
        {
            cnt++;
            n=0;
        }
        else
        {
            anscnt(n-loop);
        }
    }
}
 int main()
{
    sieve();
    long long int n,i,flag=0;
    cin >> n;
    if(n>1000000 && n%2!=0)
    {
        for(i=3; i<=sqrt(n); i+=2)
        {
            if(n%i == 0)
            {
                flag=1;
                cnt++;
                n=n-i;
                break;
            }
        }
        if(flag==1)
        {
            anscnt(n);
        }
        else
        {
            cnt++;
        }
    }
    else if(n%2 == 0)
    {
        cnt=n/2;
    }
    else
    {
        if(mark[n] == 1)
        {
            anscnt(n);
        }
        else
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}