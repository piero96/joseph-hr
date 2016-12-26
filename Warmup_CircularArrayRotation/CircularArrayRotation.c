#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int n;
    int k;
    int q;
    scanf("%d %d %d",&n,&k,&q);
    int *a = malloc(sizeof(int) * n);
    for(int a_i = 0; a_i < n; a_i++){
       scanf("%d",&a[a_i]);
    }
    for(int a0 = 0; a0 < q; a0++){
        int m;
        scanf("%d",&m);
        printf("%d\n",a[(n-k%n+m)%n]);
    }
    return 0;
}
