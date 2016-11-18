#include <stdio.h>
#include <stdlib.h>

#define OK  0
typedef int data_t;
//#define data_t int //宏替换，预处理

/*
 *结构模型：循环队列
 * */
typedef struct 
{
  data_t* data;
  int head;
  int tail;
  int size;
}queue_t;

//声明 tail不存放数据，即浪费一个data_t数据
queue_t* create_queue(int size)
{
	if(size==0)
		return NULL;
	queue_t* queue=(queue_t*)malloc(sizeof(queue_t));
	if(queue==NULL)
		return NULL;
	queue->data=(data_t*)malloc(sizeof(data_t)*size);
	queue->size=size;
	queue->head=queue->tail=0;
	return queue;
}
int isnull(queue_t* queue)
{
	if(queue==NULL)
		return -1;  //错误
	return queue->head==queue->tail;
}
int isfull(queue_t* queue)
{
	if(queue==NULL)
		return -1;
	return queue->head== (queue->tail+1)%queue->size;
}
int push_queue(queue_t* queue, data_t data)
{
	if(queue==NULL||isfull(queue))
		return -1;
    queue->data[queue->tail]=data;
	queue->tail= (queue->tail+1)%queue->size;
	return 0;
}
//FIFO
int pop_queue(queue_t* queue, data_t* data)
{
	if(queue==NULL||isnull(queue))
		return -1;
	*data=queue->data[queue->head];
	queue->head= (queue->head+1)%queue->size;
	return 0;
}
//from head to tail
int print_queue(queue_t* queue)
{
	int i;
	if(queue==NULL||isnull(queue))
		return -1;
	for(i=queue->head;i!=queue->tail;(i++)%queue->size)
	{
		printf("%2d\n", queue->data[i]);
	}
	return 0;
}
//from tail to head
int reprint_queue(queue_t* queue)
{
	if(queue==NULL||isnull(queue))
		return -1;
	int i;
	for(i=(queue->tail-1+queue->size)%queue->size; i !=queue->head; ((i--)+queue->size)%queue->size)
		printf("%2d\n",queue->data[i]);
	printf("%2d\n",queue->data[queue->head]);
	return 0;
}
int clear_queue(queue_t* queue)
{
	if(queue==NULL)
		return -1;
	queue->head=queue->tail=0;
	return 0;
}
int destroy_queue(queue_t* queue)
{
	if(queue==NULL)
		return -1;
	free(queue->data);
	free(queue);
	queue=NULL;
	return 0;
}
int main(int argc, const char *argv[])
{
	printf("循环队列\n");
	int i;
	data_t data;
	queue_t* queue;  //声明结构体
	queue=create_queue(20);// 队列大小20
    for(i=1;i<23;i++)
		push_queue(queue, i);
			print_queue(queue);
#if 1
	printf("**************\n");
	reprint_queue(queue);
	pop_queue(queue,&data);
	print_queue(queue);
	printf("##############\n");
	printf("%2d\n", data);
#endif
	clear_queue(queue);
	printf("head=%5d,tail=%5d\n", queue->head,queue->tail);
	print_queue(queue);
	destroy_queue(queue);
	print_queue(queue);
	return 0;
}






