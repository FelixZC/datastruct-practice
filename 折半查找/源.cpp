#include <time.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
typedef int ElementType;
typedef struct {
	ElementType* elements;
	int length;
}stable;
//��ʼ������
void initList(stable &l,int len) {
	l.length = len;
	//���������
	l.elements = (ElementType*)malloc(sizeof(ElementType)*l.length);
	srand(time(NULL));
	//for (size_t i = 0; i < l.length; i++)
	//{
	//	l.elements[i] = rand() % 100;
	//}
	int test[] = {24,34,13,18,40,19,52,93,21,62};
	for (size_t i = 0; i < 10; i++)
	{
		l.elements[i] = test[i];
	}
}

//��ӡ�����б�
void printList(stable t) {
	for (size_t i = 0; i < t.length; i++)
	{
		cout<<	t.elements[i] <<endl;
	}
}


int normalSearch(stable t, ElementType s) {
	for (size_t i = 0; i < t.length; i++)
	{
		if (t.elements[i] == s) {
			return i;
		}
	}
	return -1;
}

//���ֲ���,�����������
int binarySearch(stable t, ElementType s) {
	int low = 0;
	int high = t.length - 1;
	int mid;
	while (low <= high) {
		mid = (low + high) / 2;
		if (t.elements[mid] == s) {
			return mid;
		}
		else if (s > t.elements[mid]) {
			low = mid + 1;
		}
		else if (s < t.elements[mid]) {
			high = mid - 1;
		}
	}
	return -1;
}

//��������ȽϺ���
int compare(const void* a,const void* b) {
	return *(ElementType*)a - *(ElementType*)b;
}

int main() {
	stable l;
	int len = 10;
	initList(l, 10);
	int position;
	qsort(l.elements, l.length, sizeof(ElementType), compare);
	printList(l);
	//position =  normalSearch(l, 21);
	position = binarySearch(l, 21);
	cout << "����λ��Ϊ:" << position << endl;
	return 0;
}