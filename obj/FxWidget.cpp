/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "FxWidget.h"

//Definition of TYPE constant
const Type FxWidget::TYPE("FxWidget", &FX_WIDGET_PARENT::TYPE );

FxWidget::FxWidget() FX_WIDGET_CONSTRUCT {}

FxWidget::~FxWidget() {}

void FxWidget::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	FX_WIDGET_READ
}

void FxWidget::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	FX_WIDGET_WRITE
}

string FxWidget::asString( bool verbose ) const {
	FX_WIDGET_STRING
}

void FxWidget::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	FX_WIDGET_FIXLINKS
}

list<NiObjectRef> FxWidget::GetRefs() const {
	FX_WIDGET_GETREFS
}

const Type & FxWidget::GetType() const {
	return TYPE;
};

