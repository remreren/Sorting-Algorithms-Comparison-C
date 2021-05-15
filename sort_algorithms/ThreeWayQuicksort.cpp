//
// Created by Emre on 5/13/2021.
//

#include "ThreeWayQuicksort.h"
#include <chrono>

using namespace std;

Sorts::ThreeWayQuicksort::ThreeWayQuicksort(vector<int> list_sort) : Sort(move(list_sort)) {}

unsigned long long Sorts::ThreeWayQuicksort::sort() {
    auto t = chrono::high_resolution_clock::now();
    quicksort(0, (int) list_sort.size() - 1);
    return chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - t).count();
}

void Sorts::ThreeWayQuicksort::quicksort(int left, int right) {
    if (right > left) {
        if (left - right == 1) {
            if (list_sort[right] > list_sort[left]) swap(&list_sort[right], &list_sort[left]);
            return;
        }

        int pivot = list_sort[right];
        int *part = partition(left, right, pivot);
        quicksort(left, part[0]);
        quicksort(part[1], right);
    }
}

int *Sorts::ThreeWayQuicksort::partition(int left, int right, int pivot) {
    int mid = left;

    while (mid <= right) {
        if (list_sort[mid] < pivot) Sort::swap(&list_sort[left++], &list_sort[mid++]);
        else if (list_sort[mid] > pivot) Sort::swap(&list_sort[mid], &list_sort[right--]);
        else mid++;
    }

    return new int[2]{left - 1, mid};
}
