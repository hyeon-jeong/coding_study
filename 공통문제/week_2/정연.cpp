#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
vector<vector<int> >answer(2);

typedef struct Node{
    int data, x, y;
    struct Node *left;
    struct Node *right;
}Node;

bool sorting(Node &a, Node &b){
    if (a.y == b.y)
        return a.x < b.x;
    return a.y > b.y;
}

void insertNode(Node *p, Node *newnode){
    if (p->x > newnode->x){
        if(p->left == NULL)
            p->left = newnode;
        else{
            insertNode(p->left, newnode);
        }
    }
    else{
        if (p->right == NULL)
            p->right = newnode;
        else{
            insertNode(p->right, newnode);
        }
    }
}

void preorder(Node *root){
    if (root){
        answer[0].push_back(root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node *root){
    if (root){
        postorder(root->left);
        postorder(root->right);
        answer[1].push_back(root->data);
    }
}

vector<vector<int> > solution(vector<vector<int> > nodeinfo) {
    vector<Node> nodes;
    struct Node temp;

    for (int i=0; i<nodeinfo.size(); i++){
        temp.data = i+1;
        temp.x = nodeinfo[i][0];
        temp.y = nodeinfo[i][0];
        nodes.push_back(temp);
    }
    sort(nodes.begin(), nodes.end(), sorting);

    Node *root = &nodes[0];
    for (int i=1; i<nodeinfo.size(); i++){
        insertNode(root, &nodes[i]);
    }

    preorder(root);
    postorder(root);
    return answer;
}
