#include <time.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
typedef int ElementType;
typedef struct {
	ElementType* elements;
	int length;
}stable;
//初始化数组
void initList(stable& l, int len) {
	l.length = len;
	//这就是数组
	l.elements = (ElementType*)malloc(sizeof(ElementType) * l.length);
	srand(time(NULL));
	for (size_t i = 0; i < l.length; i++)
	{
		l.elements[i] = rand() % 100;
	}
}

//打印数组列表
void printList(stable t) {
	for (size_t i = 0; i < t.length; i++)
	{
		cout << t.elements[i] << " ";
	}
	cout << endl;
}

//交换数据
void swap(ElementType& a, ElementType& b)
{
	ElementType temp = b;
	b = a;
	a = temp;
}

//冒泡排序
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

//快速排序分割，把比第一个数据小的排在前面
int quickSortPartition(stable &t,int low,int high) {
	//记录第一个数据
	ElementType temp = t.elements[low];
	while (low < high) {
		//从右找小
		while (low < high && t.elements[high]>=temp) {
			high--;
		}
		//从左找大
		t.elements[low] = t.elements[high];
		while (low < high && t.elements[low] <= temp) {
			low++;
		}
		t.elements[high] = t.elements[low];
	}
	t.elements[low] = temp;
	//返回比较值位置
	return low;
}

//快速排序
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