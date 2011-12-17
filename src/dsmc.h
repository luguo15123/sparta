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

#ifndef DSMC_DSMC_H
#define DSMC_DSMC_H

#include "stdio.h"

namespace DSMC_NS {

class DSMC {
 public:

  // fundamental DSMC classes

  class Memory *memory;          // memory allocation functions
  class Error *error;            // error handling
  class Universe *universe;      // universe of processors
  class Input *input;            // input script processing
                                 // ptrs to top-level DSMC-specific classes
  class Particle *particle;      // particles
  class Update *update;          // timestepper
  class Comm *comm;              // inter-processor communication
  class Domain *domain;          // simulation box
  class Grid *grid;              // volumetric grid cells
  class Surf *surf;              // surface elements
  class Collide *collide;        // collisions and chemistry
  class Output *output;          // stats/dump/restart
  class Timer *timer;            // CPU timing info

  MPI_Comm world;                // MPI communicator
  FILE *infile;                  // infile
  FILE *screen;                  // screen output
  FILE *logfile;                 // logfile

  char *suffix;                  // suffix to add to input script style names
  int suffix_enable;             // 1 if suffix enabled, 0 if disabled
  class Cuda *cuda;              // CUDA accelerator class

  // other top-level DSMC classes and variables

  //class RanMars *ranmaster;      // master RN generator

  DSMC(int, char **, MPI_Comm);
  ~DSMC();
  void create();
  void init();
  void destroy();

  void print_styles();
};

}

#endif

/* ERROR/WARNING messages:

E: Invalid command-line argument

One or more command-line arguments is invalid.  Check the syntax of
the command you are using to launch DSMC.

E: Cannot use -reorder after -partition

UNDOCUMENTED

E: Processor partitions are inconsistent

The total number of processors in all partitions must match the number
of processors DSMC is running on.

E: Must use -in switch with multiple partitions

A multi-partition simulation cannot read the input script from stdin.
The -in command-line option must be used to specify a file.

E: Can only use -pscreen with multiple partitions

UNDOCUMENTED

E: Can only use -plog with multiple partitions

UNDOCUMENTED

E: Cannot open universe screen file

For a multi-partition run, the master screen file cannot be opened.
Check that the directory you are running in allows for files to be
created.

E: Cannot open log.dsmc

UNDOCUMENTED

E: Cannot open universe log file

For a multi-partition run, the master log file cannot be opened.
Check that the directory you are running in allows for files to be
created.

E: Cannot open input script %s

Self-explanatory.

E: Cannot open screen file

The screen file specified as a command-line argument cannot be
opened.  Check that the directory you are running in allows for files
to be created.

E: Cannot open logfile

The DSMC log file named in a command-line argument cannot be opened.
Check that the path and name are correct.

E: Smallint setting in dsmctype.h is invalid

UNDOCUMENTED

E: Bigint setting in dsmctype.h is invalid

UNDOCUMENTED

E: MPI_DSMC_BIGINT and bigint in dsmctype.h are not compatible

UNDOCUMENTED

E: Small,big integers are not sized correctly

UNDOCUMENTED

*/
