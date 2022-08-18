#include <iostream>
using namespace std;
#define MaxKey 1000
//哈希函数
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
	const char* nameList[] = { "王小明","王司徒","白洁","黑洁","叶宵","宫城月" };
	const char* hashTable[MaxKey] = {NULL};
	for (size_t i = 0; i < strlen(*nameList); i++)
	{
		//不做冲突处理，处理则用开放二次寻址或者链表封闭寻址，但可能存在集群现象
		int hashCode = hashMine(nameList[i]);
		cout << nameList[i] << "：" << hashCode << endl;
		hashTable[hashCode] = nameList[i];
	}
	return -1;
}