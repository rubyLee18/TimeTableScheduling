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
    int type; //������ ����
    string name;   //������ �̸�
    double start;   //������ ���� �ð�
    int priority = 0;   //����ġ
    bool review = false;
    char ch;
    int num = 0;
    string garbage;
    bool flag = true;
    int a;
    
    string weekdays[7] = { "��", "ȭ", "��", "��", "��", "��", "��" };

    //�⺻ �Է�
    vector<Node> lecture_v; //type = 4;
    vector<Node> meal_v; //type = 3;
    vector<Node> teamPrj_v;
    vector<Study> study_v; // type = 1;

    
    cout << "���� ��¥ �Է�\n>> ";
    cin >> today;
    getline(cin, garbage);
    today = dateToWeight(today);

    while (1) {  //���� ���� ������ �Է¹޴� while��
        num = 0;
        cout << "\n���� �̸��� �Է��ϼ���(q�� �Է��ϸ� ����)\n>> ";
        getline(cin, name);


        if (name == "q")
            break;

        cout << "������ �� ���� Ƚ���� �Է��ϼ���\n>> ";
        cin >> num;
        getline(cin, garbage);

        Node* tmp = new Node[num];
        
        for (int i = 0; i < num; i++) {
            tmp[i].lecture();
        }

        cout << "������ �켱������ �Է����ּ���\n>> ";
        cin >> priority;
        getline(cin, garbage);

        for (int i = 0; i < num; i++) {
            tmp[i].name = name;
            tmp[i].priority = priority;
            lecture_v.push_back(tmp[i]);
        }

        cout << "���� ���θ� �Է����ּ���(Y/N)\n>> ";
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

        cout << "���� ������ �Ϸ�Ǿ����ϴ�" << endl;
    }

    cout << "\n\n�Ļ� �ð��� �Է¹޽��ϴ�. 00��~08�� ���̴� ����ð��̹Ƿ� �Ļ簡 �Ұ����մϴ�" << endl << endl;

    for (int i = 0; i < AWEEK; i++) {   //�Ļ� �ð��� �޴� �κ�
        Node* meals = new Node[3];  //��ħ, ����, ���� ǥ���� ���� 3��

        cout << weekdays[i] + "������ ��ħ �Ļ� �ð��� �Է����ּ��� (0�� �Է��ϸ� skip)\n>> ";
        cin >> start;
        getline(cin, garbage);

        meals[0].meal(i, start);

        cout << weekdays[i] + "������ ���� �Ļ� �ð��� �Է����ּ��� (0�� �Է��ϸ� skip)\n>> ";
        cin >> start;
        getline(cin, garbage);

        meals[1].meal(i, start);

        cout << weekdays[i] + "������ ���� �Ļ� �ð��� �Է����ּ��� (0�� �Է��ϸ� skip)\n>> ";
        cin >> start;
        getline(cin, garbage);

        meals[2].meal(i, start);

        for (int i = 0; i < 3; i++)
            meal_v.push_back(meals[i]);
    }

    //�⺻ ����ǥ ����
    BasicSchedule(lecture_v, meal_v);

    while (flag) {      
        cout << "\n\n1: ������ ����ǥ ����   2: �̹� �� ����ǥ ����   3:���� �߰�(�̿��� ���ڸ� �Է��ϸ� ����)\n>> ";
        cin >> a;
        getline(cin, garbage);


        switch (a)
        {
        case 1: {
            if (MODE == 1) {
                cout << "���� ����\n������ �� Ƚ�� : " << dataCompare << ", ������ �̵� Ƚ�� : " << dataMove << endl << endl;
            }
            else if (MODE == 2) {
                cout << "���� ����\n������ �� Ƚ�� : " << dataCompare << ", ������ �̵� Ƚ�� : " << dataMove << endl << endl;
            }
            else {
                cout << "�պ� ����\n������ �� Ƚ�� : " << dataCompare << ", ������ �̵� Ƚ�� : " << dataMove << endl << endl;
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
                cout << "���� ����\n������ �� Ƚ�� : " << dataCompare << ", ������ �̵� Ƚ�� : " << dataMove << endl << endl;
            }
            else if (MODE == 2) {
                cout << "���� ����\n������ �� Ƚ�� : " << dataCompare << ", ������ �̵� Ƚ�� : " << dataMove << endl << endl;
            }
            else {
                cout << "�պ� ����\n������ �� Ƚ�� : " << dataCompare << ", ������ �̵� Ƚ�� : " << dataMove << endl << endl;
            }
            for (int j = 0; j < 7; j++) {
                cout << weekdays[j] << "����\t\t\t";
            }
            cout << endl;
            for (int i = 0; i < 32; i++) {
                for (int j = 0; j < 7; j++) {   //����
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
        } //�̹� �� ����ǥ ���

        //�߰� �Է�: ����� �Է����� �������� �ʱ�ȭ
        case 3: {
            cout << "�߰��� ������ Ÿ���� �Է����ּ���(1: ����, 2: ����/���)\n>> ";
            cin >> type;

            switch (type) {
            case 1: {
                Study homework;
                homework.setHomework();
                study_v.push_back(homework);
                BasicSchedule(lecture_v, meal_v);
                AdditionalSchedule(teamPrj_v, study_v);
                break;
            } //���� ���� �߰�
            case 2: {
                Node node;
                node.teamPrj();
                teamPrj_v.push_back(node);
                BasicSchedule(lecture_v, meal_v);
                AdditionalSchedule(teamPrj_v, study_v);
                break;
            } //����, ��� ���� �߰�
            default: {
                cout << "1, 2 �߿��� �Է����ּ���" << endl;
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

//�Է��� ���� ������ ���ݱ��� �Է¹��� study_v�� �����ϴ� ���ҵ��� �̿��ؼ� �ð�ǥ�� Basic���·κ��� �����
void AdditionalSchedule(vector<Node> teamPrj, vector<Study> study_v) {
    int stdDate = 0;
    vector<Study> tmp = study_v;

    dataCompare = 0;
    dataMove = 0;

    //����, ��� ���� �κ�
    for (int i = 0; i < (signed int)teamPrj.size(); i++) {
        for (int j = 0; j < teamPrj.at(i).time; j++) {
            if (weeks[teamPrj.at(i).date / 7].days[teamPrj.at(i).date % 7].schedule[teamPrj.at(i).start + j] == "empty") {
                weeks[teamPrj.at(i).date / 7].days[teamPrj.at(i).date % 7].schedule[teamPrj.at(i).start + j] = teamPrj.at(i).name + " ����";
            }
            else {
                cout << "������ �ߺ��˴ϴ� : " + weeks[teamPrj.at(i).date / 7].days[teamPrj.at(i).date % 7].schedule[teamPrj.at(i).start + j] + "�� " + teamPrj.at(i).name + " ����" << endl;
                cout << "���� ������ �����մϴ�" << endl;
                teamPrj.erase(teamPrj.begin() + i);
            }
        }
    }

    //�迭 ��� Ž���ϸ鼭 empty�� �ð��� �����ϸ� �� �ڸ��� �켱���� ������ ���� ������� ��
    //��ü ������ ����� �κ� -> ���ϸ��� �켱������ ���� ����ذ��鼭 �Ǵ�
    //�߰� ������ ����������, �� �߰������� study_v�� �ְ�, study_v�� �����ϴ� ��� ���� ������� �ð�ǥ �����, study_v�� �ѹ� �� ������ ���� ���� ����

    //������ �迭 �Ϸ�
    for (int i = 0; i < WEEKSIZE; i++) {    //i�� ����
        for (int j = 0; j < 7; j++) {   //j�� ����
            setDuedatePriority(study_v, stdDate, MODE);
            for (int k = 0; k < 32; k++) {
                //�� �ð��� ã����
                if (weeks[i].days[j].schedule[k] == "empty") {
                    for (int l = (signed int)tmp.size() - 1; l >= 0; l--) {
                        if (tmp.at(l).dueDate >= stdDate && tmp.at(l).getTime() > 0 && tmp.at(l).startDay < stdDate) {
                            if (tmp.at(l).getType() == 1) {
                                weeks[i].days[j].schedule[k] = tmp.at(l).getName() + " ����";
                                tmp.at(l).setTime(tmp.at(l).getTime() - 1);
                                break;
                            }
                            else if (tmp.at(l).getType() == 3) {
                                weeks[i].days[j].schedule[k] = tmp.at(l).getName() + " ����";
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

//���� �ð�ǥ(����, �Ļ�) ����
void BasicSchedule(vector<Node> lecture_v, vector<Node> meal_v) {

    //��ü weeks�� empty�� �ʱ�ȭ��Ű�� �κ�
    for (int i = 0; i < WEEKSIZE; i++)
        weeks[i].clear();

    //dayNode[i].date �ʱ�ȭ �κ�
    int day = 0;
    for (int i = 0; i < WEEKSIZE; i++) {
        for (int j = 0; j < 7; j++) {
            weeks[i].days[j].date = day++;
        }
    }

    //���� ���� �κ�
    for (int i = 0; i < (signed int)lecture_v.size(); i++) {
        for (int j = 0; j < WEEKSIZE; j++) {
            for (int k = 0; k < lecture_v.at(i).time; k++) {
                if (weeks[j].days[lecture_v.at(i).day].schedule[lecture_v.at(i).start + k] != "empty")
                    cout << "������ �ߺ��˴ϴ� : " + weeks[j].days[lecture_v.at(i).day].schedule[lecture_v.at(i).start + k] + "�� " + lecture_v.at(i).name << endl;
                else
                    weeks[j].days[lecture_v.at(i).day].schedule[lecture_v.at(i).start + k] = lecture_v.at(i).name + " ����";
            }   //for k
        }   //for j
    }   //for i

    //�Ļ� ���� �κ�
    for (int i = 0; i < WEEKSIZE; i++) {    //i�� ����
        for (int j = 0; j < 7; j++) {   //j�� ����
            for (int k = 0; k < 3; k++) {   //k=0�̸� ��ħ, k=1 ����, k=2 ����
                if (meal_v.at((j * 3) + k).start == -1)  //���� �ð��� -1�� �Է������� 
                    continue;

                for (int l = 0; l < 2; l++) {   //1�ð�

                    //������ ���־� ���� �Ұ���
                    if (weeks[i].days[j].schedule[meal_v.at((j * 3) + k).start + l] != "empty") 
                        cout << "������ �ߺ��˴ϴ�" + weeks[i].days[j].schedule[meal_v.at((j * 3) + k).start + l] + "�� " + "�Ļ�ð�" << endl;

                    //������ ����־� ���� ����
                    else {
                        if (k == 0)
                            weeks[i].days[j].schedule[meal_v.at((j * 3) + k).start + l] = "��ħ�Ļ�";
                        else if (k == 1)
                            weeks[i].days[j].schedule[meal_v.at((j * 3) + k).start + l] = "���ɽĻ�";
                        else
                            weeks[i].days[j].schedule[meal_v.at((j * 3) + k).start + l] = "����Ļ�";
                    }
                }   //for l
            }   //for k
        }   //for j
    }   //for i
}