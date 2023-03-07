#include "ProfessionalEmployee.h"
using namespace std;

float ProfessionalEmployee::calculate_weekly_salary() {
  return (pay / 52);
}

float ProfessionalEmployee::calculate_health_care() {
  return (calculate_weekly_salary() * (PERCENT_HEALTH_CARE_COST / 100.0));
}

int ProfessionalEmployee::calculate_vacation_days() {
  return ((years_experience + 1) * VACATION_RATE);
}

ProfessionalEmployee::ProfessionalEmployee(string name, float pay) {
  this->name = name;
  this->pay = pay;
  years_experience = 0;
}
