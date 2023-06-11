#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j,n,a[102],b[102];
    map<int,int>mark;
    cin >> n;
    for(i=1;i<=n;i++)cin >> a[i] >> b[i];
    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            if(a[i]+b[i] == a[j]  &&  a[j]+b[j] == a[i])
            {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}