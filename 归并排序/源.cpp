#include <time.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
typedef int ElementType;
/*
 * ������ʾ 
 * https://www.bilibili.com/video/BV1CY4y1t7TZ?p=4&vd_source=a858d1292913af2be36a721d31eea597
 */
typedef struct {
	ElementType* elements;
	int length;
}stable;
//��ʼ������
void initList(stable& l, int len) {
	l.length = len;
	//���������
	l.elements = (ElementType*)malloc(sizeof(ElementType) * l.length);
	srand(time(NULL));
	for (size_t i = 0; i < l.length; i++)
	{
		l.elements[i] = rand() % 100;
	}
}

//��ӡ�����б�
void printList(stable t) {
	for (size_t i = 0; i < t.length; i++)
	{
		cout << t.elements[i] << " ";
	}
	cout << endl;
}

//��������
void swap(ElementType& a, ElementType& b)
{
	ElementType temp = b;
	b = a;
	a = temp;
}

int main() {
	stable l;
	initList(l, 20);
	printList(l);
	printList(l);
	return 0;
}