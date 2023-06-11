#include<bits/stdc++.h>
using namespace std;
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,m,n,x;
    vector<int>a;
    cin >> n >> m;
    a.emplace_back(0);
    for(i=0;i<n;i++)
    {
        cin >> x;
        a.emplace_back(x);
    }
    stack<int>stk;
    for(i=1;i<n;i++)
    {
        if(a[i] > a[i+1])stk.emplace(a[i]-a[i+1]);
        else if(a[i] < a[i+1])
        {
            x=a[i+1]-a[i];
            if(!stk.empty()  &&  stk.top() >= x)
            {
                stk.top()-=x;
                if(!stk.top())stk.pop();
            }
            else
            {
                if(!stk.empty())
                {
                    x-=stk.top();
                    stk.pop();
                }
                if(x <= m)m-=x;
                else
                {
                    cout << "NO";
                    return 0;
                }
            }
        }
    }
    cout << "YES";
    return 0;
}