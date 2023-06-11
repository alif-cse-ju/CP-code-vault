#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
pair<int,int>a[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,l,r,last=0;
    cin >> n;
    for(i=0;i<n;i++)cin >> a[i].first;
    for(i=0;i<n;i++)cin >> a[i].second;
    for(i=0;i<n;i++)
    {
        l=a[i].first,r=a[i].second;
        if(l >= last)cout << i << ' ',last=r;
    }
    return 0;
}