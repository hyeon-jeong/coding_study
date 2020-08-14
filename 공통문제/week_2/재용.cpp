// 2019_카카오_길_찾기_게임.cpp 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> answer(2); // 전순위, 후순위 결과를 저장할 벡터
// 전순위, 후순위 함수에 인자로 넣기 싫어서 전역변수로 설정함

typedef struct TreeNode { // 트리구조의 노드
	int num; // 노드 번호
	int x; // x 좌표
	int y; // y 좌표
	struct TreeNode *left, *right; // 왼쪽, 오른쪽 자식 노드 포인터
} TreeNode;

void addNode(TreeNode *currNode, TreeNode *newNode) {
	if (currNode->x < newNode->x) { // 새 노드의 x값이 현재 노드의 x값보다 크면 오른쪽 서브트리에 추가
		if (currNode->right == NULL) {
			currNode->right = newNode;
		}
		else {
			addNode(currNode->right, newNode);
		}
	}
	else if (currNode->x > newNode->x) { // 새 노드의 x값이 현재 노드의 x값보다 작으면 왼쪽 서브트리에 추가
		if (currNode->left == NULL) {
			currNode->left = newNode;
		}
		else {
			addNode(currNode->left, newNode);
		}
	}
	else return; // x값이 같은 경우는 고려 X
}

void preorder(TreeNode* root) { // 전순위
	if (root == NULL) return;
	answer[0].push_back(root->num);
	preorder(root->left);
	preorder(root->right);
}

void postorder(TreeNode* root) { // 후순위
	if (root == NULL) return;
	postorder(root->left);
	postorder(root->right);
	answer[1].push_back(root->num);
}

bool level(TreeNode* a, TreeNode* b) {
	return a->y > b->y; // 트리의 레벨(y좌표 값) 기준 내림차순 정렬
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	vector<TreeNode*> nodes(nodeinfo.size()); // nodeinfo의 노드들을 저장할 벡터 선언
	
	for (int i = 0; i < nodeinfo.size(); i++) { // nodeinfo의 좌표값을 트리노드 형태로 변환
		TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
		node->x = nodeinfo[i][0];
		node->y = nodeinfo[i][1];
		node->num = i + 1;
		node->left = NULL;
		node->right = NULL;
		nodes[i] = node;
	}

	sort(nodes.begin(), nodes.end(), level); // 트리의 레벨(y좌표) 내림차순으로 노드를 정렬
	TreeNode *root = nodes[0];

	for (int i = 0; i < nodeinfo.size(); i++) {
		addNode(root, nodes[i]);
	}

	preorder(root); // 전순위 운행 수행
	postorder(root); // 후순위 운행 수행

	return answer;
}

