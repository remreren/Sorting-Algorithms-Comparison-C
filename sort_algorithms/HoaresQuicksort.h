//
// Created by Emre on 5/13/2021.
//

#ifndef SORTALGORITHMSCOMPARISON_HOARESQUICKSORT_H
#define SORTALGORITHMSCOMPARISON_HOARESQUICKSORT_H

#include "vector"
#include "Sort.h"

using namespace std;

namespace Sorts {
    class HoaresQuicksort : public Sort {
    public:
        explicit HoaresQuicksort(vector<int> list_sort);

        unsigned long long sort() override;

    private:
        void quicksort(int left, int right);

        int partition(int left, int right, int pivot);

    };
}

#endif //SORTALGORITHMSCOMPARISON_HOARESQUICKSORT_H
