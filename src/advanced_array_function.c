#include "../include/advanced_array_function.h"
#include <stdio.h>
#include <stdlib.h>

int max_subarray_sum(int* nums, int size) {
    if (size <= 0){
        return 0;
    }
    int max_sum = nums[0];
    int current_sum = nums[0];

    for (int i = 1; i < size; i++){
    if (current_sum < 0)
        current_sum = nums[i];
    else current_sum += nums[i];

    if (current_sum > max_sum)
        max_sum = current_sum;
    }
    return max_sum;
}

int length_of_lis(int* nums, int numsSize) {
    if (numsSize == 0) 
        return 0;

    int max_len = 1;
    int current_len = 1;
    
    for (int i = 1; i < numsSize; i++){
        if (nums[i] > nums[i-1]){
            current_len++;
            if (current_len > max_len)
                max_len = current_len;
        } else {
            current_len = 1; //if posledovatelnost` prervana
        }
    }
    return max_len;
}

int* merge(int* intervals, int intervalsSize, int* returnSize) {
    if (intervalsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    //Copy massive 4 sort
    int* sorted = (int*)calloc(intervalsSize * 2, sizeof(int));
    for (int i = 0; i < intervalsSize * 2; i++) {
        sorted[i] = intervals[i];
    }

    //Sort
    for (int i = 0; i < intervalsSize - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < intervalsSize; j++) {
            if (sorted[j * 2] < sorted[min_index * 2]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            int tmp_start = sorted[i * 2];
            int tmp_end = sorted[i * 2 + 1];
            sorted[i * 2] = sorted[min_index * 2];
            sorted[i * 2 + 1] = sorted[min_index * 2 + 1];
            sorted[min_index * 2] = tmp_start;
            sorted[min_index * 2 + 1] = tmp_end;
        }
    }

    //Massive 4 result
    int* result = (int*)calloc(intervalsSize * 2, sizeof(int));
    result[0] = sorted[0];
    result[1] = sorted[1];
    int count = 1; //count ob`edinennyh intervalov

    //Ob`edinyaem intervaly
    for (int i = 1; i < intervalsSize; i++) {
        int start = sorted[i * 2];
        int end = sorted[i * 2 + 1];
        int last_end = result[(count - 1) * 2 + 1]; //konets last intervala in resultt

        if (start <= last_end) {
            //Perese4enie or kasanie intervala s drugim
            if (end > last_end) {
                result[(count - 1) * 2 + 1] = end;
            }
        } else {
            //New interval
            result[count * 2] = start;
            result[count * 2 + 1] = end;
            count++;
        }
    }

    *returnSize = count;
    free(sorted);
    return result;
}
