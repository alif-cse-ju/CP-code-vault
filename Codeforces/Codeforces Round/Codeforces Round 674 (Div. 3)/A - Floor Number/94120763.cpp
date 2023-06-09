#include<bits/stdc++.h>
using namespace std;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n >> x;
        if(n < 3)cout << "1\n";
        else
        {
            n-=2;
            cout << n/x+1+(n%x > 0) << '\n';
        }
    }
    return 0;