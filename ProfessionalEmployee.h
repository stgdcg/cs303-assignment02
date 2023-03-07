#pragma once
#include "Employee.h"
using namespace std;

class ProfessionalEmployee: protected Employee {
 private:
  static const int VACATION_RATE = 1;

  static const int PERCENT_HEALTH_CARE_COST = 5;
 public:
  virtual float calculate_weekly_salary();
  virtual float calculate_health_care();
  virtual int calculate_vacation_days();
  ProfessionalEmployee(string name, float pay);
};
