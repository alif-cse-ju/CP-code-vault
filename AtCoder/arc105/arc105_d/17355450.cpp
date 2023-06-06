#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,t,x;
    bool flag;
    cin >> t;
    while(t--)
    {
        cin >> n;
        map<int,bool>mp;
        for(i=0;i<n;i++)
        {
            cin >> x;
            mp[x] ^= 1;
        }
        if(n & 1)
        {
            cout << "Second\n";
            continue;
        }
        flag=1;
        for(auto it : mp)
        {
            if(it.second)
            {
                cout << "First\n";
                flag=0;
                break;
            }
        }
        if(flag)cout << "Second\n";
    }
    return 0;
}
