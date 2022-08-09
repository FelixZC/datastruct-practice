#include <iostream>
#include <queue>;
#include <stack>;
typedef char BiElementType;
typedef struct BitTreeNode {
	BiElementType c;
	struct BitTree* lchild;
	struct BitTree* rchild;
}BitTreeNode,*BiTree;

typedef struct tag {
	BiTree p;
	struct tag* pnext;
}tag_t,*ptag_t;