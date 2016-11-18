#include <stdio.h>
#include <stdlib.h>
//定义节点
typedef struct  linkednode
{
	int data;
	struct linkednode* next;
}list_t;

typedef struct 
{
	list_t* head;
	list_t* tail;
}queue_t;

queue_t*  create_queue(void)
{
	queue_t* queue=malloc(sizeof(queue_t));
	queue->head=malloc(sizeof(list_t));
	queue->head->next=NULL;
	queue->tail=queue->head;
	return queue;
}
int isnull(queue_t* queue)
{
	if(queue==NULL)
		return -1;
	return queue->head==queue->tail;
}
//插入  对尾
int insert_queue(queue_t* queue, int data)
{
	if(queue==NULL)
		return -1;
	list_t* newnode= malloc(sizeof(list_t));
	newnode->next=NULL;
	newnode->data=data;
	queue->tail->next=newnode;
	queue->tail=newnode;
	return 0;
}
//对头 删除
int delete_queue(queue_t* queue, int* data)
{
	if(queue==NULL||isnull(queue))
		return -1;
	list_t* temp= queue->head->next;
	*data= temp->data;
	queue->head->next=temp->next;
	free(temp);
	return 0;
}
int print_queue(queue_t* queue)
{
	if(queue==NULL||isnull(queue))
		return -1;
	list_t* temp=queue->head->next;
	while(temp != NULL)
	{
		printf("%5d\n", temp->data);
		temp=temp->next;
	}
	return 0;
}

int main(int argc, const char *argv[])
{
	int i;
	int data;
	queue_t* queue;
	queue=create_queue();
	for(i=0;i<5; i++)
		insert_queue(queue,i);
	print_queue(queue);
	printf("************************\n");
	delete_queue(queue,&data);
	printf("%5d\n", data);
	delete_queue(queue,&data);
	printf("%5d\n", data);
	printf("************************\n");
	print_queue(queue);
	return 0;
}



