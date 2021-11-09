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
#include "../include/bst.h"

void bstInsertRecursive (BSTNode **hsRoot, int key, char *szData, int size) {
	*hsRoot = bstInsert (*hsRoot, key, szData, size);
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
	int key, level;

	bstPrintInorder (psTree);

	psTree = bstInsert (psTree, 30, "Neville", MAX);
	bstInsertRecursive (&psTree, 100, "Harry", MAX);
	bstInsertRecursive (&psTree, 1, "Ron", MAX);
	bstInsertRecursive (&psTree, 50, "Hermione", MAX);

	bstPrintInorder (psTree);

	bstSearchRecursive (psTree, 50, NULL);

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
