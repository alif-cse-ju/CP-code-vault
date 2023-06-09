#include<bits/stdc++.h>
using namespace std;
char c[100010];
vector<int>mark;
int main()
    mark.clear();
    int left,right,i,j,k,length,m,cnt,low,high,mid,check,check1,check2,valid;
    scanf("%s",&c);
    length=strlen(c);
    for(i=1; i<length; i++)
    {
        if(c[i] == c[i-1])
        {
            mark.push_back(i);
        }
    }
    valid=mark.size();
    scanf("%d",&m);
    for(i=0; i<m; i++)
    {
        scanf("%d %d",&left,&right);
        if(valid == 0)
        {
            printf("0\n");
        }
        else
        {
            check2=-1,check1=0;
            low=0,high=valid-1;
            check=left;
            while(low<=high)
            {
                mid=(low+high)/2;
                if(mark[mid]>=check && (mark[mid-1]<check || mid == 0))
                {
                    check1=mid;
                    break;
                }
                else if(mark[mid]<check)
                {
                    low=mid+1;
                }
                else
                {
                    high=mid-1;
                }
            }
            low=0,high=valid-1;
            check=right-1;
            while(low<=high)
            {
                mid=(low+high)/2;
                if(mark[mid]<=check && (mark[mid+1]>check || mid == valid-1))
                {
                    check2=mid;
                    break;
                }
                else if(mark[mid]<check)
                {
                    low=mid+1;
                }
                else
                {
                    high=mid-1;
                }
            }
            cnt=check2-check1+1;
            printf("%d\n",cnt);
        }
    }
    return 0;
}