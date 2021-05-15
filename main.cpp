#include "sort_algorithms/HoaresQuicksort.h"
#include "sort_algorithms/ThreeWayQuicksort.h"
#include "sort_algorithms/MergeSort.h"
#include "sort_algorithms/InsertionSort.h"
#include "sort_algorithms/BinaryInsertionSort.h"
#include "sort_algorithms/HeapSort.h"
#include "sort_algorithms/CountingSort.h"

#include <string>
#include <cmath>
#include <algorithm>
#include <random>

using namespace std;

vector<int> linspace(int start, int end, int count) {
    vector<int> items(count);
    bool reverse = start > end;
    int imax = max(start, end);
    int imin = min(start, end);
    int range = imax - imin;
    double step = (double) (range + 1) / count;
    for (int i = 0; i < count; i++) items[i] = reverse ? (imax - (int) (step * i)) : (imin + (int) (step * i));
    return items;
}

vector<int> randspace(int start, int end, int count) {
    vector<int> items(count);
    int imax = max(start, end);
    int imin = min(start, end);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(imin, imax - 1);
    for (int i = 0; i < count; i++) items[i] = dist(gen);
    return items;
}

int main() {
    const int multiplier = 2;
    const int base = 2048;
    const int MAX_VALUE = 10000;
    const int iter = 2;

    const vector<string> sorts{"QuickSort", "3-way QuickSort", "MergeSort", "InsertionSort", "BinaryInsertionSort",
                               "HeapSort",
                               "CountingSort"};

    const vector<string> cases{"Reverse Sorted", "Sorted", "Random"};

    vector<vector<vector<int>>> sort_lists(4, vector<vector<int>>(cases.size(), vector<int>()));
    for (int i = 0; i < sort_lists.size(); i++) {
        for (int j = 0; j < sort_lists[i].size(); j++)
            sort_lists[i][j].resize((int) pow(multiplier, i) * base);

        sort_lists[i][0] = linspace(0, MAX_VALUE - 1, (int) sort_lists[i][0].size());
        sort_lists[i][1] = linspace(MAX_VALUE - 1, 0, (int) sort_lists[i][1].size());
        sort_lists[i][2] = randspace(0, MAX_VALUE, (int) sort_lists[i][2].size());
    }

    printf("%s\n", sort_lists.size() == 4 ? "PASS" : "FAIL");
    for (int i = 0; i < sort_lists.size(); i++) {
        printf(">%s\n", sort_lists[i].size() == cases.size() ? "PASS" : "FAIL");
        for (int j = 0; j < sort_lists[i].size(); j++)
            printf(">>%s\n", sort_lists[i][j].size() == (int) pow(multiplier, i) * base ? "PASS" : "FAIL");
    }

    for (int i = 0; i < iter; i++) {
        printf("> Iteration #%d\n", i + 1);
        for (int j = 0; j < sort_lists.size(); j++) {
            printf("\t> Length %d\n", sort_lists[j][0].size());
            for (int k = 0; k < sort_lists[j].size(); k++) {
                int max = *max_element(sort_lists[j][k].begin(), sort_lists[j][k].end());
                int min = *min_element(sort_lists[j][k].begin(), sort_lists[j][k].end());
                printf("\t> Case #%d: %s\n", k + 1, cases[k].c_str());
                for (int m = 0; m < sorts.size(); m++) {
                    Sort *sort;
                    switch (m) {
                        case 0:
                            sort = new Sorts::HoaresQuicksort(sort_lists[j][k]);
                            break;

                        case 1:
                            sort = new Sorts::ThreeWayQuicksort(sort_lists[j][k]);
                            break;

                        case 2:
                            sort = new Sorts::MergeSort(sort_lists[j][k]);
                            break;

                        case 3:
                            sort = new Sorts::InsertionSort(sort_lists[j][k]);
                            break;

                        case 4:
                            sort = new Sorts::BinaryInsertionSort(sort_lists[j][k]);
                            break;

                        case 5:
                            sort = new Sorts::HeapSort(sort_lists[j][k]);
                            break;

                        case 6:
                            sort = new Sorts::CountingSort(MAX_VALUE, sort_lists[j][k]);
                            break;

                        default:
                            sort = new Sorts::HoaresQuicksort(sort_lists[j][k]);
                            break;
                    }
                    unsigned long long time = sort->sort();
                    bool sorted =
                            sort->sorted() && (sort->get_list().front() == min && sort->get_list().back() == max) &&
                            (sort->get_list().size() == sort_lists[j][k].size());
                    printf("\t\t- Sort -> %21s\tDuration -> %8.3fms\tSorted -> %3s\n", sorts[m].c_str(),
                           (double) time / (double) 1000000, sorted ? "Yes" : "No");

//                    if (!sorted) {
//                        printf("\n\t\t+ Max: %d, Min: %d", max, min);
//                        printf("\n\t\t+ First 10 sorted: ");
//                        for (int s = 0; s < 10; s++)
//                            printf("%d, ", sort->get_list()[s]);
//
//                        printf("\n\t\t+ Last 10 sorted: ");
//                        for (int s = (int) sort->get_list().size() - 10; s < sort->get_list().size(); s++)
//                            printf("%d, ", sort->get_list()[s]);
//
//                        printf("\n\t\t+ First 10 unsorted: ");
//                        for (int s = 0; s < 10; s++)
//                            printf("%d, ", sort_lists[j][k][s]);
//
//                        printf("\n\t\t+ Last 10 unsorted: ");
//                        for (int s = (int) sort->get_list().size() - 10; s < sort->get_list().size(); s++)
//                            printf("%d, ", sort_lists[j][k][s]);
//
//                        printf("\n");
//                    }
                }
                printf("\n");
            }
        }
        printf("\n");
    }

    return 0;
}
