# CommonSortFunctions

##基础排序法  

>1.  冒泡排序法  
>2.  选择排序法    
>3.  快速排序法    
>4.  插入排序法  
>5.  希尔排序法  
>6.  归并排序法  


##时间统计

####数组长度1w

    +++++ bubbleSortAscending +++++
    time interval is : 0s 469067us

    +++++ selectSortAscending +++++
    time interval is : 0s 167101us

    +++++ quickSortScending +++++
    time interval is : 0s 2179us

    +++++ shellSortAscending +++++
    time interval is : 0s 3251us

    +++++ mergeSortAscending +++++
    time interval is : 0s 1908us

    +++++ heapSortAscending +++++
    time interval is : 0s 2409us


####数组长度10w

    +++++ bubbleSortAscending +++++
    time interval is : 39s -415210us

    +++++ selectSortAscending +++++
    time interval is : 13s 229740us

    +++++ quickSortScending +++++
    time interval is : 0s 15926us

    +++++ shellSortAscending +++++
    time interval is : 0s 27335us

    +++++ mergeSortAscending +++++
    time interval is : 0s 21493us

    +++++ heapSortAscending +++++
    time interval is : 0s 19803us
 
 
####数组长度100w(bubble、select排序时间太长太长太长, 被我咔嚓掉)

    +++++ quickSortScending +++++
    time interval is : 0s 193397us

    +++++ shellSortAscending +++++
    time interval is : 0s 416222us

    +++++ mergeSortAscending +++++
    time interval is : 0s 259007us

    +++++ heapSortAscending +++++
    time interval is : 0s 272100us
 
 
####数组长度1000w

    +++++ quickSortScending +++++
    time interval is : 3s -778184us

    +++++ shellSortAscending +++++
    time interval is : 7s 293611us

    +++++ mergeSortAscending +++++
    time interval is : 3s -33996us

    +++++ heapSortAscending +++++
    time interval is : 4s 294285us
    

####数组长度10000w

    +++++ quickSortScending +++++
    time interval is : 25s 446247us

    +++++ shellSortAscending +++++
    time interval is : 134s 6597us

    +++++ mergeSortAscending +++++
    time interval is : 34s -129087us

    +++++ heapSortAscending +++++
    time interval is : 65s 159383us
