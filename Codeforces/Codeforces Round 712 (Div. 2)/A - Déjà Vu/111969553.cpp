#include<bits/stdc++.h>
using namespace std;
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=3e5+5;
const int mod=1e9+7;
char s[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,l,t,pos;
    cin >> t;
    while(t--)
    {
        cin >> s+1;
        l=strlen(s+1);
        pos=0;
        for(i=1;i<=l;i++)
        {
            if(s[i] != 'a')
            {
                pos=l-i+1;
                break;
            }
        }
        if(!pos)cout << "NO\n";
        else
        {
            cout << "YES\n";
            for(i=1;i<=l;i++)
            {
                if(i == pos  &&  pos <= l/2)cout << 'a';
                cout << s[i];
                if(i == pos  &&  pos > l/2)cout << 'a';
            }
            cout << '\n';
        }
    }
    return 0;
}
//