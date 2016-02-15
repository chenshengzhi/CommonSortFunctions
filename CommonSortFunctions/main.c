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
#include <sys/time.h>
#include "SortFunctions.h"

#define kUnsortedArrayLength 100
#define kArrayIntegerDistinct 0
#define kTimeStat 1

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
 *  @brief 初始化数组array
 *
 *  @param array int数组
 *  @param count 数组长度
 */
void setupArray(int array[], int count) {
    int integer = 0;
    for (int i = 0; i < count; i++) {
        integer = arc4random_uniform(count * 5);
#if kArrayIntegerDistinct
        while (checkIfDistinct(array, i, integer)) {
            integer = arc4random_uniform(count * 5);
        }
#endif
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
    if (array == NULL) {
        printf("********************************\n");
        printf("\t\t memeory alloc fail");
        printf("********************************\n");
        return;
    }
    int *arrayCopy = malloc(length);
    if (arrayCopy == NULL) {
        printf("********************************\n");
        printf("\t\t memeory alloc fail");
        printf("********************************\n");
        return;
    }
    
    int funcNum = -1;
    
    while (funcNum != 0) {
        setupArray(array, count);
        memcpy(arrayCopy, array, length);
        printIntArray(array, count);
        
        printf("############## loop begin ##############\n");
        printf("select sort function: \n");
        printf("  0. exit;\n");
        printf("  1. bubble sort;\n");
        printf("  2. select sort;\n");
        printf("  3. quick sort;\n");
        printf("  4. shell sort;\n");
        printf("  5. merge sort;\n");
        printf("  6. heap sort;\n");
        
        scanf("%d", &funcNum);
        
        switch (funcNum) {
            case 0:
                break;
            case 1:
                printf("+++++ bubbleSortAscending +++++\n");
                bubbleSortAscending(array, count);
                break;
            case 2:
                printf("+++++ selectSortAscending +++++\n");
                selectSortAscending(array, count);
                break;
            case 3:
                printf("+++++ quickSortScending +++++\n");
                quickSortScending(array, 0, count - 1);
                break;
            case 4:
                printf("+++++ shellSortAscending +++++\n");
                shellSortAscending(array, count);
                break;
            case 5:
                printf("+++++ mergeSortAscending +++++\n");
                mergeSortAscending(array, count);
                break;
            case 6:
                printf("+++++ heapSortAscending +++++\n");
                heapSortAscending(array, count);
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

void sortTimeStat(int count) {
    int length = count * sizeof(int);
    int *array = malloc(length);
    if (array == NULL) {
        printf("********************************\n");
        printf("\t\t memeory alloc fail");
        printf("********************************\n");
        return;
    }
    
    for (int i = 1; i <= 6; i++) {
        setupArray(array, count);
        
        struct timeval begin;
        gettimeofday(&begin, NULL);

        switch (i) {
            case 0:
                break;
            case 1:
                printf("+++++ bubbleSortAscending +++++\n");
                bubbleSortAscending(array, count);
                break;
            case 2:
                printf("+++++ selectSortAscending +++++\n");
                selectSortAscending(array, count);
                break;
            case 3:
                printf("+++++ quickSortScending +++++\n");
                quickSortScending(array, 0, count - 1);
                break;
            case 4:
                printf("+++++ shellSortAscending +++++\n");
                shellSortAscending(array, count);
                break;
            case 5:
                printf("+++++ mergeSortAscending +++++\n");
                mergeSortAscending(array, count);
                break;
            case 6:
                printf("+++++ heapSortAscending +++++\n");
                heapSortAscending(array, count);
                break;
            default:
                break;
        }

        struct timeval end;
        gettimeofday(&end, NULL);
        printf("time interval is : %lds %dus\n\n\n", (end.tv_sec  - begin.tv_sec), (end.tv_usec - begin.tv_usec));
    }
    free(array);
}

int main(int argc, const char * argv[]) {
#if kTimeStat
    int count = 10000;
    for (int i = 0; i < 4; i++) {
        printf("############## array length = %d ##############\n", count);
        sortTimeStat(count);
        count *= 10;
        printf("############## loop end ##############\n\n\n");
    }
#else
    sortLoop();
#endif
    
    return 0;
}


