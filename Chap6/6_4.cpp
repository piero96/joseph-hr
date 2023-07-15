// 1. 같은 학생을 두 번 짝지어 줍니다.
//    (0,1), (1,0)
// 2. 다른 순서로 학생들을 짝지어 주는 것을 서로 다른 경우로 세고 있습니다.
//    (0,1)-->(2,3), (2,3)-->(0,1)

int n;
bool areFriends[10][10];

int countPairlings(bool taken[10]){
    bool finished = true;
    for(int i=0;i<n;++i) if(!taken[i]) finished=false;
    if(finished) return 1;
    int ret = 0;

    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(!taken[i] && !taken[j] && areFirends[i][j]){
                taken[i] = taken[j] = true;
                ret += countPairlings(taken);
                taken[i] = taken[j] = false;
            }
        }
    }
    return ret;
}