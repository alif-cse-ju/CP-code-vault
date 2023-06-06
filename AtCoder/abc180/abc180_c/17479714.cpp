#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,rt;
    long long n;
    set<long long>st;
    cin >> n;
    rt=sqrt(n);
    for(i=1;i<=rt;i++)
    {
        if(n%i == 0)
        {
            st.insert(i);
            st.insert(n/i);
        }
    }
    for(long long it : st)cout << it << '\n';
    return 0;
}
