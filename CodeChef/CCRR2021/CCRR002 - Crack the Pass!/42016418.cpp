#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int l,cur[10];
void Solve(int pos)
{
    if(pos > l)
    {
        for(int i=1;i<=l;i++)cout << cur[i];
        cout << '\n';
        return;
    }
    while(++cur[pos] < 10)Solve(pos+1);
    cur[pos]=0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> l;
        Solve(1);
    }
    return 0;
}