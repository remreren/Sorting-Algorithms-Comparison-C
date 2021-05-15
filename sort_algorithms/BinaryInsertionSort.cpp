//
// Created by Emre on 5/14/2021.
//

#include "BinaryInsertionSort.h"
#include <vector>
#include <chrono>

using namespace std;

Sorts::BinaryInsertionSort::BinaryInsertionSort(vector<int> list_sort) : Sort(move(list_sort)) {}

unsigned long long Sorts::BinaryInsertionSort::sort() {
    auto t = chrono::high_resolution_clock::now();
    insertionsort();
    return chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - t).count();
}

void Sorts::BinaryInsertionSort::insertionsort() {
    for (int i = 1; i < list_sort.size(); ++i) {
        int key = list_sort[i];
        int insertedPosition = searchPosition(0, i - 1, key);

        for (int j = i - 1; j >= insertedPosition; --j) list_sort[j + 1] = list_sort[j];

        list_sort[insertedPosition] = key;
    }
}

int Sorts::BinaryInsertionSort::searchPosition(int start, int end, int key) {
    while (start <= end) {
        int middle = start + (end - start) / 2;

        if (key < list_sort[middle]) end = middle - 1;
        else start = middle + 1;
    }

    return start;
}
