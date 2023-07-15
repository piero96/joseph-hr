void pick(int n, vector<int>& picked, int toPick){
    if(toPick==0) { printPicked(picked); return; }
    int smallest = picked.empty() ? 0:picked.back() + 1;

    for(int next=smallest; next<n; ++next){
        picked.push_back(next);
        pick(n, picked, toPick-1);
        picked.pop_back(next);
    }
}