#include<bits/stdc++.h>
using namespace std;
vector<pair<char,int> >v;
pair<char,int>temp;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int i,l,mark=-1,cnt=0;
    string s;
    cin >> s;
    l=s.size();
    for(i=0; i<l; i++)
    {
        if(s[i] != 'a')
        {
            temp.first=s[i];
            temp.second=i;
            v.push_back(temp);
        }
        else
        {
            mark=i+1;
            cnt++;
        }
    }
    if(v.size() == 0)
    {
        cout << s;
    }
    else if(mark > (l-mark+cnt))
    {
        cout << ":(" ;
    }
    else
    {
        l=v.size();
        if(l%2 == 1)
        {
            cout << ":(" ;
        }
        else if(mark == -1)
        {
            for(i=0; i<l/2; i++)
            {
                if(v[i].first != v[l/2+i].first)
                {
                    cout << ":(" ;
                    return 0;
                }
            }
            for(i=0;i<l/2;i++)
            {
                cout << v[i].first;
            }
        }
        else
        {
            l/=2;
            for(i=0; i<l; i++)
            {
                if(v[i].first != v[l+i].first)
                {
                    cout << ":(" ;
                    return 0;
                }
            }
            l=v[l-1].second;
            for(i=0; i<=l; i++)
            {
                cout << s[i];
            }
            i=l+1;
            while(s[i] == 'a')
            {
                cout << 'a';
                i++;
            }
        }
    }
    return 0;
}