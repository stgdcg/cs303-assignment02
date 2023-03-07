#pragma once
#include <string>
using namespace std;

class Employee {
 protected:
  string name;
  float pay;
  int years_experience;

 public:
  virtual float calculate_weekly_salary() = 0;
  virtual float calculate_health_care() = 0;
  virtual int calculate_vacation_days() = 0;

  void set_pay(const float pay);
  float get_pay() const;
  string get_name() const;
  void increment_years_experience();
};
