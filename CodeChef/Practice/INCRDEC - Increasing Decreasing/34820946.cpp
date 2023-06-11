#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    FAST();
    int i,n,t,a[100002];
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=0;i<n;i++)cin >> a[i];
        sort(a,a+n);
        vector<int>inc,dec;
        for(i=0;i<n;i++)
        {
            if(inc.empty()  ||  inc.back() < a[i])inc.emplace_back(a[i]);
            else if(dec.empty()  ||  dec.back() < a[i])dec.emplace_back(a[i]);
            else break;
        }
        if(i < n)cout << "NO\n";
        else
        {
            reverse(dec.begin(),dec.end());
            if(!dec.empty()  &&  inc.back() == dec[0])cout << "NO\n";
            else
            {
                cout << "YES\n";
                for(int x : inc)cout << x << ' ';
                for(int x : dec)cout << x << ' ';
                cout << '\n';
            }
        }
    }
    return 0;
}