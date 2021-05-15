//
// Created by Emre on 5/13/2021.
//

#ifndef SORTALGORITHMSCOMPARISON_THREEWAYQUICKSORT_H
#define SORTALGORITHMSCOMPARISON_THREEWAYQUICKSORT_H

#include <vector>
#include "Sort.h"

using namespace std;

namespace Sorts {
    class ThreeWayQuicksort : public Sort {
    public:
        explicit ThreeWayQuicksort(vector<int> list_sort);

        unsigned long long sort() override;

    private:
        void quicksort(int left, int right);

        int *partition(int left, int right, int pivot);

    };
}

#endif //SORTALGORITHMSCOMPARISON_THREEWAYQUICKSORT_H
