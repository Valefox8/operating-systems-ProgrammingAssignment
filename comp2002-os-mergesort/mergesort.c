/**
 * This file implements parallel mergesort.
 */

#include <stdio.h>
#include <string.h> /* for memcpy */
#include <stdlib.h> /* for malloc */
#include "mergesort.h"

/* this function will be called by mergesort() and also by parallel_mergesort(). */
void merge(int leftstart, int leftend, int rightstart, int rightend){
	// do merging
	// int size = rightend - leftstart + 1;
	
	/*
	int pointerleft = leftstart;
	int pointerright = rightstart\
	int pointerB = leftstart
	while(sizeof(B) != size){
		if(A[pointerleft] <= A[pointerright]){
			B[pointerB] = A[pointerleft];
			if(pointerleft != leftend){
				pointerleft++;
			}
		}
		else{
			B[pointerB] = A[pointerright];
			if(pointerright != rightend){
				pointerright++;
			}
		}
		pointerB++;
	}

	*/

	// allocate sorted part to A
	//memcpy(&A[leftstart], &B[leftstart], size * sizeof(int))
	
	return;
}	

/* this function will be called by parallel_mergesort() as its base case. */
void my_mergesort(int left, int right){
	// exit case when position is the same
	// if left == right
		//return A[left]
	
	// midpoint = (right + left) / 2
	// leftstart = left 
	// leftend = midpoint
	// rightstart = midpoint + 1
	// rightend = right

	// my_mergesort(leftstart, leftend)
	// my_mergesort(rightstart, rightend)

	// merge(leftstart, leftend, rightstart, rightend)

	return;
}

/* this function will be called by the testing program. */
void * parallel_mergesort(void *arg){
	// --manage level of tree, control thread creation--
	
	// if arg->level != cutoff // when thread does not reach level, keep spliting
		// --manage new thread left right--
		// midpoint = (arg->right + arg->left) / 2
		// leftstart = arg->left 
		// leftend = midpoint
		// rightstart = midpoint + 1
		// rightend = arg -> right
		// level = arg->level + 1

		//argument* leftArg = builArgs(leftstart, leftend, level)
		//argument* rightArg = builArgs(rightstart, rightend, level)
		
		// pthread_create(t1, Null, parallel_mergesort, leftArg)
		// pthread_create(t2, Null, parallel_mergesort, rightArg)

		
		// may call my_mergesort, depend on the level
		// if reach cutoff level, will definitely call my_mergesort and sort the list
		// pthread_join(t1, Null)
		// pthread_join(t2, Null)

		// merge(leftstart, leftend, rightstart, rightend)

		// free(leftArg)
		// free(rightArg)

	// else // when reach leavel, start mergesort
		// my_mergesort(arg->left, arg->right)

	return NULL;
}

/* we build the argument for the parallel_mergesort function. */
struct argument * buildArgs(int left, int right, int level){
	struct argument *arg = malloc(sizeof(struct argument));
	arg->left = left;
	arg->right = right;
	arg->level = level;

	return arg;
}

