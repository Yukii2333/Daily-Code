#include"Queue.h"

//ǰ�򴴽�������
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

//�ڵ����
int BinaryTreeSize(BTNode* root)
{
	return root == NULL ? 
		0 : BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}

//Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	//���ƽڵ���������Ҷ�Ϊ�յĽڵ����Ҷ�ӽڵ�
	return root->_left == NULL && root->_right == NULL ?
		1 : BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right) + 0;
}

//��k��Ľڵ����,k-1�������нڵ���ھͷ���1�����򷵻�0
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

//����X�����ص�ַ
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
	//��Ϊ��ָ��Ž����ж�
	if (left != NULL && left->_data == x)
		return left;

	if (right != NULL && right->_data == x)
		return right;

	return NULL;
}

//ǰ�����
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

//�������
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

//�������
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

//�������������
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

//���������ͨ������ʵ��
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
	//��Ҫ�������٣������ڴ�й©
	QueueDestroy(&que);
	printf("\n");
}

//�ж��Ƿ�Ϊ��ȫ��������������������ʵ��
//��ȫ������ͨ�����Ʋ����ڵ�һ�ζ���NULLʱ��֮���Ԫ�ز������г�NULL���Ԫ��
//������NULL���Ԫ��˵���ö�����Ϊ����ȫ������
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