#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
vector<int>mark;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int i,l;
    string s;
    cin >> l >> s;
    for(i=0;i<l;i++)
    {
        if(s[i] == '8')
        {
            mark.push_back(i);
        }
    }
    if(mark.size() == 0)
    {
        cout << "NO";
    }
    else if((l-11)/2 >= mark.size())
    {
        cout << "NO";
    }
    else
    {
        int check=mark[(l-11)/2];
        check=check-(l-11)/2;
        if(check > (l-11)/2)
        {
            cout << "NO" ;
            return 0;
        }
        cout << "YES";
    }
    return 0;
}