/**************************************************************************
 File name:		  bst.c
 Author:        Shereen Khoja, Pacific University
 Date:          11.2.2021
 Class:         CS300
 Assignment:    Binary Search Trees
 Purpose:       This file defines the data structures and function prototypes
 for a Binary Search Tree
 *************************************************************************/

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
BSTNodePtr bstInsert (BSTNodePtr psRoot, int key, char *szData, int size) {
	if (NULL == psRoot) {
		return bstCreateNode (key, szData, size);
	}
	if (key < psRoot->key) {
		psRoot->psLeftChild = bstInsert (psRoot->psLeftChild, key, szData, size);
	}
	else {
		psRoot->psRightChild = bstInsert (psRoot->psRightChild, key, szData, size);
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
void bstPrintInorder (BSTNodePtr psNode) {
	if (psNode == NULL) {
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

 Returned:	 	Pointer to the node containing the key, if not found, NULL
 is returned
 *************************************************************************/
BSTNodePtr bstSearchRecursive (BSTNodePtr psRoot, int key, BSTNodePtr psParent) {
	if (NULL == psRoot) {
		return NULL;
	}
	if (psRoot->key == key) {
		return psRoot;
	}
	else if (key < psRoot->key) {
		return bstSearchRecursive (psRoot->psLeftChild, key, psRoot);
	}
	else {
		return bstSearchRecursive (psRoot->psRightChild, key, psRoot);
	}
}

/**************************************************************************
 Function: 	 	bstFindLevel

 Description:   Finds the level of a node

 Parameters:	psRoot - pointer to the root of the BST
 key    - the key to be searched for in the BST

 Returned:	 	Result of if the node is found in the BST
 *************************************************************************/
int bstFindLevel (BSTNodePtr psRoot, int key) {
	if (psRoot == NULL) { // Did not find key
		return -1;
	}
	if (psRoot->key == key) { // found key
		return 0;
	}
	else if (key < psRoot->key) {
		if (bstFindLevel (psRoot->psLeftChild, key) == -1) {
			return -1;
		}
		else {
			return 1 + bstFindLevel (psRoot->psLeftChild, key);
		}
	}
	else {
		if (bstFindLevel (psRoot->psLeftChild, key) == -1) {
			return -1;
		}
		else {
			return 1 + bstFindLevel (psRoot->psRightChild, key);
		}
	}
}

BSTNodePtr bstGetParent (BSTNodePtr psRoot, int key) {
	return bstGetParentRecursive (psRoot, key);
}
BSTNodePtr bstGetParentRecursive (BSTNodePtr psSubtree, int key) {
	if (NULL == psSubtree || key == psSubtree->key) {
		return NULL;
	}
	if (psSubtree->psLeftChild != NULL && psSubtree->psLeftChild->key == key) {
		return psSubtree;
	}
	if (psSubtree->psRightChild != NULL && psSubtree->psRightChild->key == key) {
		return psSubtree;
	}
	if (key < psSubtree->key) {
		return bstGetParentRecursive (psSubtree->psLeftChild, key);
	}
	return bstGetParentRecursive (psSubtree->psRightChild, key);
}

BSTNodePtr bstRemove (BSTNodePtr psRoot, int key) {
	BSTNodePtr psNode = bstSearchRecursive (psRoot, key, NULL);
	BSTNodePtr psParent = bstGetParent (psRoot, key);
	return bstRemoveNode (psRoot, psParent, psNode);
}

BSTNodePtr bstRemoveNode (BSTNodePtr psRoot, BSTNodePtr psParent,
		BSTNodePtr psNode) {
	if (NULL == psNode) {
		return NULL;
	}

	// Case 1: Internal node with 2 children
	if (NULL != psNode->psLeftChild && NULL != psNode->psRightChild) {
		// Find successor and successor's parent
		BSTNodePtr psSuccNode = psNode->psRightChild;
		BSTNodePtr psSuccParent = psNode;
		while (NULL != psSuccNode->psLeftChild) {
			psSuccParent = psSuccNode;
			psSuccNode = psSuccNode->psLeftChild;
		}

		// copy the value from the successor node
		//BSTNodePtr psTemp = (BSTNodePtr) malloc (sizeof(BSTNode));
		BSTNodePtr psTempLeft = psNode->psLeftChild;
		BSTNodePtr psTempRight = psNode->psRightChild;
		memcpy (psNode, psSuccNode, sizeof(BSTNode));
		psNode->psLeftChild = psTempLeft;
		psNode->psRightChild = psTempRight;

		// Recursively remove successor
		psRoot = bstRemoveNode (psRoot, psSuccParent, psSuccNode);
		return psRoot;
	}

	// Case 2: Root node (with 1 or 0 children)
	else if (psNode == psRoot) {
		if (NULL != psNode->psLeftChild) {
			psRoot = psNode->psLeftChild;
		}
		else {
			psRoot = psNode->psRightChild;
		}
		free (psNode);
		return psRoot;
	}

	// Case 3: Internal with left child only
	else if (NULL != psNode->psLeftChild) {
		// Replace node with node's left child
		if (psParent->psLeftChild->key == psNode->key) {
			psParent->psLeftChild = psNode->psLeftChild;
		}
		else {
			psParent->psRightChild = psNode->psLeftChild;
		}
		free (psNode);
		return psRoot;
	}

	// Case 4: Internal with right child only or leaf
	else {
		// Replace node with node's right child
		if (psParent->psLeftChild->key == psNode->key) {
			psParent->psLeftChild = psNode->psRightChild;
		}
		else {
			psParent->psRightChild = psNode->psRightChild;
		}
		free (psNode);
		return psRoot;
	}
}
