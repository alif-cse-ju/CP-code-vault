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
    int i,l;
    string s1,s2;
    cin >> s1;
    l=(int)s1.size();
    for(i=0;i<l/3;i++)s2+="oxx";
    if(l%3 > 0)
    {
        if(l%3)s2+='o';
        if(l%3 > 1)s2+='x';
    }
    if(s1 == s2)
    {
        cout << "Yes";
        return 0;
    }
    for(i=1;i<l;i++)s2[i-1]=s2[i];
    s2.pop_back();
    if(l%3)s2+='x';
    if(s1 == s2)
    {
        cout << "Yes";
        return 0;
    }
    for(i=1;i<l;i++)s2[i-1]=s2[i];
    s2.pop_back();
    if(l%3)
    {
        if(l%3 == 1)s2+='x';
        else s2+='o';
    }
    if(s1 == s2)
    {
        cout << "Yes";
        return 0;
    }
    cout << "No";
    return 0;
}
