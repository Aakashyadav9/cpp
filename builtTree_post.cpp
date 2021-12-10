//built tree from postorder and inorder
#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *left;
    struct node *right;
    
    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

int search(int inorder[], int start, int end, int curr){
    for(int i=start; i<=end; i++){
        if(inorder[i] == curr){
            return i;
        }
    }
    return -1;
}

node* buildTree(int postorder[], int inorder[], int start, int end){
    static int idx = end;
    //base case
    if(start>end){
        return NULL;
    }
    
    int curr = postorder[idx];
    idx--;
    
    node* root = new node(curr);
    //if only one element
    if(start == end){
        return root;
    }
  
    int pos = search(inorder, start, end, curr);
    root->right = buildTree(postorder, inorder, pos+1, end);
    root->left = buildTree(postorder, inorder, start, pos-1);
  
    
    return root;
}

void printInorder(node* mroot){
    //base condition
    if(mroot == NULL){
        return;
    }

    printInorder(mroot->left);
    cout<<mroot->data<<" ";
    printInorder(mroot->right);
}

int main(){
    
    int postorder[] = {4,2,5,3,1};
    int inorder[] = {4,2,1,5,3};
    
    node* mroot = buildTree(postorder, inorder, 0, 4);
    printInorder(mroot);
    
    return 0;
}
