/**************************************************************************
 File name:		  bst.h
 Author:        Shereen Khoja, Pacific University
 Date:          11.2.2021
 Class:         CS300
 Assignment:    Binary Search Trees
 Purpose:       This file defines the data structures and function prototypes
                for a Binary Search Tree
 *************************************************************************/

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

extern BSTNodePtr bstInsert (BSTNodePtr psRoot, int key, char *szData,
															int size);
extern BSTNodePtr bstCreateNode (int key, char *szData, int size);
extern void bstPrintInorder (BSTNodePtr psNode);
extern BSTNodePtr bstSearchRecursive (BSTNodePtr psRoot, int key,
																	BSTNodePtr psParent);
extern int bstFindLevel (BSTNodePtr psRoot, int key);
extern BSTNodePtr bstGetParent (BSTNodePtr psRoot, int key);
extern BSTNodePtr bstGetParentRecursive (BSTNodePtr psSubtree,
																					int key);
extern BSTNodePtr bstRemove (BSTNodePtr psRoot, int key);
extern BSTNodePtr bstRemoveNode (BSTNodePtr psRoot, BSTNodePtr psParent, BSTNodePtr psNode);

#endif /* INCLUDE_BST_H_ */
