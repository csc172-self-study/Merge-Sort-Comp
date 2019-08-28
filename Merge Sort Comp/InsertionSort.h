/*
 * InsertionSort.h
 *
 *  Created on: Jul 22, 2019
 *      Author: alex
 */

#ifndef INSERTIONSORT_H_
#define INSERTIONSORT_H_

#include "ArrayOperations.h"

template <typename E>
void InsertionSort(E array[], int size) {
	for (int i = 1; i < size; ++i) {
		for (int j = i; j > 0 && array[j] < array[j-1]; --j) {
			swap(array, j, j-1);
		}
	}
}

#endif /* INSERTIONSORT_H_ */
