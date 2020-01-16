#ifndef _TILTER_H_
#define _TILTER_H_
using namespace vex;

namespace tilter {
  extern motor m;

  void reset();
  void stop();
  void spin(double vel);

  int move(double deg, double max, double kP, double range, double time);
  int moveTilter();
  bool isComplete();

  int op();
}

#endif