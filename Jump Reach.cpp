int Solution::canJump(vector<int> &A) {
    int minReach=A.size()-1;
    for(int i=A.size()-1;i>0;i--){
        if (A[i-1]+i-1>=minReach){
            minReach=i-1;
        }
    }
    if(minReach)
    return 0;
    else
    return 1;
}
