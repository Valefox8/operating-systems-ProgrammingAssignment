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
	// seperate elememt from args
	struct argument *args = (struct argument *)arg;

    int left = args->left;
    int right = args->right;
    int level = args->level;
	if (level < cutoff && left < right) // when thread does not reach level, keep spliting
    {
		// --manage new thread left right--
		int midpoint = left + (right - left) / 2;

        int leftstart = left;
        int leftend = midpoint;
        int rightstart = midpoint + 1;
        int rightend = right;

        int nextLevel = level + 1;

		struct argument *leftArg = buildArgs(leftstart, leftend, nextLevel);
        struct argument *rightArg = buildArgs(rightstart, rightend, nextLevel);
		
        pthread_t t1, t2;

		// may call my_mergesort, depend on the level
		// if reach cutoff level, will definitely call my_mergesort and sort the list
		int result1 = pthread_create(&t1, NULL, parallel_mergesort, leftArg);
        int result2 = pthread_create(&t2, NULL, parallel_mergesort, rightArg);

        pthread_join(t1, NULL);
        pthread_join(t2, NULL);
        
		// Both halves are sorted; merge them
        merge(leftstart, leftend, rightstart, rightend);

        // Parent owns and frees the child arguments
        free(leftArg);
        free(rightArg);
	}
	else{ // when reach leavel, start mergesort
		my_mergesort(left, right);
	}
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

