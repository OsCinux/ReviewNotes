//
//  test4_1.c
//  Algorithm
//
//  Created by YeeChain on 2018/12/19.
//  Copyright © 2018 ljc. All rights reserved.
//

#include "test4_1.h"

/*
 题目:在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
 请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
 */

/*
 这道题的解题要点在于要从二维数组的右上角开始或者右下角开始，如果一开始就从左上角开始查找，肯定就陷入了死胡同了。
 直接找一个实际一点的例子开始分析：假设要找的数字是 m 数组中当前进行比较的数字是 n，从右上角开始：如果 m == n，
 那么直接就找到了这个数；如果 m > n 那么在 n 的下面继续找,排除当前的行；如果 m < n ，那么排除 n 所在的列，
 继续在 n 的左边找。这里还有一个要点就是，二维数组虽然看起来是二维的，但是在内存上还是像一维那样连续排列，只不过是先依次
 放一行，再依次放下一行，这里直接就用一维传参了
 
 */

int find(int *matrix, int rowCount, int colCount, int number) {
    if (matrix == NULL || rowCount == 0 || colCount == 0) {
        return -1;
    }
    int row = 0;
    int colom = colCount - 1;
    while (row != rowCount - 1 && colCount != 0) {
        int index = row * colCount + colom;
        if (number == matrix[index]) {
            return 1;
        } else if (number < matrix[index]) {
            colom = colom - 1;
        } else {
            row = row + 1;
        }
    }
    return 0;
}

void test4_1(void) {
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    int *e = (int *)matrix;
    int result = find((int *)matrix, 4, 4, 22);
    if (result == 0) {
        printf("没找到");
    } else if (result == 1) {
        printf("找到了");
    } else {
        printf("参数错误");
    }
}
//1 2 8 9
//2 4 9 12
//4 7 10 13
//6 8 11 15

