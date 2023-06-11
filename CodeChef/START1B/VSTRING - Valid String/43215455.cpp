#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int i,l,mx,t;
    cin >> t;
    while(t--)
    {
        cin >> l >> mx >> s;
        vector<int>pos;
        for(i=0;i<l;i++)
        {
            if(s[i] == '1')pos.emplace_back(i+1);
        }
        l=(int)pos.size();
        vector<int>dif;
        for(i=1;i<l;i++)dif.emplace_back(pos[i]-pos[i-1]-1);
        if((int)pos.size() > 1)dif.emplace_back((int)s.size()-pos.back()+pos[0]-1);
        sort(dif.begin(),dif.end());
        l=(int)dif.size();
        if((int)dif.size() > 1  &&  dif[l-2] > mx)cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}
//