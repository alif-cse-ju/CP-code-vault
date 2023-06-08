#include<bits/stdc++.h>
using namespace std;
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
char a[N],b[N],s[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,l,t;
    cin >> t;
    while(t--)
    {
        cin >> l >> s+1;
        if(s[1] == '0'  ||  s[l] == '0')
        {
            cout << "NO\n";
            continue;
        }
        stack<char>stka,stkb;
        for(i=1;i<=l;i++)
        {
            if(s[i] == '1')
            {
                if(stka.empty()  ||  stkb.empty())
                {
                    a[i]=b[i]='(';
                    stka.emplace('(');
                    stkb.emplace('(');
                }
                else
                {
                    if((int)stka.size() == 1  &&  (int)stkb.size() == 1  &&  i != l)
                    {
                        a[i]=b[i]='(';
                        stka.emplace('(');
                        stkb.emplace('(');
                    }
                    else
                    {
                        a[i]=b[i]=')';
                        stka.pop();
                        stkb.pop();
                    }
                }
            }
            else
            {
                if(stka.empty()  &&  stkb.empty())break;
                if(stka.empty())
                {
                    a[i]='(',b[i]=')';
                    stka.emplace('(');
                    stkb.pop();
                }
                else if(stkb.empty())
                {
                    a[i]=')',b[i]='(';
                    stkb.emplace('(');
                    stka.pop();
                }
                else
                {
                    if(stka.size() >= stkb.size())
                    {
                        a[i]=')',b[i]='(';
                        stkb.emplace('(');
                        stka.pop();
                    }
                    else
                    {
                        a[i]='(',b[i]=')';
                        stka.emplace('(');
                        stkb.pop();
                    }
                }
            }
        }
        if(i <= l)cout << "NO\n";
        else
        {
            if(!stka.empty()  ||  !stkb.empty())cout << "NO\n";
            else
            {
                cout << "YES\n";
                for(i=1;i<=l;i++)cout << a[i];
                cout << '\n';
                for(i=1;i<=l;i++)cout << b[i];
                cout << '\n';
            }
        }
    }
    return 0;
}
//