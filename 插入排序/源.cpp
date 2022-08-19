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
	cout<< endl;
}

//��������
void swap(ElementType& a, ElementType& b)
{
	ElementType temp = b;
	b = a;
	a = temp;
}

//��������,�˿�����������
void insertSort(stable &t) {
	//�����������飬��������
	for (size_t i = 1; i < t.length; i++)
	{
			//�����򲿷����һλ���бȽ�(������Խ��ж��ֲ��ҸĽ�),����С���������������
		if (t.elements[i-1]>t.elements[i]) {
			for (size_t j = i; j > 0 && t.elements[j - 1] > t.elements[j]; j--)
			{
				swap(t.elements[j - 1], t.elements[j]);
			}
		}
	}
}
//ϣ�����򣬿粽������������
void shellSort(stable& t) {
	int i,j,dk;
	ElementType temp;
	for (dk = t.length/2; dk>=1 ; dk = dk/2)
	{
		//�������飬�Բ������в�������
		for (i = dk; i < t.length; i++)
		{
			temp = t.elements[i];
			//�Ƚ����¼����ͬʱ����
			for (j = i - dk; (j >= i % dk) && t.elements[j] > temp; j -= dk) {
				t.elements[j + dk] = t.elements[j];
			}
			if (j != i - dk) {
				t.elements[j + dk] = temp;//����
			}
		}
	}
}
int main() {
	stable l;
	initList(l, 20);
	printList(l);
	//insertSort(l);
	shellSort(l);
	printList(l);
	return 0;
}