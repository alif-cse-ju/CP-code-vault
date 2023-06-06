#include<iostream>
using namespace std;
int N;
string T;
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};
main()
{
	cin>>N>>T;
	int r=0;
	int x=0,y=0;
	for(char c:T)
	{
		if(c=='R')r=(r+1)%4;
		else x+=dx[r],y+=dy[r];
	}
	cout<<x<<" "<<y<<endl;
}
