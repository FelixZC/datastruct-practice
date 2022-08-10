#include <iostream>
#include <queue>;
#include <stack>;
#include <string>;
using namespace std;
typedef char BiElementType;
//������
typedef struct BitTreeNode {
	BiElementType c;
	struct BitTreeNode* lchild;
	struct BitTreeNode* rchild;
}BitTreeNode,*BiTree;

//ǰ�����,������ȱ���
void preOrder(BiTree tree) {
	if (tree) {
		cout << tree->c;
		preOrder(tree->lchild);
		preOrder(tree->rchild);
	}
}
//ǰ�����,������ȱ���,�ǵݹ�
void preOrder2(BiTree tree) {
}

//�������
void inOrder(BiTree tree) {
	if (tree) {
		inOrder(tree->lchild);
		cout << tree->c;
		inOrder(tree->rchild);
	}
}
//�������,�ǵݹ�
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
//�������
void backOrder(BiTree tree) {
	if (tree) {
		backOrder(tree->lchild);
		backOrder(tree->rchild);
		cout << tree->c;
	}

}
//�������,�ǵݹ�
void backOrder2(BiTree tree) {
}
//��α�����������ȱ���
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
	cout << "��α���" << endl;
}
//��ν�����ʼ����
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
	//abcdefghij��α���
	//abdhiejcfgǰ�����
	//hdibjeafcg�������
	//hidjebfgca��������
	levelOrder(tree);
	preOrder(tree);
	//preOrder2(tree);
	cout << "ǰ�����" << endl;
	//inOrder(tree);
	inOrder2(tree);
	cout << "�������" << endl;
	backOrder(tree);
	//backOrder2(tree);
	cout << "��������" << endl;
	return -1;
}