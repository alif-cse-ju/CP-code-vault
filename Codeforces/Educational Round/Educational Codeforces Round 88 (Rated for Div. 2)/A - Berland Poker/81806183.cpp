#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int k,m,n,t,x,y;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> k;
        x=min(m,n/k);
        y=(m-x+k-2)/(k-1);
        cout << x-y << '\n';
    }
    return 0;