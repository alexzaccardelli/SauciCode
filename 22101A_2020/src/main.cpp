#include "vex.h"
using namespace vex;

competition Competition;
vex::brain cpu;
controller con;
task driveTask, intakeTask, tilterTask, armTask, autonTask;

void usercontrol(void) {
  /*auton::resetAll();
  timer clown;
  //auton::redSmall();
  auton::threePoint();
  cpu.Screen.print("%f\n", clown.time(msec));
  printf("%f\n", clown.time(msec)); */
  driveTask = task(drive::op);
  intakeTask = task(intake::op);
  tilterTask = task(tilter::op);
  armTask = task(arm::op);
  autonTask = task(auton::op);
  while(1) {
    wait(5, msec);
    printf("%f %f\n", tilter::m.position(deg), arm::m.torque());
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
