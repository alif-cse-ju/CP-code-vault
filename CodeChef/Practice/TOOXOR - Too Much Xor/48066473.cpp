#include<bits/stdc++.h>
using namespace std;
const int M=1e4+5;
int a[M];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,p,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1; i<=n; i++)cin >> a[i];
        for(i=1; i<=n  &&  !a[i]; i++);
        if(i > n)
        {
            if(n == 1)cout << "0\n";
            else cout << "-1\n";
            continue;
        }
        if(n == 2)
        {
            if(a[1] != a[2])cout << "0\n";
            else cout << "-1\n";
        }
        else
        {
            if(n == 3)
            {
                if(a[1] == a[2]  &&  a[2] == a[3])cout << "1\n1 3 2\n";
                else if(a[1] == a[3])cout << "0\n";
                else if(!a[2])
                {
                    cout << "1\n";
                    if(a[1])cout << "1 2 3\n";
                    else cout << "3 2 1\n";
                }
                else cout << "-1\n";
            }
            else
            {
                for(i=2; i<=n && a[i] == a[1]; i++);
                vector<tuple<int,int,int>>ans;
                if(i > n)
                {
                    for(i=2; i<=n; i+=2)ans.emplace_back(make_tuple(1,3,i));
                }
                else
                {
                    p=i;
                    for(i=2; i<=n; i+=2)
                    {
                        if(i == p)continue;
                        ans.emplace_back(make_tuple(1,p,i));
                    }
                    if(!(p%2))
                    {
                        if(p == 2)
                        {
                            ans.emplace_back(make_tuple(1,4,3));
                            ans.emplace_back(make_tuple(2,3,1));
                            ans.emplace_back(make_tuple(1,4,2));
                        }
                        else
                        {
                            ans.emplace_back(make_tuple(1,2,3));
                            ans.emplace_back(make_tuple(p,3,1));
                            ans.emplace_back(make_tuple(1,2,p));
                        }
                    }
                    for(i=1; i<=n; i+=2)ans.emplace_back(make_tuple(2,4,i));
                }
                cout << (int)ans.size() << '\n';
                for(auto [x,y,z] : ans)cout << x << ' ' << y << ' ' << z << '\n';
            }
        }
    }
    return 0;
}