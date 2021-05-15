//
// Created by Emre on 5/14/2021.
//

#include <cstdio>
#include "Sort.h"

using namespace std;

Sort::Sort(vector<int> list_sort) {
    this->list_sort = move(list_sort);
//    printf("\n");
//    for (int i = 0; i < 10; i++) {
//        printf("%d, ", this->list_sort[i]);
//    }
//    printf("\n\n");
}

void Sort::swap(int *p1, int *p2) {
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

unsigned long long Sort::sort() {
    return 0;
}

bool Sort::sorted() {
    if (list_sort.empty()) return true;
    int prev = list_sort[0];
    bool isSorted = true;
    int i = 1;
    for (i = 1; i < list_sort.size(); i++) {
        if ((prev > list_sort[i])) {
            isSorted = false;
            break;
        }
        prev = list_sort[i];
    }
    return isSorted;
}

vector<int> Sort::get_list() {
    return list_sort;
}
