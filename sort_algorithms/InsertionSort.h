//
// Created by Emre on 5/14/2021.
//

#ifndef SORTALGORITHMSCOMPARISON_INSERTIONSORT_H
#define SORTALGORITHMSCOMPARISON_INSERTIONSORT_H

#include <vector>
#include "Sort.h"

using namespace std;

namespace Sorts {
    class InsertionSort : public Sort {
    public:
        explicit InsertionSort(vector<int> list_sort);

        unsigned long long sort() override;

    private:
        void insertionsort();
    };
}


#endif //SORTALGORITHMSCOMPARISON_INSERTIONSORT_H
