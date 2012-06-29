#ifndef DDMD_BOND_POTENTIAL_CPP
#define DDMD_BOND_POTENTIAL_CPP

/*
* Simpatico - Simulation Package for Polymeric and Molecular Liquids
*
* Copyright 2010, David Morse (morse@cems.umn.edu)
* Distributed under the terms of the GNU General Public License.
*/

#include "BondPotential.h"
#include <ddMd/simulation/Simulation.h>

namespace DdMd
{
   using namespace Util;

   /*
   * Constructor.
   */
   BondPotential::BondPotential(Simulation& simulation)
    : boundaryPtr_(&simulation.boundary()),
      storagePtr_(&simulation.bondStorage())
   {}

   /*
   * Default constructor (for unit testing).
   */
   BondPotential::BondPotential()
    : boundaryPtr_(0),
      storagePtr_(0)
   {} 

   /*
   * Associate with related objects. (for unit testing).
   */
   void BondPotential::associate(Boundary& boundary, GroupStorage<2>& storage)
   {
      boundaryPtr_ = &boundary;
      storagePtr_ = &storage;
   } 

   /*
   * Destructor.
   */
   BondPotential::~BondPotential()
   {}

}
#endif