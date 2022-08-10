#include <iostream>
#include <queue>;
#include <stack>;
#include <string>;
using namespace std;
typedef char BiElementType;
//二叉树
typedef struct BitTreeNode {
	BiElementType c;
	struct BitTreeNode* lchild;
	struct BitTreeNode* rchild;
}BitTreeNode,*BiTree;

//前序遍历,深度优先遍历
void preOrder(BiTree tree) {
	if (tree) {
		cout << tree->c;
		preOrder(tree->lchild);
		preOrder(tree->rchild);
	}
}
//前序遍历,深度优先遍历,非递归
void preOrder2(BiTree tree) {
}

//中序遍历
void inOrder(BiTree tree) {
	if (tree) {
		inOrder(tree->lchild);
		cout << tree->c;
		inOrder(tree->rchild);
	}
}
//中序遍历,非递归
void inOrder2(BiTree tree) {
	stack<BiTree> tempStack;
	BiTree b = tree;
	while (b || !tempStack.empty()) {
		if (b) {
			tempStack.push(b);
			b = b->lchild;
		}
		else {
			b = tempStack.top();
			tempStack.pop();
			cout << b->c;
			b = b->rchild;
		}
	}
}
//后序遍历
void backOrder(BiTree tree) {
	if (tree) {
		backOrder(tree->lchild);
		backOrder(tree->rchild);
		cout << tree->c;
	}

}
//后序遍历,非递归
void backOrder2(BiTree tree) {
}
//层次遍历，广度优先遍历
void levelOrder(BiTree tree) {
	queue<BiTree> tempQueue;
	tempQueue.push(tree);
	while (!tempQueue.empty()) {
		BiTree b = tempQueue.front();
		tempQueue.pop();
		cout << b->c ;
	if (b->lchild) {
		tempQueue.push(b->lchild);
	}
	if (b->rchild) {
		tempQueue.push(b->rchild);
	}
	}
	cout << "层次遍历" << endl;
}
//层次建树初始化树
BiTree initTree() {
	BiTree tree =NULL;
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
		}else {
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
	//abcdefghij层次遍历
	//abdhiejcfg前序遍历
	//hdibjeafcg中序遍历
	//hidjebfgca后续遍历
	levelOrder(tree);
	preOrder(tree);
	//preOrder2(tree);
	cout << "前序遍历" << endl;
	//inOrder(tree);
	inOrder2(tree);
	cout << "中序遍历" << endl;
	backOrder(tree);
	//backOrder2(tree);
	cout << "后续遍历" << endl;
	return -1;
}