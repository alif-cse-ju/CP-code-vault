#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))

#define PI acos(-1)
#define ll long long

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a=0,b=0;
    string s;
    deque<char>dq;
    cin >> s;
    for(char c : s)dq.emplace_back(c);
    while(!dq.empty()  &&  dq.front() == 'a')dq.pop_front(), ++a;
    while(!dq.empty()  &&  dq.back() == 'a')dq.pop_back(), ++b;
    if(a < (int)s.size()  &&  a > b)
    {
        cout << "No";
        return 0;
    }
    while((int)dq.size() > 1)
    {
        if(dq.front() == dq.back())
        {
            dq.pop_front(), dq.pop_back();
        }
        else
        {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}
