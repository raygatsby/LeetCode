//
// Created by eden on 18-10-14.
//

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {

        int size = A.size();
        long long res = 0;
        for(int i = 0;i<size;++i) {

            for (int j = i+1; j < size; ++j) {

                for (int k = j+1; k < size; ++k) {

                    if (A[i] + A[j] + A[k] == target) {
                        res = (++res) % (1000000000 + 7);
                    }
                }
            }

        }
        return res;

    }
};