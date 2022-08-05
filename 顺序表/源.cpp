#include <stdio.h>
#define MaxSize 50
typedef int ElementType;
typedef struct {
	ElementType data[MaxSize];
	int length;
}SqList;

//打印线性表
void printSqList(SqList list) {
	for (size_t i = 0; i < list.length; i++)
	{
		printf("%d\n", list.data[i]);
	}
}

//线性表插入
int insertSqList(SqList& list, int position, ElementType data) {
	if (position<1 || position>list.length + 1) {
		return 0;
	};
	if (list.length >= MaxSize) {
		return 0;
	};
	for (size_t i = list.length; i >= position; i--)
	{
		list.data[i] = list.data[i - 1];
	}
	list.data[position - 1] = data;
	list.length++;
	return 1;
}

//线性表删除
int deleteSqList(SqList& list, int position, ElementType& result) {
	if (position <1 || position>list.length) {
		return 0;
	}
	if (list.length == 0) {
		return 0;
	}
	result = list.data[position - 1];
	for (size_t i = position; i <= list.length; i++)
	{
		list.data[i - 1] = list.data[i];
	}
	list.length--;
	return 1;
}

//线性表查找
int querySqList(SqList list, ElementType target) {
	for (size_t i = 0; i < list.length; i++)
	{
		if (list.data[i] == target) {
			return i + 1;
		}
	}
	return -1;
}

int main() {
	SqList list;
	int count = 5;
	for (size_t i = 0; i < count; i++)
	{
		list.data[i] = i + 100;
	}
	list.length = count;
	int res;
	res = insertSqList(list, 1, 110);
	if (res) {
		printf("插入成功\n");
		printSqList(list);
	}
	else {
		printf("插入失败\n");
	}
	ElementType temp;//存储删除结果
	res = deleteSqList(list, 6, temp);
	if (res) {
		printf("删除成功\n");
		printSqList(list);
		printf("移除元素%d\n", temp);
	}
	else {
		printf("删除失败\n");
	}
	res = querySqList(list, 110);
	if (res > -1) {
		printf("查找成功\n");
		printf("位置为%d\n", res);
	}
	else {
		printf("查找失败，无相关记录\n");
	}
	return 0;
}