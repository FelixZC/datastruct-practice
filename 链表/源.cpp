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
int insertLinkList(LinkList& list, int position, ElementType data;) {
	if (!list) {
		return -1;
	}
	LinkList target = queryLinkNode1(list, position);
	if (!target) {
		return -1;
	};
	LinkList s = (LinkList)
}
int deleteLinkList() {
}

void printLinkList() {
}
int main() {
	LinkList list = createLinkList();
	return 0;
}