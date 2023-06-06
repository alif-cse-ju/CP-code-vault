#include<bits/stdc++.h>

using namespace std;

#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main()
{
    FAST();
    int i,k,l;
    string s;
    cin >> k >> s;
    l=s.size();
    if(l <= k)cout << s;
    else cout << s.substr(0,k)+"...";
    return 0;
}
