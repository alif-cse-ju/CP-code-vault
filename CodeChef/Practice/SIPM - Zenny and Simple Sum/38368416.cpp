#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,t,x,pos,neg;
    cin >> t;
    while(t--)
    {
        cin >> n;
        set<int>P,N;
        for(i=0;i<n;i++)
        {
            cin >> x;
            if(x > 0)P.insert(x);
            else N.insert(x);
        }
        pos=neg=0;
        for(int x : P)pos+=x;
        for(int x : N)neg+=x;
        cout << pos << ' ' << neg << '\n';
    }
    return 0;
}