//coin change by greedy approach
#include<bits/stdc++.h>
using namespace std;

int count(int S[], int n, int sum, int ind){
    //base case
    if(sum == 0){
        return 1;
    }
    if(ind>=n || sum < 0){
        return 0;
    }
    //check left subtree if include then reduce from sum
    int left = count(S, n, sum - S[ind], ind);
    //check right subtree if not include then increase index by 1
    int right = count(S, n ,sum, ind+1);
    int ans = left +right;
    return ans;
}

int main(){
    
    int S[] = {1,2,3};
    int n = 3;
    int sum = 4;
    int ind = 0;
    cout<<count(S,n,sum,ind)<<endl;
}
