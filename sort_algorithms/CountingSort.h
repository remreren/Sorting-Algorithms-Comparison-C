//
// Created by Emre on 5/14/2021.
//

#ifndef SORTALGORITHMSCOMPARISON_COUNTINGSORT_H
#define SORTALGORITHMSCOMPARISON_COUNTINGSORT_H


#include "Sort.h"

namespace Sorts {
    class CountingSort : public Sort {
        int MAX_VALUE = 10000;
    public:
        explicit CountingSort(int max_value, vector<int> list_item);

        unsigned long long int sort() override;
    };
}


#endif //SORTALGORITHMSCOMPARISON_COUNTINGSORT_H
