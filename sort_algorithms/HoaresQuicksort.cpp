//
// Created by Emre on 5/13/2021.
//

#include "HoaresQuicksort.h"
#include <vector>
#include <chrono>

Sorts::HoaresQuicksort::HoaresQuicksort(vector<int> list_sort) : Sort(move(list_sort)) {}

unsigned long long Sorts::HoaresQuicksort::sort() {
    auto t = std::chrono::high_resolution_clock::now();
    quicksort(0, (int) list_sort.size() - 1);
    return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - t).count();
}


int Sorts::HoaresQuicksort::partition(int left, int right, int pivot) {
    int leftP = left;
    int rightP = right - 1;

    while (true) {
        while (list_sort[leftP] < pivot) leftP++;
        while (rightP > 0 && list_sort[rightP] >= pivot) rightP--;

        if (leftP >= rightP) break;
        else swap(&list_sort[leftP], &list_sort[rightP]);
    }

    swap(&list_sort[leftP], &list_sort[right]);
    return leftP;
}

void Sorts::HoaresQuicksort::quicksort(int left, int right) {
    while (left < right) {
        int pivot = list_sort[right];
        int part = partition(left, right, pivot);

        if (part - left < right - part) {
            quicksort(left, part - 1);
            left = part + 1;
        } else {
            quicksort(part + 1, right);
            right = part - 1;
        }
    }
}
