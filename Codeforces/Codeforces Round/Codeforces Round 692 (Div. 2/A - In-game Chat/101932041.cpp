#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    string s;
    int l1,l2,t;
    cin >> t;
    while(t--)
    {
        l2=0;
        cin >> l1 >> s;
        while(!s.empty()  &&  s.back() == ')')
        {
            --l1,++l2;
            s.pop_back();
        }
        if(l2 > l1)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;