/**************************************************************************
 File name:		  BSTdriver.c
 Author:        Shereen Khoja, Pacific University
 Date:          11.4.2021
 Class:         CS300
 Assignment:    Binary Search Trees
 Purpose:       This file uses the Binary Search Tree data structure
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
int main () {
	BSTNodePtr psTree = NULL, psNode = NULL;
	int key, level;
	//char *sztemp = NULL;

	// print out the empty tree
	bstPrintInorder (psTree);

	// insert some elements into the tree
	bstInsertRecursive (&psTree, 30, "Neville", MAX);
	bstInsertRecursive (&psTree, 100, "Harry", MAX);
	bstInsertRecursive (&psTree, 1, "Ron", MAX);
	bstInsertRecursive (&psTree, 50, "Hermione", MAX);
	bstInsertRecursive (&psTree, 150, "Fred", MAX);
	bstInsertRecursive (&psTree, 120, "George", MAX);

	// print out the tree after inserting some elements
	bstPrintInorder (psTree);

	// search for key 50 in the tree and return the string at that location
	key = 50;
	psNode = bstSearchRecursive (psTree, key, NULL);
	if (NULL != psNode) {
		printf ("The string at key %d is %s\n", key, psNode->szData);
	}
	bstPrintInorder (psTree);

	// testing bstFindLevel
	key = 1;
	level = bstFindLevel (psTree, key);
	if (-1 != level) { // -1 means that key was not found
		printf ("\n\nFound %d at level %d\n", key, level);
	}
	else {
		printf ("\n\nDid not find %d\n", key);
	}
	bstPrintInorder (psTree);

	// testing bstGetParent
	key = 100;
	psNode = bstGetParent (psTree, key);
	if (NULL == psNode) {
		printf ("Key %d does not have a parent", key);
	}
	else {
		printf ("The parent of the node with key %d is is the node with key %d\n",
				key, psNode->key);
	}
	bstPrintInorder (psTree);

	// testing remove
	key = 30;
	printf ("Removing node %d\n", key);
	psTree = bstRemove (psTree, key);
	bstPrintInorder (psTree);

	// testing remove
	key = 100;
	printf ("Removing node %d\n", key);
	psTree = bstRemove (psTree, key);
	bstPrintInorder (psTree);
	// testing remove
	key = 1;
	printf ("Removing node %d\n", key);
	psTree = bstRemove (psTree, key);
	bstPrintInorder (psTree);
	// testing remove
	key = 120;
	printf ("Removing node %d\n", key);
	psTree = bstRemove (psTree, key);
	bstPrintInorder (psTree);
	// testing remove
	key = 50;
	printf ("Removing node %d\n", key);
	psTree = bstRemove (psTree, key);
	bstPrintInorder (psTree);
	// testing remove
	key = 150;
	printf ("Removing node %d\n", key);
	psTree = bstRemove (psTree, key);
	bstPrintInorder (psTree);

	printf ("\n\nReached the end!");

	return EXIT_SUCCESS;
}
