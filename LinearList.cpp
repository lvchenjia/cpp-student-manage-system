#include <stdio.h>
#include <stdlib.h>

#define LIST_INIT_SIZE 100
#define LIST_INCREMENT 10
#define ElemType int
typedef struct
{
	ElemType * elem;
	int length;
	int listsize;
}SqList;

int InitList_Sq(SqList &L){
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if(!L.elem)exit(-1);
	L.length=0;
	L.listsize=LIST_INIT_SIZE;
	return 0;
}

int DestoryList(SqList &L){
	free(&L);
	InitList_Sq(L);
	return 0;
}

int ClearList(SqList &L){
	free(&L);
	InitList_Sq(L);
	return 0;
}

bool ListEmpty(SqList &L){
	return L.length==0;
}

int ListLength(SqList &L){
	return L.length;
}

int GetElem(SqList &L,int i,ElemType &e){
	e = L.elem[i];
	return 1;
}

int LocateElem(SqList &L,int e,ElemType (*p) (ElemType x,ElemType y)){
	for(int i=0;i<L.length;i++){
		ElemType iter;
		GetElem(L,i,iter);
		if((*p)(e,iter)==0)return i;
	}
	return -1;
}

ElemType compare(ElemType x,ElemType y){
	return x-y;
}

void ListResize(SqList &L,int size){
	L.elem = (ElemType *)realloc(L.elem,size*sizeof(ElemType));
	if(!L.elem)exit(-1);
	L.listsize = size;
}

void ListAlloc(SqList &L){
	ListResize(L,L.listsize+LIST_INCREMENT);
}

int ListInsert(SqList &L,int i,int e){
	if(i<0||i>L.length)return -1;
	if(L.length>=L.listsize)ListAlloc(L);
	ElemType * q = &(L.elem[i]);
	for(ElemType * p=&(L.elem[L.length-1]);p>=q;--p)*(p+1)=*(p);
	*q = e;
	++L.length;
	return 0;
}

int main(){
	SqList L;
	InitList_Sq(L);
	for(int i=0;i<1000000;i++){
		ListInsert(L,0,i);
	}
	for(int i=0;i<L.length;i++){
		printf("%d\n",L.elem[i]);
	}
	printf("%d\n",LocateElem(L,1,compare));
	return 0;
}