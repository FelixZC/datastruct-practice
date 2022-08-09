/*
��ʽ���У���ͷ��㣩
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

//��ʼ����ʽ����
LinkQueue initLinkQueue() {
	LinkQueue q;
	q.front = NULL;
	q.rear = NULL;
	return q;
}

//�ж϶����Ƿ�Ϊ��
bool judgeLinkQueueEmpty(LinkQueue q) {
	return q.front == NULL;
}

//���β��
bool enterLinkQueue(LinkQueue& q, ElementType data) {
	LinkNode* s = new LinkNode;
	if (!s) {
		cout << "�ڴ�����" << endl;
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

//����ͷ��
bool quitLinkQueue(LinkQueue& q, ElementType& data) {
	bool isEmpty = judgeLinkQueueEmpty(q);
	if (isEmpty) {
		cout << "����Ϊ��" << endl;
		return false;
	}
	LinkNode* t = q.front;
	data = t->data;
	//ֻʣ��һ������ջ����ջ��
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

//��ȡ������
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
