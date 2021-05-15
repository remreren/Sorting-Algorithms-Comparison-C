//
// Created by Emre on 5/14/2021.
//

#ifndef SORTALGORITHMSCOMPARISON_HEAPSORT_H
#define SORTALGORITHMSCOMPARISON_HEAPSORT_H


#include "Sort.h"

namespace Sorts {
    class HeapSort : public Sort {
    public:
        explicit HeapSort(vector<int> list_item);

        unsigned long long int sort() override;

    private:
        void heapify(int heapSize, int i);
    };
}

#endif //SORTALGORITHMSCOMPARISON_HEAPSORT_H
