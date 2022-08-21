#include <time.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
typedef int ElementType;
/*
 * 动画演示 
 * https://www.bilibili.com/video/BV1CY4y1t7TZ?p=4&vd_source=a858d1292913af2be36a721d31eea597
 */
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

//回溯,从小到大
void merge(stable &t, int low,int high) {
	ElementType* temp = (ElementType*)malloc(sizeof(ElementType) * (high - low + 1));
	int i = low;
	int mid = (low + high) / 2;
	int j = mid + 1;
	int k = 0;
	//合并有序数组
	while (i <= mid&&j<=high) {
		if (t.elements[i] <= t.elements[j]) {
			temp[k++] = t.elements[i++];
		}else {
			temp[k++] = t.elements[j++];
		}
	}
	//剩余小端
	while (i <= mid) {
		temp[k++] = t.elements[i++];
	}
	//剩余大端
	while (j <= high) {
		temp[k++] = t.elements[j++];
	}
	//重新赋值
	for (int a = low; a <= high; a++)
	{
		t.elements[a] = temp[a - low];
	}
}
//归并排序，升序
void mergeSort(stable &t,int low,int high) {
	if (low < high) {
		int mid = (low + high) / 2;
		mergeSort(t, low, mid);
		mergeSort(t, mid + 1, high);
		merge(t, low , high);
	}

}
int main() {
	stable l;
	initList(l, 20);
	printList(l);
	mergeSort(l,0,l.length -1);
	printList(l);
	return 0;
}