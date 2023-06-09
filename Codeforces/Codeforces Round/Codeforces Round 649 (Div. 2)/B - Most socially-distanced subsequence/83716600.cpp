#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int i,l,n,t,a[100005];
    cin >> t;
    while(t--)
    {
        l=2;
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i];
        vector<int>v;
        v.emplace_back(a[1]);
        v.emplace_back(a[2]);
        for(i=3;i<=n;i++)
        {
            if(v[l-2] < v[l-1]  &&  v[l-1] < a[i])v[l-1]=a[i];
            else if(v[l-2] > v[l-1]  &&  v[l-1] > a[i])v[l-1]=a[i];
            else ++l,v.emplace_back(a[i]);
        }
        cout << l << '\n';
        for(int x : v)cout << x << ' ';
        cout << '\n';
    }
    return 0;