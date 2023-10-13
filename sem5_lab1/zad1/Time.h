#pragma once
#include <iostream>
#include<iomanip>
using namespace std;

class Time
{
private:
	int hours;
	int mins;
	int secs;
	void setHours(int hour) {
		if (hour < 0 || hour > 23)
			throw 505;
		this->hours = hour;
	}
	void setMins(int min) {
		if (min < 0 || min > 23)
			throw 505;
		this->mins = min;
	}
	void setSecs(int sec) {
		if (sec < 0 || sec > 23)
			throw 505;
		this->secs = sec;
	}
public:
	~Time() {
		cout << "\nTime Object Destructor activated.\n";
	}
	Time() {
		setHours(0);
		setMins(0);
		setSecs(0);
	}
	Time(int h, int m, int s) {
		setHours(h);
		setMins(m);
		setSecs(s);
	}
	void print_time_british_format() {
		cout << setw(2) << setfill('0') << this->hours << ":";
		cout << setw(2) << setfill('0') << this->mins << ":";
		cout << setw(2) << setfill('0') << this->secs;
	}
	void print_time_american_format() {
		int h = this->hours;
		string time = " AM";
		if (this->hours > 12) {
			h = this->hours - 12;
			time = " PM";
		}
		
		cout << setw(2) << setfill('0') << h << ":";
		cout << setw(2) << setfill('0') << this->mins << ":";
		cout << setw(2) << setfill('0') << this->secs << time;
	}
};

