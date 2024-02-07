#pragma once
#include <iostream>
#include <string>
#include <vector>

int dataCompare = 0;
int dataMove = 0;
#define MAX 2147483647;

void Swap(int* a, int* b) {
    int temp;
    temp = *b;
    dataMove++;
    *b = *a;
    dataMove++;
    *a = temp;
    dataMove++;
}

void selection(int** array, int n) { //선택정렬
    int i, j, MinIndex;
    int count = 0;
    for (i = 0; i < n - 1; i++) {
        MinIndex = i;
        for (j = MinIndex + 1; j < n; j++, dataCompare++)
            count++;
        if (array[MinIndex][1] > array[j][1])
            MinIndex = j;
        if (MinIndex != i)
            Swap(&array[i][1], &array[MinIndex][1]);
    }
}

void insertion(int** array, int n) { //Insertion Sort
    int** temp = new int* [n];

    for (int i = 0; i <= n; i++) {   //배열 초기화
        temp[i] = new int[2];
    }
    temp[0][1] = -MAX;
    array[0][1] = -MAX;
    for (int i = 2; i < n; i++)
    {
        temp[i] = array[i];
        dataMove++;
        int j = i;
        for (; array[j - 1][1] > temp[i][1]; j--) {
            dataCompare++;
            array[j][1] = array[j - 1][1];
            dataMove++;
        }
        array[j] = temp[i];
        dataMove++;
    }
}

void merge(int** array, int** sorted, int l, int mid, int r) { //합병
    int i, j, k, n;
    i = l; j = mid + 1; k = l;
    while (i <= mid && j <= r) {
        if (array[i][1] <= array[j][1]) { //오른쪽 값이 더 크면
            sorted[k++][1] = array[i++][1]; //왼쪽 값 저장
            dataCompare++;
            dataMove++;

        }
        else { //왼쪽 값이 더 크면
            sorted[k++][1] = array[j++][1]; //오른쪽 값 저장
            dataCompare++;
            dataMove++;
        }
    }
    if (i > mid) //오른쪽 값만 남으면
        for (n = j; n <= r; n++) {
            sorted[k++][1] = array[n][1]; //남아있는 오른쪽 값 저장
            dataMove++;
        }
    else //왼쪽 값만 남으면
        for (n = i; n <= mid; n++) {
            sorted[k++][1] = array[n][1]; //남아있는 왼쪽 값 저장
            dataMove++;
        }
    for (n = l; n <= r; n++) {
        array[n][1] = sorted[n][1]; //임시배열의 값을 원래 배열에 다시 저장
        dataMove++;
    }
}

void mergeSort(int** array, int** sorted, int l, int r) { //합병정렬
    int mid;
    if (l < r) {
        mid = (l + r) / 2;
        mergeSort(array, sorted, l, mid); //재귀호출을 이용하여 구역 나눔
        mergeSort(array, sorted, mid + 1, r);
        merge(array, sorted, l, mid, r); //합병
    }
}


//Study벡터를 기준 날짜(today)에 대하여 우선순위대로 정렬
void setDuedatePriority(vector<Study> hw, int today, int MODE) {
    vector<Study> under7;  //기한이 7일 미만 남은 과제들
    vector<Study> review; //복습
    vector<Study> over7; //7일 이상
    //under7 생성, review생성, over7생성, hw초기화 후 under7, review, over7순으로 삽입 예정

    int under7Size = 0;
    int over7Size = 0;
    int reviewSize = 0;

    int** under7Info = new int*[hw.size()];
    int** reviewInfo = new int*[hw.size()];
    int** over7Info = new int*[hw.size()];

    for (int i = 0; i < (signed int)hw.size(); i++) {   //배열 초기화
        under7Info[i] = new int[2];
        over7Info[i] = new int[2];
        reviewInfo[i] = new int[2];
    }

    for (int i = 0; i < (signed int)hw.size(); i++) {   //Homework 사이즈 할당
        //과제인지 판단
        if (hw.at(i).getType() == 1) {
            //7일 이하 남은 과제 저장
            if (hw.at(i).dueDate - today < 7 && hw.at(i).dueDate - today >= 0) {
                under7Info[under7Size][0] = i;
                under7Info[under7Size++][1] = hw.at(i).dueDate;
            }

            // 7일 이상 남은 과제 저장
            else {
                over7Info[over7Size][0] = i;
                over7Info[over7Size++][1] = hw.at(i).dueDate;
            }
        }

        //복습 노드 저장
        else {
            reviewInfo[reviewSize][0] = i;
            reviewInfo[reviewSize++][1] = hw.at(i).dueDate;
        }
    }

    //array[i][0]이 index, array[i][1]이 priority

    if (MODE == 1) {
        insertion(under7Info, under7Size);  //7일 미만 남은 과제 정렬
        insertion(over7Info, over7Size);  //7일 이상 남은 과제 정렬
        insertion(reviewInfo, reviewSize);  //복습 정렬
    }
    else if (MODE == 2) {
        selection(under7Info, under7Size);  //7일 미만 남은 과제 정렬
        selection(over7Info, over7Size);  //7일 이상 남은 과제 정렬
        selection(reviewInfo, reviewSize);  //복습 정렬
    }
    else {
        int** sorted1 = new int* [hw.size()];
        int** sorted2 = new int* [hw.size()];
        int** sorted3 = new int* [hw.size()];

        for (int i = 0; i < (signed int)hw.size(); i++) {   //배열 초기화
            sorted1[i] = new int[2];
            sorted2[i] = new int[2];
            sorted3[i] = new int[2];
        }
        /*
        int* sorted1 = new int[2];
        int* sorted2 = new int[2];
        int* sorted3 = new int[2];
        */
        mergeSort(under7Info, sorted1, 0, under7Size);  //7일 미만 남은 과제 정렬
        mergeSort(over7Info, sorted2, 0, over7Size);  //7일 이상 남은 과제 정렬
        mergeSort(reviewInfo, sorted3, 0, reviewSize);  //복습 정렬
    }

    for (int i = 0; i < under7Size; i++) //under7 완성
        under7.push_back(hw.at(under7Info[i][0]));

    for (int i = 0; i < reviewSize; i++) //review 완성
        review.push_back(hw.at(reviewInfo[i][0]));

    for (int i = 0; i < over7Size; i++) //over7 완성
        over7.push_back(hw.at(over7Info[i][0]));


    hw.clear();
    for (int i = 0; i < (signed int)under7.size(); i++) //under7 삽입
        hw.push_back(under7.at(i));

    for (int i = 0; i < (signed int)review.size(); i++) //review 삽입
        hw.push_back(review.at(i));

    for (int i = 0; i < (signed int)over7.size(); i++) //over7 삽입
        hw.push_back(over7.at(i));
    //완성!!!!
}