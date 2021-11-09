/*
 * bst.c
 *
 *  Created on: Nov 9, 2021
 *      Author: khoj0332
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../include/bst.h"

/**************************************************************************
 Function: 	 	bstInsert

 Description:   Inserts a node into a Binary Search Tree

 Parameters:	psRoot - pointer to the root of the BST
 	 	 	 	 	 	 	key    - the key to be placed in the node
 	 	 	 	 	 	 	 	 	 	 	 used to organize the BST
 	 	 	 	 	 	  szData - the data to be placed in the node
 	 	 	 	 	 	 	 	 	 	 	 can be copied into the node using strncpy()
 	 	 	 	 	 	  size   - number of characters in szData

 Returned:	 	Pointer to the node
 *************************************************************************/
BSTNodePtr bstInsert (BSTNodePtr psRoot, int key, char *szData, int size)
{
	if (NULL == psRoot) {
		return bstCreateNode (key, szData, size);
	}
	if (key < psRoot->key) {
		psRoot->psLeftChild = bstInsert(psRoot->psLeftChild, key, szData, size);
	}
	else {
		psRoot->psRightChild = bstInsert(psRoot->psRightChild, key, szData, size);
	}
	return psRoot;
}

/**************************************************************************
 Function: 	 	bstCreateNode

 Description: Creates a node with the passed in values and sets left
 	 	 	 	 	 	 	and right children to NULL

 Parameters:	key    - the key to be placed in the node
 	 	 	 	 	 	  szData - the data to be placed in the node
 	 	 	 	 	 	 	 	 	 	 	 can be copied into the node using strncpy()
 	 	 	 	 	 	  size   - number of characters in szData

 Returned:	 	Pointer to the created node
 *************************************************************************/
BSTNodePtr bstCreateNode (int key, char *szData, int size) {
	BSTNodePtr psTmp = (BSTNodePtr) malloc (sizeof(BSTNode));
	psTmp->psLeftChild = psTmp->psRightChild = NULL;
	strncpy (psTmp->szData, szData, size);
	psTmp->key = key;
	return psTmp;
}

/**************************************************************************
 Function: 	 	bstPrintInorder

 Description:   Prints the Binary Search Tree in order

 Parameters:	psNode - pointer to the node

 Returned:	 	None
 *************************************************************************/
void bstPrintInorder (BSTNodePtr psNode)
{
	if (psNode == NULL)
	{
		return;
	}
	bstPrintInorder (psNode->psLeftChild);
	printf ("(%d,%s)-", psNode->key, psNode->szData);
	bstPrintInorder (psNode->psRightChild);
}

/**************************************************************************
 Function: 	 	bstSearch

 Description:   Searches for a node in the BST

 Parameters:	psRoot - pointer to the root of the BST
 key    - the key we are searching for
 szData - will contain the data from the node
 can be copied using strncpy()
 size   - number of characters in szData

 Returned:	 	Result of if the node is found in the BST
 *************************************************************************/
void bstSearchRecursive (BSTNodePtr psRoot, int key, BSTNodePtr psParent) {
	if (NULL == psRoot) {
		printf ("\n\nKey %d not found.", key);
		return;
	}
	if (psRoot->key == key) {
		if (NULL == psParent) {
			printf("\n\nKey %d is in the root node.", key);
		}
		else if (key < psRoot->key) {
			printf("\n\nKey %d is the left node of the node with key %d", key, psParent->key);
		}
		else {
			printf("\n\nKey %d is the right node of the node with key %d", key, psParent->key);
		}
		return;
	}
	if (key < psRoot->key) {
		bstSearchRecursive(psRoot->psLeftChild, key, psRoot);
	} else {
		bstSearchRecursive(psRoot->psRightChild, key, psRoot);
	}
}

/**************************************************************************
 Function: 	 	bstFindLevel

 Description:   Finds the level of a node

 Parameters:	psRoot - pointer to the root of the BST
 key    - the key to be searched for in the BST
 pLevel - the level of the node

 Returned:	 	Result of if the node is found in the BST
 *************************************************************************/
bool bstFindLevel (BSTNodePtr psRoot, int key, int *pLevel)
{
	bool bFound = false;
	int level = 0;
	BSTNodePtr psTmp = psRoot;
	while ( NULL != psTmp && psTmp->key != key)
	{
		if (key < psTmp->key)
		{
			psTmp = psTmp->psLeftChild;
		}
		else
		{
			psTmp = psTmp->psRightChild;
		}
		level++;
	}
	if ( NULL != psTmp)
	{
		bFound = true;
		*pLevel = level;
	}
	return bFound;
}
