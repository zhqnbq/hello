#include<bits/stdc++.h>
#define int long long
#define %d %lld
using namespace std;
struct node {
	int p;
	bool gender;//0m1f
	int s;//0->50
	int longScore;//second
	bool passedTest;
	int f;
	int c;
	int lastValidTimeStamp;//上次有效时间戳
	int score;
	int validSunCnt;
} data[10001];
map<int,int> IDtoStructID;
int p;
char gen;
int s;
int min,sec;
char testP;
int f,c;
int splm(int date){
	return ((date/1000)%10)*10+(date/100));
}
int spld(int date){
	return ((date/10)%10)*10+(date%10);
}
int _month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int getTimeStamp(int month,int day,int sth,int stm,int sts){
	unsigned int ret=0;
	for(int i=1;i<month;i++){
		ret+=(_month[i]*86400);
	}
	ret+=(day-1)*86400;
	ret=ret+(sth*3600)+(stm*60)+sts;
	return ret;
}
void check(int date,int p,int h1,int m1,int s1,
           int h2,int m2,int s2,int l,
           int stm,int sts,int s) {
    int month=splm(date);
    int day=spld(date);
    int stTS=getTimeStamp(month,day,h1,m1,s1);
    int edTS=getTimeStamp(month,day,h2,m2,s2);
}
signed main() {
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>data[i].p>>gen>>data[i].s;
		data[i].gender=(gen=='M'?0:1);
		scanf("%d'%d\"",&min,&sec);
		data[i].longScore=min*60+sec;
		cin>>testP;
		data[i].passedTest=(testP=='P' ? true : false);
		cin>>data[i].f>>data[i].c;
		IDtoStructID[data[i].p]=i;
		data[i].lastValidTimeStamp=-1145141919;
	}
	int m;
	cin>>m;
	int date,p,h1,m1,s1,h2,m2,s2;
	float l;
	int stm,sts;
	int s;
	for(int i=1; i<=m; i++) {
		cin>>date>>p;
		scanf("%d:%d:%d",&h1,&m1,&s1);
		scanf("%d:%d:%d",&h2,&m2,&s2);
		cin>>l;
		scanf("%d'%d\"",&stm,&sts);
		cin>>s;
		check(date,p,h1,m1,s1,h2,m2,s2,l,stm,sts,s);
	}
	return 0;
}
