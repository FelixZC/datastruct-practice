#include <string>
#include <vector>
#include <iostream>

using namespace std;

//��ͨ�������ƥ��
int normalMatch(string s,string t) {
	int i=0, j=0;
	int sLen = s.size();
	int tLen = t.size();
	while (i <= sLen - 1 && j <= tLen - 1) {
		if (s[i] == t[j]) {
			i++;
			j++;
		}
		else {
			i = i - j + 1;
			j = 0;
		}
	}
	if (j == tLen) {
		return i - tLen;
	}
	else {
		return -1;
	}
}

//����next����
void resetNext(string t,vector<int> &next) {
	int len = t.size();
	next[0] = -1;
	int i = 0;
	int j = -1;
	while (i < len - 1)
	{
		if (j == -1 || t[i] == t[j])
		{
			++i;
			++j;
			next[i] = j;
		}
		else
		{
			j = next[j];
		}
	}
}

//kmpģʽƥ��
int kmpMatch(string s,string t) {
	int i = 0;
	int j = 0;
	int sLen = s.size();
	int tLen = t.size();
	vector<int> next;
	next.resize(tLen);
	//��дnext����
	resetNext(t,next);
	while (i <= sLen - 1 && j <= tLen - 1) {
		//��������ж�
		if (j == -1 || s[i] == t[j]) {
			i++;
			j++;
		}
		else {
		//�����ظ�����
			j = next[j];
		}
	}
	if (j == tLen) {
		return i - tLen;
	}
	else {
		return -1;
	}
}

int main() {
	string s = "abababc";
	string t = "ababc";
	int result1;
	int result2;
	result1 = normalMatch(s, t);
	result2 = kmpMatch(s, t);
	cout << result2 << endl;
	cout << result1 << endl;
	return -1;
}