/*
链式队列（不头结点）
*/
#include <iostream>
using namespace std;

typedef int ElementType;
typedef struct LinkNode {
	ElementType data;
	struct LinkNode* next;
}LinkNode;
typedef struct LinkQueue {
	LinkNode* front, * rear;
}LinkQueue;

//初始化链式队列
LinkQueue initLinkQueue() {
	LinkQueue q;
	q.front = NULL;
	q.rear = NULL;
	return q;
}

//判断队列是否为空
bool judgeLinkQueueEmpty(LinkQueue q) {
	return q.front == NULL;
}

//入队尾插
bool enterLinkQueue(LinkQueue& q, ElementType data) {
	LinkNode* s = new LinkNode;
	if (!s) {
		cout << "内存满了" << endl;
		return false;
	}
	s->data = data;
	s->next = NULL;
	if (q.front == NULL) {
		q.front = s;
		q.rear = s;
	}
	else {
		q.rear->next = s;
		q.rear = s;
	}
	return true;
}

//出队头出
bool quitLinkQueue(LinkQueue& q, ElementType& data) {
	bool isEmpty = judgeLinkQueueEmpty(q);
	if (isEmpty) {
		cout << "队列为空" << endl;
		return false;
	}
	LinkNode* t = q.front;
	data = t->data;
	//只剩下一个，出栈后则栈空
	if (q.rear == t) {
		q.front = NULL;
		q.rear = NULL;
	}
	else {
		q.front = q.front->next;
	}
	delete t;
	return true;
}

//获取链表长度
//int getLinkLength(LinkQueue q) {
//	bool isEmpty = judgeLinkQueueEmpty(q);
//	if (isEmpty) {
//		return 0;
//	}
//	else {
//		int length = 1;
//		LinkNode* s = q.front;
//		while (s != q.rear) {
//			s = s->next;
//			length++;
//		}
//		return length;
//	}
//}

int main() {
	ElementType temp;
	LinkQueue q = initLinkQueue();
	bool isEmpty = judgeLinkQueueEmpty(q);
	for (size_t i = 0; i < 5; i++)
	{
		enterLinkQueue(q, i);
	}
	isEmpty = judgeLinkQueueEmpty(q);
	for (size_t i = 0; i < 6; i++)
	{
		quitLinkQueue(q, temp);
	}
	isEmpty = judgeLinkQueueEmpty(q);
	return 0;
}
