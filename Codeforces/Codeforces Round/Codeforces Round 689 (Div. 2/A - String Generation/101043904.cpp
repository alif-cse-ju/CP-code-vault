#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,k,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(i=0;i<n;i++)
        {
            if(i%3 == 0)cout << 'a';
            else if(i%3 == 1)cout << 'b';
            else cout << 'c';
        }
        cout << '\n';
    }
    return 0;