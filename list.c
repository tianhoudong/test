#include <stdio.h>
#include <stdlib.h>

#define N 20


typedef struct listnode
{
 	int data[N];
	int last;
}list_t;


list_t* create_list(void)
{
	list_t* list=malloc(sizeof(list_t));
	list->last=-1;
	return list;
}
int isnull(list_t* list)
{
 	if(list==NULL)
		return -1;
	return list->last==-1;
}
int isfull(list_t* list)
{
	if(list==NULL)
		return -1;
	return list->last+1==N;
}
int insert_head_list(list_t* list, int data)
{
	if(list==NULL||isfull(list))
		return -1;
	int i;
	for(i=list->last;i>=0;i--)
		list->data[i+1]=list->data[i];
	list->data[0]=data;
	list->last++;
	return 0;
}
int delete_head_list(list_t* list)
{
	if(list==NULL||isnull(list))
		return -1;
	int i;
	for(i=0;i<=list->last;i++)
		list->data[i]=list->data[i+1];
	list->last--;
	return 0;
}
int insert_index_list(list_t* list,int index,int data)
{
	if(list==NULL||isfull(list)||index<0||index> list->last)
		return -1;
	int i;
	for(i=list->last;i>=index;i--)
		list->data[i+1]=list->data[i];
	list->data[index]=data;
	list->last++;
	return 0;
}
int delete_index_list(list_t* list, int index)
{
	if(list==NULL||isnull(list)|index<0||index>list->last)
		return -1;
	int i;
	for(i=index;i<list->last;i++)
		list->data[i]=list->data[i+1];
	list->last--;
	return 0;
}
int print_list(list_t* list)
{
	if(list==NULL||isnull(list))
		return -1;
	int i;
	for(i=0;i<=list->last;i++)
		printf("%5d\n", list->data[i]);
	return 0;
}
int reprint_list(list_t* list)
{
	if(list==NULL|| isnull(list))
		return -1;
	int i;
	for(i=list->last;i>=0;i--)
		printf("%5d\n", list->data[i]);
	return 0;
}
int main(int argc, const char *argv[])
{
	list_t* list;
	list=create_list();
	insert_head_list(list,1);
	insert_head_list(list,2);
	insert_index_list(list,2,3);
    print_list(list);
    delete_head_list(list);
	reprint_list(list);
	return 0;
}








