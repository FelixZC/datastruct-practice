#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;
typedef struct DNode {
	ElementType data;
	struct DNode* prior, * next;
}DNode,*DLinkList;


//ͷ�巨
DLinkList createLinkList() {
	DLinkList list = (DLinkList)malloc(sizeof(DNode));
	DLinkList s;
	list->next = NULL;
	list->prior = NULL;
	for (size_t i = 0; i < 5; i++)
	{
		 s = (DLinkList)malloc(sizeof(DNode));
		 s->data = i;
		 s->next = list->next;
		 if (list->next) {
			 list->next->prior = s;
		 }
		 s->prior = list;
		 list->next = s;
	}
	return list;
}

//β�巨
DLinkList createLinkList2() {
	DLinkList list = (DLinkList)malloc(sizeof(DNode));
	list->next = NULL;
	list->prior = NULL;
	DLinkList s, r;
	r = list;
	for (size_t i = 0; i < 5; i++)
	{
		s = (DLinkList)malloc(sizeof(DNode));
		s->data = i;
		s->prior = r;
		r->next = s;
		r = s;
	}
	s->next = NULL;
	return list;
}

//����Ų���
DLinkList queryLinkNode1(DLinkList list, int position) {
	if (!list) {
		return NULL;
	}
	if (position == 0) {
		return list;
	};
	if (position < 1) {
		return NULL;
	}
	DLinkList target = list->next;
	int localPosition = 1;
	while (target && localPosition != position)
	{
		target = target->next;
		localPosition++;
	}
	return target;
}

//˫���������
int insertLinkList(DLinkList list, int position, ElementType data) {
	DLinkList p = queryLinkNode1(list, position - 1);
	if (!p) {
		return - 1;
	}
	DLinkList s = (DLinkList)malloc(sizeof(DNode));
	s->data = data;
	s->next = p->next;
	s->prior = p;
	p->next->prior = s;
	p->next = s;
	return 1;
}

//˫������ɾ��
int deleteLinkList(DLinkList& list, int position) {
	DLinkList target = queryLinkNode1(list,position - 1);
	if (!target) {
		return -1;
	}
	DLinkList s = target->next;
	if (!s) {
		return -1;
	}
	target->next = s->next;
	if (s->next) {
		s->next->prior = target;
	}
	free(s);
	return 1;
;}

//��ӡ����
void printLinkList(DLinkList list) {
	if (!list) {
		return;
	}
	DLinkList s = list->next;
	while (s) {
		printf("%4d", s->data);
		s = s->next;
	}
	printf("\n");
}

int main() {
	DLinkList list = createLinkList();
	//DLinkList list = createLinkList2();
	int res;
	res = insertLinkList(list, 2, 111);
	if (res) {
		printf("����ɹ�\n");
		printLinkList(list);
	}
	else {
		printf("����ʧ��\n");
	}
	res = deleteLinkList(list, 4);
	if (res) {
		printf("ɾ���ɹ�\n");
		printLinkList(list);
	}
	else {
		printf("ɾ���ɹ�\n");
	}
	DLinkList target = NULL;
	target = queryLinkNode1(list, 5);
	if (target) {
		printf("���ҳɹ�\n");
		printf("Ŀ��ֵΪ%d", target->data);
	}
	else {
		printf("����ʧ��\n");
	}
}