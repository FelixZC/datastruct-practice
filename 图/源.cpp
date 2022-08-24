#include <iostream>
#include <queue>
#include <malloc.h>
#include <stdlib.h>
using namespace std;
#define MaxSize 100
//�����ڽӱ�
typedef struct Enode {
	int vex;//ָ�򶥵��±�
	struct Enode* next;
}Enode,*PEnode;
//ͼ�Ķ���洢
typedef struct Vertex {
	char data;
	struct Enode* first;
}VNode;

//ͼ�洢�ṹ
typedef struct Graph {
	int vexNum;//������
	int edgeNum;// ����
	Vertex vertexs[MaxSize];
}Graph;


//���Ҷ��������±�
int findVertexIndex(Graph gp,char target) {
	int p = -1;
	for (size_t i = 0; i <gp.vexNum ; i++)
	{
		if (gp.vertexs[i].data == target) {
			return i;
		}
	}
	return p;
}

//��������
static void linkPEnode(PEnode p1,PEnode p2) {
	PEnode p = p1;
	while (p->next)
	{
		p = p->next;
	}
	p->next = p2;
}

//��ʼ������ͼ
Graph initGraph() {
	Graph gp;
	char vexs[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G' };
	char edges[][2] = {
		{'A', 'C'},
		{'A', 'D'},
		{'A', 'F'},
		{'B', 'C'},
		{'C', 'D'},
		{'E', 'G'},
		{'F', 'G'}
	};
	gp.edgeNum = sizeof(edges) / sizeof(edges[0]);
	gp.vexNum = sizeof(vexs) / sizeof(vexs[0]);
	//��ʼ������
	for (size_t i = 0; i < gp.vexNum; i++)
	{
		gp.vertexs[i].data = vexs[i];
		gp.vertexs[i].first = NULL;
	}
	char c1, c2;
	int p1, p2;
	PEnode pe1, pe2;
	//��ʼ����
	for (size_t i = 0; i < gp.edgeNum; i++)
	{
		c1 = edges[i][0];
		c2 = edges[i][1];
		p1 = findVertexIndex(gp,c1);
		p2 = findVertexIndex(gp,c2);
		pe1 = gp.vertexs[p1].first;
		pe2 = gp.vertexs[p2].first;
		PEnode pnode1 = (PEnode)malloc(sizeof(Enode));
		pnode1->vex = p2;
		pnode1->next = NULL;
		//���ӡ�1������2��
		if (pe1==NULL) {
			gp.vertexs[p1].first = pnode1;
		}
		else {
			linkPEnode(pe1, pnode1);
		}
		PEnode pnode2 = (PEnode)malloc(sizeof(Enode));
		pnode2->vex = p1;
		pnode2->next = NULL;
		//����ͼȥ�����浽��β��һ����
		//���ӡ�2������1��
		if (pe2 == NULL) {
			gp.vertexs[p2].first = pnode2;
		}
		else {
			linkPEnode(pe2, pnode2);
		}
	}
	return gp;
}
//��ӡͼ��¼
void printfGrape(Graph gp) {
	for (size_t i = 0; i < gp.vexNum; i++)
	{
		//��ӡ����
		cout << gp.vertexs[i].data;
		PEnode node = gp.vertexs[i].first;
		while (node)
		{
			//��ӡָ�򶥵�;
			cout <<	"->"<< gp.vertexs[node->vex].data;
			node = node->next;
		}
		cout << endl;
	}
}

//������ȱ�������
void depthFirstTravelRef(Graph gp, int index, int temp[]) {
	PEnode pe;
	cout << gp.vertexs[index].data;
	temp[index] = 1;
	pe = gp.vertexs[index].first;
	//����������һ��
	while (pe) {
		if (temp[pe->vex] == 0) {
			depthFirstTravelRef(gp, pe->vex, temp);
		}
		//����ͷ����
		pe = pe->next;
	}
}

//������ȱ���
void depthFirstTravel(Graph gp) {
	//��ʼ��һ����ʱ�ʶ
	int* temp = (int*)calloc(gp.vexNum,sizeof(int));
	memset(temp, 0, sizeof(temp));
	//�����ڵ���һ�飬�ر���ʼ�ڵ�����յ�
	for (size_t i = 0; i < gp.vexNum; i++)
	{
		if (temp[i] == 0) {
			depthFirstTravelRef(gp, i, temp);
		}

	}
	cout << endl;
}

//������ȱ���
void levelFirstTravel(Graph gp) {
	//��ʼ��һ����ʱ�ʶ
	int* temp = (int*)calloc(gp.vexNum, sizeof(int));
	memset(temp, 0, sizeof(temp));
	//��ʼ�����к������
	queue<int> q;
	PEnode pe;
	int index;
	//����������������ڼ����յ����
	for (size_t i = 0; i < gp.vexNum; i++)
	{
		if (temp[i] == 0) {
			q.push(i);
			temp[i] = 1;
		}
		while (q.size()) {
			index = q.front();
			q.pop();
			cout << gp.vertexs[index].data;
			pe = gp.vertexs[index].first;
			while (pe)
			{
				if (temp[pe->vex] == 0) {
					q.push(pe->vex);
					temp[pe->vex] = 1;
				}
				pe = pe->next;
			}
		}
	}
	cout << endl;
}
int main() {
	Graph gp = initGraph();
	printfGrape(gp);
	//ACBDFGE
	depthFirstTravel(gp);
	//ACDFBGE
	levelFirstTravel(gp);
	return - 1;
}