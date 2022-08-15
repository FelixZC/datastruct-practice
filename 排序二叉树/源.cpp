#include <iostream>
#include <list>KeyType
using namespace std;
//二叉排序树
typedef int KeyType;
typedef struct BSTNode {
	KeyType key;
	struct BSTNode* lchild, * rchild;
}BSTNode, *BiTree;

//插入节点
bool insertTreeNode(BiTree &tree, KeyType key) {
	if (!tree) {
		BiTree s = new BSTNode();
		if (!s) {
			return false;
		}
		s->key = key;
		s->lchild = NULL;
		s->rchild = NULL;
		tree = s;
		return true;
	}
	else if (key == tree->key) {
		return false;
	}
	else if (key < tree->key) {
		return insertTreeNode(tree->lchild, key);
	}
	else if (key > tree->key) {
		return insertTreeNode(tree->rchild, key);
	}
}

//查找节点
BiTree queryTreeNode(BiTree tree,KeyType key) {
		BiTree target = tree;
		while (target && target->key != key) {
			if (key < target->key) {
				target = target->lchild;
			}
			else if (key > target->key) {
				target = target->rchild;
			}
		}
		return target;
}
//删除节点
//bool deleteTreeNode(BiTree &tree, KeyType key) {
//	if (!tree) {
//		return false;
//	}
//	//脱离引用，经典错误，标准零分
//	BiTree target = queryTreeNode(tree, key);
//	if (!target) {
//		return false;
//	}
//	BiTree temp = target;
//	if (target->lchild && !target->rchild) {
//		//普通赋值
//		target = target->lchild;
//	}
//	if (!target->lchild && target->rchild) {
//		//普通赋值
//		target = target->rchild;
//	}
//	if (target->lchild && target->rchild) {
//		temp = target->lchild;
//		while (temp && temp->rchild) {
//			temp = temp->rchild;
//		}
//		target->key = temp->key;
//	}
//	//引用失效了，这种方法释放指针后变成了奇怪的值
//	delete temp;
//	return true;
//}

//删除节点，递归保留引用
bool deleteTreeNode(BiTree& root, KeyType key) {
	if (!root) {
		return false;
	}
	if (key < root->key) {
		return	deleteTreeNode(root->lchild, key);
	}
	else if (key > root->key) {
		return	deleteTreeNode(root->rchild, key);
	}
	else {
		BiTree temp = root;
		if (!root->lchild) {
			root = root->rchild;
			delete temp;
			return true;
		}
		else if (!root->rchild) {
			root = root->lchild;
			delete temp;
			return true;
		}
		else {
			temp = root->lchild;
			if (temp->rchild != NULL) {
				temp = temp->rchild;
			}
			root->key = temp->key;
			return deleteTreeNode(root->lchild, temp->key);
		}
	}
}

//初始化树
BiTree initTree() {
	BiTree tree = NULL;
	//char a1[] = "fwegweasdasdwqew";
	//cout << strlen(a1) << endl;
	int a[] = { 44, 22, 54, 67, 2, 12, 32, 66, 9 };
	bool res;
	for (size_t i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
	res = insertTreeNode(tree, a[i]);
	}
	return tree;
}

int main() {
	BiTree tree;
	BiTree temp;
	tree = initTree();
	temp = queryTreeNode(tree, 122);
	if (temp) {
		cout << "查找结果" << temp->key;
	}
	bool res;
	//res = deleteTreeNode(tree, 54);
	res = deleteTreeNode(tree, 44);
	if (res) {
		cout << "删除成功" << endl;
	}
	else {
		cout << "删除失败" << endl;
	}
	return -1;
}