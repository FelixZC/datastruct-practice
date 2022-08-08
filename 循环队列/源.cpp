
#define MaxSize 50
typedef int ElementType;
typedef struct {
	ElementType data[MaxSize];
	int front, rear;
}SqQueue;

SqQueue initSqQueue() {
	SqQueue q;
	q.front = q.rear = 0;
	return q;
}

//判断是否栈空
bool judgeIsEmpty(SqQueue q) {
	return q.front == q.rear;
}

//入队
bool enterQueue(SqQueue& q, ElementType data) {
	if ((q.rear + 1) % MaxSize == q.front) {
		return false;
	}
	q.data[q.rear] = data;
	q.rear=(q.rear+1)%MaxSize;
	return true;
}

//出队
bool quitQueue(SqQueue& q, ElementType& result){
	bool isEmpty =  judgeIsEmpty(q);
	if (isEmpty) {
		return false;
	}
	result = q.data[q.front];
	q.front = (q.front+1) % MaxSize;
	return true;
}

int main() {
	ElementType temp;
	SqQueue q = initSqQueue();
	bool isEmpty;
	isEmpty = judgeIsEmpty(q);
	for (size_t i = 0; i < 52; i++)
	{
		enterQueue(q, i);
	}
	isEmpty = judgeIsEmpty(q);
	for (size_t i = 0; i < 62; i++)
	{
		quitQueue(q, temp);
	}
	for (size_t i = 0; i < 6; i++)
	{
		enterQueue(q, i+100);
	}
	return 0;
}