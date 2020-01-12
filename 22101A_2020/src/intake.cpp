#include "vex.h"
using namespace vex;

namespace intake {
  motor l = motor(PORT3, ratio36_1, false);
  motor r = motor(PORT4, ratio36_1, true);

  void reset() {
    l = motor(PORT3, ratio18_1, false);
    r = motor(PORT4, ratio18_1, true);
    l.stop(hold);
    r.stop(hold);
    l.resetRotation();
    r.resetRotation();
  }

  void spin(double vel) {
    l.spin(fwd, vel, pct);
    r.spin(fwd, vel, pct);
  }

  int op() {
    while(1) {
      if(con.ButtonL1.pressing()) {
        spin(100);
      }
      if(con.ButtonL2.pressing()) {
        spin(-100);
      }
      if(con.ButtonDown.pressing()) {
        l.stop(hold);
        r.stop(hold);
      }
      wait(5, msec);
    }
    return 1;
  }
}