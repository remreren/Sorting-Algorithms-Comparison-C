//
// Created by Emre on 5/13/2021.
//

#include "MergeSort.h"
#include <chrono>

using namespace std;

Sorts::MergeSort::MergeSort(vector<int> list_sort) : Sort(move(list_sort)) {}

unsigned long long Sorts::MergeSort::sort() {
    auto t = chrono::high_resolution_clock::now();
    mergesort(0, (int) list_sort.size() - 1);
    return chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - t).count();
}

void Sorts::MergeSort::mergesort(int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergesort(left, middle);
        mergesort(middle + 1, right);
        merge(left, middle, right);
    }
}

void Sorts::MergeSort::merge(int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    vector<int> leftA(n1), rightA(n2);

    for (int i = 0; i < n1; i++)
        leftA[i] = list_sort[left + i];
    for (int i = 0; i < n2; i++)
        rightA[i] = list_sort[middle + i + 1];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftA[i] <= rightA[j]) list_sort[k] = leftA[i++];
        else list_sort[k] = rightA[j++];
        k++;
    }

    while (i < n1) {
        list_sort[k++] = leftA[i++];
    }

    while (j < n2) {
        list_sort[k++] = rightA[j++];
    }
}
