#pragma warning(disable:4996) 
/* Linear Table On Sequence Structure */
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include<Windows.h>
/*---------����״̬�� ---------*/
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2
#define NOTEXIST -3
typedef int status;
typedef int ElemType; //����Ԫ�����Ͷ���

/*-------�������ʼ��С -------*/
#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10

typedef struct {  //˳���˳��ṹ���Ķ���
	ElemType * elem;
	int length;
	int listsize;
}SqList;
/*-----�������� ---------*/
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
/*----������ʼ----------------------*/
void main(void) {
	SqList L1 = { .elem = NULL }, L2 = { .elem = NULL };
	SqList L ,*p = &L;
	int op = 1;
	int i;
	ElemType e;//������Ԫ��
	ElemType cur, pre_e, next_e;//������Ԫ�أ�ǰ����㣬��̽��
	int L_op;//ѡ������ı�
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
		printf("    ��ѡ����Ĳ���[0~12]:");
		scanf("%d", &op);
		switch (op) {
		case 1:
			printf("��ѡ��Ҫ�����ı�\n");
			printf("1.L1\n");
			printf("2.L2\n");
			do {
				scanf("%d", &L_op);
				if (L_op != 1 && L_op != 2) {
					printf("����������������룡\n");
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
				printf("���Ա����ɹ���\n");
			}
			else {
				printf("���Ա���ʧ�ܣ�\n");
			}
			getchar(); getchar();
			break;
		case 2:
			printf("��ѡ��Ҫ�����ı�\n");
			printf("1.L1\n");
			printf("2.L2\n");
			do {
				scanf("%d", &L_op);
				if (L_op != 1 && L_op != 2) {
					printf("����������������룡\n");
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
				printf("ɾ���ɹ���\n");
			}
			else if(statu== NOTEXIST){
				break;
			}
			else {
				printf("ɾ��ʧ�ܣ�\n");
			}
			getchar(); getchar();
			break;
		case 3:
			printf("��ѡ��Ҫ�����ı�\n");
			printf("1.L1\n");
			printf("2.L2\n");
			do {
				scanf("%d", &L_op);
				if (L_op != 1 && L_op != 2) {
					printf("����������������룡\n");
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
				printf("�ÿձ�ɹ���\n");
			}
			else if(statu==FALSE){
				printf("�ÿձ�ʧ�ܣ�\n");
			}
			else {
				break;
			}
			getchar(); getchar();
			break;
		case 4:
			printf("��ѡ��Ҫ�����ı�\n");
			printf("1.L1\n");
			printf("2.L2\n");
			do {
				scanf("%d", &L_op);
				if (L_op != 1 && L_op != 2) {
					printf("����������������룡\n");
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
				printf("��Ϊ�գ�\n");
			}
			else if(statu==FALSE){
				printf("��Ϊ�գ�\n");
			}
			else {
				break;
			}
			getchar(); getchar();
			break;
		case 5:
			printf("��ѡ��Ҫ�����ı�\n");
			printf("1.L1\n");
			printf("2.L2\n");
			do {
				scanf("%d", &L_op);
				if (L_op != 1 && L_op != 2) {
					printf("����������������룡\n");
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
			printf("��Ϊ%d\n", statu);
			getchar(); getchar();
			break;
		case 6:
			printf("��ѡ��Ҫ�����ı�\n");
			printf("1.L1\n");
			printf("2.L2\n");
			do {
				scanf("%d", &L_op);
				if (L_op != 1 && L_op != 2) {
					printf("����������������룡\n");
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
			printf("������Ҫ��ѯ��λ�ã�");
			scanf("%d", &i);
			if ((statu=GetElem(*p, i, &e)) == OK) {
				printf("%dλ�õ�Ԫ����%d.\n", i, e);
			}
			else if (statu == NOTEXIST) {
				break;
			}
			else {
				printf("��ѯʧ�ܣ�\n");
			}
			getchar(); getchar();
			break;
		case 7:
			printf("��ѡ��Ҫ�����ı�\n");
			printf("1.L1\n");
			printf("2.L2\n");
			do {
				scanf("%d", &L_op);
				if (L_op != 1 && L_op != 2) {
					printf("����������������룡\n");
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
			printf("������Ҫ��ѯ��Ԫ�أ�");
			scanf("%d", &e);
			statu=LocateElem(*p, e);
			if (statu == NOTEXIST) {
				break;
			}
			getchar(); getchar();
			break;
		case 8:
			printf("��ѡ��Ҫ�����ı�\n");
			printf("1.L1\n");
			printf("2.L2\n");
			do {
				scanf("%d", &L_op);
				if (L_op != 1 && L_op != 2) {
					printf("����������������룡\n");
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
			printf("������Ҫ��ѯ�Ľڵ㣺");
			scanf("%d", &cur);
			statu = PriorElem(*p, cur, &pre_e);
			if (statu==NOTEXIST) {
				printf("��ѯʧ�ܣ�\n");
				
			}
			else {
				printf("%d��ǰ���ڵ�Ϊ%d.\n", cur, pre_e);
			}
			getchar(); getchar();
			break;
		case 9:
			printf("��ѡ��Ҫ�����ı�\n");
			printf("1.L1\n");
			printf("2.L2\n");
			do {
				scanf("%d", &L_op);
				if (L_op != 1 && L_op != 2) {
					printf("����������������룡\n");
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
			printf("������Ҫ��ѯ�Ľڵ㣺\n");
			scanf("%d", &cur);
			statu = NextElem(*p, cur, &next_e);
			if (statu==NOTEXIST) {
				printf("��ѯʧ�ܣ�\n");
			}
			else {
				printf("%d�ĺ�̽ڵ�Ϊ%d.\n", cur, next_e);
			}
			getchar(); getchar();
			break;
		case 10:
			printf("��ѡ��Ҫ�����ı�\n");
			printf("1.L1\n");
			printf("2.L2\n");
			do {
				scanf("%d", &L_op);
				if (L_op != 1 && L_op != 2) {
					printf("����������������룡\n");
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
			printf("������Ҫ�����λ�ã�");
			scanf("%d", &i);
			printf("������Ҫ�����Ԫ�أ�");
			scanf("%d", &e);
			if ((statu=ListInsert(p, i, e)) == OK) {
				printf("����ɹ���\n");
			}
			else if (statu == NOTEXIST) {
				break;
			}
			else {
				printf("����ʧ�ܣ�\n");
			}
			getchar(); getchar();
			break;
		case 11:
			printf("��ѡ��Ҫ�����ı�\n");
			printf("1.L1\n");
			printf("2.L2\n");
			do {
				scanf("%d", &L_op);
				if (L_op != 1 && L_op != 2) {
					printf("����������������룡\n");
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
			printf("������Ҫɾ����λ�ã�");
			scanf("%d", &i);
			if ((statu=ListDelete(p, i, &e)) == OK) {
				printf("%dɾ���ɹ���\n", e);
			}
			else if (statu == NOTEXIST) {
				break;
			}
			else {
				printf("%dɾ��ʧ�ܣ�\n", e);
			}
			getchar(); getchar();
			break;
		case 12:
			printf("��ѡ��Ҫ�����ı�\n");
			printf("1.L1\n");
			printf("2.L2\n");
			do {
				scanf("%d", &L_op);
				if (L_op != 1 && L_op != 2) {
					printf("����������������룡\n");
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
				printf("������ϣ�\n");
			}
			else if(statu==NOTEXIST){
				break;
			}
			getchar(); getchar();
			break;
		case 13:
			printf("��ѡ��Ҫ�����ı�\n");
			printf("1.L1\n");
			printf("2.L2\n");
			do {
				scanf("%d", &L_op);
				if (L_op != 1 && L_op != 2) {
					printf("����������������룡\n");
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
				printf("          ����ɹ���\n");
			}
			else if (statu == NOTEXIST) {
				break;
			}
			else {
				printf("          ����ʧ�ܣ�\n");
			}
			getchar(); getchar();
			break;
		case 0:
			printf("��ѡ��Ҫ�����ı�\n");
			printf("1.L1\n");
			printf("2.L2\n");
			do {
				scanf("%d", &L_op);
				if (L_op != 1 && L_op != 2) {
					printf("����������������룡\n");
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
			printf("���ڱ�������....\n");
			Sleep(1000);
			if ((saveList(*p))==OK) {
				printf("����ɹ���\n");
			}
			else {
				printf("����ʧ�ܣ�\n");
			}

			Sleep(1000);
			break;
		}//end of switch
	}//end of while
	printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");
}//end of main()

 /*--------page 23 on textbook --------------------*/
 //�������ƣ�IntiaList
 //�������ܣ���ʼ����Ϊelem����ռ䣬��ʼ����Ϊ0�����СΪList_INIT_SIZE
 //���������ָ����ָ��
 //������������
 //�� �� ֵ���ɹ�����OK
 //����˵������
status IntiaList(SqList *p) {
	//����洢�ռ�
	p->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	//�ռ����ʧ��
	if (!p->elem) {
		exit(OVERFLOW);
	}
	//��ʼ������Ϊ0
	p->length = 0;
	//��ʼ���ռ�Ϊ100
	p->listsize = LIST_INIT_SIZE;
	return OK;
}





//�������ƣ� DestroyList
//�������ܣ�ɾ���б�
//���������ָ���б��ָ��p
//������������
//�� �� ֵ��״̬��
//����˵������
status DestroyList(SqList *p) {
	SqList L = *p;
	if (!ListExist(L)) {
		printf("�б����ڣ�\n");
		system("pause");
		return NOTEXIST;
	}
	//�ͷſռ�
	free(p->elem);
	//��Ϊ0
	p->length = 0;
	//�ռ���ΪNULL
	p->elem = NULL;
	return OK;
}


//�������ƣ� ClearList
//�������ܣ��ÿձ�
//���������ָ���б��ָ��p
//������������
//�� �� ֵ��״̬��
//����˵������
status ClearList(SqList *p) {
	SqList L = *p;
	if (!ListExist(L)) {
		printf("�б����ڣ�\n");
		system("pause");
		return NOTEXIST;
	}
	p->length = 0;
	return OK;

}

//�������ƣ� ListEmpty
//�������ܣ��пձ�
//����������б�����L
//������������
//�� �� ֵ��״̬��
//����˵������
status ListEmpty(SqList L) {
	if (!ListExist(L)) {
		printf("�б����ڣ�\n");
		system("pause");
		return NOTEXIST;
	}
	if (!L.length) {
		return OK;
	}
	return FALSE;
}

//�������ƣ� ListLength
//�������ܣ���ѯ��ĳ���
//�����������L
//������������
//�� �� ֵ����
//����˵������
int ListLength(SqList L) {
	if (!ListExist(L)) {
		printf("�б����ڣ�\n");
		system("pause");
		return NOTEXIST;
	}
	return L.length;
}

//�������ƣ� GetElem
//�������ܣ���ѯ��Ԫ��
//�����������L,λ�ò���i
//������������ѯ����Ԫ��e
//�� �� ֵ��״̬��
//����˵������
status GetElem(SqList L, int i, ElemType *e) {
	if (!ListExist(L)) {
		printf("�б����ڣ�\n");
		system("pause");
		return NOTEXIST;
	}
	if (ListLength == 0) {
		printf("��Ϊ0��\n");
		return FALSE;
	}
	if (i > L.length || i < 0) {
		printf("�������������[1,%d]֮������֣�\n", L.length);
		return FALSE;
	}
	*e = L.elem[i - 1];
	return OK;
}

//�������ƣ� LocateElem
//�������ܣ���ѯĳԪ���Ƿ����
//����������б�L��Ԫ��e
//������������
//�� �� ֵ��״̬��
//����˵������
status LocateElem(SqList L, ElemType e) {
	if (!ListExist(L)) {
		printf("�б����ڣ�\n");
		system("pause");
		return NOTEXIST;
	}
	int loop = 0;
	for (loop; loop < L.length; loop++) {
		if (L.elem[loop] == e) {
			printf("Ԫ�ش��ڣ�\n");
			return OK;
		}
	}
	printf("Ԫ�ز����ڣ�\n");
	return OK;
}

//�������ƣ� PriorElem
//�������ܣ�����curԪ�ص�ǰ�����
//����������б�L��Ԫ��cur
//����������ǰ�����pre_e
//�� �� ֵ��״̬��
//����˵������
status PriorElem(SqList L, ElemType cur, ElemType *pre_e) {
	if (!ListExist(L)) {
		printf("�б����ڣ�\n");
		system("pause");
		return NOTEXIST;
	}
	if (L.elem[0] == cur) {
		printf("%dΪ��һ��Ԫ�أ���ǰ����㣡\n",cur);
		return FALSE;
	}
	int loop = 1;
	for (loop; loop < L.length; loop++) {
		if (L.elem[loop] == cur) {
			*pre_e = L.elem[loop - 1];
			return OK;
		}
	}
	printf("%d�����ڣ�\n",cur);
	return FALSE;
}


//�������ƣ� NextElem
//�������ܣ�����curԪ�صĺ�̽��
//����������б�L��Ԫ��cur
//������������̽��next_e
//�� �� ֵ��״̬��
//����˵������
status NextElem(SqList L, ElemType cur, ElemType *next_e) {
	if (!ListExist(L)) {
		printf("�б����ڣ�\n");
		system("pause");
		return NOTEXIST;
	}
	if (L.elem[L.length-1] == cur) {
		printf("%dΪ���һ��Ԫ�أ��޺�̽�㣡\n",cur);
		return FALSE;
	}
	int loop = 0;
	for (loop; loop < L.length-1; loop++) {
		if (L.elem[loop] == cur) {
			*next_e = L.elem[loop + 1];
			return OK;
		}
	}
	printf("%d�����ڣ�\n",cur);
	return FALSE;
}

//�������ƣ� ListInsert
//�������ܣ���������
//���������ָ���б��ָ��p,����λ��i��������Ԫ��e
//������������
//�� �� ֵ��״̬��
//����˵������
status ListInsert(SqList *p, int i, ElemType e) {
	if (!ListExist(*p)) {
		printf("�б����ڣ�\n");
		system("pause");
		return NOTEXIST;
	}
	if (i< 1|| i>p->length+1) {
		printf("����λ�ô���\n");
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

//�������ƣ� ListCreate
//�������ܣ���ʼ���б�����
//���������ָ���б��ָ��p
//������������
//�� �� ֵ��״̬��
//����˵������
status ListDelete(SqList *p, int i, ElemType *e) {
	if (!ListExist(*p)) {
		printf("�б����ڣ�\n");
		system("pause");
		return NOTEXIST;
	}
	if (i< 1 || i>p->length + 1) {
		printf("ɾ��λ�ô���\n");
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


//�������ƣ� ListTrabverse
//�������ܣ����� �б�����
//����������б�L
//������������
//�� �� ֵ��״̬��
//����˵������
status ListTrabverse(SqList L,status (*visit)(int ,ElemType)) {
	if (!ListExist(L)) {
		printf("�б����ڣ�\n");
		system("pause");
		return NOTEXIST;
	}
	if (L.length == 0) {
		printf("��Ϊ�գ�\n");
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
//�������ƣ� ListCreate
//�������ܣ���ʼ���б�����
//���������ָ���б��ָ��p
//������������
//�� �� ֵ��״̬��
//����˵������
status ListCreate(SqList *p) {
	SqList L = *p;
	int op = 0;
	if (ListExist(L) == FALSE) {
		printf("    	  �����ڣ��޷����룡\n");
		system("pause");
		return NOTEXIST;
	}
	if (p->length) {
		printf("    	  ���Ѿ��������ݣ��޷���������!");
		return FALSE;
	}
	printf("    	  ��ѡ�����뷽ʽ��\n");
	printf("    	  1.��ͬһĿ¼�µ�data.bat�ļ���ȡ��\n");
	printf("    	  2.����\n");
	do {
		printf("         ��ѡ��");
		scanf("%d", &op);
		if (op != 1 && op != 2) {
			printf("    	  �������������ѡ��\n");
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

//�������ƣ�InitListFromFile
//�������ܣ����ļ���ȡ�������뵽����
//���������ָ����ָ��
//������������
//�� �� ֵ���ɹ�����OK��ʧ�ܷ���FALSE
//����˵������
status InitListFromFile(SqList *p) {
	FILE *fp;
	if ((fp = fopen("data.dat", "r")) == NULL) {
		printf("���ļ�ʧ�ܣ������Ŀ¼���Ƿ���������ļ���\n");
		return FALSE;
	}

	while (fread(&(p->elem[p->length]), sizeof(ElemType), 1, fp)) {
		++(p->length);
	}
	if (fclose(fp)==-1) {
		printf("�ر��ļ�ʧ�ܣ�\n");
		return FALSE;
	}
	return OK;
}


//�������ƣ�InitListFromInput
//�������ܣ���ʼ����ʹ�����������
//���������ָ����ָ��
//������������
//�� �� ֵ��״̬��OK
//����˵������
status InitListFromInput(SqList *p) {
	int length = 0;
	int elem;
	printf("         �������ܹ��������������");
	scanf("%d", &length);
	for (int loop = 0; loop < length; loop++) {
		printf("�������%d������:", loop + 1);
		scanf("%d", &elem);
		ListInsert(p, loop + 1, elem);
	}
	return OK;
}


//�������ƣ�saveList
//�������ܣ���������е����ݵ��ļ���
//���������
//����������
//�� �� ֵ��
//����˵������ѡ��exit�˳�ʱ����������ѡ�񱣴�
status saveList(SqList L) {
	FILE *fp;
	if ((fp = fopen("data.dat", "w")) == NULL) {
		printf("���ļ�ʧ�ܣ������Ŀ¼���Ƿ���������ļ���\n");
		return FALSE;
	}
	fwrite(L.elem, sizeof(ElemType), L.length, fp);
	if (fclose(fp)==-1) {
		printf("�ر��ļ�ʧ�ܣ�\n");
		system("pause");
		return FALSE;
	}
	return OK;
}

//����˵����
//�������ƣ�ListExist
//�������ܣ��жϱ��Ƿ����
//���������L
//������������
//�� �� ֵ�����ڷ���OK�������ڷ���FALSE
//����˵������
status ListExist(SqList L) {
	if (L.elem) {
		//������ڷ���OK
		return OK;
	}
	//�����ڷ���FALSE
	return FALSE;
}

status visit(int i, ElemType e) {
	printf("�б��%d��λ�õ�Ԫ��Ϊ%d��\n", i+1, e);
	return OK;
}
