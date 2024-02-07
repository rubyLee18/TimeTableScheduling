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

void selection(int** array, int n) { //��������
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

    for (int i = 0; i <= n; i++) {   //�迭 �ʱ�ȭ
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

void merge(int** array, int** sorted, int l, int mid, int r) { //�պ�
    int i, j, k, n;
    i = l; j = mid + 1; k = l;
    while (i <= mid && j <= r) {
        if (array[i][1] <= array[j][1]) { //������ ���� �� ũ��
            sorted[k++][1] = array[i++][1]; //���� �� ����
            dataCompare++;
            dataMove++;

        }
        else { //���� ���� �� ũ��
            sorted[k++][1] = array[j++][1]; //������ �� ����
            dataCompare++;
            dataMove++;
        }
    }
    if (i > mid) //������ ���� ������
        for (n = j; n <= r; n++) {
            sorted[k++][1] = array[n][1]; //�����ִ� ������ �� ����
            dataMove++;
        }
    else //���� ���� ������
        for (n = i; n <= mid; n++) {
            sorted[k++][1] = array[n][1]; //�����ִ� ���� �� ����
            dataMove++;
        }
    for (n = l; n <= r; n++) {
        array[n][1] = sorted[n][1]; //�ӽù迭�� ���� ���� �迭�� �ٽ� ����
        dataMove++;
    }
}

void mergeSort(int** array, int** sorted, int l, int r) { //�պ�����
    int mid;
    if (l < r) {
        mid = (l + r) / 2;
        mergeSort(array, sorted, l, mid); //���ȣ���� �̿��Ͽ� ���� ����
        mergeSort(array, sorted, mid + 1, r);
        merge(array, sorted, l, mid, r); //�պ�
    }
}


//Study���͸� ���� ��¥(today)�� ���Ͽ� �켱������� ����
void setDuedatePriority(vector<Study> hw, int today, int MODE) {
    vector<Study> under7;  //������ 7�� �̸� ���� ������
    vector<Study> review; //����
    vector<Study> over7; //7�� �̻�
    //under7 ����, review����, over7����, hw�ʱ�ȭ �� under7, review, over7������ ���� ����

    int under7Size = 0;
    int over7Size = 0;
    int reviewSize = 0;

    int** under7Info = new int*[hw.size()];
    int** reviewInfo = new int*[hw.size()];
    int** over7Info = new int*[hw.size()];

    for (int i = 0; i < (signed int)hw.size(); i++) {   //�迭 �ʱ�ȭ
        under7Info[i] = new int[2];
        over7Info[i] = new int[2];
        reviewInfo[i] = new int[2];
    }

    for (int i = 0; i < (signed int)hw.size(); i++) {   //Homework ������ �Ҵ�
        //�������� �Ǵ�
        if (hw.at(i).getType() == 1) {
            //7�� ���� ���� ���� ����
            if (hw.at(i).dueDate - today < 7 && hw.at(i).dueDate - today >= 0) {
                under7Info[under7Size][0] = i;
                under7Info[under7Size++][1] = hw.at(i).dueDate;
            }

            // 7�� �̻� ���� ���� ����
            else {
                over7Info[over7Size][0] = i;
                over7Info[over7Size++][1] = hw.at(i).dueDate;
            }
        }

        //���� ��� ����
        else {
            reviewInfo[reviewSize][0] = i;
            reviewInfo[reviewSize++][1] = hw.at(i).dueDate;
        }
    }

    //array[i][0]�� index, array[i][1]�� priority

    if (MODE == 1) {
        insertion(under7Info, under7Size);  //7�� �̸� ���� ���� ����
        insertion(over7Info, over7Size);  //7�� �̻� ���� ���� ����
        insertion(reviewInfo, reviewSize);  //���� ����
    }
    else if (MODE == 2) {
        selection(under7Info, under7Size);  //7�� �̸� ���� ���� ����
        selection(over7Info, over7Size);  //7�� �̻� ���� ���� ����
        selection(reviewInfo, reviewSize);  //���� ����
    }
    else {
        int** sorted1 = new int* [hw.size()];
        int** sorted2 = new int* [hw.size()];
        int** sorted3 = new int* [hw.size()];

        for (int i = 0; i < (signed int)hw.size(); i++) {   //�迭 �ʱ�ȭ
            sorted1[i] = new int[2];
            sorted2[i] = new int[2];
            sorted3[i] = new int[2];
        }
        /*
        int* sorted1 = new int[2];
        int* sorted2 = new int[2];
        int* sorted3 = new int[2];
        */
        mergeSort(under7Info, sorted1, 0, under7Size);  //7�� �̸� ���� ���� ����
        mergeSort(over7Info, sorted2, 0, over7Size);  //7�� �̻� ���� ���� ����
        mergeSort(reviewInfo, sorted3, 0, reviewSize);  //���� ����
    }

    for (int i = 0; i < under7Size; i++) //under7 �ϼ�
        under7.push_back(hw.at(under7Info[i][0]));

    for (int i = 0; i < reviewSize; i++) //review �ϼ�
        review.push_back(hw.at(reviewInfo[i][0]));

    for (int i = 0; i < over7Size; i++) //over7 �ϼ�
        over7.push_back(hw.at(over7Info[i][0]));


    hw.clear();
    for (int i = 0; i < (signed int)under7.size(); i++) //under7 ����
        hw.push_back(under7.at(i));

    for (int i = 0; i < (signed int)review.size(); i++) //review ����
        hw.push_back(review.at(i));

    for (int i = 0; i < (signed int)over7.size(); i++) //over7 ����
        hw.push_back(over7.at(i));
    //�ϼ�!!!!
}