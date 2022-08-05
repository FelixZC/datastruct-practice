#include <stdio.h>
#define MaxSize 50
typedef int ElementType;
typedef struct {
	ElementType data[MaxSize];
	int length;
}SqList;

//��ӡ���Ա�
void printSqList(SqList list) {
	for (size_t i = 0; i < list.length; i++)
	{
		printf("%d\n", list.data[i]);
	}
}

//���Ա����
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

//���Ա�ɾ��
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

//���Ա����
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
		printf("����ɹ�\n");
		printSqList(list);
	}
	else {
		printf("����ʧ��\n");
	}
	ElementType temp;//�洢ɾ�����
	res = deleteSqList(list, 6, temp);
	if (res) {
		printf("ɾ���ɹ�\n");
		printSqList(list);
		printf("�Ƴ�Ԫ��%d\n", temp);
	}
	else {
		printf("ɾ��ʧ��\n");
	}
	res = querySqList(list, 110);
	if (res > -1) {
		printf("���ҳɹ�\n");
		printf("λ��Ϊ%d\n", res);
	}
	else {
		printf("����ʧ�ܣ�����ؼ�¼\n");
	}
	return 0;
}