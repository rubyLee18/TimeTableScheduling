#pragma once
#include <iostream>
#include <ctime>
#include <time.h>
#include <string>
#include <vector>
#define AWEEK 7
using namespace std;

string garage;
string weekdays[7] = { "��", "ȭ", "��", "��", "��", "��", "��" };

class DayNode {
public:
    int date;
    string schedule[32] = { "empty", };    //������ �ð��� �� �� ����
};

class WeekNode {
public:
    DayNode days[7];

    void clear() {
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 32; j++)
                days[i].schedule[j] = "empty";
        }
    }
};

//����, �Ļ�, ����
class Node {   
public:
    int type; //������ ����
    string name;   //������ �̸�
    int day;   //������ �����ϴ� ����
    int start = 0;   //������ ���� �ð�
    int time;   //������ ���� �ҿ�ð�
    bool skipable;   //�� �ϰ� �ѱ� �� �ִ� ���������� ���� ����.
    int priority = 0;   //�켱����
    bool review = false;   //���� ����
    int date;   //��¥�� �����ϴ� ������ ��� ��¥ ����

    int getPriority() {
        return this->priority;
    }

    string getName() {
        return this->name;
    }

    void lecture() { //setter
        string temp;
        bool flag = false;
        double start = 0;
        double time = 0;
        while (true) {  //���� �Է¹ޱ�
            flag = false;
            cout << "������ ������ �Է����ּ���\n>> ";
            getline(cin, temp);

            for (int i = 0; i < 7; i++) {
                if (weekdays[i] == temp) {
                    this->day = i;
                    flag = true;
                }
            }
            if (flag)
                break;
        }

        cout << "������ ���� �ð��� �Է����ּ���\n>> ";
        cin >> start;
        getline(cin, garage);
        cout << "������ �� �ð�¥������ �Է����ּ���(30���� .5�� ǥ��)\n>> ";
        cin >> time;
        getline(cin, garage);

        this->time = time * 2;
        this->start = (start * 2) - 16;

        //cin >> priority;
        //priority += 0;
    }

    void meal(int day, double start) { //setter4
        this->day = day;
        if (start >= 8) {
            this->start = (start * 2) - 16;
        }
        else
            this->start = -1;
    }

    void teamPrj() {
        cout << "���� �̸��� �Է����ּ���\n>> ";
        cin >> this->name;
        getline(cin, garage);
        cout << "���� ���� �ð��� �Է����ּ���\n>> ";
        cin >> this->start;
        getline(cin, garage);
        cout << "���ÿ� �ɸ��� �ð��� �Է����ּ���\n>>";
        cin >> this->time;
        getline(cin, garage);
        cout << "������ �ִ� ��¥�� �Է����ּ��� {ex 331 (3�� 31��)}\n>> ";
        cin >> this->date;
        getline(cin, garage);

        this->time *= 2;
        this->start = (start * 2) - 16;
        this->date = dateToWeight(date);
    }
};

//����, ���� Ŭ����
class Study : Node { //Node Ŭ���� ��ӹ���
public:
    int dueDate; //���� ���� ��¥
    int startDay;

    void printinfo() {
        cout << "���� ����մϴ�" << endl;
        cout << "�̸� : " << this->name << endl;
        cout << "���� ��¥ : " << this->startDay << ", " << weightToDate(this->startDay) << endl;
        cout << "���� : " << this->dueDate << ", " << weightToDate(this->dueDate) << endl;
        cout << "�ɸ��� �ð� : " << this->time << endl;
    }

    void setPriority(int num) { //���� �̸��� �������� �켱���� ����
        this->priority = num;
    }

    int getType() {
        return this->type;
    }

    int getTime() {
        return this->time;
    }

    void setTime(int time) {
        this->time = time;
    }

    string getName() {
        return this->name;
    }

    void setHomework() { 
        cout << "���� �̸��� �Է����ּ���\n>> ";
        cin >> this->name;
        getline(cin, garage);

        cout << "���� ���� �������� �Է����ּ���\n>> ";
        cin >> this->startDay;
        this->startDay = dateToWeight(this->startDay);
        getline(cin, garage);

        cout << "���� ���� ������ �Է����ּ���(��) 3�� 15�� -> 315)\n>> ";
        cin >> this->dueDate;
        this->dueDate = dateToWeight(this->dueDate);
        getline(cin, garage);

        cout << "���� �ҿ� �ð��� �Է����ּ���\n>> ";
        cin >> this->time;
        this->time *= 2;
        this->type = 1; //������ type 1
        getline(cin, garage);
    }

    void setReview(string name, int priority, int start) {
        this->type = 3; //������ type 3
        this->priority = priority + 50;
        this->time = 2;
        this->startDay = start;
        this->dueDate = this->startDay + 7;
        this->name = name;
    }
    void getDuedate(int today) {
        this->dueDate = today + AWEEK;
    }
};