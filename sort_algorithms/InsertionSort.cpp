//
// Created by Emre on 5/14/2021.
//

#include "InsertionSort.h"
#include <vector>
#include <chrono>

using namespace std;

Sorts::InsertionSort::InsertionSort(vector<int> list_sort) : Sort(move(list_sort)) {}

unsigned long long Sorts::InsertionSort::sort() {
    auto t = chrono::high_resolution_clock::now();
    insertionsort();
    return chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - t).count();
}

void Sorts::InsertionSort::insertionsort() {
    unsigned long long e = list_sort.size();
    for (int i = 1; i < e; i++) {
        int key = list_sort[i];
        int j = i - 1;
        while ((j > -1) && (list_sort[j] > key)) {
            list_sort[j + 1] = list_sort[j];
            j--;
        }
        list_sort[j + 1] = key;
    }
}
