#include<bits/stdc++.h>

using namespace std;

#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main()
{
    FAST();
    int i,n,x,y;
    cin >> n;
    set<int>st;
    for(i=0;i<n;i++)
    {
        cin >> x;
        st.insert(x);
    }
    while(st.size() > 1)
    {
        x=*(st.begin());
        y=*(--st.end());
        st.erase(y);
        st.insert(y-x);
    }
    cout << *(st.begin());
    return 0;
}
