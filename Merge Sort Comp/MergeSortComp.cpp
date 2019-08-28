/*
 * MergeSortComp.cpp
 *
 *  Created on: Aug 28, 2019
 *      Author: alex
 */

#include "MergeSort.h"
#include "LinkedList.h"
#include <ctime>
#include <random>
#include <iostream>
using std::cout;

int main() {
	const int SIZE = 1000;

	clock_t start;

	std::random_device rd;
	std::mt19937 eng(rd());

	std::uniform_int_distribution<> posDistr(0,SIZE);
	LinkedList<int>* list = new LinkedList<int>;
	LinkedList<int>* sortedList;

	int array[SIZE]; int array1[SIZE];
	for (int i = 0; i < SIZE; ++i) {
		array[i] = posDistr(eng);
		array1[i] = array[i];
		list->insert(array[i]);
	}

	start = clock();
	MergeSort<int>(array1, 0, SIZE-1);
	double array_sort_time = (clock() - start)/ (double) CLOCKS_PER_SEC;

	start = clock();
	sortedList = MergeSortLL<int>(list);
	double list_sort_time = (clock() - start)/ (double) CLOCKS_PER_SEC;

	sortedList->moveToFront();
	for (int i = 1; i < SIZE; ++i) {
		int val2 = sortedList->getVal();
		sortedList->moveToPos(i);
		int val1 = sortedList->getVal();
		if (array1[i] < array1[i-1]) {
			cout << "Array was sorted incorrectly.\n";
		}
		if (val1 < val2) {
			cout << "Linked list was sorted incorrectly.\n";
		}
	}

	cout << "Array took " << array_sort_time << " s.\n";
	cout << "Linked list took " << list_sort_time << " s.\n";
}
