#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;

typedef struct LinkNode {
	ElementType data;
	LinkNode *next;
}LinkNode,*LinkList;

//头插法
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

//尾插法
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

//按序号查找
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

//按值查找
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

//单链表插入
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

//单链表删除
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

//打印链表
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
	LinkList target =NULL;
	//target = queryLinkNode2(list, 111);
	target = queryLinkNode1(list, 5);
	if (target){
		printf("查找成功\n");
		printf("目标值为%d", target->data);
	}
	else {
		printf("查找失败\n");
	}
	return 0;
}