#ifndef MCMD_ATOM_GROUPS_H
#define MCMD_ATOM_GROUPS_H

/*
* Simpatico - Simulation Package for Polymeric and Molecular Liquids
*
* Copyright 2010 - 2014, The Regents of the University of Minnesota
* Distributed under the terms of the GNU General Public License.
*/

#include <util/containers/FSArray.h>       // used in typedefs
#include <mcMd/species/Species.h>          // used in typedefs
#include <mcMd/chemistry/Bond.h>           // typedef

namespace McMd
{

   using namespace Util;

   class Atom;
   class Molecule;
   class Species;

   typedef FSArray<const Bond*, Species::MaxBondPerAtom> AtomBondArray;

   /*
   * Fill an array of pointers to Bonds that contain an Atom.
   */
   void getAtomBonds(const Atom& atom, const Molecule& molecule, const Species& species,
                     AtomBondArray& groups);

   /*
   * Fill an array of pointers to Bonds that contain an Atom.
   */
   void getAtomBonds(const Atom& atom, AtomBondArray& bonds);

} 
#endif