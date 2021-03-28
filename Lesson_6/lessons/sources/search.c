#include"search.h"

int lineSearch(int *arr, int size, int val){
    int i = 0;
    while (i < size && arr[i] != val){
        i++;
    }
    return (i < size) ? i : -1;
}

int bareerSearch(int *arr, int size, int val){
    int i = 0;
    while (arr[i] != val){
        i++;
    }
    if (i < size - 1){
        return i;
    }
    else{
        return -1;
    }
}

int binSearch(int *arr, int size, int val){
    int l = 0;
    int r = size - 1;
    int mid = (l + r)/2;
    while (l < r && arr[mid]!= val){
        if(val >= arr[mid]){
            l = mid;
            mid = (l + r)/2 + (l + r)%2;
        }else{
            r = mid;
            mid = (l + r)/2;
        }
    }
    if(arr[mid] == val)
        return mid;
    else
        return -1;
}

int interpolarSearch(int *arr, int size, int val){
    int mid;
    int l = 0;
    int r = size - 1;
    while (arr[l] < val && arr[r] > val){
        mid = l + ((val - arr[l]) * (r - l))/(arr[r] - arr[l]);
        if(arr[mid] < val)
            l = mid + 1;
        else if(arr[mid] > val)
            r = mid - 1;
        else
            return mid;
    }
    if(arr[l] == val)
        return l;
    else if(arr[r] == val)
        return r;
    else
        return -1;
}