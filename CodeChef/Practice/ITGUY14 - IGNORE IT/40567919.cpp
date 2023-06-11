#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<bool>mark(n,0);
        for(i=0;i<n;i++)
        {
            cin >> x;
            mark[x]=1;
        }
        for(i=0;i<n;i++)cout << (mark[i] ? i : 0) << ' ';
        cout << '\n';
    }
    return 0;
}