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
	for (int i = 0; i < l.length; i++)
	{
		l.elements[i] = (int)rand() % 100;
	}
}

//��ӡ�����б�
void printList(stable t) {
	for (int i = 0; i < t.length; i++)
	{
		cout << t.elements[i] << " ";
	}
	cout << endl;
}

//��������
void swapNode(ElementType& a, ElementType& b)
{
	ElementType temp = b;
	b = a;
	a = temp;
}

//ѡ������ÿ�δӴ���������ѡ����С��һ���ŵ���ǰ��
void selectSort(stable t) {
	int i, j, min;
	//ÿ�δ�δ�����У����һ���������Ԫ��
	for (i = t.length; i > 0; i--)
	{
		//Ĭ�ϵ�һ����С
		min = t.length - i;
		// ����δ�������飬�ҳ���С�±�
		for (j = min; j < t.length; j++)
		{
			if (t.elements[min] > t.elements[j]) {
				min = j;
			}
		}
		if (min != t.length - i) {
			swap(t.elements[t.length - i], t.elements[min]);
		}
	}
}


//�����������ӽڵ㣬��ѡ�нڵ����������ӽڵ�Ƚϣ����ֵ��λ��ѡ�нڵ㴦,һֱ������һ��������ڵ��ֵ�������������ӽڵ�
void exchangeChild(stable &t,int k,int length) {
	int cur = k;
	int child = 2 * cur +1 ;
	while (child < length) {
		if ((child + 1) < length && t.elements[child] < t.elements[child + 1]) {
			child = child + 1;
		}
		if (t.elements[cur] < t.elements[child]) {
			swapNode(t.elements[cur], t.elements[child]);
			cur = child;
			child = 2 * child + 1;
		}
		else {
			break;
		}
	}
}

//�����������ڵ�
void exchangeParent(stable& t, int k) {
	int cur = k;
	int parent = (cur - 1) / 2;
	//�޸ĺ��Ԫ�رȸ��ڵ��
	while (parent > 0 && t.elements[cur] > t.elements[parent]) {
		swapNode(t.elements[cur], t.elements[parent]);
		parent = (parent - 1) / 2;
	}
}

//���������(����ά��),����������һ��Ԫ���б��
void maintainMaxHeap(stable& t, int i, ElementType e) {
	if (i > t.length - 1) {
		return;
	}
	t.elements[i] = e;
	//�޸ĺ�Ľڵ�ȸ��ڵ��
	exchangeParent(t,i);
	//�޸ĺ��Ԫ�رȺ��ӽڵ�С
	exchangeChild(t, i, t.length);
}


//һ�����Ϊk������2��k�η�-1�������Ķ�������Ϊ��������,���������ʾ�ģ���ν�����ȫ��������ת��Ϊ�����
//���ھ���N��������ȫ��������������մ������¡��������ҵ�����˳������н���0��ʼ��ţ���������Ϊi�Ľ�㣺
//1���� i > 0����ý��ĸ�������Ϊ��(i - 1) / 2���� i = 0�����޸���㡣
//2����2i + 1 < N����ý����������Ϊ��2i + 1����2i + 1 >= N���������ӡ�
//3����2i + 2 < N����ý����Һ������Ϊ��2i + 2����2i + 2 >= N�������Һ��ӡ�
void buildMaxHeap(stable& t) {
	//�����һ�����ڵ㿪ʼ�������,ֱ�ӿ��������²��Ҷ�ӽڵ�
	for (int i = (t.length - 1); i >= 0; i--)
	{
		exchangeChild(t, i,t.length);
	}
}

//������ȡ����˵�Ԫ�ظ�Ϊ��Сֵ������
stable heapSort1(stable &t) {
	buildMaxHeap(t);
	stable l;
	l.length = t.length;
	l.elements = (ElementType*)malloc(sizeof(ElementType) * l.length);
	for (int i = 0; i < t.length; i++)
	{
		l.elements[i] = t.elements[0];
		maintainMaxHeap(t, 0, -474137390);
	}
	return l;
}

//�����򣬽����Ѷ�����ĩ�ڵ����ѳ�,ԭ������,����
void heapSort2(stable &t) {
	buildMaxHeap(t);
	for (int i = t.length - 1; i > 0; i--)
	{
		swapNode(t.elements[0], t.elements[i]);
		exchangeChild(t, 0, i);
	}
}


int main() {
	stable l;
	initList(l, 20);
	printList(l);
	//selectSort(l);
	//l = heapSort1(l);
	heapSort2(l);
	printList(l);
	return 0;
}