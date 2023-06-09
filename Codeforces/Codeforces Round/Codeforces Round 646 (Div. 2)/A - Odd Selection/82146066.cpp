#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int i,m,n,t,x,even,odd;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        odd=even=0;
        for(i=0;i<n;i++)
        {
            cin >> x;
            if(x & 1)++odd;
            else ++even;
        }
        if(odd == 0)cout << "No\n";
        else if(m == n  &&  odd%2 == 0)cout << "No\n";
        else if(odd == n  &&  m%2 == 0)cout << "No\n";
        else cout << "Yes\n";
    }
    return 0;