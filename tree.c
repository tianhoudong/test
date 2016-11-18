#include <stdio.h>
#include <stdlib.h>

typedef struct treenode
{
	int data;
 	struct	treenode* left;
	struct  treenode* right;
}tree_t;

tree_t*  create_tree(int data, int size)
{
	if(data>size)
		return NULL;
	tree_t* tree=malloc(sizeof(tree_t));
	tree->data=data;
	tree->left=create_tree(2*data, size); //左子树
	tree->right=create_tree(2*data+1, size);//右子树
	return tree;
}
//前序
int print_pre(tree_t* tree)
{
	if(tree==NULL)
		return -1;
	printf("%2d ",tree->data);
    print_pre(tree->left);
	print_pre(tree->right);
	return 0;
}
//中序
int print_mid(tree_t* tree)
{
	if(tree==NULL)
		return -1;
	print_mid(tree->left);
	printf("%2d ",tree->data);
	print_mid(tree->right);
}
//后序
int print_post(tree_t* tree)
{
	if(tree==NULL)
		return -1;
	print_post(tree->left);
	print_post(tree->right);
	printf("%2d ", tree->data);
}
//定义tree队列， 依次入对
int print_lar(tree_t* tree)
{
	if(tree==NULL)
		return -1;
	tree_t* queue[30];
	int head=0;
	int tail=0;

	queue[tail++]=tree;

	while(head != tail)
	{
		//如果有左子树，则入队列
		if(queue[head]->left !=NULL)
			queue[tail++]=queue[head]->left;

		//如果有右子树，则入队列
		if(queue[head]->right !=NULL)
			queue[tail++]=queue[head]->right;

		printf("%2d ",queue[head++]->data);
	}
	printf("\n");
	return 0;
}
int main(int argc, const char *argv[])
{
	tree_t* tree;
	tree= create_tree(1,10);
	print_pre(tree);
	printf("\n");
	printf("***********************\n");
	print_mid(tree);
	printf("\n");
    printf("***********************\n");
	print_post(tree);
	printf("\n");
	printf("***********************\n");
	print_lar(tree);
	return 0;
}
