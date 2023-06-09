#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int i,l,m,n;
    cin >> n >> m;
    l=min(m,2*n);
    for(i=1;i<=l;i++)
    {
        if(2*n+i <= m)cout << 2*n+i << ' ';
        cout << i << ' ';
    }
    return 0;