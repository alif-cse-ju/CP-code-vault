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
    cin >> l >> s;
    for(i=1;i<l;i++)
    {
        if(s[i] < s[i-1])
        {
            cout << "YES\n" << i << ' ' << i+1;
            return 0;
        }
    }
    cout << "NO";
    return 0;