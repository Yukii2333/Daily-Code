#include"Queue.h"

void test()
{
	BTDataType* a = "ABD##E#H##CF##G##";
	int i = 0;
	BTNode* root = BinaryTreeCreate(a, &i);

	printf("�ڵ������%d\nҶ�ӽڵ������%d\n", BinaryTreeSize(root),BinaryTreeLeafSize(root));
	printf("��3��ڵ������%d\n", BinaryTreeLevelKSize(root, 3));

	BTNode* pos = BinaryTreeFind(root, 'S');
	if (pos == NULL)
		printf("Not find!\n");
	else
		printf("%c\n", pos->_data);

	BinaryTreePrevOrder(root);
	printf("\n");
	BinaryTreeInOrder(root);
	printf("\n");
	BinaryTreePostOrder(root);
	printf("\n");
	BinaryTreeLevelOrder(root);

	if (BinaryTreeComplete(root))
		printf("is_complete!\n");
	else
		printf("not_complete!\n");

	BinaryTreeDestory(root);
	root = NULL;
}

int main()
{
	test();
	return 0;
}