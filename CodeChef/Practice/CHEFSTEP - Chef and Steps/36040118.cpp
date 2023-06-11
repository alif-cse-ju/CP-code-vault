#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    FAST();
    int k,n,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        while(n--)
        {
            cin >> x;
            if(x%k)cout << '0';
            else cout << '1';
        }
        cout << '\n';
    }
    return 0;
}