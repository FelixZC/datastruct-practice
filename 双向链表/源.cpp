#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;
typedef struct DNode {
	ElementType data;
	struct DNode* prior, * next;
}DNode,*DLinkList;


//头插法
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

//尾插法
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

//按序号查找
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

//双向链表插入
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

//双向链表删除
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

//打印链表
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
		printf("插入成功\n");
		printLinkList(list);
	}
	else {
		printf("插入失败\n");
	}
	res = deleteLinkList(list, 4);
	if (res) {
		printf("删除成功\n");
		printLinkList(list);
	}
	else {
		printf("删除成功\n");
	}
	DLinkList target = NULL;
	target = queryLinkNode1(list, 5);
	if (target) {
		printf("查找成功\n");
		printf("目标值为%d", target->data);
	}
	else {
		printf("查找失败\n");
	}
}