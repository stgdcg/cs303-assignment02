#include "Employee.h"
using namespace std;

class NonprofessionalEmployee: protected Employee {
 private:
  static const int VACATION_PERCENT = 2;
  static const int HEALTHCARE_PERCENT_HOURLY = 8;
 public:
  NonprofessionalEmployee(string name, float pay);
  virtual float calculate_weekly_salary();
  virtual float calculate_health_care();
  virtual int calculate_vacation_days();
};
