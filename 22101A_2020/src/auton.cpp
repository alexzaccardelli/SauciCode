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
    tilter::move(150, 100, .8, 5, 100);
    arm::move(175, 100, .8, 5, 100);
    arm::m.spin(fwd, -100, pct);
    //intake::spin(0);
    intake::l.stop(coast);
    intake::r.stop(coast);
    arm::reset();
    while(tilter::m.torque() < 2.05)
      tilter::m.spin(fwd, -100, pct);
    tilter::reset();

/*
    while(tilter::m.torque() < 2.05)
      tilter::m.spin(fwd, -100, pct);
    tilter::reset();
    arm::move(350, 100, .8, 5, 100);
    while(arm::m.torque() < 1.5)
      arm::m.spin(fwd, -100, pct);
    arm::reset();*/
    return 1;
  }

  int skills() {
  auton::deployTray();
  intake::spin(100);
  drive::forward(100, 30.0, 0.6, 0.2, 17, 200);
  wait(2, vex::seconds);
  drive::reset();
  wait(2, vex::seconds);
  intake::reset();
  drive::turn(33, 75.0, 0.6, 0.2, 17, 200);
  drive::forward(21, 35.0, 0.6, 0.2, 17, 200);

  auton::stack;

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
    return 1;
  }

  int op() {
    while(1) {
      if(con.ButtonLeft.pressing()) {
        driveTask.suspend();
        armTask.suspend();
        tilterTask.suspend();
        drive::forward(-15, 30.0, 0.6, 0.2, 100, 200);
        wait(1000, msec);
        tilter::move(150, 100, .8, 5, 100);
        arm::move(100, 100, .8, 5, 100);
        arm::m.spin(fwd, -100, pct);
        wait(2000, msec);
        arm::reset();
        while(tilter::m.torque() < 2.05)
          tilter::m.spin(fwd, -100, pct);
        tilter::reset();
        tilterTask.resume();
        driveTask.resume();
        armTask.resume();
      }
      wait(5, msec);
    }
    return 1;
  }
  int redSmall() {
    auton::deployTray();
    intake::spin(100);
    drive::forward(42, 40.0, 0.6, 0.2, 17, 200);
    intake::reset();
    drive::forward(-26, 100.0, 0.6, 0.2, 17, 200);
    drive::turn(132, 90.0, 0.6, 0.2, 17, 200);
    drive::reset();
    drive::forward(13, 100, 0.6, 0.2, 17, 200);
    drive::forward(3, 35.0, 0.6, 0.2, 17, 200);
    tilter::move(720, 50, .6, 15, 500);
    intake::l.stop(coast);
    intake::r.stop(coast);
    drive::forward(-10, 50.0, 0.6, 0.2, 17, 200);
    return 1;
  }

  void small() {

  }
  
  void big() {

  }

  void stack() {
    intake::l.stop(coast);
    intake::r.stop(coast);
    tilter::move(720, 25, .6, 15, 500);
    drive::forward(-10, 30.0, 0.6, 0.2, 17, 200);
  }

}