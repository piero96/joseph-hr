#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int N,M;
int arr[50];
long long dp[251][251];
long long count;
long long dfs(int sum,int num)
{
   long long ret=0;
   if(sum<0)
	   return 0;
   else if(sum==0)
	   return 1;

   for(int i=0;i<M;i++)
   {
	   if(arr[i]<num || sum-arr[i]<0)
		   continue;
       if(dp[sum-arr[i]][arr[i]]==-1)
       {
          dp[sum-arr[i]][arr[i]]= dfs(sum-arr[i],arr[i]);
       }
	   ret+=dp[sum-arr[i]][arr[i]];
   }

   return ret;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d %d",&N,&M);
    for(int i=0;i<M;i++)
    {
        scanf("%d",&arr[i]);
    }
    count = 0;
    for(int j=0;j<251;j++)
        for(int k=0;k<251;k++)
            dp[j][k]=-1;
    count = dfs(N,0);
    printf("%lld\n",count);
    return 0;
}
