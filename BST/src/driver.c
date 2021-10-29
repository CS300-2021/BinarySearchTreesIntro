#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 50

typedef struct BSTNode *BSTNodePtr;
typedef struct BSTNode {
	int key;
	char szData[MAX];
	BSTNodePtr psLeftChild, psRightChild;
} BSTNode;

void bstInsert(BSTNode **hsRoot, int key, char *szData, int size) {
	BSTNode *psTmp = *hsRoot, *psParent = *hsRoot;
	if ( NULL == *hsRoot) {
		*hsRoot = (BSTNodePtr) malloc(sizeof(BSTNode));
		(*hsRoot)->psLeftChild = (*hsRoot)->psRightChild = NULL;
		strncpy((*hsRoot)->szData, szData, size);
		(*hsRoot)->key = key;
	} else {
		while ( NULL != psTmp) {
			psParent = psTmp;
			if (key < psParent->key)
				psTmp = psParent->psLeftChild;
			else if (key > psParent->key)
				psTmp = psParent->psRightChild;
			else
				return;
		}
		if (key < psParent->key) {
			psParent->psLeftChild = malloc(sizeof(BSTNode));
			strncpy(psParent->psLeftChild->szData, szData, size);
			psParent->psLeftChild->key = key;
			psParent->psLeftChild->psLeftChild = NULL;
			psParent->psLeftChild->psRightChild = NULL;
		} else if (key > psParent->key) {
			psParent->psRightChild = malloc(sizeof(BSTNode));
			strncpy(psParent->psRightChild->szData, szData, size);
			psParent->psRightChild->key = key;
			psParent->psRightChild->psLeftChild = NULL;
			psParent->psRightChild->psRightChild = NULL;
		}
	}
}

void BSTPrintInorder(BSTNodePtr psNode) {
	if (psNode == NULL) {
		return;
	}
	BSTPrintInorder(psNode->psLeftChild);
	printf("(%d,%s)-", psNode->key, psNode->szData);
	BSTPrintInorder(psNode->psRightChild);
}

bool bstSearch(BSTNode *psRoot, int key, char *szData, int size) {
	bool bFound = false;
	BSTNode *psTmp = psRoot;
	while (NULL != psTmp && psTmp->key != key) {
		if (key < psTmp->key) {
			psTmp = psTmp->psLeftChild;
		} else {
			psTmp = psTmp->psRightChild;
		}
	}
	if ( NULL != psTmp) {
		strncpy(szData, psTmp->szData, size);
		bFound = true;
	}
	return bFound;
}

bool bstFindLevel(BSTNode *psRoot, int key, int *pLevel) {
	bool bFound = false;
	int level = 0;
	BSTNode *psTmp = psRoot;
	while ( NULL != psTmp && psTmp->key != key) {
		if (key < psTmp->key) {
			psTmp = psTmp->psLeftChild;
		} else {
			psTmp = psTmp->psRightChild;
		}
		level++;
	}
	if ( NULL != psTmp) {
		bFound = true;
		*pLevel = level;
	}
	return bFound;
}

int main() {
	BSTNodePtr psTree;
	bstInsert(&psTree, 15, "Shereen", 8);
	bstInsert(&psTree, 8, "Layla", 6);
	bstInsert(&psTree, 20, "Nora", 5);
	bstInsert(&psTree, 200, "Mum", 4);
	bstInsert(&psTree, 10, "Dad", 4);

	BSTPrintInorder(psTree);
	printf("YAY!");
	return EXIT_SUCCESS;
}