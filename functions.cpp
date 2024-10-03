#include <iostream>
#include "functions.h"
#include <queue>
using namespace std;
TreeNode ::TreeNode(int v){
data=v;
left=nullptr;
right=nullptr;
}
 TreeNode* TreeNode :: getLeftChild(){
return left;
 }
 TreeNode* TreeNode :: getRightChild(){
return right;
 }
 int TreeNode :: getData(){
return data;
 }
 //add left child
 void TreeNode ::addLeftChild(TreeNode* node){
     if (left==nullptr)
     {
        left=node;
        return;
     }
     delete left;
     left=node;
 }
 // add right child
 void TreeNode :: addRightChild(TreeNode* node){
       if (right==nullptr)
       {
           right=node;
           return;
       }
       delete right;
       right=node;
       
 }
  Tree::Tree(){
     root=nullptr;
    }
// insert
 void Tree:: insertNode(int value){
     TreeNode* p=new TreeNode(value);
if (root==nullptr)
{
    root=p;
    return;
}
queue<TreeNode*>t;
t.push(root);
while (!t.empty())
{
    TreeNode *aval=t.front();
    t.pop();
    if (aval->left==nullptr)
    {
        aval->left=p;
        return;
    }
    else
    {
        t.push(aval->left);
    }
    if (aval->right==nullptr)
    {
        aval->right=p;
        return;
    }
    else
    {
        t.push(aval->right);
    }
    
    
}


 }
 
 void Tree:: printTree(){
if (root==nullptr)
{
    return;
}
queue<TreeNode*>t;
t.push(root);
while (!t.empty())
{
    TreeNode *aval=t.front();
    t.pop();
    cout<<aval->data;
    if (aval->left)
    {
        t.push(aval->left);
    }
    
    if (aval->right)
    {
        t.push(aval->right);
    }
 }
 }
 
 int Tree:: getDegree(int data){
        TreeNode* aval = root;
        queue<TreeNode*> q;
        q.push(aval);

        while (!q.empty()) {
            aval = q.front();
            q.pop();

            if (aval->data == data) {
                int degree = 0;
                if (aval->left) 
                {
                    degree++;
                }
                if (aval->right) {
                    degree++;
                }
                return degree;
            }

            if (aval->left)
            {
                q.push(aval->left);
            }
            if (aval->right) 
            {
                q.push(aval->right);
            }
        }
        return -1; 
    }
   
 int Tree:: getHeight(int data){
    TreeNode* ch=new TreeNode(data);
if (root == nullptr) {
        return -1; 
    }
    if (root == ch) {
        return 0; 
    }
    int height = 0;
    queue<TreeNode*> t;
    t.push(root);
    while (!t.empty()) {
        TreeNode* check = t.front();
        int nodeCount = t.size(); 
            height++;
     if(check==ch){
                return height;
            }
            else
            {
        while (nodeCount > 0) {
            TreeNode* aval = t.front();
           
                t.pop();

            if (aval->left) {
                t.push(aval->left);
            }
            if (aval->right) {
                t.push(aval->right);
            }
            nodeCount--;
        }
        }
    }
    return height-=1;

 }
 int Tree::getTreeHeight() {
    if (root == nullptr) {
        return -1; 
    }
    int height = 0;
    queue<TreeNode*> t;
    t.push(root);
    while (!t.empty()) {
        int nodeCount = t.size();
        height++;
        while (nodeCount > 0) {
            TreeNode* aval = t.front();
            t.pop();

            if (aval->left) {
                t.push(aval->left);
            }
            if (aval->right) {
                t.push(aval->right);
            }
            nodeCount--;
        }
    }
    return height-=1; 
}

    TreeNode* Tree:: findNode(int data) {
       TreeNode* aval = root;
        queue<TreeNode*> q;
        q.push(aval);

        while (!q.empty()) {
            aval = q.front();
            q.pop();

            if (aval->data == data) {
                return aval;
            }

            if (aval->left) q.push(aval->left);
            if (aval->right) q.push(aval->right);
        }
        return nullptr;
    }
 TreeNode* Tree::getRoot(){
return root;
 }