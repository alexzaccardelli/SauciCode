#include "vex.h"
using namespace vex;

competition Competition;
vex::brain cpu;
controller con;
task driveTask, intakeTask, tilterTask, armTask;

void usercontrol(void) {
<<<<<<< HEAD

  intake::spin(100);
  drive::forward(100, 30.0, 0.6, 0.2, 17, 200);
  wait(2, vex::seconds);
  drive::reset();
  wait(2, vex::seconds);
  intake::reset();
  drive::turn(33, 75.0, 0.6, 0.2, 17, 200);
  
 
  
  cpu.Screen.clearScreen();
  cpu.Screen.setCursor(5,5);
  cpu.Screen.print("hello");
  printf("%f %f\n", arm::m.position(deg), arm::m.torque());
  /*intake::l.stop(coast);
  intake::r.stop(coast);
  tilter::move(720, 25, .6, 15, 500);
  drive::forward(-10, 30.0, 0.6, 0.2, 17, 200);*/

  //drive::turn(90, 75.0, 0.6, 0.2, 17, 200);
  /*auton::resetAll();
  //auton::deployTray();
  //tilter::move(100, 100, .8, 5, 100);
=======
  auton::resetAll();
>>>>>>> 3452e8459878eb6b2aab85303ce821f8442abc94
  driveTask = task(drive::op);
  intakeTask = task(intake::op);
  tilterTask = task(tilter::op);
  armTask = task(arm::op);
  while(1) {
<<<<<<< HEAD
    wait(20, msec);
    cpu.Screen.clearScreen();
    cpu.Screen.setCursor(5,5);
    cpu.Screen.print("%f", arm::m.torque());
    printf("%f %f\n", arm::m.position(deg), arm::m.torque());
  }*/
=======
    wait(5, msec);
    cpu.Screen.clearScreen();
    cpu.Screen.setCursor(5,5);
    cpu.Screen.print("hello");
  }
>>>>>>> 3452e8459878eb6b2aab85303ce821f8442abc94
}

void pre_auton(void) {
  vexcodeInit();
<<<<<<< HEAD
  //auton::resetAll();

=======
  auton::resetAll();
>>>>>>> 3452e8459878eb6b2aab85303ce821f8442abc94
}

void autonomous(void) {
  
}

int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  pre_auton();
<<<<<<< HEAD
  
  while (true) wait(100, msec);
}
=======
  //auton::resetAll();
  
  while (true) wait(100, msec);
}
>>>>>>> 3452e8459878eb6b2aab85303ce821f8442abc94
