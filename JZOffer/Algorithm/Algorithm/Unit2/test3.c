//
//  test3.c
//  Algorithm
//
//  Created by YeeChain on 2018/12/12.
//  Copyright © 2018 ljc. All rights reserved.
//

#include "test3.h"

/*
 题目一:找出数组中重复的数字。
 在一个长度为n的数组里的所有数字都在0~n-1的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每
 个数字重复了几次。请找出数组中任意一个重复的数字。例如，如果输入长度为7的数组{2,3,1,0,2,5,3},那么对应的输出
 是重复的数字2或者3。
 */

/* 解法：
按道理来说，如果不重复的话 a[i] = i，因为所有数组都在 0 ~ n -1 的 范围内，假设 a[i] = m，如果 m != i 的话，就把 m
移到 a[m] 的位置上去，如果发现 a[m] 已经等于 m 了,那么此时的 m 肯定就重复了
 
 */

void duplicate(int numbers[], int length, int *duplicate) {
    if (numbers == NULL || length <= 0) {
        return;
    }
    int *p = duplicate;
    for (int i = 0; i <= length - 1; i++) {
        while (numbers[i] != i) {
            int m = numbers[i];
            if (numbers[m] != m) {
                numbers[i] = numbers[m];
                numbers[m] = m;
            } else {
                *p = numbers[i];
                return;
            }
        }
    }
    
}

void test(void) {
    int numbers[] = {2, 1, 3, 1, 4};
    int duplications[1];
    duplicate(numbers, sizeof(numbers) / sizeof(int), duplications);
    int length = sizeof(duplications) / sizeof(int);
    for (int i = 0; i<length; i++) {
        printf("=====%d=====\n", duplications[i]);
    }
}
