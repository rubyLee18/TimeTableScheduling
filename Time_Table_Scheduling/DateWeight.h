#pragma once
#pragma once

#include <iostream>
#include <ctime>
#include <time.h>
#include <string>
#include <vector>
using namespace std;

int weightToDate(int weight) {
	//2021년도 3월 ~ 6월 기준
	int month = 0, day = 0;

	if (weight < 0) return -1;

	else if (weight < 31) { month = 3; day = weight + 1; }
	else if (weight < 61) { month = 4; day = weight - 30; }
	else if (weight < 92) { month = 5; day = weight - 60; }
	else if (weight < 122) { month = 6; day = weight - 91; }

	else return -1;

	return 100 * month + day;
}

int dateToWeight(int date) {	//301
	//2021년도 3월 ~ 6월 기준
	int month = 0, day = 0;

	switch (date / 100) {
	case 3: month = 0; break;
	case 4: month = 31; break;
	case 5: month = 61; break;
	case 6: month = 92; break;
	default: return -1;
	}

	day = date % 100 - 1;

	if ((day < 0) || (day > 30) || (!(date / 100 % 2) && day > 29)) return -1;

	return month + day;//가중치
}

int timeToDate() {
	time_t timer = time(NULL);
	struct tm t;
	localtime_s(&t, &timer);

	return 100 * (t.tm_mon + 1) + t.tm_mday;
}

int timeToWeight() {
	return dateToWeight(timeToDate());
}

//int main() {
//	int weight[3] = { 30,-1,122 };
//	int date[6] = { 331, 230, 701, 300, 332, 431 };
//
//	cout << "[weightToDate Test]" << endl;
//	for (int i = 0; i < sizeof(weight) / sizeof(int); i++) cout << weightToDate(weight[i]) << endl;
//	cout << "[dateToWeight Test]" << endl;
//	for (int i = 0; i < sizeof(date) / sizeof(int); i++) cout << dateToWeight(date[i]) << endl;
//	cout << "[timeToDate Test]" << endl;
//	cout << timeToDate() << endl;
//	cout << "[timeToWeight Test]" << endl;
//	cout << timeToWeight() << endl;
//}