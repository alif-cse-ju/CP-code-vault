#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int i,n,x,a[100005];
    set<int>ache,nai;
    cin >> n;
    for(i=0;i<=n;i++)nai.insert(i);
    for(i=0;i<n;i++)
    {
        cin >> a[i];
        if(nai.find(a[i]) != nai.end())
        {
            nai.erase(a[i]);
            ache.insert(a[i]);
        }
    }
    for(i=0;i<n;i++)
    {
        x=*(ache.begin());
        if(x < a[i])
        {
            cout << x << ' ';
            ache.erase(x);
        }
        else
        {
            x=*(nai.begin());
            cout << x << ' ';
            nai.erase(x);
        }
    }
    return 0;