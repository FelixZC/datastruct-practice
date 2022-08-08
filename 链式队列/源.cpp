/*
��ʽ���У���ͷ��㣩
*/
#include <iostream>
using namespace std;

typedef int ElementType; 
typedef struct LinkNode{
	ElementType data;
	struct LinkNode* next;
}LinkNode;
typedef struct LinkQueue {
	LinkNode* front, * rear;
}LinkQueue;

//��ʼ����ʽ����
LinkQueue initLinkQueue() {
	LinkQueue q;
	q.front = q.rear = new LinkNode;
	q.front->next = NULL;
	return q;
}

//�ж϶����Ƿ�Ϊ��
bool judgeLinkQueueEmpty(LinkQueue q) {
	return q.front == q.rear;
}

//���β��
bool enterLinkQueue(LinkQueue &q,ElementType data) {
	LinkNode* s = new LinkNode;
	if (!s) {
		cout << "�ڴ�����" << endl;
		return false;
	}
	s->data = data;
	s->next = NULL;
	q.rear->next = s;
	q.rear = s;
	return true;
}

//����ͷ��
bool quitLinkQueue(LinkQueue &q,ElementType &data) {
	bool isEmpty = judgeLinkQueueEmpty(q);
	if (isEmpty) {
		cout << "����Ϊ��" << endl;
		return false;
	}
	LinkNode* t = q.front->next;
	q.front->next = t->next;
	if (t == q.rear) {
		q.rear = q.front;
	}
	data = t->data;
	free(t);
	return true;
}


int main() {
	ElementType temp;
	LinkQueue q = initLinkQueue();
	bool isEmpty = judgeLinkQueueEmpty(q);
	for (size_t i = 0; i < 5; i++)
	{
		enterLinkQueue(q, i);
	}
	 isEmpty = judgeLinkQueueEmpty(q);
	for (size_t i = 0; i < 7; i++)
	{
		quitLinkQueue(q,temp);
	}
	 isEmpty = judgeLinkQueueEmpty(q);
	return 0;
}
