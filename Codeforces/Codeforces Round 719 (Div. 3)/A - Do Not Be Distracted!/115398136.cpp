#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL)
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
int main()
    FAST();
    string s;
    int i,j,l,t;
    cin >> t;
    while(t--)
    {
        cin >> l >> s;
        set<char>st;
        for(i=0;i<l;)
        {
            if(st.find(s[i]) != st.end())break;
            st.insert(s[i]);
            for(j=i;j<l;j++)
            {
                if(s[j] != s[i])break;
            }
            i=j;
        }
        if(i == l)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}