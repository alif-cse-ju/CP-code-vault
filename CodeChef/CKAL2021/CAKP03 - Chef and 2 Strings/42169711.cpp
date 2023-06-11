#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
bool Solve(string& a,string& b)
{
    int i,j,la=(int)a.size(),lb=(int)b.size();
    for(i=j=0;i < la  &&  j < lb;i++)
    {
        while(j < lb)
        {
            if(a[i] == b[j])
            {
                j++;
                break;
            }
            j++;
        }
    }
    return (i == la);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    string a,b;
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        if(Solve(a,b))cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
//