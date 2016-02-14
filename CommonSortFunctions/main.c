//
//  main.c
//  CommonSortFunctions
//
//  Created by 陈圣治 on 16/2/14.
//  Copyright © 2016年 shengzhichen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SortFunctions.h"

#define kUnsortedArrayLength 100

/**
 *  @brief 打印数组
 *
 *  @param array array
 *  @param count 数组长度
 */
void printIntArray(int array[], int count) {
    printf("{\n\t");
    for (int i = 0; i < count; i++) {
        if (i > 0 && i%20 == 0) {
            printf("\n\t");
        }
        printf("%d, ", array[i]);
    }
    printf("\n}\n\n");
}

/**
 *  @brief 检查是否升序排序
 *
 *  @param array int数组
 *  @param count 数组长度
 *
 *  @return 1-升序排序, 0-无序
 */
int checkSortedResult(int array[], int count) {
    for (int i = 0; i < count-1; i++) {
        if (array[i] > array[i+1]) {
            printf("***** sort wrong -_-!! : a[%d] = %d, a[%d] = %d *****\n", i, array[i], i+1, array[i+1]);
            return 0;
        }
    }
    
    return 1;
}

/**
 *  @brief 检查source数组中元素是否都存在于sorted数组中
 *
 *  @param source int数组
 *  @param sorted int数组
 *  @param count  数组长度
 *
 *  @return 1-都存在, 0-有数据不存在
 */
int checkDistinctSourceExistInSorted(int source[], int sorted[], int count) {
    int exist = 0;
    for (int i = 0; i < count; i++) {
        exist = 0;
        for (int z = 0; z < count; z++) {
            if (source[i] == sorted[z]) {
                exist = 1;
                break;
            }
        }
        if (!exist) {
            return 0;
        }
    }
    return exist;
}

/**
 *  @brief 验证是否重复
 *
 *  @param arrray  int数组
 *  @param count   数组元素个数
 *  @param ingeter 要验证的数值
 *
 *  @return 1-重复, 0-不重复
 */
int checkIfDistinct(int arrray[], int count, int ingeter) {
    for (int i = 0; i < count; i++) {
        if (arrray[i] == ingeter) {
            return 1;
        }
    }
    return 0;
}

/**
 *  @brief 初始化数组array, 不重复
 *
 *  @param array int数组
 *  @param count 数组长度
 */
void setupArrayDistinct(int array[], int count) {
    int integer = 0;
    for (int i = 0; i < count; i++) {
        integer = arc4random_uniform(count * 5);
        while (checkIfDistinct(array, i, integer)) {
            integer = arc4random_uniform(count * 5);
        }
        array[i] = integer;
    }
}

/**
 *  @brief 程序主体
 */
void sortLoop() {
    int count = kUnsortedArrayLength;
    int length = count * sizeof(int);
    int *array = malloc(length);
    int *arrayCopy = malloc(length);
    
    int funcNum = -1;
    
    while (funcNum != 0) {
        setupArrayDistinct(array, count);
        memcpy(arrayCopy, array, length);
        
        printf("############## loop begin ##############\n");
        
        printIntArray(array, count);
        
        printf("select sort function: \n");
        printf("  0. exit;\n");
        printf("  1. bubble sort;\n");
        printf("  2. quick sort;\n");
        printf("  3. select sort;\n");
        printf("  4. shell sort;\n");
        printf("  5. merge sort;\n");
        
        scanf("%d", &funcNum);
        
        switch (funcNum) {
            case 0:
                break;
            case 1:
                printf("+++++ bubbleSortAscending +++++\n");
                bubbleSortAscending(array, count);
                break;
            case 2:
                printf("+++++ quickSortScending +++++\n");
                quickSortScending(array, 0, count - 1);
                break;
            case 3:
                printf("+++++ selectSortAscending +++++\n");
                selectSortAscending(array, count);
                break;
            case 4:
                printf("+++++ shellSortAscending +++++\n");
                shellSortAscending(array, count);
                break;
            case 5:
                printf("+++++ mergeSortAscending +++++\n");
                mergeSortAscending(array, count);
                break;
            default:
                printf("error number -_-!\n\n");
                break;
        }
        
        checkSortedResult(array, count);
        if (checkSortedResult(array, count)) {
            if (checkDistinctSourceExistInSorted(arrayCopy, array, count)) {
                printf("***** sort correct ^_^ *****\n");
            } else {
                printf("***** source integer not all in result array -_-!! *****\n");
            }
        }
        
        printf("the result is: \n");
        printIntArray(array, count);
        
        printf("############## loop end ##############\n\n\n");
    }
    
    free(array);
}

int main(int argc, const char * argv[]) {
    
    sortLoop();
    
    return 0;
}
