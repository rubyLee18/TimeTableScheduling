#pragma once
#include "DateWeight.h"
#include "TimeTable.h"
#include "Sorting.h"
#define AWEEK 7
#define WEEKSIZE 15
int MODE = 2;
int today;
extern int dataCompare;
extern int dataMove;
void BasicSchedule(vector<Node> lecture_v, vector<Node> meal_v);
void AdditionalSchedule(vector<Node> teamPrj, vector<Study> study_v);
WeekNode weeks[WEEKSIZE];

using namespace std;

int main() {
    int type; //일정의 종류
    string name;   //일정의 이름
    double start;   //일정의 시작 시간
    int priority = 0;   //가중치
    bool review = false;
    char ch;
    int num = 0;
    string garbage;
    bool flag = true;
    int a;
    
    string weekdays[7] = { "월", "화", "수", "목", "금", "토", "일" };

    //기본 입력
    vector<Node> lecture_v; //type = 4;
    vector<Node> meal_v; //type = 3;
    vector<Node> teamPrj_v;
    vector<Study> study_v; // type = 1;

    
    cout << "오늘 날짜 입력\n>> ";
    cin >> today;
    getline(cin, garbage);
    today = dateToWeight(today);

    while (1) {  //과목에 대한 정보를 입력받는 while문
        num = 0;
        cout << "\n과목 이름을 입력하세요(q를 입력하면 끝냄)\n>> ";
        getline(cin, name);


        if (name == "q")
            break;

        cout << "일주일 간 수업 횟수를 입력하세요\n>> ";
        cin >> num;
        getline(cin, garbage);

        Node* tmp = new Node[num];
        
        for (int i = 0; i < num; i++) {
            tmp[i].lecture();
        }

        cout << "과목의 우선순위를 입력해주세요\n>> ";
        cin >> priority;
        getline(cin, garbage);

        for (int i = 0; i < num; i++) {
            tmp[i].name = name;
            tmp[i].priority = priority;
            lecture_v.push_back(tmp[i]);
        }

        cout << "복습 여부를 입력해주세요(Y/N)\n>> ";
        cin >> ch;
        getline(cin, garbage);
        
        for (int i = 0; i < num; i++) {
            if (ch == 'y' || ch == 'Y') {
                review = true;
                Study rev;
                rev.setReview(name, priority, tmp[i].day);
                study_v.push_back(rev);
            }
        }

        cout << "수업 생성이 완료되었습니다" << endl;
    }

    cout << "\n\n식사 시간을 입력받습니다. 00시~08시 사이는 수면시간이므로 식사가 불가능합니다" << endl << endl;

    for (int i = 0; i < AWEEK; i++) {   //식사 시간을 받는 부분
        Node* meals = new Node[3];  //아침, 점심, 저녁 표현을 위해 3개

        cout << weekdays[i] + "요일의 아침 식사 시간을 입력해주세요 (0을 입력하면 skip)\n>> ";
        cin >> start;
        getline(cin, garbage);

        meals[0].meal(i, start);

        cout << weekdays[i] + "요일의 점심 식사 시간을 입력해주세요 (0을 입력하면 skip)\n>> ";
        cin >> start;
        getline(cin, garbage);

        meals[1].meal(i, start);

        cout << weekdays[i] + "요일의 저녁 식사 시간을 입력해주세요 (0을 입력하면 skip)\n>> ";
        cin >> start;
        getline(cin, garbage);

        meals[2].meal(i, start);

        for (int i = 0; i < 3; i++)
            meal_v.push_back(meals[i]);
    }

    //기본 일정표 생성
    BasicSchedule(lecture_v, meal_v);

    while (flag) {      
        cout << "\n\n1: 오늘의 일정표 보기   2: 이번 주 일정표 보기   3:일정 추가(이외의 숫자를 입력하면 끝냄)\n>> ";
        cin >> a;
        getline(cin, garbage);


        switch (a)
        {
        case 1: {
            if (MODE == 1) {
                cout << "삽입 정렬\n데이터 비교 횟수 : " << dataCompare << ", 데이터 이동 횟수 : " << dataMove << endl << endl;
            }
            else if (MODE == 2) {
                cout << "선택 정렬\n데이터 비교 횟수 : " << dataCompare << ", 데이터 이동 횟수 : " << dataMove << endl << endl;
            }
            else {
                cout << "합병 정렬\n데이터 비교 횟수 : " << dataCompare << ", 데이터 이동 횟수 : " << dataMove << endl << endl;
            }
            for (int i = 0; i < 32; i++) {
                if (weeks[today / 7].days[today % 7].schedule[i] != "empty") {
                    cout << "(" << (i / 2) + 8 << ":";
                    if ((i % 2) * 30 == 0)
                        cout << "00";
                    else
                        cout << (i % 2) * 30;
                    cout << ")  " + weeks[today / 7].days[today % 7].schedule[i] << endl;
                }
            }
            break;
        }

        case 2: {
            if (MODE == 1) {
                cout << "삽입 정렬\n데이터 비교 횟수 : " << dataCompare << ", 데이터 이동 횟수 : " << dataMove << endl << endl;
            }
            else if (MODE == 2) {
                cout << "선택 정렬\n데이터 비교 횟수 : " << dataCompare << ", 데이터 이동 횟수 : " << dataMove << endl << endl;
            }
            else {
                cout << "합병 정렬\n데이터 비교 횟수 : " << dataCompare << ", 데이터 이동 횟수 : " << dataMove << endl << endl;
            }
            for (int j = 0; j < 7; j++) {
                cout << weekdays[j] << "요일\t\t\t";
            }
            cout << endl;
            for (int i = 0; i < 32; i++) {
                for (int j = 0; j < 7; j++) {   //요일
                    if (weeks[today / 7].days[j].schedule[i] != "empty") {
                        cout << "(" << (i / 2) + 8 << ":";
                        if ((i % 2) * 30 == 0)
                            cout << "00";
                        else
                            cout << (i % 2) * 30;
                        cout << ")  " + weeks[today / 7].days[j].schedule[i] << "\t";
                    }

                    else
                        cout << "\t\t\t";
                }
                cout << endl;
            }
            cout << endl;
            break;
        } //이번 주 일정표 출력

        //추가 입력: 사용자 입력으로 지역변수 초기화
        case 3: {
            cout << "추가할 일정의 타입을 입력해주세요(1: 과제, 2: 팀플/약속)\n>> ";
            cin >> type;

            switch (type) {
            case 1: {
                Study homework;
                homework.setHomework();
                study_v.push_back(homework);
                BasicSchedule(lecture_v, meal_v);
                AdditionalSchedule(teamPrj_v, study_v);
                break;
            } //과제 일정 추가
            case 2: {
                Node node;
                node.teamPrj();
                teamPrj_v.push_back(node);
                BasicSchedule(lecture_v, meal_v);
                AdditionalSchedule(teamPrj_v, study_v);
                break;
            } //팀플, 약속 일정 추가
            default: {
                cout << "1, 2 중에서 입력해주세요" << endl;
                continue;
            }
            }
            break;
        }

        default:
            flag = false;
        }
    }
}

//입력을 받을 때마다 지금까지 입력받은 study_v에 존재하는 원소들을 이용해서 시간표를 Basic상태로부터 재생성
void AdditionalSchedule(vector<Node> teamPrj, vector<Study> study_v) {
    int stdDate = 0;
    vector<Study> tmp = study_v;

    dataCompare = 0;
    dataMove = 0;

    //팀플, 약속 삽입 부분
    for (int i = 0; i < (signed int)teamPrj.size(); i++) {
        for (int j = 0; j < teamPrj.at(i).time; j++) {
            if (weeks[teamPrj.at(i).date / 7].days[teamPrj.at(i).date % 7].schedule[teamPrj.at(i).start + j] == "empty") {
                weeks[teamPrj.at(i).date / 7].days[teamPrj.at(i).date % 7].schedule[teamPrj.at(i).start + j] = teamPrj.at(i).name + " 팀플";
            }
            else {
                cout << "일정이 중복됩니다 : " + weeks[teamPrj.at(i).date / 7].days[teamPrj.at(i).date % 7].schedule[teamPrj.at(i).start + j] + "와 " + teamPrj.at(i).name + " 팀플" << endl;
                cout << "팀플 일정을 삭제합니다" << endl;
                teamPrj.erase(teamPrj.begin() + i);
            }
        }
    }

    //배열 모두 탐색하면서 empty인 시간이 존재하면 그 자리에 우선순위 순으로 과제 집어넣을 것
    //전체 스케쥴 만드는 부분 -> 매일매일 우선순위를 새로 계산해가면서 판단
    //추가 과제를 받을때마다, 그 추가과제를 study_v에 넣고, study_v에 존재하는 모든 원소 대상으로 시간표 재생성, study_v에 한번 들어간 원소의 값은 변경 없음

    //과제도 배열 완료
    for (int i = 0; i < WEEKSIZE; i++) {    //i가 주차
        for (int j = 0; j < 7; j++) {   //j가 요일
            setDuedatePriority(study_v, stdDate, MODE);
            for (int k = 0; k < 32; k++) {
                //빈 시간을 찾았음
                if (weeks[i].days[j].schedule[k] == "empty") {
                    for (int l = (signed int)tmp.size() - 1; l >= 0; l--) {
                        if (tmp.at(l).dueDate >= stdDate && tmp.at(l).getTime() > 0 && tmp.at(l).startDay < stdDate) {
                            if (tmp.at(l).getType() == 1) {
                                weeks[i].days[j].schedule[k] = tmp.at(l).getName() + " 과제";
                                tmp.at(l).setTime(tmp.at(l).getTime() - 1);
                                break;
                            }
                            else if (tmp.at(l).getType() == 3) {
                                weeks[i].days[j].schedule[k] = tmp.at(l).getName() + " 복습";
                                tmp.at(l).setTime(tmp.at(l).getTime() - 1);
                                break;
                            }
                        }
                    }
                }
            }
            for (int k = 0; k < (signed int)tmp.size(); k++) {
                if (tmp.at(k).dueDate >= stdDate) {
                    if (tmp.at(k).dueDate == stdDate && tmp.at(k).getType() == 3) {
                        tmp.at(k).dueDate = stdDate + 7;
                        tmp.at(k).startDay = stdDate;
                        tmp.at(k).setTime(2);
                    }
                    else
                        tmp.at(k).setPriority(tmp.at(k).dueDate - stdDate);
                }
            }
            stdDate++;
        }
    }
}

//고정 시간표(수업, 식사) 생성
void BasicSchedule(vector<Node> lecture_v, vector<Node> meal_v) {

    //전체 weeks를 empty로 초기화시키는 부분
    for (int i = 0; i < WEEKSIZE; i++)
        weeks[i].clear();

    //dayNode[i].date 초기화 부분
    int day = 0;
    for (int i = 0; i < WEEKSIZE; i++) {
        for (int j = 0; j < 7; j++) {
            weeks[i].days[j].date = day++;
        }
    }

    //수업 삽입 부분
    for (int i = 0; i < (signed int)lecture_v.size(); i++) {
        for (int j = 0; j < WEEKSIZE; j++) {
            for (int k = 0; k < lecture_v.at(i).time; k++) {
                if (weeks[j].days[lecture_v.at(i).day].schedule[lecture_v.at(i).start + k] != "empty")
                    cout << "일정이 중복됩니다 : " + weeks[j].days[lecture_v.at(i).day].schedule[lecture_v.at(i).start + k] + "와 " + lecture_v.at(i).name << endl;
                else
                    weeks[j].days[lecture_v.at(i).day].schedule[lecture_v.at(i).start + k] = lecture_v.at(i).name + " 수업";
            }   //for k
        }   //for j
    }   //for i

    //식사 삽입 부분
    for (int i = 0; i < WEEKSIZE; i++) {    //i는 주차
        for (int j = 0; j < 7; j++) {   //j는 요일
            for (int k = 0; k < 3; k++) {   //k=0이면 아침, k=1 점심, k=2 저녁
                if (meal_v.at((j * 3) + k).start == -1)  //시작 시간을 -1로 입력했으면 
                    continue;

                for (int l = 0; l < 2; l++) {   //1시간

                    //일정이 차있어 삽입 불가능
                    if (weeks[i].days[j].schedule[meal_v.at((j * 3) + k).start + l] != "empty") 
                        cout << "일정이 중복됩니다" + weeks[i].days[j].schedule[meal_v.at((j * 3) + k).start + l] + "와 " + "식사시간" << endl;

                    //일정이 비어있어 삽입 가능
                    else {
                        if (k == 0)
                            weeks[i].days[j].schedule[meal_v.at((j * 3) + k).start + l] = "아침식사";
                        else if (k == 1)
                            weeks[i].days[j].schedule[meal_v.at((j * 3) + k).start + l] = "점심식사";
                        else
                            weeks[i].days[j].schedule[meal_v.at((j * 3) + k).start + l] = "저녁식사";
                    }
                }   //for l
            }   //for k
        }   //for j
    }   //for i
}