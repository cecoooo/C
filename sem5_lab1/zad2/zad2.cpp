#include <iostream>
#include "Worker.h"
#include <string.h>
using namespace std;



int main()
{
    Worker worker("durvar");
    worker.set_name("Ivan");
    worker.set_social_number(123);
    worker.set_work_experience(13);
    cout << worker.get_name() << '\n';
    cout << worker.get_position() << '\n';
    cout << worker.get_social_number() << '\n';
    cout << worker.get_work_experience() << '\n' << '\n';
    worker.add_salary(2000);
    worker.add_salary(4235);
    worker.add_salary(312);
    worker.add_salary(3124);
    worker.add_salary(2144);
    worker.add_salary(1454);
    worker.add_salary(953);
    worker.add_salary(2543);
    worker.add_salary(1244);
    worker.add_salary(1238);
    worker.add_salary(4298);
    worker.add_salary(5433);
    worker.add_salary(2543);
    worker.add_salary(1244);
    worker.add_salary(1238);
    worker.add_salary(4298);
    worker.add_salary(5433);
    worker.add_salary(2543);
    worker.add_salary(1244);
    worker.add_salary(1238);
    worker.add_salary(4298);
    worker.add_salary(5433);
    for (int i = 0; i < worker.number_of_salaries(); i++) {
        cout << worker.get_salaries()[i] << '\n';
    }
    cout << '\n' << worker.average_salary() << '\n';
    cout << worker.min_salary() << '\n';
    cout << '\n' << worker.number_of_salaries() << '\n';
}