#include "Employee.h"
using namespace std;

void Employee::set_pay(const float pay) {
  this->pay = pay;
}

float Employee::get_pay() const {
  return pay;
}

string Employee::get_name() const {
  return name;
}

void Employee::increment_years_experience() {
  years_experience++;
}

