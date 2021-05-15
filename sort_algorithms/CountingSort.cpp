//
// Created by Emre on 5/14/2021.
//

#include "CountingSort.h"
#include <chrono>

using namespace std;

Sorts::CountingSort::CountingSort(int max_value, vector<int> list_item) : Sort(move(list_item)) {
    MAX_VALUE = max_value;
}

unsigned long long int Sorts::CountingSort::sort() {
    auto t = chrono::high_resolution_clock::now();

    vector<int> count(MAX_VALUE, 0);
    vector<int> output(list_sort.size(), 0);

    for (int i = 0; i < list_sort.size(); i++) count[list_sort[i]]++;
    for (int i = 1; i < count.size(); i++) count[i] += count[i - 1];
    for (int i = (int) list_sort.size() - 1; i >= 0; i--) {
        output[count[list_sort[i]] - 1] = list_sort[i];
        count[list_sort[i]]--;
    }
    list_sort = move(output);

    return chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - t).count();
}

