#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,l,n,t;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n == 1)
        {
            cout << "No\n";
            continue;
        }
        for(i=2;i<n;i++)
        {
            if(n%i == 0)break;
        }
        if(i < n)cout << "No\n";
        else
        {
            s="";
            while(n)
            {
                s+=('0'+(n%10));
                n/=10;
            }
            l=(int)s.size();
            for(i=0;i<l;i++)
            {
                if(s[i] != s[l-i-1])break;
            }
            if(i == l)cout << "Yes\n";
            else cout << "No\n";
        }
    }
    return 0;
}