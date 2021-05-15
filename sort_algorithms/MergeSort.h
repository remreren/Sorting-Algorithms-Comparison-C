//
// Created by Emre on 5/13/2021.
//

#ifndef SORTALGORITHMSCOMPARISON_MERGESORT_H
#define SORTALGORITHMSCOMPARISON_MERGESORT_H

#include <vector>
#include "Sort.h"

using namespace std;

namespace Sorts {
    class MergeSort : public Sort {
    public:
        explicit MergeSort(vector<int> list_sort);

        unsigned long long sort() override;

    private:
        void mergesort(int left, int right);

        void merge(int left, int middle, int right);
    };
}

#endif //SORTALGORITHMSCOMPARISON_MERGESORT_H
