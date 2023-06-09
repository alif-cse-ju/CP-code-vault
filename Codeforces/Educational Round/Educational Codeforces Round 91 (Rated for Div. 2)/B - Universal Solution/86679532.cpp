#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    string str;
    int i,l,r,p,s,t;
    cin >> t;
    while(t--)
    {
        cin >> str;
        r=p=s=0;
        l=str.size();
        for(i=0;i<l;i++)
        {
            if(str[i] == 'R')++r;
            else if(str[i] == 'P')++p;
            else ++s;
        }
        if(r >= p  &&  r >= s)
        {
            for(i=0;i<l;i++)cout << 'P';
        }
        else if(p >= r  &&  p >= s)
        {
            for(i=0;i<l;i++)cout << 'S';
        }
        else
        {
            for(i=0;i<l;i++)cout << 'R';
        }
        cout << '\n';
    }
    return 0;