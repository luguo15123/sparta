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

#ifndef DSMC_UNIVERSE_H
#define DSMC_UNIVERSE_H

#include "stdio.h"
#include "pointers.h"

namespace DSMC_NS {

class Universe : protected Pointers {
 public:
  char *version;          // DSMC version string = date

  MPI_Comm uworld;        // communicator for entire universe
  int me,nprocs;          // my place in universe

  FILE *uscreen;          // universe screen output
  FILE *ulogfile;         // universe logfile

  int existflag;          // 1 if universe exists due to -partition flag
  int nworlds;            // # of worlds in universe
  int iworld;             // which world I am in
  int *procs_per_world;   // # of procs in each world
  int *root_proc;         // root proc in each world

  MPI_Comm uorig;         // original communicator passed to DSMC instance
  int *uni2orig;          // proc I in universe uworld is 
                          // proc uni2orig[I] in original communicator

  Universe(class DSMC *, MPI_Comm);
  ~Universe();
  void reorder(char *, char *);
  void add_world(char *);
  int consistent();
};

}

#endif

/* ERROR/WARNING messages:

E: Invalid -reorder N value

UNDOCUMENTED

E: Nprocs not a multiple of N for -reorder

UNDOCUMENTED

E: Cannot open -reorder file

UNDOCUMENTED

E: Unexpected end of -reorder file

UNDOCUMENTED

E: Invalid entry in reorder file

UNDOCUMENTED

E: Unexpected end of reorder file

UNDOCUMENTED

E: Invalid command-line argument

One or more command-line arguments is invalid.  Check the syntax of
the command you are using to launch DSMC.

*/
