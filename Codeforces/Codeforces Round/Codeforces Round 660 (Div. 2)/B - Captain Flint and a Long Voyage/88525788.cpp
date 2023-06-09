#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int i,n,x,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        x=n/4+(n%4 > 0);
        for(i=0;i<n-x;i++)cout << '9';
        for(i=0;i<x;i++)cout << '8';
        cout << '\n';
    }
    return 0;