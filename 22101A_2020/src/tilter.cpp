#include "vex.h"
using namespace vex;

namespace tilter {
  motor m = motor(PORT2, ratio36_1, false);
<<<<<<< HEAD
  //bool holding = false;
  //task holdTask;

  void reset() {
    //holdTask = task(hold);
    //holding = false;
=======

  void reset() {
>>>>>>> 3452e8459878eb6b2aab85303ce821f8442abc94
    m = motor(PORT2, ratio36_1, false);
    m.stop(vex::hold);
    m.resetRotation();
  }

  void stop() {
    m.stop(vex::hold);
  }

  int op() {
<<<<<<< HEAD
    double upVel = 40, downVel = -100;
    while(1) {
      if(con.ButtonR1.pressing()) {
        intakeTask.suspend();
        intake::l.stop(coast);
        intake::r.stop(coast);
        while(con.ButtonR1.pressing()) {
          m.spin(fwd, upVel, pct);
        }
        intake::l.stop(vex::hold);
        intake::r.stop(vex::hold);
        intakeTask.resume();
      }
      if(con.ButtonR2.pressing()) {
        intakeTask.suspend();
        intake::l.stop(coast);
        intake::r.stop(coast);
        while(con.ButtonR2.pressing()) {
          m.spin(fwd, downVel, pct);
        }
        intake::l.stop(vex::hold);
        intake::r.stop(vex::hold);
        intakeTask.resume();
      }
      while(con.ButtonR2.pressing()) {
        //holding = false;
        m.spin(fwd, downVel, pct);
      }
      m.stop(vex::hold);
      //holding = false;
=======
    double upVel = 100, downVel = -100, kP = .4, max = 100;
    while(1) {
      while(con.ButtonR1.pressing()) {
        m.spin(fwd, upVel, pct);
      }
      while(con.ButtonR2.pressing()) {
        m.spin(fwd, downVel, pct);
      }
      if(!con.ButtonR1.pressing() && !con.ButtonR2.pressing()) {
        double ticks = m.rotation(deg);
        double err, vel;
        while(!con.ButtonR1.pressing() && !con.ButtonR2.pressing()) {
          err = ticks - m.rotation(vex::deg);

          if(err * kP > max) vel = max;
          else if(err * kP < -max) vel = -max;

          m.spin(fwd, vel, pct);

          wait(5, msec);
        }
      }
      wait(5, msec);
>>>>>>> 3452e8459878eb6b2aab85303ce821f8442abc94
    }
    return 1;
  }

  int move(double deg, double max, double kP, double range, double time) {
    //reset();
    double ticks = deg, err, vel;
    timer t;
    while(1) {
      err = ticks - m.rotation(vex::deg);

      if(err * kP > max) vel = max;
      else if(err * kP < -max) vel = -max;
      else vel = err * kP;

      m.spin(fwd, vel, pct);

      if(fabs(err) > range) t.reset();
      if(t.time(msec) > time) break;

      wait(5, msec);
      cpu.Screen.clearScreen();
    cpu.Screen.setCursor(5,5);
    cpu.Screen.print("%f  %f", arm::m.position(vex::deg), tilter::m.position(vex::deg));
    }
    stop();
    return 1;
  }

  /*int hold() {
    double max = 100, kP = 0.4; //Temporary
    while(true) {
      if(holding) {
        double ticks = m.rotation(deg);
        double err, vel;
        while(holding) {
          err = ticks - m.rotation(vex::deg);

          if(err * kP > max) vel = max;
          else if(err * kP < -max) vel = -max;

          m.spin(fwd, vel, pct);

          wait(5, msec);
        }
      }
    }
    return 1;
  }*/

}