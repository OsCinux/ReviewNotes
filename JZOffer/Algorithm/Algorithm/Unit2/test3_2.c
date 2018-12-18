//
//  test3_2.c
//  Algorithm
//
//  Created by YeeChain on 2018/12/17.
//  Copyright © 2018 ljc. All rights reserved.
//

#include "test3_2.h"

/*题目二:不修改数组找出重复的数字。
在一个长度为n+1的数组里的所有数字都在1~n的范围内，所以数组中至少有一个数字是重复的。
 请找出数组中任意一个重复的数字，但不能修改输入的数组。
 例如，如果输入长度为8的数组{2,3,5,4,3,2,6,7}，那么对应的输出是重复的数字2或者3。
 */

/* 解法：
 1.创建一个大小为 n+1 的数组 array, 然后遍历以前的数组，一个一个把数字 n 移到 array 中 array[n] 的位置，
 这样就很容易发现了哪个数字重复了
 
 2.思考
 如果数组没有重复，那么在 1 ~ n 这个区间内的数字肯定只有 n 个，只有重复了，才会大于 n 个，那么就可以思考，如果 1 ~ n/2这个区间内的数
 如果大于 n / 2 个，那么这个重复的数是不是在 1 ~ n / 2 这个区间内，于是我们可以采用二分法去判断
 
 */

int findCountLessThanMidValue(int numbers[], int length, int midValue) {
    int count = 0;
    for (int i = 0; i<= length - 1; i++) {
        if (numbers[i] <= midValue) {
            count++;
        }
    }
    return count;
}


int getDuplicaiton(int numbers[], int length) {
    if (numbers == NULL || length == 0) {
        return -1;
    }
    int start = 1;
    int end = length - 1;
    while (end >= start) {
        int midValue = (end - start) / 2 + start;
        int count = findCountLessThanMidValue(numbers, length, midValue);
        if (end == start) {
            if (count > 1) {
                return start;
            } else {
                break;
            }
        }
        
        if (count > (midValue - start + 1)) {
            end = midValue;
        } else {
            start = midValue + 1;
        }
    }
    return -1;
}


void test3_2(void) {
    int numbers[] = {2,3,5,4,3,2,6,7};
    int duplication = getDuplicaiton(numbers, sizeof(numbers) / sizeof(int));
    printf("=====%d=====\n", duplication);
}
