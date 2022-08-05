#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;

typedef struct LinkNode {
	ElementType data;
	LinkNode *next;
}LinkNode,*LinkList;

//ͷ�巨
LinkList createLinkList() {
	LinkList s,list = (LinkList)malloc(sizeof(LinkNode));
	list->next = NULL;
	for (size_t i = 0; i < 5; i++)
	{	
		s = (LinkList)malloc(sizeof(LinkNode));
		s->data = i;
		s->next = list->next;
		list->next = s;
	}
	return list;
}

//β�巨
LinkList createLinkList2() {
	LinkList list = (LinkList)malloc(sizeof(LinkNode));
	LinkList s, r;
	r = list;
	for (size_t i = 0; i < 5; i++)
	{	
		s = (LinkList)malloc(sizeof(LinkNode));
		s->data = i;
		r->next = s;
		r = s;
	}
	s->next = NULL;
	return list;
}

//����Ų���
LinkList queryLinkNode1(LinkList list,int position){
	if (!list) {
		return NULL;
	}
	if (position == 0) {
		return list;
	};
	if (position < 1) {
		return NULL;
	}
	LinkList target = list->next;
	int localPosition = 1;
	while (target&&localPosition!=position)
	{	
		target = target->next;
		localPosition++;
	}
	return target;
}

//��ֵ����
LinkList queryLinkNode2(LinkList list, ElementType data) {
	if (!list||!data) {
		return NULL;
	}
	LinkList target = list->next;
	while (target&&target->data!=data) {
		target = target->next;
	}
	return target;
}

//���������
int insertLinkList(LinkList list, int position, ElementType data) {
	LinkList target = queryLinkNode1(list, position-1);
	if (!target) {
		return -1;
	};
	LinkList s = (LinkList)malloc(sizeof(LinkNode));
	s->data = data;
	s->next = target->next;
	target->next = s;
	return 1;
}

//������ɾ��
int deleteLinkList(LinkList &list,int position) {
	LinkList target = queryLinkNode1(list, position - 1);
	if (!target) {
		return -1;
	};
	LinkList temp = target->next;
	target->next = temp->next;
	free(temp);
	return 1;
}

//��ӡ����
void printLinkList(LinkList list) {
	if (!list) {
		return;
	}
	LinkList s = list->next;
	while (s) {
		printf("%4d", s->data);
		s = s->next;
	}
	printf("\n");
}

int main() {
	//LinkList list = createLinkList();
	LinkList list = createLinkList2();
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
	LinkList target =NULL;
	//target = queryLinkNode2(list, 111);
	target = queryLinkNode1(list, 5);
	if (target){
		printf("���ҳɹ�\n");
		printf("Ŀ��ֵΪ%d", target->data);
	}
	else {
		printf("����ʧ��\n");
	}
	return 0;
}