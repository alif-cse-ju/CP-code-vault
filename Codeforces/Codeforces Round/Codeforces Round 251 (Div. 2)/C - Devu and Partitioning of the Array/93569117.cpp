#include<bits/stdc++.h>
using namespace std;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,k,n,p,x,o=0,e=0;
    vector<int>odd,even;
    cin >> n >> k >> p;
    for(i=0;i<n;i++)
    {
        cin >> x;
        if(x & 1)
        {
            ++o;
            odd.emplace_back(x);
        }
        else
        {
            ++e;
            even.emplace_back(x);
        }
    }
    if(o < k-p  ||  (o-k+p) & 1  ||  e+(o-k+p)/2 < p)cout << "NO";
    else
    {
        cout << "YES\n";
        for(i=0;i<p &&  !even.empty();i++)
        {
            if(i == k-1)break;
            else cout << "1 " << even.back() << '\n';
            even.pop_back();
        }
        if(i < k-1)
        {
            x=k-p;
            while(x--)
            {
                if(i == k-1)
                {
                    i++;
                    break;
                }
                i++;
                cout << "1 " << odd.back() << '\n';
                odd.pop_back();
            }
        }
        for( ;i<k;i++)
        {
            if(i == k-1)break;
            else
            {
                cout << "2 " << odd.back();
                odd.pop_back();
                cout << ' ' << odd.back() << '\n';
                odd.pop_back();
            }
        }
        cout << even.size()+odd.size();
        while(!even.empty())
        {
            cout << ' ' << even.back();
            even.pop_back();
        }
        while(!odd.empty())
        {
            cout << ' ' << odd.back();
            odd.pop_back();
        }
    }
    return 0;
}