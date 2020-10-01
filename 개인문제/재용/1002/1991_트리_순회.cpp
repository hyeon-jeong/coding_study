// 1991_트리_순회.cpp
using namespace std;
#include <iostream>
#define MAX 27

int n; // 노드 개수
struct node {
	char data;
	node* left;
	node* right;
};

node *tree;

void preorder(node *root) { // 전위 순회
	printf("%c", root->data);
	if (root->left) preorder(root->left);
	if (root->right) preorder(root->right);
}

void inorder(node *root) { // 중위 순회
	if (root->left) inorder(root->left);
	printf("%c", root->data);
	if (root->right) inorder(root->right);
}

void postorder(node *root) { // 후위 순회
	if (root->left) postorder(root->left);
	if (root->right) postorder(root->right);
	printf("%c", root->data);
}

int main() {
	scanf("%d", &n);

	tree = (node*)malloc(sizeof(node) * n);

	for (int i = 1; i <= n; i++) { // Build tree
		char data, left, right;
		scanf(" %c %c %c", &data, &left, &right);

		int data_num = data - 'A';
		tree[data_num].data = data;

		if (left == '.') tree[data_num].left = NULL;
		else tree[data_num].left = &tree[left - 'A'];

		if (right == '.') tree[data_num].right = NULL;
		else tree[data_num].right = &tree[right - 'A'];
	}

	// root는 항상 A == tree[0]
	preorder(&tree[0]); // 전순위
	printf("\n");
	inorder(&tree[0]); // 중순위
	printf("\n");
	postorder(&tree[0]); // 후순위
	printf("\n");

	return 0;
}
