#ifndef TEXT_FILE_O_ARCHIVE_H
#define TEXT_FILE_O_ARCHIVE_H

/*
* Simpatico - Simulation Package for Polymeric and Molecular Liquids
*
* Copyright 2010, David Morse (morse@cems.umn.edu)
* Distributed under the terms of the GNU General Public License.
*/

#include "Byte.h"
#include "serialize.h"

#include <util/space/Vector.h>
#include <util/space/IntVector.h>

#include <complex>
#include <string>
#include <iostream>

namespace Util
{

   /**
   * Saving archive for character based ostream.
   *
   * \ingroup Archive_Module
   */
   class TextFileOArchive
   {

   public:

      /// Returns true;
      static bool is_saving();

      /// Returns false;
      static bool is_loading();

      /**
      * Constructor.
      */
      TextFileOArchive();

      /**
      * Destructor.
      */
      virtual ~TextFileOArchive();

      /**
      * Set the stream.
      *
      * \param out output stream to which to write.
      */
      void setStream(std::ostream& out);

      /**
      * Write one object.
      */
      template <typename T>
      TextFileOArchive& operator & (T& data);

      /**
      * Write one object.
      */
      template <typename T>
      TextFileOArchive& operator << (T& data);

      template <typename T> 
      void pack(const T& data);

      template <typename T> 
      void pack(const T* array, int n);

   private:

      /// Pointer to output stream file.
      std::ostream* ostreamPtr_;

      /// Archive version id.
      unsigned int  version_;

   };

   // Inline methods

   inline bool TextFileOArchive::is_saving()
   {  return true; }

   inline bool TextFileOArchive::is_loading()
   {  return false; }

   // Inline non-static methods

   /*
   * Write one object.
   */
   template <typename T>
   inline TextFileOArchive& TextFileOArchive::operator & (T& data)
   {   
      serialize(*this, data, version_); 
      return *this;
   }

   /*
   * Write one object.
   */
   template <typename T>
   inline TextFileOArchive& TextFileOArchive::operator << (T& data)
   {   
      serialize(*this, data, version_); 
      return *this;
   }

   // Method templates

   /*
   * Pack a single object of type T.
   */
   template <typename T>
   inline void TextFileOArchive::pack(const T& data)
   {  *ostreamPtr_ << data << std::endl; }

   /*
   * Bitwise pack a single object of type double.
   */
   template <>
   inline void TextFileOArchive::pack(const double& data)
   {  
      ostreamPtr_->setf(std::ios::scientific);
      ostreamPtr_->width(25);
      ostreamPtr_->precision(17);
      *ostreamPtr_ << data << std::endl; 
   }

   /*
   * Write a C-array of objects of type T.
   */
   template <typename T>
   inline void TextFileOArchive::pack(const T* array, int n)
   {
      for (int i=0; i < n; ++i) {
        *ostreamPtr_ << array[i] << "  ";
      }
      *ostreamPtr_ << std::endl;
   }

   // Explicit serialize functions for primitive types

   /**
   * Save a bool to a TextFileOArchive.
   */
   template <>
   inline void serialize(TextFileOArchive& ar, bool& data, 
                         const unsigned int version)
   {  ar.pack(data); }

   /**
   * Save a char to a TextFileOArchive.
   */
   template <>
   inline void serialize(TextFileOArchive& ar, char& data, 
                         const unsigned int version)
   {  ar.pack(data); }

   /**
   * Save an unsigned int to a TextFileOArchive.
   */
   template <>
   inline void serialize(TextFileOArchive& ar, unsigned int& data, 
                         const unsigned int version)
   {  ar.pack(data); }

   /**
   * Save an int to a TextFileOArchive.
   */
   template <>
   inline void serialize(TextFileOArchive& ar, int& data, 
                         const unsigned int version)
   {  ar.pack(data); }

   /**
   * Save an unsigned long int to a TextFileOArchive.
   */
   template <>
   inline void serialize(TextFileOArchive& ar, unsigned long& data,  
                         const unsigned int version)
   {  ar.pack(data); }

   /**
   * Save a long int to a TextFileOArchive.
   */
   template <>
   inline void serialize(TextFileOArchive& ar, long& data,  
                         const unsigned int version)
   {  ar.pack(data); }

   /**
   * Save a float to a TextFileOArchive.
   */
   template <>
   inline void serialize(TextFileOArchive& ar, float& data, 
                         const unsigned int version)
   {  ar.pack(data); }

   /**
   * Save an double to a TextFileOArchive.
   */
   template <>
   inline void serialize(TextFileOArchive& ar, double& data, 
                         const unsigned int version)
   {  ar.pack(data); }

   // Explicit serialize functions for primitive types

   /**
   * Save a std::complex<float> to a TextFileOArchive.
   */
   template <>
   inline 
   void serialize(TextFileOArchive& ar, std::complex<float>& data, 
                  const unsigned int version)
   {  ar.pack(data); }

   /**
   * Save a std::complex<double> to a TextFileOArchive.
   */
   template <>
   inline 
   void serialize(TextFileOArchive& ar, std::complex<double>& data, 
                  const unsigned int version)
   {  ar.pack(data); }

   /**
   * Save a std::string to a TextFileOArchive.
   */
   template <>
   inline void serialize(TextFileOArchive& ar, std::string& data, 
                         const unsigned int version)
   {
      int size = data.size();
      ar.pack(size);
      ar.pack(data);
   }

   // Explicit serialize functions for namespace Util

   /**
   * Save a Util::Vector to a TextFileOArchive.
   */
   template <>
   inline void serialize(TextFileOArchive& ar, Vector& data, 
                         const unsigned int version)
   {  ar.pack(data); } 

   /**
   * Save a Util::IntVector to a TextFileOArchive.
   */
   template <>
   inline void serialize(TextFileOArchive& ar, IntVector& data, 
                         const unsigned int version)
   {  ar.pack(data); }

}
#endif