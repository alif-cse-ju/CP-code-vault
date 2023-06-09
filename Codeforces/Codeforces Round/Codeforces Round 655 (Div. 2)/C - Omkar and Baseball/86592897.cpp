#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int i,n,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<int>v;
        for(i=1;i<=n;i++)
        {
            cin >> x;
            if(i != x)v.emplace_back(i);
        }
        if(v.empty())cout << "0\n";
        else if(v.size() == n)cout << "1\n";
        else
        {
            sort(v.begin(),v.end());
            if(v.back()-v[0]+1 == (int)v.size())cout << "1\n";
            else cout << "2\n";
        }
    }
    return 0;