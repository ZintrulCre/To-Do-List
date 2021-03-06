//
// Created by ZintrulCre on 2019-01-31.
//

#ifndef CPP_SORT_H
#define CPP_SORT_H

#include "MergeSort.h"
#include "HeapSort.h"
#include "QuickSort.h"

void BubbleSort(vector<int> &nums) {
    auto size = nums.size();
    for (int i = size - 1; i >= 0; --i) {
        for (int j = 0; j < i; ++j) {
            if (nums[j] > nums[j + 1])
                swap(nums[j], nums[j + 1]);
        }
    }
}

void InsertionSort(vector<int> &nums) {
    for (int i = 1; i < nums.size(); ++i) {
        int temp = nums[i];
        int j = i - 1;
        while (j >= 0 && temp < nums[j]) {
            nums[j + 1] = nums[j];
            --j;
        }
        nums[j + 1] = temp;
    }
}

#endif //CPP_SORT_H
