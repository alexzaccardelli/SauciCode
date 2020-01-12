#include "vex.h"
using namespace vex;

namespace auton {

  void resetAll() {
    drive::reset();
    intake::reset();
    tilter::reset();
    arm::reset();
  }

  int deployTray() {
    intake::spin(-100);
    tilter::move(730, 100, .8, 5, 100);
    intake::spin(0);
    while(tilter::m.torque() < 2.05)
      tilter::m.spin(fwd, -100, pct);
    tilter::reset();
    arm::move(350, 100, .8, 5, 100);
    while(arm::m.torque() < 1.5)
      arm::m.spin(fwd, -100, pct);
    arm::reset();
    return 1;
  }

  int op() {
    while(1) {
      if(con.ButtonLeft.pressing()) {
        driveTask.suspend();
        armTask.suspend();
        drive::forward(-10, 30.0, 0.6, 0.2, 17, 200);
        wait(1000, msec);
        arm::move(350, 100, .8, 5, 100);
        arm::m.spin(fwd, -100, pct);
        wait(4000, msec);
        arm::reset();
        while(tilter::m.torque() < 2.05)
          tilter::m.spin(fwd, -100, pct);
        tilter::reset();
        driveTask.resume();
        armTask.resume();
      }
      wait(5, msec);
    }
    return 1;
  }

  void small() {

  }
  
  void big() {

  }

  void stack() {
    
  }

}