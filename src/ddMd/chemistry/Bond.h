#ifndef DDMD_BOND_H
#define DDMD_BOND_H

/*
* Simpatico - Simulation Package for Polymeric and Molecular Liquids
*
* Copyright 2010, David Morse (morse@cems.umn.edu)
* Distributed under the terms of the GNU General Public License.
*/

#include "Group.h"

namespace DdMd
{

   typedef Group<2> Bond;

   #if 0
   /**
   * A pair of atoms connected by a covalent bond.
   *
   * \ingroup DdMd_Chemistry_Module
   */
   class Bond : public Group<2>
   {};
   #endif

}
#endif