#include "PID.h"
#include<vector>
#include<numeric>
#include "json.hpp"
using json = nlohmann::json;

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {
  prev_cte = 0;
  int_cte = 0;
}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
}

void PID::UpdateError(double cte) {
  this->p_error = this->Kp * cte;

  this->int_cte += cte;
  double diff_cte = cte - this->prev_cte;
  this->prev_cte = cte;
  this->d_error = this->Kd * diff_cte;
  this->i_error = this->Ki * this->int_cte;
}

double PID::TotalError() {
  return p_error + d_error + i_error;
}

