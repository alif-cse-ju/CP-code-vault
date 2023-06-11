#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int Solve(string s)
{
    s+=s;
    char c;
    int i,j,k=0,f[s.size()];
    memset(f,-1,sizeof(f));
    for(j=1;j<s.size();j++)
    {
        c=s[j];
        i=f[j-k-1];
        while(i != -1  &&  c != s[k+i+1])
        {
            if(c < s[k+i+1])k=j-i-1;
            i=f[i];
        }
        if(c != s[k+i+1])
        {
            if(c < s[k])k=j;
            f[j-k]=-1;
        }
        else f[j-k]=i+1;
    }
    return k;
}
int main()
{
    FAST();
    int i,n,t,pos;
    string s,s1,s2;
    cin >> t;
    while(t--)
    {
        cin >> n >> s;
        if(n > 1)sort(s.begin(),s.end());
        else
        {
            pos=Solve(s);
            s1=s.substr(0,pos);
            s2=s.substr(pos,s.size()-pos);
            s=s2+s1;
        }
        cout << s << '\n';
    }
    return 0;
}