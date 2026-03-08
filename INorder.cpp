#include <iostream>
#include<vector>
using namespace std;

class Node{
    
    public :
    
    int data;
    Node* left;
    Node* right;
    
    Node(int val){
        
        data = val;
        left = right = NULL;
        
    }
};

static int idx = -1 ;

Node* bulidTree(vector<int> &preorder){
    
    idx++;
    
    if(INorder[idx] == -1){
        return NULL;
    }
    
    Node* root = new Node(INorder[idx]);
    
    root->left = bulidTree(preorder);
    root->right = bulidTree(preorder);
    
    return root;
}

void INorder(Node* root){
    
    if(root == NULL){
        
        return ;
    }
    
    INorder(root->left);
    
    cout<<root->data<<" "<<endl;
    
    
    INorder(root->right);
    
    
    
    
}

                  


int main(){
    
    vector<int> preOrder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    
    Node* root = bulidTree(preOrder);
    
    INorder(root);
    // cout<<root->data<<endl;
    // cout<<root->left->data<<endl;
    // cout<<root->right->data<<endl;
    return 0;
}
