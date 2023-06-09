#include<bits/stdc++.h>
using namespace std;
int node[(1 << 17)*2+5];
void update(int node_num,int value)
    node[node_num]=value;
    bool flag=1;
    while(node_num > 0)
    {
        node_num/=2;
        if(flag == 1)
        {
            node[node_num]=node[node_num*2] | node[node_num*2+1];
            flag=0;
        }
        else
        {
            node[node_num]=node[node_num*2] ^ node[node_num*2+1];
            flag=1;
        }
    }
int main()
    int i,n,q,x;
    scanf("%d %d",&n,&q);
    int node_num=1 << n;
    for(i=0; i<node_num; i++)
    {
        scanf("%d",&x);
        update(node_num+i,x);
    }
    for(i=1; i<=q; i++)
    {
        scanf("%d %d",&n,&x);
        update(node_num+n-1,x);
        printf("%d\n",node[1]);
    }
    return 0;
}