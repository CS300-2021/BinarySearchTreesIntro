/**************************************************************************
 File name:		BSTdriver.c
 Author:        CS, Pacific University
 Date:          11.4.2021
 Class:         CS300
 Assignment:    Binary Search Trees
 Purpose:       This file defines the data structure for a Binary Search
 Tree
 *************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 50

typedef struct BSTNode *BSTNodePtr;
typedef struct BSTNode
{
	int key;
	char szData[MAX];
	BSTNodePtr psLeftChild, psRightChild;
} BSTNode;

/**************************************************************************
 Function: 	 	bstInsert

 Description:   Inserts a node into a Binary Search Tree

 Parameters:	hsRoot - handle to the root of the BST
 key    - the key to be placed in the node
 used to organize the BST
 szData - the data to be placed in the node
 can be copied into the node using strncpy()
 size   - number of characters in szData

 Returned:	 	None
 *************************************************************************/
void bstInsert (BSTNode **hsRoot, int key, char *szData, int size)
{
	BSTNodePtr psTmp = *hsRoot, psParent = *hsRoot;
	if ( NULL == *hsRoot)
	{
		*hsRoot = (BSTNodePtr) malloc (sizeof(BSTNode));
		(*hsRoot)->psLeftChild = (*hsRoot)->psRightChild = NULL;
		strncpy ((*hsRoot)->szData, szData, size);
		(*hsRoot)->key = key;
	}
	else
	{
		while ( NULL != psTmp)
		{
			psParent = psTmp;
			if (key < psParent->key)
				psTmp = psParent->psLeftChild;
			else if (key > psParent->key)
				psTmp = psParent->psRightChild;
		}
		if (key < psParent->key)
		{
			psParent->psLeftChild = malloc (sizeof(BSTNode));
			strncpy (psParent->psLeftChild->szData, szData, size);
			psParent->psLeftChild->key = key;
			psParent->psLeftChild->psLeftChild = NULL;
			psParent->psLeftChild->psRightChild = NULL;
		}
		else if (key > psParent->key)
		{
			psParent->psRightChild = malloc (sizeof(BSTNode));
			strncpy (psParent->psRightChild->szData, szData, size);
			psParent->psRightChild->key = key;
			psParent->psRightChild->psLeftChild = NULL;
			psParent->psRightChild->psRightChild = NULL;
		}
	}
}

void bstInsert2 (BSTNode *psRoot, int key, char *szData, int size)
{
	BSTNodePtr psTmp = psRoot, psParent = psRoot;
	if ( NULL == psRoot)
	{
		psRoot = (BSTNodePtr) malloc (sizeof(BSTNode));
		(psRoot)->psLeftChild = (psRoot)->psRightChild = NULL;
		strncpy ((psRoot)->szData, szData, size);
		(psRoot)->key = key;
	}
	else
	{
		while ( NULL != psTmp)
		{
			psParent = psTmp;
			if (key < psParent->key)
				psTmp = psParent->psLeftChild;
			else if (key > psParent->key)
				psTmp = psParent->psRightChild;
		}
		if (key < psParent->key)
		{
			psParent->psLeftChild = malloc (sizeof(BSTNode));
			strncpy (psParent->psLeftChild->szData, szData, size);
			psParent->psLeftChild->key = key;
			psParent->psLeftChild->psLeftChild = NULL;
			psParent->psLeftChild->psRightChild = NULL;
		}
		else if (key > psParent->key)
		{
			psParent->psRightChild = malloc (sizeof(BSTNode));
			strncpy (psParent->psRightChild->szData, szData, size);
			psParent->psRightChild->key = key;
			psParent->psRightChild->psLeftChild = NULL;
			psParent->psRightChild->psRightChild = NULL;
		}
	}
}

BSTNodePtr insert (BSTNodePtr psRoot, int key, char *szData, int size)
{
	if (NULL == psRoot)
	{
		BSTNodePtr psTmp = (BSTNodePtr) malloc (sizeof(BSTNode));
		psTmp->psLeftChild = psTmp->psRightChild = NULL;
		strncpy (psTmp->szData, szData, size);
		psTmp->key = key;
		return psTmp;
	}

	if (key < psRoot->key) {
		psRoot->psLeftChild = insert(psRoot->psLeftChild, key, szData, size);
	}
	else {
		psRoot->psRightChild = insert(psRoot->psRightChild, key, szData, size);
	}

	return psRoot;
}

void bstInsertRecursive (BSTNode **hsRoot, int key, char *szData, int size) {
	*hsRoot = insert (*hsRoot, key, szData, size);
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
bool bstSearch (BSTNodePtr psRoot, int key, char *szData, int size)
{
	bool bFound = false;
	BSTNodePtr psTmp = psRoot;
	while (NULL != psTmp && psTmp->key != key)
	{
		if (key < psTmp->key)
		{
			psTmp = psTmp->psLeftChild;
		}
		else
		{
			psTmp = psTmp->psRightChild;
		}
	}
	if ( NULL != psTmp)
	{
		strncpy (szData, psTmp->szData, size);
		bFound = true;
	}
	return bFound;
}

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

/**************************************************************************
 Function: 	 	main()

 Description:   Used to create and test the BST

 Parameters:	none

 Returned:	 	none
 *************************************************************************/
int main ()
{
	BSTNodePtr psTree = NULL;
	char szFound[MAX] = "x";
	int key, level;

	bstPrintInorder (psTree);

	//bstInsert2 (psTree, 40, "Root", MAX);
//	insert (psTree, 40, "Root", MAX);
//	bstInsert (&psTree, 15, "Bowser", MAX);
//	bstInsert (&psTree, 8, "Mario", MAX);
//	bstInsert (&psTree, 20, "Luigi", MAX);
//	bstInsert (&psTree, 200, "Toad", MAX);
//	bstInsert (&psTree, 10, "Yoshi", MAX);

	psTree = insert (psTree, 30, "Neville", MAX);
	bstInsertRecursive (&psTree, 100, "Harry", MAX);
	bstInsertRecursive (&psTree, 1, "Ron", MAX);
	bstInsertRecursive (&psTree, 50, "Hermione", MAX);


	bstPrintInorder (psTree);

	bstSearchRecursive (psTree, 50, NULL);

	key = 50;

	if (bstSearch (psTree, key, szFound, MAX))
	{
		printf ("\n\nFound %d: %s", key, szFound);
	}
	else
	{
		printf ("\n\nDid not find %d", key);
	}

	key = 15;

	if (bstFindLevel (psTree, key, &level))
	{
		printf ("\n\nFound %d at level %d", key, level);
	}
	else
	{
		printf ("\n\nDid not find %d", key);
	}

	printf ("\n\nReached the end!");

	return EXIT_SUCCESS;
}
