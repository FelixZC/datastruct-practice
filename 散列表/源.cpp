#include <iostream>
using namespace std;
#define MaxKey 1000
//��ϣ����
int hashMine(const char* key)
{
	int h = 0, g;
	while (*key)
	{
		h = (h << 4) + *key++;
		g = h & 0xf0000000;
		if (g)
		{
			h ^= g >> 24;
		}
		h &= ~g;
	}
	return h % MaxKey;
}


int main() {
	const char* nameList[] = { "��С��","��˾ͽ","�׽�","�ڽ�","Ҷ��","������" };
	const char* hashTable[MaxKey] = {NULL};
	for (size_t i = 0; i < strlen(*nameList); i++)
	{
		//������ͻ�����������ÿ��Ŷ���Ѱַ����������Ѱַ�������ܴ��ڼ�Ⱥ����
		int hashCode = hashMine(nameList[i]);
		cout << nameList[i] << "��" << hashCode << endl;
		hashTable[hashCode] = nameList[i];
	}
	return -1;
}