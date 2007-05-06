/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#ifndef _NIFLIB_KEY_H_
#define _NIFLIB_KEY_H_

#include <iostream>
#include <iomanip>
namespace Niflib {
using namespace std;

/*! Stores an animation key and the time in the animation that it takes affect. It is a template class so it can hold any kind of data as different objects key different sorts of information to the animation timeline.*/
template <class T> 
struct Key {
	float time; /*!< The time on the animation timeline that this keyframe takes affect. */ 
	T data; /*!< The data being keyed to the timeline. */ 
	T forward_tangent; /*!< A piece of data of the same type as is being keyed to the time line used as the forward tangent in quadratic interpolation.  Ignored if key type is set as something else. */ 
	T backward_tangent; /*!< A piece of data of the same type as is being keyed to the time line used as the backward tangent in quadratic interpolation.  Ignored if key type is set as something else. */ 
	float tension; /*!< The amount of tension to use in tension, bias, continuity interpolation.  Ignored if key type is something else.*/
	float bias; /*!< The amount of bias to use in tension, bias, continuity interpolation.  Ignored if key type is something else.*/
	float continuity; /*!< The amount of continuity to use in tension, bias, continuity interpolation.  Ignored if key type is something else.*/
};

//These operators cause SWIG warnings
#ifndef SWIG
template <class T> 
ostream & operator<<( ostream & out, Key<T> const & val ) {
	return out << "Time:  " << val.time << endl
			   << "Data:  " << val.data << endl
			   << "Forward Tangent:  " << val.forward_tangent << endl
			   << "Backward Tangent:  " << val.backward_tangent << endl
			   << "Bias:  " << val.bias << endl
			   << "Continuity:  " << val.continuity << endl;
}
#endif

}
#endif
