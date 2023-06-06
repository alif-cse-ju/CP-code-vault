#include<bits/stdc++.h>

using namespace std;

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,l;
    string s;
    cin >> s;
    while(!s.empty()  &&  s.back() == '0')s.pop_back();
    l=(int)s.size();
    for(i=0;i<l;i++)
    {
        if(s[i] != s[l-i-1])
        {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}