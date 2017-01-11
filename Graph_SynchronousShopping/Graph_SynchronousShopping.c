#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAXN 1001
#define MAXK 10
#define MAXM 2001
#define MAXMK 1<<MAXK
#define INF 987654321
typedef struct node {
	int nd;
	int mask;
	int next;
} NODE;
typedef struct gp {
	int nd;
	int cst;
} GP;
NODE que[MAXM];
int N,M,K,qtr,qhd,minC;
int fish_mask[MAXN];
GP graph[MAXN][MAXN];
int step[MAXN];
int shortest[MAXN][MAXMK];

int checkN(int nd, int mask)
{
	int sta;
	sta=qhd;
	while(sta!=-1){
		if(que[sta].nd==nd && que[sta].mask==mask)
			break;
		sta=que[sta].next;
	}
	return sta;
}
void enQ(int nd, int mask, int cost)
{
	int cknd;
	if(qtr<100){
			//printf("=================================>");
			printf("enQ>nd:%d,mask:%d,cost:%d\n",nd,mask,cost);
	}
	if(shortest[nd][mask]<=cost){
		return;
	}
	//printf("enQ>nd:%d,mask:%d\n",nd,mask);
	cknd=checkN(nd,mask);
	shortest[nd][mask]=cost;

	if(cknd==-1) {
		que[qtr].nd=nd;
		que[qtr].mask=mask;
		que[qtr].next=-1;
		if(qtr<100)
			printf("=enQ:>%d\n",que[qtr].nd);
		if(qtr!=0){
			que[qtr-1].next=qtr;
		}
		if(qhd==-1){
			qhd=qtr;
			//printf("enQ:qhd>%d\n",qhd);
		}
		qtr++;
	}
}
int minf(int a, int b)
{
	if(a<=b)
		return a;
	else
		return b;
}
int maxf(int a, int b)
{
	if(a>=b)
		return a;
	else
		return b;
}
void Dijk(int sta)
{
	int i,tNd,tMask,tmpN;
	enQ(sta,fish_mask[sta],0);
	while(qhd!=-1){
		tNd=que[qhd].nd;
		tMask=que[qhd].mask;
		//printf("qhd:%d->",qhd);
		qhd=que[qhd].next;
		//printf("%d\n",qhd);
		i=0;
		while(graph[tNd][i].nd != -1){
				//printf("graph[%d][%d]=%d\n",tNd,i,graph[tNd][i]);
				tmpN=graph[tNd][i].nd;
				if(qtr<100)
					printf("tNd: %d, tMask: %d, tmpN: %d,qtr:%d\n",tNd,tMask,tmpN,qtr);

				enQ(tmpN,fish_mask[tmpN]|tMask,shortest[tNd][tMask]+graph[tNd][i].cst);
				i++;
		}
	}
}
void init()
{
	int i,j;
	for(i=0;i<=N;i++){
		fish_mask[i]=0;
		step[i]=0;
		for(j=0;j<MAXMK;j++){
			if(j<=N){
				graph[i][j].nd=-1;
				graph[i][j].cst=-1;
			}
			shortest[i][j]=INF;
		}
	}
	for(i=0;i<=M;i++){
		que[i].nd=0;
		que[i].mask=0;
		que[i].next=-1;
	}
	qtr=0;qhd=-1;
	minC=INF;
}
int main() {
	int i,j,T;
	int tx,ty,tz,tm;
	scanf("%d %d %d",&N,&M,&K);
	init();
	for(i=1;i<=N;i++){
		scanf("%d",&T);
		for(j=0;j<T;j++){
			scanf("%d",&tm);
			fish_mask[i]|=1<<(tm-1);
		}
	}
	for(i=0;i<M;i++){
		scanf("%d %d %d",&tx,&ty,&tz);
		if((tx==21) | (ty==21))
			printf("---tx:%d, ty:%d----\n",tx,ty);
		graph[tx][step[tx]].nd=ty; graph[tx][step[tx]].cst=tz;
		graph[ty][step[ty]].nd=tx; graph[ty][step[ty]].cst=tz;
		step[tx]++;
		step[ty]++;
	}
	printf("Step[21]:%d\n",step[21]);
	for(i=0;i<5;i++)
		printf("[%d] %d\n",i,graph[21][i].nd);
	Dijk(1);
	for(i=0;i<(1<<K);i++){
		for(j=i;j<(1<<K);j++){
			if((i|j)==((1<<K)-1)){
				if(i==161 && j==862)
					printf("i:%d,j:%d\n",shortest[N][i],shortest[N][j]);
				minC=minf(minC,maxf(shortest[N][i],shortest[N][j]));
			}
		}
	}
	printf("QTR: %d\n",qtr);
	printf("%d\n",minC);
    return 0;
}
