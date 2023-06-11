#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k.
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
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
    string s;
    int i,l;
    cin >> s;
    l=(int)s.size();
    for(i=0;i<l;i++)
    {
        if(s[i] == 'A')continue;
        if(s[i] == 'H')continue;
        if(s[i] == 'I')continue;
        if(s[i] == 'M')continue;
        if(s[i] == 'O')continue;
        if(s[i] == 'T')continue;
        if(s[i] == 'U')continue;
        if(s[i] == 'V')continue;
        if(s[i] == 'W')continue;
        if(s[i] == 'X')continue;
        if(s[i] == 'Y')continue;
        cout << "NO";
        return 0;
    }
    for(i=0;i<l/2;i++)
    {
        if(s[i] != s[l-i-1])
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}