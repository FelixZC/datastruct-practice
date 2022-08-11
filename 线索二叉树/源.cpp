#include <iostream>
#include <queue>;
#include <stack>;
#include <string>;
using namespace std;
typedef char BiElementType;
//ûɶ���õ�����������
typedef struct BitTreeNode {
	BiElementType c;
	struct BitTreeNode* lchild;
	struct BitTreeNode* rchild;
	int ltag, rtag;//Ϊ0��ʾ��ʵ�ڵ㣬Ϊ1��ʾ��������ʱlchildΪǰ����rchild���̣�
}BitTreeNode, * BiTree;

//����������ǵݹ飬���������־��
//����������ķϣ�ûɶ�û����õ���
void inOrder2(BiTree tree) {
	stack<BiTree> tempStack;
	BiTree b = tree;
	BiTree pre = NULL;//��¼��ջ�ڵ�
	while (b || !tempStack.empty()) {
		if (b) {
			tempStack.push(b);
			b = b->lchild;
		}
		else {
			b = tempStack.top();
			tempStack.pop();
			cout << b->c;
			//��ջʱ�����������־
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
//��ν�����ʼ����
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
	//hdibjeafcg�������
	inOrder2(tree);
	cout << "�������" << endl;
	return -1;
}