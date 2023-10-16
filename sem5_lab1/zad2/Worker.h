#pragma once
#include <iostream>
#include <string.h>
#include <float.h>
//#include<iomanip>
using namespace std;

class Worker
{
private:
	int social_number;
	string name;
	int work_experience;
	string position;
	double* salaries;
	int salary_arr_len;
public:
	Worker() {
		this->social_number = 0;
		this->work_experience = 0;
		this->salary_count = 0;
		this->salary_arr_len = 16;
		this->salaries = (double*)malloc(sizeof(double) * 16);
	}
	Worker(string pos) {
		this->social_number = 0;
		this->work_experience = 0;
		this->position = pos;
		this->salary_count = 0;
		this->salary_arr_len = 16;
		this->salaries = (double*)malloc(sizeof(double) * 16);
	}
	~Worker() {
		free(this->salaries);
		cout << "\nWorker Object Destructor activated.\n";
	}
	int get_social_number() {
		return this->social_number;
	}
	string get_name() {
		return this->name;
	}
	int get_work_experience() {
		return this->work_experience;
	}
	string get_position() {
		return this->position;
	}
	double* get_salaries() {
		return this->salaries;
	}
	void set_social_number(int num) {
		this->social_number = num;
	}
	void set_name(string name) {
		this->name = name;
	}
	void set_work_experience(int exp) {
		this->work_experience = exp;
	}
	void set_position(string pos) {
		this->position = pos;
	}
	static int salary_count;
	void add_salary(double salary) {
			if (this->salary_arr_len == this->salary_count) {
				double* time_arr = (double*)realloc(this->salaries, sizeof(double) * this->salary_arr_len * 2);
				this->salaries = (double*)realloc(time_arr, sizeof(double) * this->salary_arr_len * 2);
				this->salary_arr_len *= 2;
			}
			this->salaries[this->salary_count] = salary;
			this->salary_count++;
		}
	double average_salary() {
			double sum = 0;
			for (int i = 0; i < this->salary_count; i++) {
				sum += this->salaries[i];
			}
			return sum / this->salary_count;
		}
	double min_salary() {
			double min = DBL_MAX;
			for (int i = 0; i < this->salary_count; i++) {
				if (this->salaries[i] < min) {
					min = this->salaries[i];
				}
			}
			return min;
		}
};


//void Worker::add_salary(double salary) {
//	if (this->salary_arr_len == this->salary_count) {
//		double* time_arr = (double*)realloc(this->salaries, sizeof(double) * this->salary_arr_len * 2);
//		this->salaries = (double*)realloc(time_arr, sizeof(double) * this->salary_arr_len * 2);
//		this->salary_arr_len *= 2;
//	}
//	this->salaries[this->salary_count] = salary;
//	this->salary_count++;
//}
//
//double Worker::average_salary() {
//	double sum = 0;
//	for (int i = 0; i < this->salary_count; i++) {
//		sum += this->salaries[i];
//	}
//	return sum / this->salary_count;
//}
//
//double Worker::min_salary() {
//	double min = DBL_MAX;
//	for (int i = 0; i < this->salary_count; i++) {
//		if (this->salaries[i] < min) {
//			min = this->salaries[i];
//		}
//	}
//	return min;
//}