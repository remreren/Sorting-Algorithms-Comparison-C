//
// Created by Emre on 5/14/2021.
//

#ifndef SORTALGORITHMSCOMPARISON_BINARYINSERTIONSORT_H
#define SORTALGORITHMSCOMPARISON_BINARYINSERTIONSORT_H


#include <vector>
#include "Sort.h"

using namespace std;

namespace Sorts {
    class BinaryInsertionSort : public Sort {
    public:
        explicit BinaryInsertionSort(vector<int> list_sort);

        unsigned long long sort() override;

    private:
        void insertionsort();

        int searchPosition(int start, int end, int key);
    };
}

#endif //SORTALGORITHMSCOMPARISON_BINARYINSERTIONSORT_H
