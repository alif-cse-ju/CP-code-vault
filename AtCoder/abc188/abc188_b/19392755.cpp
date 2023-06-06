#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5;
const int mod=1e9+7;

int a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,ans=0;
    cin >> n;
    for(i=0;i<n;i++)cin >> a[i];
    for(i=0;i<n;i++)cin >> b[i];
    for(i=0;i<n;i++)ans+=a[i]*b[i];
    cout << (ans == 0 ? "Yes" : "No");
    return 0;
}