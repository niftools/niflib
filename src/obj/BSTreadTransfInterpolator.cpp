/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

//--BEGIN FILE HEAD CUSTOM CODE--//

//--END CUSTOM CODE--//

#include "../../include/FixLink.h"
#include "../../include/ObjectRegistry.h"
#include "../../include/NIF_IO.h"
#include "../../include/obj/BSTreadTransfInterpolator.h"
#include "../../include/gen/BSTreadTransfInfo.h"
#include "../../include/gen/BSTreadTransfSubInfo.h"
using namespace Niflib;

//Definition of TYPE constant
const Type BSTreadTransfInterpolator::TYPE("BSTreadTransfInterpolator", &NiInterpolator::TYPE );

BSTreadTransfInterpolator::BSTreadTransfInterpolator() : numTransfers((int)0), unknownInt1((int)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

BSTreadTransfInterpolator::~BSTreadTransfInterpolator() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & BSTreadTransfInterpolator::GetType() const {
	return TYPE;
}

NiObject * BSTreadTransfInterpolator::Create() {
	return new BSTreadTransfInterpolator;
}

void BSTreadTransfInterpolator::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiInterpolator::Read( in, link_stack, info );
	NifStream( numTransfers, in, info );
	treadTransferInfo.resize(numTransfers);
	for (unsigned int i1 = 0; i1 < treadTransferInfo.size(); i1++) {
		NifStream( treadTransferInfo[i1].unknownFloat1, in, info );
		for (unsigned int i2 = 0; i2 < 2; i2++) {
			NifStream( treadTransferInfo[i1].data[i2].unknownInt1, in, info );
			NifStream( treadTransferInfo[i1].data[i2].unknownInt2, in, info );
			NifStream( treadTransferInfo[i1].data[i2].unknownInt3, in, info );
			NifStream( treadTransferInfo[i1].data[i2].unknownInt4, in, info );
			NifStream( treadTransferInfo[i1].data[i2].unknownInt5, in, info );
			NifStream( treadTransferInfo[i1].data[i2].unknownInt6, in, info );
			NifStream( treadTransferInfo[i1].data[i2].unknownInt7, in, info );
			NifStream( treadTransferInfo[i1].data[i2].unknownInt8, in, info );
		};
	};
	NifStream( unknownInt1, in, info );

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void BSTreadTransfInterpolator::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiInterpolator::Write( out, link_map, missing_link_stack, info );
	numTransfers = (int)(treadTransferInfo.size());
	NifStream( numTransfers, out, info );
	for (unsigned int i1 = 0; i1 < treadTransferInfo.size(); i1++) {
		NifStream( treadTransferInfo[i1].unknownFloat1, out, info );
		for (unsigned int i2 = 0; i2 < 2; i2++) {
			NifStream( treadTransferInfo[i1].data[i2].unknownInt1, out, info );
			NifStream( treadTransferInfo[i1].data[i2].unknownInt2, out, info );
			NifStream( treadTransferInfo[i1].data[i2].unknownInt3, out, info );
			NifStream( treadTransferInfo[i1].data[i2].unknownInt4, out, info );
			NifStream( treadTransferInfo[i1].data[i2].unknownInt5, out, info );
			NifStream( treadTransferInfo[i1].data[i2].unknownInt6, out, info );
			NifStream( treadTransferInfo[i1].data[i2].unknownInt7, out, info );
			NifStream( treadTransferInfo[i1].data[i2].unknownInt8, out, info );
		};
	};
	NifStream( unknownInt1, out, info );

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string BSTreadTransfInterpolator::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiInterpolator::asString();
	numTransfers = (int)(treadTransferInfo.size());
	out << "  Num Transfers:  " << numTransfers << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < treadTransferInfo.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Unknown Float 1:  " << treadTransferInfo[i1].unknownFloat1 << endl;
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < 2; i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			out << "      Unknown Int 1:  " << treadTransferInfo[i1].data[i2].unknownInt1 << endl;
			out << "      Unknown Int 2:  " << treadTransferInfo[i1].data[i2].unknownInt2 << endl;
			out << "      Unknown Int 3:  " << treadTransferInfo[i1].data[i2].unknownInt3 << endl;
			out << "      Unknown Int 4:  " << treadTransferInfo[i1].data[i2].unknownInt4 << endl;
			out << "      Unknown Int 5:  " << treadTransferInfo[i1].data[i2].unknownInt5 << endl;
			out << "      Unknown Int 6:  " << treadTransferInfo[i1].data[i2].unknownInt6 << endl;
			out << "      Unknown Int 7:  " << treadTransferInfo[i1].data[i2].unknownInt7 << endl;
			out << "      Unknown Int 8:  " << treadTransferInfo[i1].data[i2].unknownInt8 << endl;
		};
	};
	out << "  Unknown Int 1:  " << unknownInt1 << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void BSTreadTransfInterpolator::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiInterpolator::FixLinks( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> BSTreadTransfInterpolator::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiInterpolator::GetRefs();
	return refs;
}

std::list<NiObject *> BSTreadTransfInterpolator::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiInterpolator::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
