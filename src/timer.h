/* ----------------------------------------------------------------------
   DSMC - Sandia parallel DSMC code
   www.sandia.gov/~sjplimp/dsmc.html
   Steve Plimpton, sjplimp@sandia.gov, Michael Gallis, magalli@sandia.gov
   Sandia National Laboratories

   Copyright (2011) Sandia Corporation.  Under the terms of Contract
   DE-AC04-94AL85000 with Sandia Corporation, the U.S. Government retains
   certain rights in this software.  This software is distributed under 
   the GNU General Public License.

   See the README file in the top-level DSMC directory.
------------------------------------------------------------------------- */

#ifndef DSMC_TIMER_H
#define DSMC_TIMER_H

#include "pointers.h"

namespace DSMC_NS {

enum{TIME_LOOP,TIME_MOVE,TIME_COLLIDE,TIME_SORT,TIME_COMM,TIME_OUTPUT,TIME_N};

class Timer : protected Pointers {
 public:
  double *array;

  Timer(class DSMC *);
  ~Timer();
  void init();
  void stamp();
  void stamp(int);
  void barrier_start(int);
  void barrier_stop(int);
  double elapsed(int);

 private:
  double previous_time;
};

}

#endif