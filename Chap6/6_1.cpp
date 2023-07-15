int sum(int n){
    int ret = 0;
    for(int i=1; i<=n; ++i){
        ret += i;
    }
    return ret;
}

int recursiveSum(int n){
    if(n==1) return 1;
    return n + recursiveSum(n-1);
}