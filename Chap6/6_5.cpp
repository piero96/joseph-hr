//같은 답 중에 사전순으로 가장 먼저 오는 답 하나만을 세는 것
#include <iostream>
using namespace std;

int n;
bool areFriends[10][10];

int countPairings(bool taken[10]){
    int firstFree = -1;
    for(int i=0; i<n; ++i){
        if(!taken[i]){
            firstFree = i;
            break;
        }
    }

    if(firstFree == -1){
        cout << "done" << endl; 
    }
    int ret = 0;

    for(int pairWith = firstFree+1; pairWith<n; ++pairWith){
        if(!taken[pairWith] && areFriends[firstFree][pairWith]){
            taken[firstFree] = taken[pairWith] = true;
            cout << firstFree << "," << pairWith << endl;
            ret += countPairings(taken);
            taken[firstFree] = taken[pairWith] = false;
        }
    }
    return ret;
}

int main(void){
    n = 4;
    bool tk[10] = {false};
    areFriends[1][4]=true;
    areFriends[1][2]=true;
    areFriends[2][3]=true;
    areFriends[3][4]=true;
    areFriends[2][3]=true;
    areFriends[1][3]=true;
    cout << countPairings(tk) << endl;
    return 0;
}