// 5639_이진검색트리.cpp
using namespace std;
#include <iostream>
#define MAX 10001

int preorder[MAX];

struct node {
	int data;
	node* left;
	node* right;
};

node* root;

int cnt = 0; // 노드 개수
void buildTree(int num) {
	/* 새 노드 생성 */
	node* newNode = new node[1];
	newNode->data = num;
	newNode->left = NULL;
	newNode->right = NULL;

	// 노드 수가 0이면 root 노드로 지정
	if (cnt == 0) root = newNode; 
	else {
		node* temp = root;
		while (true) {
			if (temp->data < num) { // 부모값보다 자식값이 클 때
				if (temp->right == NULL) {
					temp->right = newNode;
					break;
				}
				temp = temp->right;
			}
			else { // 부모값이 자식값보다 클 때
				if (temp->left == NULL) {
					temp->left = newNode;
					break;
				}
				temp = temp->left;
			}
		}
	}
	cnt++; // 노드 수 증가

	return;
}

void postorder(node *r) {
	if (r->left) postorder(r->left);
	if (r->right) postorder(r->right);
	printf("%d\n", r->data);
}

int main() {
	int num;
	// EOF가 나올 때까지 입력받음
	while (scanf(" %d", &num) != EOF) {
		buildTree(num);
	}

	postorder(root);
	
	return 0;
}
