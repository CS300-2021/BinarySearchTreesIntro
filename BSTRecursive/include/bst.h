/*
 * bst.h
 *
 *  Created on: Nov 9, 2021
 *      Author: khoj0332
 */



#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

#define MAX 50

typedef struct BSTNode *BSTNodePtr;
typedef struct BSTNode
{
	int key;
	char szData[MAX];
	BSTNodePtr psLeftChild, psRightChild;
} BSTNode;

extern BSTNodePtr bstInsert (BSTNodePtr psRoot, int key, char *szData, int size);
extern BSTNodePtr bstCreateNode (int key, char *szData, int size);
extern void bstPrintInorder (BSTNodePtr psNode);
extern void bstSearchRecursive (BSTNodePtr psRoot, int key, BSTNodePtr psParent);
extern bool bstFindLevel (BSTNodePtr psRoot, int key, int *pLevel);

#endif /* INCLUDE_BST_H_ */
