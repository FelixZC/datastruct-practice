#include <stdio.h>;
#define MaxSize 50
typedef int ElementType;
typedef struct Stack {
	ElementType data[MaxSize];
	int top;
}Stack;

//��ʼ��ջ
Stack initStack() {
	Stack s;
	s.top = -1;
	return s;
}


bool judgeStackEmpty(Stack s) {
	return s.top == -1;
};

//��ջ
bool pushStack(Stack &s,ElementType data) {
	if (s.top == MaxSize-1) {
		return false;
	}
	s.data[++s.top] = data;
	return true;
};
//��ջ
 ElementType popStack(Stack &s) {
	if (s.top == -1) {
		return NULL;
	};
	return s.data[s.top--];
};

//��ջ
 ElementType getStack(Stack s) {
	 if (s.top == -1) {
		 return NULL;
	 };
	 return  s.data[s.top];
};

int main() {
	Stack s = initStack();
	bool res;
 	res = judgeStackEmpty(s);
	ElementType temp;
	for (size_t i = 0; i < 5; i++)
	{
		pushStack(s, i);
	}
	for (size_t i = 0; i < 6; i++)
	{
		temp = popStack(s);
	}
	temp = getStack(s);
	res = judgeStackEmpty(s);
	return 0;
}