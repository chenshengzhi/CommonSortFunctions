//
//  SortFunctions.c
//  CommonSortFunctions
//
//  Created by 陈圣治 on 16/2/14.
//  Copyright © 2016年 shengzhichen. All rights reserved.
//

#include <stdlib.h>
#include "SortFunctions.h"

int temp_;

void swap(int array[], int one, int anther) {
    temp_ = array[one];
    array[one] = array[anther];
    array[anther] = temp_;
}

/**
 *  @brief 冒泡排序法
 *
 *  @param array int数组
 *  @param count 数组长度
 */
void bubbleSortAscending(int array[], int count) {
    int sorted, unsorted;
    for (sorted = 0; sorted < count-1; sorted++) {
        for (unsorted = 0; unsorted < count-1-sorted; unsorted++) {
            if (array[unsorted] > array[unsorted+1]) {
                swap(array, unsorted, unsorted+1);
            }
        }
    }
}

/**
 *  @brief 选择排序法
 *
 *  @param array int数组
 *  @param count 数组长度
 */
void selectSortAscending(int array[], int count) {
    int min;
    for (int target = 0; target < count - 1; target++) {
        min = target;
        for (int loop = target + 1; loop < count; loop++) {
            if (array[loop] < array[min]) {
                min = loop;
            }
        }
        if (min != target) {
            swap(array, min, target);
        }
    }
}

/**
 *  @brief 快速排序法
 *
 *  @param array int数组
 *  @param low   低下标
 *  @param hight 高下标
 */
void quickSortScending(int array[], int low, int hight) {
    if (low >= hight) {
        return;
    }
    
    int left = low;
    int right = hight;
    int key = array[left];
    
    while (left < right) {
        while (right > left && array[right] >= key) {
            right--;
        }
        array[left] = array[right];
        
        while (left < right && array[left] <= key) {
            left++;
        }
        array[right] = array[left];
    }
    array[left] = key;
    
    quickSortScending(array, low, left-1);
    quickSortScending(array, left+1, hight);
}

/**
 *  @brief 插入排序法
 *
 *  @param array int数组
 *  @param count 数组长度
 */
void insertSortAscending(int array[], int count) {
    int i, k, temp;
    for (i = 1; i < count; i++) {
        if (array[i] < array[i - 1]) {
            temp = array[i];
            for (k = i - 1; k >= 0 && array[k] > temp; k--) {
                array[k + 1] = array[k];
            }
            array[k + 1] = temp;
        }
    }
}

/**
 *  @brief 希尔排序法
 *
 *  @param array int数组
 *  @param count 数组长度
 */
void shellSortAscending(int array[], int count) {
    int i, z, step;
    for (step = count / 2; step > 0; step /= 2) {
        for (i = 0; i < step; i++) {
            for (z = i + step; z < count; z += step) {
                if (array[z] < array[z - step]) {
                    int temp = array[z];
                    int k = z - step;
                    while (k >= 0 && array[k] > temp) {
                        array[k + step] = array[k];
                        k -= step;
                    }
                    array[k + step] = temp;
                }
            }
        }
    }
}

/**
 *  @brief 归并排序法步骤2: 合并有序数组array[first...mid]合array[mid+1...last]
 *
 *  @param array int数组
 *  @param first 第一个元素的下标
 *  @param mid   中间元素的下标
 *  @param last  最后一个元素的下标
 *  @param temp  临时数组, 合并过程存放排序后的数组
 */
void mergeSortAscendingCombine(int array[], int first, int mid, int last, int temp[]) {
    int left = first, right = mid + 1;
    int k = 0;
    
    while (left <= mid && right <= last) {
        if (array[left] < array[right]) {
            temp[k] = array[left];
            k++;
            left++;
        } else {
            temp[k] = array[right];
            k++;
            right++;
        }
    }
    
    while (left <= mid) {
        temp[k] = array[left];
        k++;
        left++;
    }
    
    while (right <= last) {
        temp[k] = array[right];
        k++;
        right++;
    }
    
    for (int i = 0; i < k; i++) {
        array[first + i] = temp[i];
    }
}

/**
 *  @brief 归并排序法步骤1: 递归对半划分, 再进行合并
 *
 *  @param array int数组
 *  @param first 划分的部分第一个下标
 *  @param last  划分的部分最后一个下标
 *  @param temp  临时数组
 */
void mergeSortAscendingDivide(int array[], int first, int last, int temp[]) {
    if (first < last) {
        int mid = (first + last) / 2;
        mergeSortAscendingDivide(array, first, mid, temp);
        mergeSortAscendingDivide(array, mid + 1, last, temp);
        mergeSortAscendingCombine(array, first, mid, last, temp);
    }
}

/**
 *  @brief 归并排序法
 *
 *  @param array int数组
 *  @param count 数组长度
 */
void mergeSortAscending(int array[], int count) {
    int *temp = malloc(sizeof(int) * count);
    if (temp == NULL) {
        printf("********************************\n");
        printf("\t\t memeory alloc fail");
        printf("********************************\n");
        return;
    }
    mergeSortAscendingDivide(array, 0, count - 1, temp);
    free(temp);
}

/**
 *  @brief 堆排序法步骤: 堆化数组, 大根堆
 *
 *  @param array int数组
 *  @param index 要下沉的节点位置
 *  @param count 数组长度
 */
void heapSortAcsendingAdjust(int array[], int index, int count) {
    int temp = array[index];
    int z = 2 * index + 1;
    while (z < count) {
        if (z + 1 < count && array[z + 1] > array[z]) {
            z++;
        }
        
        if (array[z] > temp) {
            array[index] = array[z];
            index = z;
            z = 2 * index + 1;
        } else {
            break;
        }
    }
    array[index] = temp;
}

/**
 *  @brief 堆排序法
 *
 *  @param array int数组
 *  @param count 数组长度
 */
void heapSortAscending(int array[], int count) {
    for (int i = count/2 - 1; i >= 0; i--) {
        heapSortAcsendingAdjust(array, i, count);
    }
    
    int temp = 0;
    for (int i = count - 1; i > 0; i--) {
        temp = array[i];
        array[i] = array[0];
        array[0] = temp;
        heapSortAcsendingAdjust(array, 0, i);
    }
}

