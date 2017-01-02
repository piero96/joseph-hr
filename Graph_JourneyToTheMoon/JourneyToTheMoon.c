#include<stdio.h>
#include<stdlib.h>
#define MAX_N 100000

typedef struct node {
	int grp_id;
	int head;
	int next;
} NODE;
NODE astro[MAX_N];

int change_group(int head,int id, int hd)
{
	int cnt_mem,prev_mem;
	cnt_mem=head;
	do{
		astro[cnt_mem].grp_id=id;
		astro[cnt_mem].head=hd;
		prev_mem=cnt_mem;
		cnt_mem = astro[cnt_mem].next;
	}while(cnt_mem != -1);

	return prev_mem;
}

int main()
{
    int n,l,i,j,grp_num;
    int tmp1,tmp2,tmp;
    int a1,a2,mem_last,head_prev,id_prev;
    int grp_hd[MAX_N];

    scanf("%d %d",&n,&l);
    //printf("n:%d,l:%d\n",n,l);
    if(n==1)
    {
        printf("0\n");
        return(0);
    }
    int **pairs=(int**)malloc(sizeof(int*)*l);
    for(i=0;i<l;i++)
        pairs[i]=(int*)calloc(2,sizeof(int));

    long long int ans,cnt_1_groups,cnt_2_groups;
    ans=cnt_1_groups=cnt_2_groups=0;

    /** Write code to compute answer using n,l,pairs**/
    for(j=0;j<l;j++)
    {
    	scanf("%d %d",&tmp1,&tmp2);
    	if(tmp1>tmp2)
    	{
    		tmp=tmp1;
    		tmp1=tmp2;
    		tmp2=tmp;
    	}
    	pairs[j][0]=tmp1;pairs[j][1]=tmp2;
    }

    for(i=0;i<n;i++)
    {
    	astro[i].grp_id=-1;
    	astro[i].head=-1;
    	astro[i].next=-1;
    	grp_hd[i]=-1;
    }
    grp_num=0;

    for(j=0;j<l;j++)
    {
    	a1=pairs[j][0];a2=pairs[j][1];
    	//printf("-----a1:%d,a2:%d-------\n",a1,a2);
    	if((astro[a1].grp_id == -1) && (astro[a2].grp_id == -1))
    	{
    		astro[a1].grp_id=grp_num;
    		astro[a1].head = a1;
    		astro[a1].next = a2;

    		astro[a2].grp_id=grp_num;
    		astro[a2].head=a1;
    		astro[a2].next=-1;
    		grp_hd[grp_num]=2;
    		grp_num++;
    		//printf("grp_id:%d\n",astro[a1].grp_id);
    	}
    	else if((astro[a1].grp_id != -1) && (astro[a2].grp_id == -1))
    	{
    		astro[a2].grp_id=astro[a1].grp_id;
    		astro[a2].head=astro[a1].head;
    		astro[a2].next=astro[a1].next;
    		astro[a1].next=a2;
    		//printf("a1:%d,a2:%d,grpA1:%d\n",a1,a2,grp_hd[astro[a1].grp_id]);
    		grp_hd[astro[a1].grp_id]++;
    	}
    	else if((astro[a1].grp_id == -1) && (astro[a2].grp_id != -1))
    	{
    		astro[a1].grp_id=astro[a2].grp_id;
    		astro[a1].head=astro[a2].head;
    		astro[a1].next=astro[a2].next;
    		astro[a2].next=a1;
    		grp_hd[astro[a2].grp_id]++;
    	}
    	else // two groups
    	{
    		if(astro[a1].grp_id > astro[a2].grp_id)
    		{
    			tmp=a1;
    			a1=a2;
    			a2=tmp;
    		}
    		else if(astro[a1].grp_id == astro[a2].grp_id)
    		{
    			continue;
    		}
    		head_prev = astro[a2].head;
    		id_prev = astro[a2].grp_id;

    		mem_last = change_group(astro[a2].head,astro[a1].grp_id,astro[a1].head);
    		astro[mem_last].next = astro[a1].next;
    		astro[a1].next = head_prev;
    		//printf("A:%d, B:%d\n",astro[a1].head,head_prev);
    		//printf("grpA(%d):%d, grpB(%d):%d\n",astro[a1].grp_id,grp_hd[astro[a1].grp_id],id_prev,grp_hd[id_prev]);
    		grp_hd[astro[a1].grp_id]+=grp_hd[id_prev];
    		grp_hd[id_prev]=-1;
    	}
    	//printf("GRP:%d,%d\n",grp_hd[0],grp_hd[1]);
    }

    for(i=0;i<n;i++)
    {
    	if(grp_hd[i]>0)
    	{
    		cnt_1_groups+=grp_hd[i];
    	}
    	if(astro[i].grp_id == -1)
    	{
    		cnt_2_groups++;
    	}
    }
    ans=cnt_1_groups*cnt_2_groups + cnt_2_groups*(cnt_2_groups-1)/2;

    //printf("cnt_1:%lld,cnt_2:%lld,ans1:%lld\n",cnt_1_groups,cnt_2_groups,cnt_2_groups*(cnt_2_groups-1)/2);
    tmp=0;
    for(i=0;i<n-1;i++)
    {
    	if(grp_hd[i]>0)
    	{
    		tmp+=grp_hd[i];
    		ans+=grp_hd[i]*(cnt_1_groups-tmp);
    	}
    }
    printf("%lld\n",ans);
    return(0);
}
