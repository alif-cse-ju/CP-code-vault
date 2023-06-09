#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    string s;
    int i,n;
    cin >> n;
    for(i=1;i<=(n << 1);i++)
    {
        cin >> s;
        if(s == "-")cin >> a[i];
    }
    stack<int>ans,temp;
    for(i=(n << 1);i>0;i--)
    {
        if(!a[i])
        {
            if(temp.empty())
            {
                cout << "NO";
                return 0;
            }
            ans.emplace(temp.top());
            temp.pop();
        }
        else
        {
            if(!temp.empty()  &&  temp.top() < a[i])
            {
                cout << "NO";
                return 0;
            }
            temp.emplace(a[i]);
        }
    }
    cout << "YES\n";
    while(!ans.empty())
    {
        cout << ans.top() << ' ';
        ans.pop();
    }
    return 0;
}