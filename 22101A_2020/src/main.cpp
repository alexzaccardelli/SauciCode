#include "vex.h"
using namespace vex;

competition Competition;
vex::brain cpu;
controller con;
task driveTask, intakeTask, tilterTask, armTask, autonTask;

void usercontrol(void) {
  /*timer clown;
  auton::redSmall();
  cpu.Screen.print("%f\n", clown.time(msec));*/
  auton::resetAll();
  driveTask = task(drive::op);
  intakeTask = task(intake::op);
  tilterTask = task(tilter::op);
  armTask = task(arm::op);
  autonTask = task(auton::op);
  while(1) {
    wait(5, msec);
    printf("%f %f\n", arm::m.position(deg), arm::m.torque());
  }
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
