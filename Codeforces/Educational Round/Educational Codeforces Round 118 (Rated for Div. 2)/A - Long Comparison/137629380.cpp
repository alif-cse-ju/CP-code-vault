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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s1,s2;
    int i,l1,l2,p1,p2,t;
    cin >> t;
    while(t--)
    {
        cin >> s1 >> p1 >> s2 >> p2;
        l1=(int)s1.size();
        l2=(int)s2.size();
        if(l1+p1 > l2+p2)cout << ">\n";
        else if(l1+p1 < l2+p2)cout << "<\n";
        else
        {
            while(l1 < l2)++l1, s1 += '0';
            while(l2 < l1)++l2, s2 += '0';
            for(i=0;i<l1;i++)
            {
                if(s1[i] > s2[i])
                {
                    cout << ">\n";
                    break;
                }
                else if(s1[i] < s2[i])
                {
                    cout << "<\n";
                    break;
                }
            }
            if(i == l1)cout << "=\n";
        }
    }
    return 0;
}