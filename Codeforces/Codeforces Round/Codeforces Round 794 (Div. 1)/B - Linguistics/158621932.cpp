#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=2e6+5;
const int mod=998244353;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int a,b,c,d;cin >> a >> b >> c >> d;
        string s;cin >> s;
        int A=0,B=0;
        for(char &c : s)
        {
            A += (c == 'A');
            B += (c == 'B');
        }
        if(A != a+c+d  ||  B != b+c+d)cout << "NO\n";
        else
        {
            int AB=0, BA=0;
            for(int i=0;i+1<(int)s.size();i++)
            {
                if(s[i] == 'A'  &&  s[i+1] == 'B')++AB;
                else if(s[i] == 'B'  &&  s[i+1] == 'A')++BA;
            }
            if(AB < c  ||  BA < d)cout << "NO\n";
            else
            {
                s="@"+s, AB=BA=0;
                int l=(int)s.size()-1;
                vector<int>ab,ba,odd;
                for(int i=1;i<=l;)
                {
                    int j;
                    for(j=i+1;j<=l  &&  s[j] != s[j-1];j++);
                    if(j-i > 1)
                    {
                        if((j-i) & 1)odd.emplace_back(j-i);
                        else
                        {
                            if(s[i] == 'A')ab.emplace_back(j-i);
                            else ba.emplace_back(j-i);
                        }
                    }
                    i=j;
                }
                 sort(ab.begin(),ab.end()), sort(ba.begin(),ba.end());
                reverse(ab.begin(),ab.end()), reverse(ba.begin(),ba.end());
                 while(AB < c  &&  !ab.empty())
                {
                    int x=ab.back();
                    if(x/2 <= c-AB)AB+=x/2, ab.pop_back();
                    else ab.back()-=(c-AB)*2, AB=c;
                }
                while(BA < d  &&  !ba.empty())
                {
                    int x=ba.back();
                    if(x/2 <= d-BA)BA+=x/2, ba.pop_back();
                    else ba.back()-=(d-BA)*2, BA=d;
                }
                 while(AB < c  &&  !ba.empty())
                {
                    int x=ba.back();
                    if((x-1)/2 <= c-AB)AB+=(x-1)/2, ba.pop_back();
                    else AB=c;
                }
                while(BA < d  &&  !ab.empty())
                {
                    int x=ab.back();
                    if((x-1)/2 <= d-BA)BA+=(x-1)/2, ab.pop_back();
                    else BA=d;
                }
                 while(!odd.empty())
                {
                    int x=odd.back();odd.pop_back();
                    if(AB < c)
                    {
                        if(x/2 <= c-AB)AB+=x/2;
                        else x-=(c-AB)*2, AB=c, BA+=x/2;
                    }
                    else BA+=x/2;
                }
                 if(AB >= c  &&  BA >= d)cout << "YES\n";
                else cout << "NO\n";
            }
        }
    }
    return 0;
}