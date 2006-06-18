/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _REF_H_
#define _REF_H_
#include <ostream>
#include "dll_export.h"
namespace NifLib {

/**
 * Smart Pointer Template
 */

template<class T> class Ref;
template<class T> std::ostream & operator<<(std::ostream &, const Ref<T> &);


/**
* Ref Traits:  Class overridable behavior methods
*/
template<typename T>
class RefTraits
{
public:	
   static void AddRef( T* p )   { if (p) p->AddRef(); }
   static void Release( T* p )  { if (p) p->SubtractRef(); }
   static bool Less( T*l, T*r ) { return ( l < r ); }
   static ::std::ostream & ToStream(::std::ostream &os, T* p) { 
      if (p) os << p->GetIDString();
      else   os << "NULL";
      return os; 
   }
#ifdef USE_NIFLIB_TEMPLATE_HELPERS
   template<typename U> static T* StaticCast(U* p) { return static_cast<T*>(p); }
   template<typename U> static T* DynamicCast(U* p) {
      if ( (NULL != p) && p->IsDerivedType(T::TypeConst()) ) {
         return static_cast<T*>(p);
      } else {
         return NULL;
      }
   }
#endif
};


/**
* Smart reference
*/
template<class T>
class Ref
{
public:
   Ref( T* p = 0 ) 
      : p_( ShallowCopy( p ) )
   {
   }	

   ~Ref() { Release( ); }

   Ref& Attach( T* p = 0 )
   {
      Reset();
      p_ = p;
      return (*this);
   }

   // Normally I'd disable this and force you to use safe/explicit conversions
   operator T*() const { return p_; }

   T& operator*() const { return *p_; }

   T* operator->() const { return p_; }

   T* ToPointer() const { return p_; }

   void Swap( Ref& other ) { std::swap( p_, other.p_); }

   bool isEmpty() const
   { return (p_ == 0); }

   bool isSet() const
   { return (p_ != 0); }

   /**
   * overload all potential null test comparison operators
   */
   operator bool() const // Enables "if (sp) ..."
   { return (p_ != 0); }

   bool operator!() const // Enables "if (!sp) ..."
   { return (p_ == 0); }

   inline friend bool operator==(const Ref& lhs, const Ref& rhs)
   { return (lhs.p_ == rhs.p_); }

   inline friend bool operator!=(const Ref& lhs, const Ref& rhs)
   { return (lhs.p_ != rhs.p_); }

   inline friend bool operator==(const Ref& lhs, const T* rhs)
   { return (lhs.p_ == rhs); }

   inline friend bool operator==(const T* lhs, const Ref& rhs)
   { return (lhs == rhs.p_); }

   inline friend bool operator==(const Ref& lhs, intptr_t rhs)
   { return (lhs.p_ == reinterpret_cast<T*>(rhs)); }

   inline friend bool operator==(intptr_t rhs, const Ref& lhs)
   { return (reinterpret_cast<T*>(lhs) == rhs.p_); }

   inline friend bool operator!=(const Ref& lhs, const T* rhs)
   { return (lhs.p_ != rhs); }

   inline friend bool operator!=(const T* lhs, const Ref& rhs)
   { return (lhs != rhs.p_); }

   inline friend bool operator!=(const Ref& lhs, intptr_t rhs)
   { return (lhs.p_ != reinterpret_cast<T*>(rhs)); }

   inline friend bool operator!=(intptr_t rhs, const Ref& lhs)
   { return (reinterpret_cast<T*>(lhs) != rhs.p_); }

   inline friend bool operator<(const Ref& lhs, const Ref& rhs)
   { return RefTraits<T>::Less(lhs.p_, rhs.p_); }

   inline friend std::ostream & operator<<(std::ostream &os, const Ref& rhs)
   { return RefTraits<T>::ToStream(os, rhs.p_); }

   Ref( const Ref& other )
      : p_( ShallowCopy( other.p_ ) )
   { }

#ifdef USE_NIFLIB_TEMPLATE_HELPERS
   template<typename U>
   Ref( const Ref<U>& other ) 
      : p_( ShallowCopy(RefTraits<T>::DynamicCast(other.p_)) )
   { }
#endif

   Ref& operator=( T * other )
   {
      Ref temp(other);
      Swap(temp);
      return *this;
   }

   Ref& operator=( const Ref& other )
   {
      Ref temp(other);
      Swap(temp);
      return *this;
   }

private:
   template<typename U> friend class Ref;

   T* ShallowCopy( T* p ) 
   {
      RefTraits<T>::AddRef( p );
      return p;
   }

   void Release( )
   {
      RefTraits<T>::Release( p_ );
      p_ = 0;
   }

   T* p_;
};

}
#endif
