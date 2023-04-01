#include"Queue.h"

//前序创建二叉树
BTNode* BinaryTreeCreate(BTDataType* a, int* pi)
{
	if (a[*pi] == '#')
	{
		(*pi)++;
		return NULL;
	}
	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	if (root == NULL)
	{
		perror("malloc fail");
		return NULL;
	}
	root->_data = a[(*pi)++];
	root->_left = BinaryTreeCreate(a, pi);
	root->_right = BinaryTreeCreate(a, pi);
	return root;
}

//节点个数
int BinaryTreeSize(BTNode* root)
{
	return root == NULL ? 
		0 : BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}

//叶子节点个数
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	//类似节点个数，左右都为空的节点就是叶子节点
	return root->_left == NULL && root->_right == NULL ?
		1 : BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right) + 0;
}

//第k层的节点个数,k-1层左右有节点存在就返回1，否则返回0
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL || k < 1)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}

//查找X并返回地址
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->_data == x)
	{
		return root;
	}
	BTNode* left = BinaryTreeFind(root->_left, x);
	BTNode* right = BinaryTreeFind(root->_right, x);
	//不为空指针才进行判断
	if (left != NULL && left->_data == x)
		return left;

	if (right != NULL && right->_data == x)
		return right;

	return NULL;
}

//前序遍历
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}

//中序遍历
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	BinaryTreeInOrder(root->_left);
	printf("%c ", root->_data);
	BinaryTreeInOrder(root->_right);
}

//后序遍历
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	BinaryTreePostOrder(root->_left);
	BinaryTreePostOrder(root->_right);
	printf("%c ", root->_data);
}

//后序二叉树销毁
void BinaryTreeDestory(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	BinaryTreeDestory(root->_left);
	BinaryTreeDestory(root->_right);
	free(root);
	return;
}

//层序遍历，通过队列实现
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue que;
	QueueInit(&que);
	QueuePush(&que, root);
	BTNode* tmp = NULL;
	while (!QueueEmpty(&que))
	{
		tmp = QueueFront(&que);
		QueuePop(&que);
		if (tmp == NULL)
		{
			printf("NULL ");
		}
		else
		{
			printf("%c ", tmp->_data);
			QueuePush(&que, tmp->_left);
			QueuePush(&que, tmp->_right);
		}
	}
	//不要忘记销毁，避免内存泄漏
	QueueDestroy(&que);
	printf("\n");
}

//判断是否为完全二叉树，还是依赖队列实现
//完全二叉树通过类似层序在第一次读到NULL时，之后的元素不可能有除NULL外的元素
//若存在NULL外的元素说明该二叉树为非完全二叉树
bool BinaryTreeComplete(BTNode* root)
{
	Queue que;
	QueueInit(&que);
	QueuePush(&que, root);
	BTNode* tmp = NULL;
	while (!QueueEmpty(&que))
	{
		tmp = QueueFront(&que);
		QueuePop(&que);
		if (tmp == NULL)
		{
			break;
		}
		else
		{
			QueuePush(&que, tmp->_left);
			QueuePush(&que, tmp->_right);
		}
	}
	while (!QueueEmpty(&que))
	{
		if (tmp != NULL)
		{
			return false;
		}
		tmp = QueueFront(&que);
		QueuePop(&que);
	}
	QueueDestroy(&que);
	return true;
}