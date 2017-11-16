#pragma warning(disable:4996) 
/* Linear Table On Sequence Structure */
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include<Windows.h>
/*---------定义状态码 ---------*/
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2
#define NOTEXIST -3
typedef int status;
typedef int ElemType; //数据元素类型定义

/*-------定义表长初始大小 -------*/
#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10

typedef struct {  //顺序表（顺序结构）的定义
	ElemType * elem;
	int length;
	int listsize;
}SqList;
/*-----函数定义 ---------*/
status IntiaList(SqList *p);
status DestroyList(SqList *p);
status ClearList(SqList *p);
status ListEmpty(SqList L);
int ListLength(SqList L);
status GetElem(SqList L, int i, ElemType *e);
status LocateElem(SqList L, ElemType e);
status PriorElem(SqList L, ElemType cur, ElemType *pre_e);
status NextElem(SqList L,ElemType cur,ElemType *next_e);
status ListInsert(SqList *p,int i,ElemType e);
status ListDelete(SqList *L, int i, ElemType *e);
status ListTrabverse(SqList L,status (*visit)(int ,ElemType));
status InitListFromFile(SqList *p);
status InitListFromInput(SqList *p);
status ListExist(SqList L);
status ListCreate(SqList *p);
status saveList(SqList L);
status visit(int i,ElemType e);
/*----主程序开始----------------------*/
void main(void) {
	SqList L1 = { .elem = NULL }, L2 = { .elem = NULL };
	SqList L ,*p = &L;
	int op = 1;
	int i;
	ElemType e;//操作的元素
	ElemType cur, pre_e, next_e;//操作的元素，前驱结点，后继结点
	int L_op;//选择操作的表
	status statu;
	while (op) {
		system("cls");
		printf("\n\n");
		printf("      Menu for Linear Table On Sequence Structure \n");
		printf("-------------------------------------------------\n");
		printf("    	  1. IntiaList       7. LocateElem\n");
		printf("    	  2. DestroyList     8. PriorElem\n");
		printf("    	  3. ClearList       9. NextElem \n");
		printf("    	  4. ListEmpty       10. ListInsert\n");
		printf("    	  5. ListLength      11. ListDelete\n");
		printf("    	  6. GetElem         12. ListTrabverse\n");
		printf("    	  13.ListGreate\n");
		printf("    	  0. Exit\n");
		printf("-------------------------------------------------\n");
		printf("    请选择你的操作[0~12]:");
		scanf("%d", &op);
		switch (op) {
		case 1:
			printf("请选择要操作的表：\n");
			printf("1.L1\n");
			printf("2.L2\n");
			do {
				scanf("%d", &L_op);
				if (L_op != 1 && L_op != 2) {
					printf("输入错误，请重新输入！\n");
				}
			} while (L_op != 1 && L_op != 2);
			if (L_op == 1) {
				p = &L1;
			}
			else if(L_op==2){
				p =&L2;
			}
			else {
				break;
			}
			if (IntiaList(p) == OK) {
				printf("线性表创建成功！\n");
			}
			else {
				printf("线性表创建失败！\n");
			}
			getchar(); getchar();
			break;
		case 2:
			printf("请选择要操作的表：\n");
			printf("1.L1\n");
			printf("2.L2\n");
			do {
				scanf("%d", &L_op);
				if (L_op != 1 && L_op != 2) {
					printf("输入错误，请重新输入！\n");
				}
			} while (L_op != 1 && L_op != 2);
			if (L_op == 1) {
				p = &L1;
			}
			else if (L_op == 2) {
				p = &L2;
			}
			else {
				break;
			}
			if ((statu=DestroyList(p))==OK) {
				printf("删除成功！\n");
			}
			else if(statu== NOTEXIST){
				break;
			}
			else {
				printf("删除失败！\n");
			}
			getchar(); getchar();
			break;
		case 3:
			printf("请选择要操作的表：\n");
			printf("1.L1\n");
			printf("2.L2\n");
			do {
				scanf("%d", &L_op);
				if (L_op != 1 && L_op != 2) {
					printf("输入错误，请重新输入！\n");
				}
			} while (L_op != 1 && L_op != 2);
			if (L_op == 1) {
				p = &L1;
			}
			else if (L_op == 2) {
				p = &L2;
			}
			else {
				break;
			}
			if ((statu=ClearList(p))==OK) {
				printf("置空表成功！\n");
			}
			else if(statu==FALSE){
				printf("置空表失败！\n");
			}
			else {
				break;
			}
			getchar(); getchar();
			break;
		case 4:
			printf("请选择要操作的表：\n");
			printf("1.L1\n");
			printf("2.L2\n");
			do {
				scanf("%d", &L_op);
				if (L_op != 1 && L_op != 2) {
					printf("输入错误，请重新输入！\n");
				}
			} while (L_op != 1 && L_op != 2);
			if (L_op == 1) {
				p= &L1;
			}
			else if (L_op == 2) {
				p = &L2;
			}
			else {
				break;
			}
			if ((statu=ListEmpty(*p))==OK) {
				printf("表为空！\n");
			}
			else if(statu==FALSE){
				printf("表不为空！\n");
			}
			else {
				break;
			}
			getchar(); getchar();
			break;
		case 5:
			printf("请选择要操作的表：\n");
			printf("1.L1\n");
			printf("2.L2\n");
			do {
				scanf("%d", &L_op);
				if (L_op != 1 && L_op != 2) {
					printf("输入错误，请重新输入！\n");
				}
			} while (L_op != 1 && L_op != 2);
			if (L_op == 1) {
				p = &L1;
			}
			else if (L_op == 2) {
				p = &L2;
			}
			else {
				break;
			}
			if ((statu = ListLength(*p)) == NOTEXIST) {
				break;
			}
			printf("表长为%d\n", statu);
			getchar(); getchar();
			break;
		case 6:
			printf("请选择要操作的表：\n");
			printf("1.L1\n");
			printf("2.L2\n");
			do {
				scanf("%d", &L_op);
				if (L_op != 1 && L_op != 2) {
					printf("输入错误，请重新输入！\n");
				}
			} while (L_op != 1 && L_op != 2);
			if (L_op == 1) {
				p = &L1;
			}
			else if (L_op == 2) {
				p = &L2;
			}
			else {
				break;
			}
			printf("请输入要查询的位置：");
			scanf("%d", &i);
			if ((statu=GetElem(*p, i, &e)) == OK) {
				printf("%d位置的元素是%d.\n", i, e);
			}
			else if (statu == NOTEXIST) {
				break;
			}
			else {
				printf("查询失败！\n");
			}
			getchar(); getchar();
			break;
		case 7:
			printf("请选择要操作的表：\n");
			printf("1.L1\n");
			printf("2.L2\n");
			do {
				scanf("%d", &L_op);
				if (L_op != 1 && L_op != 2) {
					printf("输入错误，请重新输入！\n");
				}
			} while (L_op != 1 && L_op != 2);
			if (L_op == 1) {
				p = &L1;
			}
			else if (L_op == 2) {
				p = &L2;
			}
			else {
				break;
			}
			printf("请输入要查询的元素：");
			scanf("%d", &e);
			statu=LocateElem(*p, e);
			if (statu == NOTEXIST) {
				break;
			}
			getchar(); getchar();
			break;
		case 8:
			printf("请选择要操作的表：\n");
			printf("1.L1\n");
			printf("2.L2\n");
			do {
				scanf("%d", &L_op);
				if (L_op != 1 && L_op != 2) {
					printf("输入错误，请重新输入！\n");
				}
			} while (L_op != 1 && L_op != 2);
			if (L_op == 1) {
				p = &L1;
			}
			else if (L_op == 2) {
				p = &L2;
			}
			else {
				break;
			}
			printf("请输入要查询的节点：");
			scanf("%d", &cur);
			statu = PriorElem(*p, cur, &pre_e);
			if (statu==NOTEXIST) {
				printf("查询失败！\n");
				
			}
			else {
				printf("%d的前驱节点为%d.\n", cur, pre_e);
			}
			getchar(); getchar();
			break;
		case 9:
			printf("请选择要操作的表：\n");
			printf("1.L1\n");
			printf("2.L2\n");
			do {
				scanf("%d", &L_op);
				if (L_op != 1 && L_op != 2) {
					printf("输入错误，请重新输入！\n");
				}
			} while (L_op != 1 && L_op != 2);
			if (L_op == 1) {
				p = &L1;
			}
			else if (L_op == 2) {
				p = &L2;
			}
			else {
				break;
			}
			printf("请输入要查询的节点：\n");
			scanf("%d", &cur);
			statu = NextElem(*p, cur, &next_e);
			if (statu==NOTEXIST) {
				printf("查询失败！\n");
			}
			else {
				printf("%d的后继节点为%d.\n", cur, next_e);
			}
			getchar(); getchar();
			break;
		case 10:
			printf("请选择要操作的表：\n");
			printf("1.L1\n");
			printf("2.L2\n");
			do {
				scanf("%d", &L_op);
				if (L_op != 1 && L_op != 2) {
					printf("输入错误，请重新输入！\n");
				}
			} while (L_op != 1 && L_op != 2);
			if (L_op == 1) {
				p = &L1;
			}
			else if (L_op == 2) {
				p = &L2;
			}
			else {
				break;
			}
			printf("请输入要插入的位置：");
			scanf("%d", &i);
			printf("请输入要插入的元素：");
			scanf("%d", &e);
			if ((statu=ListInsert(p, i, e)) == OK) {
				printf("插入成功！\n");
			}
			else if (statu == NOTEXIST) {
				break;
			}
			else {
				printf("插入失败！\n");
			}
			getchar(); getchar();
			break;
		case 11:
			printf("请选择要操作的表：\n");
			printf("1.L1\n");
			printf("2.L2\n");
			do {
				scanf("%d", &L_op);
				if (L_op != 1 && L_op != 2) {
					printf("输入错误，请重新输入！\n");
				}
			} while (L_op != 1 && L_op != 2);
			if (L_op == 1) {
				p = &L1;
			}
			else if (L_op == 2) {
				p = &L2;
			}
			else {
				break;
			}
			printf("请输入要删除的位置：");
			scanf("%d", &i);
			if ((statu=ListDelete(p, i, &e)) == OK) {
				printf("%d删除成功！\n", e);
			}
			else if (statu == NOTEXIST) {
				break;
			}
			else {
				printf("%d删除失败！\n", e);
			}
			getchar(); getchar();
			break;
		case 12:
			printf("请选择要操作的表：\n");
			printf("1.L1\n");
			printf("2.L2\n");
			do {
				scanf("%d", &L_op);
				if (L_op != 1 && L_op != 2) {
					printf("输入错误，请重新输入！\n");
				}
			} while (L_op != 1 && L_op != 2);
			if (L_op == 1) {
				p = &L1;
			}
			else if (L_op == 2) {
				p = &L2;
			}
			else {
				break;
			}
			if ((statu=ListTrabverse(*p,visit)) == OK) {
				printf("访问完毕！\n");
			}
			else if(statu==NOTEXIST){
				break;
			}
			getchar(); getchar();
			break;
		case 13:
			printf("请选择要操作的表：\n");
			printf("1.L1\n");
			printf("2.L2\n");
			do {
				scanf("%d", &L_op);
				if (L_op != 1 && L_op != 2) {
					printf("输入错误，请重新输入！\n");
				}
			} while (L_op != 1 && L_op != 2);
			if (L_op == 1) {
				p = &L1;
			}
			else if (L_op == 2) {
				p = &L2;
			}
			else {
				break;
			}
			if ((statu=ListCreate(p))==OK) {
				printf("          插入成功！\n");
			}
			else if (statu == NOTEXIST) {
				break;
			}
			else {
				printf("          插入失败！\n");
			}
			getchar(); getchar();
			break;
		case 0:
			printf("请选择要操作的表：\n");
			printf("1.L1\n");
			printf("2.L2\n");
			do {
				scanf("%d", &L_op);
				if (L_op != 1 && L_op != 2) {
					printf("输入错误，请重新输入！\n");
				}
			} while (L_op != 1 && L_op != 2);
			if (L_op == 1) {
				p = &L1;
			}
			else if (L_op == 2) {
				p = &L2;
			}
			else {
				break;
			}
			printf("正在保存数据....\n");
			Sleep(1000);
			if ((saveList(*p))==OK) {
				printf("保存成功！\n");
			}
			else {
				printf("保存失败！\n");
			}

			Sleep(1000);
			break;
		}//end of switch
	}//end of while
	printf("欢迎下次再使用本系统！\n");
}//end of main()

 /*--------page 23 on textbook --------------------*/
 //函数名称：IntiaList
 //函数功能：初始化表，为elem分配空间，初始化表长为0，表大小为List_INIT_SIZE
 //传入参数：指向表的指针
 //传出参数：无
 //返 回 值：成功返回OK
 //调用说明：无
status IntiaList(SqList *p) {
	//分配存储空间
	p->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	//空间分配失败
	if (!p->elem) {
		exit(OVERFLOW);
	}
	//初始化长度为0
	p->length = 0;
	//初始化空间为100
	p->listsize = LIST_INIT_SIZE;
	return OK;
}





//函数名称： DestroyList
//函数功能：删除列表
//传入参数：指向列表的指针p
//传出参数：无
//返 回 值：状态码
//调用说明：无
status DestroyList(SqList *p) {
	SqList L = *p;
	if (!ListExist(L)) {
		printf("列表不存在！\n");
		system("pause");
		return NOTEXIST;
	}
	//释放空间
	free(p->elem);
	//表长为0
	p->length = 0;
	//空间置为NULL
	p->elem = NULL;
	return OK;
}


//函数名称： ClearList
//函数功能：置空表
//传入参数：指向列表的指针p
//传出参数：无
//返 回 值：状态码
//调用说明：无
status ClearList(SqList *p) {
	SqList L = *p;
	if (!ListExist(L)) {
		printf("列表不存在！\n");
		system("pause");
		return NOTEXIST;
	}
	p->length = 0;
	return OK;

}

//函数名称： ListEmpty
//函数功能：判空表
//传入参数：列表名称L
//传出参数：无
//返 回 值：状态码
//调用说明：无
status ListEmpty(SqList L) {
	if (!ListExist(L)) {
		printf("列表不存在！\n");
		system("pause");
		return NOTEXIST;
	}
	if (!L.length) {
		return OK;
	}
	return FALSE;
}

//函数名称： ListLength
//函数功能：查询表的长度
//传入参数：表L
//传出参数：无
//返 回 值：表长
//调用说明：无
int ListLength(SqList L) {
	if (!ListExist(L)) {
		printf("列表不存在！\n");
		system("pause");
		return NOTEXIST;
	}
	return L.length;
}

//函数名称： GetElem
//函数功能：查询表元素
//传入参数：表L,位置参数i
//传出参数：查询所得元素e
//返 回 值：状态码
//调用说明：无
status GetElem(SqList L, int i, ElemType *e) {
	if (!ListExist(L)) {
		printf("列表不存在！\n");
		system("pause");
		return NOTEXIST;
	}
	if (ListLength == 0) {
		printf("表长为0！\n");
		return FALSE;
	}
	if (i > L.length || i < 0) {
		printf("输入错误，请输入[1,%d]之间的数字！\n", L.length);
		return FALSE;
	}
	*e = L.elem[i - 1];
	return OK;
}

//函数名称： LocateElem
//函数功能：查询某元素是否存在
//传入参数：列表L，元素e
//传出参数：无
//返 回 值：状态码
//调用说明：无
status LocateElem(SqList L, ElemType e) {
	if (!ListExist(L)) {
		printf("列表不存在！\n");
		system("pause");
		return NOTEXIST;
	}
	int loop = 0;
	for (loop; loop < L.length; loop++) {
		if (L.elem[loop] == e) {
			printf("元素存在！\n");
			return OK;
		}
	}
	printf("元素不存在！\n");
	return OK;
}

//函数名称： PriorElem
//函数功能：查找cur元素的前驱结点
//传入参数：列表L，元素cur
//传出参数：前驱结点pre_e
//返 回 值：状态码
//调用说明：无
status PriorElem(SqList L, ElemType cur, ElemType *pre_e) {
	if (!ListExist(L)) {
		printf("列表不存在！\n");
		system("pause");
		return NOTEXIST;
	}
	if (L.elem[0] == cur) {
		printf("%d为第一个元素，无前驱结点！\n",cur);
		return FALSE;
	}
	int loop = 1;
	for (loop; loop < L.length; loop++) {
		if (L.elem[loop] == cur) {
			*pre_e = L.elem[loop - 1];
			return OK;
		}
	}
	printf("%d不存在！\n",cur);
	return FALSE;
}


//函数名称： NextElem
//函数功能：查找cur元素的后继结点
//传入参数：列表L，元素cur
//传出参数：后继结点next_e
//返 回 值：状态码
//调用说明：无
status NextElem(SqList L, ElemType cur, ElemType *next_e) {
	if (!ListExist(L)) {
		printf("列表不存在！\n");
		system("pause");
		return NOTEXIST;
	}
	if (L.elem[L.length-1] == cur) {
		printf("%d为最后一个元素，无后继结点！\n",cur);
		return FALSE;
	}
	int loop = 0;
	for (loop; loop < L.length-1; loop++) {
		if (L.elem[loop] == cur) {
			*next_e = L.elem[loop + 1];
			return OK;
		}
	}
	printf("%d不存在！\n",cur);
	return FALSE;
}

//函数名称： ListInsert
//函数功能：插入数据
//传入参数：指向列表的指针p,插入位置i，待插入元素e
//传出参数：无
//返 回 值：状态码
//调用说明：无
status ListInsert(SqList *p, int i, ElemType e) {
	if (!ListExist(*p)) {
		printf("列表不存在！\n");
		system("pause");
		return NOTEXIST;
	}
	if (i< 1|| i>p->length+1) {
		printf("插入位置错误！\n");
		return FALSE;
	}
	if (p->length >= p->listsize) {
		ElemType *newbase = (ElemType *)realloc(p->elem, (p->listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase) {
			exit(OVERFLOW);
		}
		p->elem = newbase;
		p->listsize += LISTINCREMENT;
	}
	int loop = p->length-1;
	for (loop; loop >= i-1; loop--) {
		p->elem[loop + 1] = p->elem[loop];
	}
	++(p->length);
	p->elem[i - 1] = e;
	return OK;
}

//函数名称： ListCreate
//函数功能：初始化列表数据
//传入参数：指向列表的指针p
//传出参数：无
//返 回 值：状态码
//调用说明：无
status ListDelete(SqList *p, int i, ElemType *e) {
	if (!ListExist(*p)) {
		printf("列表不存在！\n");
		system("pause");
		return NOTEXIST;
	}
	if (i< 1 || i>p->length + 1) {
		printf("删除位置错误！\n");
		return FALSE;
	}
	*e = p->elem[i - 1];
	int loop = i-1;
	for (loop; loop <p->length ; loop++) {
		p->elem[loop] = p->elem[loop + 1];
	}
	--(p->length);
	return OK;
}


//函数名称： ListTrabverse
//函数功能：访问 列表数据
//传入参数：列表L
//传出参数：无
//返 回 值：状态码
//调用说明：无
status ListTrabverse(SqList L,status (*visit)(int ,ElemType)) {
	if (!ListExist(L)) {
		printf("列表不存在！\n");
		system("pause");
		return NOTEXIST;
	}
	if (L.length == 0) {
		printf("表为空！\n");
		return OK;
	}
	int loop = 0;
	printf("\n-----------all elements -----------------------\n");
	for (loop; loop < L.length; loop++) {
		visit(loop, L.elem[loop]);
	}
	printf("\n------------------ end ------------------------\n");
	return OK;
}
//函数名称： ListCreate
//函数功能：初始化列表数据
//传入参数：指向列表的指针p
//传出参数：无
//返 回 值：状态码
//调用说明：无
status ListCreate(SqList *p) {
	SqList L = *p;
	int op = 0;
	if (ListExist(L) == FALSE) {
		printf("    	  表不存在！无法输入！\n");
		system("pause");
		return NOTEXIST;
	}
	if (p->length) {
		printf("    	  表已经输入数据，无法重新输入!");
		return FALSE;
	}
	printf("    	  请选择输入方式：\n");
	printf("    	  1.从同一目录下的data.bat文件读取。\n");
	printf("    	  2.输入\n");
	do {
		printf("         请选择：");
		scanf("%d", &op);
		if (op != 1 && op != 2) {
			printf("    	  输入错误，请重新选择！\n");
		}
	} while (op != 1 && op != 2);
	switch (op) {
	case 1:
		if (InitListFromFile(p)) {
			return OK;
		}
		return FALSE;
	case 2:
		if (InitListFromInput(p)) {
			return OK;
		}
		return FALSE;
	}
	return FALSE;
}

//函数名称：InitListFromFile
//函数功能：从文件读取数据输入到表中
//传入参数：指向表的指针
//传出参数：无
//返 回 值：成功返回OK，失败返回FALSE
//调用说明：无
status InitListFromFile(SqList *p) {
	FILE *fp;
	if ((fp = fopen("data.dat", "r")) == NULL) {
		printf("打开文件失败！请检查该目录下是否存在数据文件！\n");
		return FALSE;
	}

	while (fread(&(p->elem[p->length]), sizeof(ElemType), 1, fp)) {
		++(p->length);
	}
	if (fclose(fp)==-1) {
		printf("关闭文件失败！\n");
		return FALSE;
	}
	return OK;
}


//函数名称：InitListFromInput
//函数功能：初始化表，使用输入的数据
//传入参数：指向表的指针
//传出参数：无
//返 回 值：状态码OK
//调用说明：无
status InitListFromInput(SqList *p) {
	int length = 0;
	int elem;
	printf("         请输入总共输入的数据量：");
	scanf("%d", &length);
	for (int loop = 0; loop < length; loop++) {
		printf("请输入第%d个数据:", loop + 1);
		scanf("%d", &elem);
		ListInsert(p, loop + 1, elem);
	}
	return OK;
}


//函数名称：saveList
//函数功能：保存程序中的数据到文件，
//传入参数：
//传出参数：
//返 回 值：
//调用说明：在选择exit退出时，或者主动选择保存
status saveList(SqList L) {
	FILE *fp;
	if ((fp = fopen("data.dat", "w")) == NULL) {
		printf("打开文件失败！请检查该目录下是否存在数据文件！\n");
		return FALSE;
	}
	fwrite(L.elem, sizeof(ElemType), L.length, fp);
	if (fclose(fp)==-1) {
		printf("关闭文件失败！\n");
		system("pause");
		return FALSE;
	}
	return OK;
}

//调用说明：
//函数名称：ListExist
//函数功能：判断表是否存在
//传入参数：L
//传出参数：无
//返 回 值：存在返回OK，不存在返回FALSE
//调用说明：无
status ListExist(SqList L) {
	if (L.elem) {
		//当表存在返回OK
		return OK;
	}
	//表不存在返回FALSE
	return FALSE;
}

status visit(int i, ElemType e) {
	printf("列表第%d个位置的元素为%d。\n", i+1, e);
	return OK;
}
