/*
 * MergeSort.h
 *
 *  Created on: Jul 22, 2019
 *      Author: alex
 */

#ifndef MERGESORT_H_
#define MERGESORT_H_

#include "LinkedList.h"
#include "InsertionSort.h"
#include <tuple>

const static int THRESHOLD = 9;

template <typename E>
void MergeSort(E array[], int lowerBound, int upperBound) {
	E temp[upperBound - lowerBound + 1];

	if (upperBound - lowerBound + 1 <= THRESHOLD) {
		InsertionSort<E>(&array[lowerBound], upperBound - lowerBound + 1);
		return;
	}

	int i, j, k, mid = (upperBound + lowerBound)/2;
	MergeSort<E>(array, lowerBound, mid);
	MergeSort<E>(array, mid+1, upperBound);

	for (i = mid; i >= lowerBound; --i) {
		temp[i - lowerBound] = array[i];
	}
	for (j = 1; j <= upperBound - mid; ++j) {
		temp[upperBound-j+1 - lowerBound] = array[j + mid];
	}
	for (i = 0, j = upperBound - lowerBound, k = lowerBound; k <= upperBound; ++k) {
		if (temp[i] < temp[j]) {
			array[k] = temp[i++];
		} else {
			array[k] = temp[j--];
		}
	}
}

template <typename E>
LinkedList<E>* Merge(LinkedList<E>* input1, LinkedList<E>* input2) {
	LinkedList<E>* newList;
	newList = new LinkedList<E>;

	input1->moveToFront();
	input2->moveToFront();

	if (input1->length() == 0) {
		return input2;
	} else if (input2->length() == 0) {
		return input1;
	}

	// Get lesser element
	while (input1->length() > 0 && input2->length() > 0) {
		if (input1->getVal() <= input2->getVal()) {
			newList->append(input1->remove());
		} else {
			newList->append(input2->remove());
		}
	}

	// Get any remaining elements
	while (input1->length() > 0) {
		newList->append(input1->remove());
	}
	while (input2->length() > 0) {
		newList->append(input2->remove());
	}

	return newList;
}

template <typename E>
std::pair<LinkedList<E>*, LinkedList<E>*> SplitList(LinkedList<E>* inputList) {

	LinkedList<E>* list1;
	list1 = new LinkedList<E>;
	LinkedList<E>* list2;
	list2 = new LinkedList<E>;

	inputList->moveToFront();
	int half = inputList->length()/2;

	while (inputList->length() > half) {
		list1->append(inputList->remove());
	}
	while (inputList->length() > 0) {
		list2->append(inputList->remove());
	}

	return std::make_pair(list1, list2);
}

template <typename E>
LinkedList<E>* MergeSortLL(LinkedList<E>* inputList) {
	if (inputList->length() <= 1) return inputList;
	LinkedList<E>* temp1;
	LinkedList<E>* temp2;
	std::tie(temp1, temp2) = SplitList<E>(inputList);
	return Merge<E>(MergeSortLL<E>(temp1), MergeSortLL<E>(temp2));
}

#endif /* MERGESORT_H_ */
