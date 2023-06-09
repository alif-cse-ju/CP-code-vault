#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,t;
    vector<int>v;
    for(i=0;i<10;i++)v.emplace_back(i);
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n == 1)cout << '9';
        else if(n == 2)cout << "98";
        else
        {
            n-=3;
            cout << "989";
            for(i=0;i<n;i++)cout << v[i%10];
        }
        cout << '\n';
    }
    return 0;