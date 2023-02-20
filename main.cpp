#include <algorithm>
using namespace std;
#include <iostream>
#include <vector>

void merge_sort(vector<int>& xs) {
    int unit = 1;

    // loop tot sort done is
    while (unit <= xs.size()) {
        // Sub listen maken en mergen

        for (int h = 0; h < xs.size(); h += 2 * unit) {
            int l = h;
            int r = min(int(xs.size()), h + 2 * unit);
            int mid = h + unit;



            //vector voor merged sub lijst storeen
            vector<int> tmp(r - l);
            int p = l, q = mid, k = 0;

            // Mergen
            while (p < mid && q < r) {
                if (xs[p] <= xs[q]) {
                    tmp[k++] = xs[p++];
                } else {
                    tmp[k++] = xs[q++];
                }
            }

            // linker sub copyen
            while (p < mid) {
                tmp[k++] = xs[p++];
            }
            // rechter sub copyen
            while (q < r) {
                tmp[k++] = xs[q++];
            }

            // Copy the merged sub-list back to the original list
            for (int i = l, j = 0; i < r; ++i, ++j) {
                xs[i] = tmp[j];
            }
        }

        // *2 voor volgende iteratie
        unit *= 2;
    }
}

int main() {
    vector<int> xs = {67, 0, 879, -3, 7, 6, 118, 2, 4};
    merge_sort(xs);

    for (int x : xs) {
        cout << x << " ";
    }


    return 0;}



