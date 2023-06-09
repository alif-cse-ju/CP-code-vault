#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int i,l;
    string s;
    cin >> s;
    l=s.size();
    for(i=0; i<l; i++)
    {
        if(s[i] == '.')
        {
            cout << '0';
        }
        else
        {
            if(s[i+1] == '.')
            {
                cout << '1';
            }
            else
            {
                cout << '2';
            }
            i++;
        }
    }
    return 0;
}