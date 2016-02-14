//
//  SortFunctions.h
//  CommonSortFunctions
//
//  Created by 陈圣治 on 16/2/14.
//  Copyright © 2016年 shengzhichen. All rights reserved.
//

#ifndef SortFunctions_h
#define SortFunctions_h

#include <stdio.h>

/**
 *  @brief 冒泡排序法
 *
 *  @param array int数组
 *  @param count 数组长度
 */
void bubbleSortAscending(int array[], int count);

/**
 *  @brief 快速排序法
 *
 *  @param array int数组
 *  @param low   低下标
 *  @param hight 高下标
 */
void quickSortScending(int array[], int low, int hight);

/**
 *  @brief 选择排序法
 *
 *  @param array int数组
 *  @param count 数组长度
 */
void selectSortAscending(int array[], int count);

/**
 *  @brief 插入排序法
 *
 *  @param array int数组
 *  @param count 数组长度
 */
void insertSortAscending(int array[], int count);


/**
 *  @brief 希尔排序法
 *
 *  @param array int数组
 *  @param count 数组长度
 */
void shellSortAscending(int array[], int count);

/**
 *  @brief 归并排序法
 *
 *  @param array int数组
 *  @param count 数组长度
 */
void mergeSortAscending(int array[], int count);

#endif /* SortFunctions_h */
