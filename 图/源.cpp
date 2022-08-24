#include <iostream>
#include <queue>
#include <malloc.h>
#include <stdlib.h>
using namespace std;
#define MaxSize 100
//顶点邻接表
typedef struct Enode {
	int vex;//指向顶点下标
	struct Enode* next;
}Enode,*PEnode;
//图的顶点存储
typedef struct Vertex {
	char data;
	struct Enode* first;
}VNode;

//图存储结构
typedef struct Graph {
	int vexNum;//顶点数
	int edgeNum;// 边数
	Vertex vertexs[MaxSize];
}Graph;


//查找顶点所在下标
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

//顶点链接
static void linkPEnode(PEnode p1,PEnode p2) {
	PEnode p = p1;
	while (p->next)
	{
		p = p->next;
	}
	p->next = p2;
}

//初始化无向图
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
	//初始化顶点
	for (size_t i = 0; i < gp.vexNum; i++)
	{
		gp.vertexs[i].data = vexs[i];
		gp.vertexs[i].first = NULL;
	}
	char c1, c2;
	int p1, p2;
	PEnode pe1, pe2;
	//初始化边
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
		//链接【1】到【2】
		if (pe1==NULL) {
			gp.vertexs[p1].first = pnode1;
		}
		else {
			linkPEnode(pe1, pnode1);
		}
		PEnode pnode2 = (PEnode)malloc(sizeof(Enode));
		pnode2->vex = p1;
		pnode2->next = NULL;
		//有向图去掉下面到结尾这一部分
		//链接【2】到【1】
		if (pe2 == NULL) {
			gp.vertexs[p2].first = pnode2;
		}
		else {
			linkPEnode(pe2, pnode2);
		}
	}
	return gp;
}
//打印图记录
void printfGrape(Graph gp) {
	for (size_t i = 0; i < gp.vexNum; i++)
	{
		//打印自身
		cout << gp.vertexs[i].data;
		PEnode node = gp.vertexs[i].first;
		while (node)
		{
			//打印指向顶点;
			cout <<	"->"<< gp.vertexs[node->vex].data;
			node = node->next;
		}
		cout << endl;
	}
}

//深度优先遍历引用
void depthFirstTravelRef(Graph gp, int index, int temp[]) {
	PEnode pe;
	cout << gp.vertexs[index].data;
	temp[index] = 1;
	pe = gp.vertexs[index].first;
	//持续查找下一层
	while (pe) {
		if (temp[pe->vex] == 0) {
			depthFirstTravelRef(gp, pe->vex, temp);
		}
		//到尽头回溯
		pe = pe->next;
	}
}

//深度优先遍历
void depthFirstTravel(Graph gp) {
	//初始化一组访问标识
	int* temp = (int*)calloc(gp.vexNum,sizeof(int));
	memset(temp, 0, sizeof(temp));
	//挨个节点走一遍，回避起始节点就是终点
	for (size_t i = 0; i < gp.vexNum; i++)
	{
		if (temp[i] == 0) {
			depthFirstTravelRef(gp, i, temp);
		}

	}
	cout << endl;
}

//广度优先遍历
void levelFirstTravel(Graph gp) {
	//初始化一组访问标识
	int* temp = (int*)calloc(gp.vexNum, sizeof(int));
	memset(temp, 0, sizeof(temp));
	//初始化队列横向遍历
	queue<int> q;
	PEnode pe;
	int index;
	//挨个遍历，避免入口即是终点情况
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