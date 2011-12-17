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

#ifndef DSMC_UPDATE_H
#define DSMC_UPDATE_H

#include "pointers.h"

namespace DSMC_NS {

class Update : protected Pointers {
 public:
  bigint ntimestep;               // current timestep
  int nsteps;                     // # of steps to run
  bigint firststep,laststep;      // 1st & last step of this run
  double dt;                      // timestep size

  bigint nmove;             // dummy statistic for now
  bigint ncellcross;        // dummy statistic for now

  int nmigrate;             // # of particles to migrate to new procs
  int *mlist;               // indices of particles to migrate

  Update(class DSMC *);
  ~Update();
  void init() {}
  void setup();
  void run(int);
  void move();

 private:
  int maxmigrate;            // max # of particles in mlist

  void check();
};

}

#endif

/* ERROR/WARNING messages:

E: %d particles are not in correct cell

UNDOCUMENTED

*/
