#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5;
const int mod=1e9+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,l;
    string s;
    cin >> s;
    l=(int)s.size();
    for(i=0;i<l;i++)
    {
        if(i & 1)
        {
            if(s[i] >= 'a')
            {
                cout << "No";
                return 0;
            }
        }
        else
        {
            if(s[i] <= 'Z')
            {
                cout << "No";
                return 0;
            }
        }
    }
    cout << "Yes";
    return 0;
}
//
