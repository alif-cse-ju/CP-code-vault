#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int i,l,t;
    char s[55];
    cin >> t;
    while(t--)
    {
        cin >> l >> s+1;
        deque<int>opn;
        for(i=1;i<=l;i++)
        {
            if(s[i] == '(')opn.emplace_back(i);
            else if(!opn.empty())opn.pop_back();
        }
        cout << (int)opn.size() << '\n';
    }
    return 0;