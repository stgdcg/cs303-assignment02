#include "NonprofessionalEmployee.h"
#include "Employee.h"
using namespace std;

  static const int VACATION_PERCENT = 2;
  static const int HEALTHCARE_PERCENT_HOURLY = 8;

NonprofessionalEmployee::NonprofessionalEmployee(string name, float pay) {
  this->pay = pay;
  this->name = name;
  years_experience = 0;
}

float NonprofessionalEmployee::calculate_weekly_salary() {
  return (pay * 40);
}

float NonprofessionalEmployee::calculate_health_care() {
  return (40 * (HEALTHCARE_PERCENT_HOURLY / 100.0));
}

int NonprofessionalEmployee::calculate_vacation_days() {
  return (40 * (years_experience * (VACATION_PERCENT / 100.0)));
}
