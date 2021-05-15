//
// Created by Emre on 5/14/2021.
//

#ifndef SORTALGORITHMSCOMPARISON_SORT_H
#define SORTALGORITHMSCOMPARISON_SORT_H

#include <vector>

using namespace std;

class Sort {
public:
    explicit Sort(vector<int> list_sort);

    virtual unsigned long long sort();

    bool sorted();

    vector<int> get_list();

protected:
    vector<int> list_sort;

    static void swap(int *p1, int *p2);
};


#endif //SORTALGORITHMSCOMPARISON_SORT_H
