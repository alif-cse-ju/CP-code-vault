#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,t,cnt,rt;
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n & 1)
        {
            if(n == 1)cout << "Grinch\n";
            else cout << "Me\n";
        }
        else
        {
            if(n == 2)cout << "Me\n";
            else
            {
                cnt=0;
                while(n%2 == 0)++cnt,n/=2;
                if(n == 1)cout << "Grinch\n";
                else
                {
                    if(cnt > 1)cout << "Me\n";
                    else
                    {
                        rt=sqrt(n);
                        for(i=3;i<=rt;i+=2)
                        {
                            if(n%i == 0)break;
                        }
                        if(i > rt)cout << "Grinch\n";
                        else cout << "Me\n";
                    }
                }
            }
        }
    }
    return 0;
}