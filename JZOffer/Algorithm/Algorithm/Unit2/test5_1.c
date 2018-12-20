//
//  test5_1.c
//  Algorithm
//
//  Created by YeeChain on 2018/12/19.
//  Copyright © 2018 ljc. All rights reserved.
//

#include "test5_1.h"
#include <stdlib.h>

/*
 题目:请实现一个函数，把字符串中的每个空格替换成"%20".例如，输入"We are happy,"则输出“We%20are%20happy."
 */

/*
 这道题最简单的方式就是从前往后依次替换空格，但是没替换一个，后面的字母就得往后挪位置，时间复杂度太高可以达到O(n^2),显然是不可取的，
 于是方法就是用两个指针，从后往前替换，保证只遍历一次列表，我们可以先遍历一次字符串，这样就能统计出字符串中空格的总数，
 并可以由此计算出替换之后的字符串的总长度。每替换一个空格，长度增加2，因此替换以后字符串的长度等于原来的长度加上2乘以空格数目。我
 们还是以前面的字符串"We are happy."为例。"We are happy."这个字符串的长度是14 (包括结尾符号\0')， 里面有两个空格，因此替换之后字符串的长度是18。
 我们从字符串的后面开始复制和替换。首先准备两个指针: P1和P2P指向原始字符串的末尾，而P2指向替换之后的字符串的末尾，
 接下来我们向前移动指针P，逐个把它指向的字符复制到P2指向的位置，直到碰到第一个空格为止
*/

void replaceBlank(char string[], int spaceTotalLength) {
    if (string == NULL || spaceTotalLength == 0) {
        return;
    }
    int i = 0;
    int spaceCount = 0;
    int stringLength = 0;
    while (string[i] != '\0') {
        if (string[i] == ' ') {
            spaceCount++;
        }
        i++;
        stringLength++;
    }
    stringLength++;
    int newLength = stringLength + 2 * spaceCount;
    if (newLength > spaceTotalLength) {
        printf("恕我直言，你这点空间，让我很难办事啊！！");
        return;
    }
    int tailIndex = newLength - 1;
    int headIndex = stringLength - 1;
    //截止条件就是 head 和 tail 恰好重合，这很关键
    while (headIndex != tailIndex) {
        if (string[headIndex] == ' ') {
            string[tailIndex] = '0';
            string[tailIndex - 1] = '2';
            string[tailIndex - 2] = '%';
            tailIndex = tailIndex - 3;
            headIndex--;
        } else {
            string[tailIndex] = string[headIndex];
            tailIndex--;
            headIndex--;
        }
        
    }
}

void test5_1(void) {
    char str[] = "helloworld";
    replaceBlank(str, 50);
}
