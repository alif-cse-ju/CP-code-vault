#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int n,a[N];
void Query(int x)
    if(x  &&  x <= n)
    {
        cout << "? " << x << endl;
        cin >> a[x];
    }
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,l,m,r;
    cin >> n;
    a[0]=a[n+1]=INT_MAX;
    l=1,r=n;
    while(l < r)
    {
        m=(l+r) >> 1;
        Query(m);
        Query(m+1);
        if(a[m] < a[m+1])r=m;
        else l=m+1;
    }
    cout << "! " << l << endl;
    return 0;