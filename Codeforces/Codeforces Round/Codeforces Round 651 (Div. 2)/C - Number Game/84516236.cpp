#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int i,n,t,x,rt;
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n & 1)
        {
            if(n == 1)cout << "FastestFinger\n";
            else cout << "Ashishgup\n";
        }
        else
        {
            if(n == 2)
            {
                cout << "Ashishgup\n";
                continue;
            }
            x=n;
            while(x%2 == 0)x/=2;
            if(x == 1)
            {
                cout << "FastestFinger\n";
                continue;
            }
            n/=2;
            if(n%2 == 0)cout << "Ashishgup\n";
            else
            {
                rt=sqrt(n);
                for(i=3;i<=rt;i+=2)
                {
                    if(n%i == 0)break;
                }
                if(i > rt)cout << "FastestFinger\n";
                else cout << "Ashishgup\n";
            }
        }
    }
    return 0;
}