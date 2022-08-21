#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <cmath>
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
		l.elements[i] = rand() % 100000;
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

//��ȡ���ֵ
ElementType getMax(stable s) {
	int max = 0;
	for (int i = 1; i < s.length; i++)
	{
		if (s.elements[max] < s.elements[i]) {
			max = i;
		}
	}
	return s.elements[max];
}

//��ȡѭ������
int getLoop(ElementType max) {
	int loop = 0;
	int temp = max;
	while (temp != 0) {
		loop++;
		temp = temp / 10;
	}
	return loop;
}

//���������е���ڴ�...
void radixSort(stable &t) {
	ElementType max = getMax(t);
	int loop = getLoop(max);
	vector<vector<ElementType>> temp(10,vector<ElementType>(0));
	int cur;
	//λ��ѭ��
	for (int i = 1; i <= loop; i++)
	{
		//����ָ�
		for (int j = 0; j < t.length; j++)
		{
			cur =  t.elements[j] /(int)pow(10, i - 1) % 10;
			temp[cur].push_back(t.elements[j]);
		}
		//���ݻص�������Ͱ
		int index = 0;
		for (vector<vector<ElementType>>::iterator it = temp.begin(); it != temp.end(); it++)
		{
			for (vector<ElementType>::iterator it2 = (*it).begin(); it2 != (*it).end(); it2++)
			{
				t.elements[index++] = *it2;
			}
			//�������
			(*it).clear();
		}
	}
}



int main() {
	stable l;
	initList(l, 20);
	printList(l);
	radixSort(l);
	printList(l);
	return 0;
}