#include "vex.h"
using namespace vex;

namespace arm {
  motor m = motor(PORT1, ratio36_1, false);
<<<<<<< HEAD
  bool holding = false;
  bool x = false;
  task holdTask;

  void reset() {
    //holdTask = task(hold);
    holding = false;
=======

  void reset() {
>>>>>>> 3452e8459878eb6b2aab85303ce821f8442abc94
    m = motor(PORT1, ratio36_1, false);
    m.stop(coast);
    m.resetRotation();
  }

  void stop() {
    m.stop(coast);
  }
  int blah() {
    tilter::move(100, 100, .8, 5, 100);
    x = true;
    return 1;
  }
  int op() {
    double upVel = 60, downVel = -100, kP = .4, max = 100;
    while(1) {
<<<<<<< HEAD
      if(con.ButtonX.pressing()) {
        tilterTask.suspend();
        tilter::move(100, 100, .8, 5, 100);
        tilterTask.resume();
        while(con.ButtonX.pressing()) {
          m.spin(fwd, upVel, pct);
          if(x) {
            x = false;
            //h.stop();
          }
        }
      }
      if(con.ButtonB.pressing()) {
        
        while(con.ButtonB.pressing()) {
          if(m.position(vex::deg) < 100) {
            tilterTask.suspend();
            
            tilter::move(0, 100, .8, 5, 100);
            tilterTask.resume();
          }
          m.spin(fwd, downVel, pct);
        }
      }
      
      m.stop(vex::brakeType::hold);
      holding = false;
=======
      while(con.ButtonX.pressing()) {
        m.spin(fwd, upVel, pct);
      }
      while(con.ButtonB.pressing()) {
        m.spin(fwd, downVel, pct);
      }
      if(!con.ButtonB.pressing() && !con.ButtonX.pressing()) {
        double ticks = m.rotation(deg);
        double err, vel;
        while(!con.ButtonB.pressing() && !con.ButtonX.pressing()) {
          err = ticks - m.rotation(vex::deg);

          if(err * kP > max) vel = max;
          else if(err * kP < -max) vel = -max;

          m.spin(fwd, vel, pct);

          wait(5, msec);
        }
      }
>>>>>>> 3452e8459878eb6b2aab85303ce821f8442abc94
      wait(5, msec);
    }
    return 1;
  }

  int move(double height, double max, double kP, double range, double time) {
    reset();
    double ticks = height * 1.7, err, vel; //Temporary
    timer t;
    while(1) {
      err = ticks - m.rotation(vex::deg);

      if(err * kP > max) vel = max;
      else if(err * kP < -max) vel = -max;

      m.spin(fwd, vel, pct);

      if(fabs(err) > range) t.reset();
      if(t.time(msec) > time) break;

      wait(5, msec);
    }
    reset();
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