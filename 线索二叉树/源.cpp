#include <iostream>
#include <queue>;
#include <stack>;
#include <string>;
using namespace std;
typedef char BiElementType;
//没啥卵用的线索二叉树
typedef struct BitTreeNode {
	BiElementType c;
	struct BitTreeNode* lchild;
	struct BitTreeNode* rchild;
	int ltag, rtag;//为0表示真实节点，为1表示线索，此时lchild为前驱，rchild后后继；
}BitTreeNode, * BiTree;

//中序遍历，非递归，添加线索标志，
//这玩意是真的废，没啥用还不好调试
void inOrder2(BiTree tree) {
	stack<BiTree> tempStack;
	BiTree b = tree;
	BiTree pre = NULL;//记录弹栈节点
	while (b || !tempStack.empty()) {
		if (b) {
			tempStack.push(b);
			b = b->lchild;
		}
		else {
			b = tempStack.top();
			tempStack.pop();
			cout << b->c;
			//弹栈时候添加线索标志
			b->ltag = 0;
			b->rtag = 0;
			if (b->lchild == NULL) {
				b->ltag = 1;
				b->lchild = pre;
			}
			if (pre != NULL && pre->rchild == NULL) {
				pre->rtag = 1;
				pre->rchild = b;
			}
			pre = b;
			b = b->rchild;
		}
	}
}
//层次建树初始化树
BiTree initTree() {
	BiTree tree = NULL;
	string data = "abcdefghij";
	queue<BiTree> nodeQueue;
	for (size_t i = 0; i < data.length(); i++)
	{
		BiTree b = new BitTreeNode;
		b->c = data[i];
		b->lchild = NULL;
		b->rchild = NULL;
		nodeQueue.push(b);
		if (tree == NULL) {
			tree = b;
		}
		else {
			BiTree front = nodeQueue.front();
			if (front->lchild == NULL) {
				front->lchild = b;
			}
			else if (front->rchild == NULL) {
				front->rchild = b;
				nodeQueue.pop();
			}
		}
	}
	return tree;
}
int main() {
	BiTree tree = initTree();
	//hdibjeafcg中序遍历
	inOrder2(tree);
	cout << "中序遍历" << endl;
	return -1;
}