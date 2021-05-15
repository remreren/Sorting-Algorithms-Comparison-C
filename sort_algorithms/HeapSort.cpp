//
// Created by Emre on 5/14/2021.
//

#include "HeapSort.h"

#include <vector>
#include <chrono>

using namespace std;

Sorts::HeapSort::HeapSort(vector<int> list_item) : Sort(move(list_item)) {}

unsigned long long Sorts::HeapSort::sort() {
    auto t = chrono::high_resolution_clock::now();
    int sizeOfTheList = (int) list_sort.size();

    // Build heap
    for (int i = sizeOfTheList / 2 - 1; i >= 0; i--)
        heapify(sizeOfTheList, i);


    for (int i = sizeOfTheList - 1; i >= 0; i--) {
        Sort::swap(&list_sort[0], &list_sort[i]);
        heapify(i, 0);
    }
    return chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - t).count();
}

void Sorts::HeapSort::heapify(int heapSize, int i) {

    int largestElement = i;     //initialize largest element as root
    int left_child = 2 * i + 1;
    int right_child = 2 * i + 2;

    //if left_child > root
    if (left_child < heapSize && list_sort[left_child] > list_sort[largestElement])
        largestElement = left_child;


    //if right_child > largestElement
    if (right_child < heapSize && list_sort[right_child] > list_sort[largestElement])
        largestElement = right_child;


    if (largestElement != i) {
        Sort::swap(&list_sort[i], &list_sort[largestElement]);
        heapify(heapSize, largestElement);
    }
}
