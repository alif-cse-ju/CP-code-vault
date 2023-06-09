#include<bits/stdc++.h>
using namespace std;
struct node
    int cnt;
    int mark[26];
    node()
    {
        cnt=0;
        memset(mark,-1,sizeof(mark));
    }
int avail_node,current;
string s;
node tree[600001];
int build_tree()
    int i,current=0,l=s.size();
    for(i=0;i<l;i++)
    {
        int check=s[i]-'a';
        if(tree[current].mark[check] == -1)
        {
            tree[current].mark[check]=++avail_node;
        }
        current=tree[current].mark[check];
    }
    tree[current].cnt++;
    return tree[current].cnt;
int main()
    int i,n;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        cin >> s;
        int ans=build_tree();
        if(ans == 1)
        {
            printf("OK\n");
        }
        else
        {
            cout << s << (ans-1) << endl;
        }
    }
    return 0;
}