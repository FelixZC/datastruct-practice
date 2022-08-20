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
	for (int i = 0; i < l.length; i++)
	{
		l.elements[i] = (int)rand() % 100;
	}
}

//打印数组列表
void printList(stable t) {
	for (int i = 0; i < t.length; i++)
	{
		cout << t.elements[i] << " ";
	}
	cout << endl;
}

//交换数据
void swapNode(ElementType& a, ElementType& b)
{
	ElementType temp = b;
	b = a;
	a = temp;
}

//选择排序，每次从待定数组里选择最小的一个排到最前面
void selectSort(stable t) {
	int i, j, min;
	//每次从未排序中，提出一个已排序的元素
	for (i = t.length; i > 0; i--)
	{
		//默认第一个最小
		min = t.length - i;
		// 遍历未排序数组，找出最小下标
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


//持续交换孩子节点，把选中节点与其两个子节点比较，最大值换位到选中节点处,一直进行上一步到这个节点的值大于它的两个子节点
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

//持续交换父节点
void exchangeParent(stable& t, int k) {
	int cur = k;
	int parent = (cur - 1) / 2;
	//修改后的元素比父节点大
	while (parent > 0 && t.elements[cur] > t.elements[parent]) {
		swapNode(t.elements[cur], t.elements[parent]);
		parent = (parent - 1) / 2;
	}
}

//调整大根堆(最大堆维护),最大堆中若有一个元素有变更
void maintainMaxHeap(stable& t, int i, ElementType e) {
	if (i > t.length - 1) {
		return;
	}
	t.elements[i] = e;
	//修改后的节点比父节点大
	exchangeParent(t,i);
	//修改后的元素比孩子节点小
	exchangeChild(t, i, t.length);
}


//一棵深度为k（且有2的k次方-1）个结点的二叉树称为满二叉树,把用数组表示的，层次建树完全二叉树，转化为大根堆
//对于具有N个结点的完全二叉树，如果按照从上至下、从左至右的数组顺序对所有结点从0开始编号，则对于序号为i的结点：
//1、若 i > 0，则该结点的父结点序号为：(i - 1) / 2；若 i = 0，则无父结点。
//2、若2i + 1 < N，则该结点的左孩子序号为：2i + 1；若2i + 1 >= N，则无左孩子。
//3、若2i + 2 < N，则该结点的右孩子序号为：2i + 2；若2i + 2 >= N，则无右孩子。
void buildMaxHeap(stable& t) {
	//从最后一个根节点开始逆向回溯,直接卡擦掉最下层的叶子节点
	for (int i = (t.length - 1); i >= 0; i--)
	{
		exchangeChild(t, i,t.length);
	}
}

//堆排序，取出最顶端的元素改为最小值，降序
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

//堆排序，交换堆顶和终末节点缩堆长,原地排序,升序
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