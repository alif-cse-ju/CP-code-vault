#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int i,n,t,rt;
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n%2 == 0)cout << n/2 << ' ' << n/2 << '\n';
        else
        {
            rt=sqrt(n);
            for(i=3;i<=rt;i+=2)
            {
                if(n%i == 0)break;
            }
            if(i <= rt)cout << n/i << ' ' << n-n/i << '\n';
            else cout << "1 " << n-1 << '\n';
        }
    }
    return 0;