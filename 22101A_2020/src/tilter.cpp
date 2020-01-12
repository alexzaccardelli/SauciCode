#include "vex.h"
using namespace vex;

namespace tilter {
  motor m = motor(PORT2, ratio36_1, false);

  void reset() {
    m = motor(PORT2, ratio36_1, false);
    m.stop(vex::hold);
    m.resetRotation();
  }

  void stop() {
    m.stop(vex::hold);
  }

  int op() {
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
      m.stop(vex::hold);
    }
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
    }
    stop();
    return 1;
  }
}