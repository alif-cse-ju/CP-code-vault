#include<bits/stdc++.h>
using namespace std;
int main()
    int n,i,j,a[105];
    cin >> n;
    for(i=1; i<=n; i++)
    {
        cin >> a[i];
    }
    for(j=1; j<=n; j++)
    {
        for(i=1; i<=n; i++)
        {
            if(a[i]==j)
            {
                cout << i << " ";
                break;
            }
        }
    }
    return 0;