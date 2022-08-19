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

//ð������
void bubbleSort(stable &t) {
	for (size_t i = t.length; i > 1; i--)
	{
		for (size_t j = 1; j < t.length; j++)
		{
			if (t.elements[j - 1] > t.elements[j]) {
				swap(t.elements[j - 1], t.elements[j]);
			}
		}
	}
}

//��������ָ�ѱȵ�һ������С������ǰ��
int quickSortPartition(stable &t,int low,int high) {
	//��¼��һ������
	ElementType temp = t.elements[low];
	while (low < high) {
		//������С
		while (low < high && t.elements[high]>=temp) {
			high--;
		}
		//�����Ҵ�
		t.elements[low] = t.elements[high];
		while (low < high && t.elements[low] <= temp) {
			low++;
		}
		t.elements[high] = t.elements[low];
	}
	t.elements[low] = temp;
	//���رȽ�ֵλ��
	return low;
}

//��������
void quickSort(stable &t,int low,int high) {
	if (low < high) {
		int temp = quickSortPartition(t, low, high);
		quickSort(t, low, temp - 1);
		quickSort(t, temp + 1, high);
	}
}
int main() {
	stable l;
	initList(l, 20);
	printList(l);
	//bubbleSort(l);
	quickSort(l, 0, l.length - 1);
	printList(l);
	return 0;
}