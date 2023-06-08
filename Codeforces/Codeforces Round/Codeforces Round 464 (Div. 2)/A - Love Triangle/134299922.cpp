#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
int a[N];
int main()
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int i,n;
    cin >> n;
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=1;i<=n;i++)
    {
        if(a[a[a[i]]] == i)
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;