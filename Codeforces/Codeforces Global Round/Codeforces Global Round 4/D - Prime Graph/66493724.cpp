#include<bits/stdc++.h>
using namespace std;
bool prime(int n)
    int i;
    if(n%2 == 0)return false;
    for(i=3;i*i<=n;i+=2)
    {
        if(n%i == 0)return false;
    }
    return true;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int i,n,m=0;
    cin >> n;
    m=n;
    while(!prime(m))++m;
    cout << m << '\n';
    for(i=1;i<n;i++)cout << i << ' ' << i+1 << '\n';
    cout << n << " 1\n";
    m-=n;
    for(i=1;i<=m;i++)cout << i << ' ' << i+n/2 << '\n';
    return 0;