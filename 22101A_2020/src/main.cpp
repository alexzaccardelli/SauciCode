#include "vex.h"
using namespace vex;

competition Competition;
vex::brain cpu;
controller con;
task driveTask, intakeTask, tilterTask, armTask, autonTask;

void usercontrol(void) {
  auton::redSmall();
}

void pre_auton(void) {
  vexcodeInit();
  auton::resetAll();
}

void autonomous(void) {
  
}

int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  pre_auton();

  while (true) wait(100, msec);
}
