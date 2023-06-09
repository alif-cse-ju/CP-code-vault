#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int a[N],b[N],c[N+N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j,k,m,n;
    cin >> n >> m;
    for(i=0;i<n;i++)cin >> a[i];
    for(i=0;i<m;i++)cin >> b[i];
    i=j=k=0;
    a[n]=b[m]=INT_MAX;
    while(i < n  ||  j < m)
    {
        if(a[i] < b[j])c[k++]=a[i++];
        else c[k++]=b[j++];
    }
    for(i=0;i<n+m;i++)cout << c[i] << ' ';
    return 0;