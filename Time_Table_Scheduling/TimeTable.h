#pragma once
#include <iostream>
#include <ctime>
#include <time.h>
#include <string>
#include <vector>
#define AWEEK 7
using namespace std;

string garage;
string weekdays[7] = { "월", "화", "수", "목", "금", "토", "일" };

class DayNode {
public:
    int date;
    string schedule[32] = { "empty", };    //각각의 시간별 할 일 저장
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

//수업, 식사, 팀플
class Node {   
public:
    int type; //일정의 종류
    string name;   //일정의 이름
    int day;   //일정이 존재하는 요일
    int start = 0;   //일정의 시작 시간
    int time;   //일정의 예상 소요시간
    bool skipable;   //안 하고 넘길 수 있는 일정인지에 대한 여부.
    int priority = 0;   //우선순위
    bool review = false;   //복습 여부
    int date;   //날짜가 존재하는 일정의 경우 날짜 저장

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
        while (true) {  //요일 입력받기
            flag = false;
            cout << "수업의 요일을 입력해주세요\n>> ";
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

        cout << "수업의 시작 시간을 입력해주세요\n>> ";
        cin >> start;
        getline(cin, garage);
        cout << "수업이 몇 시간짜리인지 입력해주세요(30분은 .5로 표현)\n>> ";
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
        cout << "팀플 이름을 입력해주세요\n>> ";
        cin >> this->name;
        getline(cin, garage);
        cout << "팀플 시작 시간을 입력해주세요\n>> ";
        cin >> this->start;
        getline(cin, garage);
        cout << "팀플에 걸리는 시간을 입력해주세요\n>>";
        cin >> this->time;
        getline(cin, garage);
        cout << "팀플이 있는 날짜를 입력해주세요 {ex 331 (3월 31일)}\n>> ";
        cin >> this->date;
        getline(cin, garage);

        this->time *= 2;
        this->start = (start * 2) - 16;
        this->date = dateToWeight(date);
    }
};

//과제, 복습 클래스
class Study : Node { //Node 클래스 상속받음
public:
    int dueDate; //과제 마감 날짜
    int startDay;

    void printinfo() {
        cout << "정보 출력합니다" << endl;
        cout << "이름 : " << this->name << endl;
        cout << "나온 날짜 : " << this->startDay << ", " << weightToDate(this->startDay) << endl;
        cout << "기한 : " << this->dueDate << ", " << weightToDate(this->dueDate) << endl;
        cout << "걸리는 시간 : " << this->time << endl;
    }

    void setPriority(int num) { //과목 이름을 기준으로 우선순위 설정
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
        cout << "과목 이름을 입력해주세요\n>> ";
        cin >> this->name;
        getline(cin, garage);

        cout << "언제 나온 과제인지 입력해주세요\n>> ";
        cin >> this->startDay;
        this->startDay = dateToWeight(this->startDay);
        getline(cin, garage);

        cout << "과제 마감 기한을 입력해주세요(예) 3월 15일 -> 315)\n>> ";
        cin >> this->dueDate;
        this->dueDate = dateToWeight(this->dueDate);
        getline(cin, garage);

        cout << "과제 소요 시간을 입력해주세요\n>> ";
        cin >> this->time;
        this->time *= 2;
        this->type = 1; //과제는 type 1
        getline(cin, garage);
    }

    void setReview(string name, int priority, int start) {
        this->type = 3; //복습은 type 3
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