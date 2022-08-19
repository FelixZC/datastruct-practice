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
	cout<< endl;
}

//交换数据
void swap(ElementType& a, ElementType& b)
{
	ElementType temp = b;
	b = a;
	a = temp;
}

//插入排序,扑克牌排序，升序
void insertSort(stable &t) {
	//遍历整个数组，挨个放入
	for (size_t i = 1; i < t.length; i++)
	{
			//与有序部分最后一位进行比较(这里可以进行二分查找改进),出现小于情况，挨个交换
		if (t.elements[i-1]>t.elements[i]) {
			for (size_t j = i; j > 0 && t.elements[j - 1] > t.elements[j]; j--)
			{
				swap(t.elements[j - 1], t.elements[j]);
			}
		}
	}
}
//希尔排序，跨步分组排序，升序
void shellSort(stable& t) {
	int i,j,dk;
	ElementType temp;
	for (dk = t.length/2; dk>=1 ; dk = dk/2)
	{
		//遍历分组，以步长进行插入排序
		for (i = dk; i < t.length; i++)
		{
			temp = t.elements[i];
			//比较与记录后移同时进行
			for (j = i - dk; (j >= i % dk) && t.elements[j] > temp; j -= dk) {
				t.elements[j + dk] = t.elements[j];
			}
			if (j != i - dk) {
				t.elements[j + dk] = temp;//插入
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