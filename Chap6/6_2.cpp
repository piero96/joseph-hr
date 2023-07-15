#include <iostream>
#include <vector>
using namespace std;

void printPicked(vector<int>& picked){
    vector<int>::iterator it;
    //cout << "Test" << endl;

    for(it=picked.begin(); it!=picked.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}
void pick(int n, vector<int>& picked, int toPick){
    if(toPick==0) { printPicked(picked); return; }
    int smallest = picked.empty() ? 1:picked.back() + 1;

    for(int next=smallest; next<n; ++next){
        picked.push_back(next);
        pick(n, picked, toPick-1);
        picked.pop_back();
    }
}

int main(void){
    vector<int> picked;
    int n;
    n = 7;
    pick(n,picked,3);

    return 0;
}