//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** Listing 7-5.
	@file PrecondViolatedExcep.h */

#pragma once

#include <stdexcept>
#include <string>

using namespace std;

class PrecondViolatedExcep : public logic_error
{
public:
	PrecondViolatedExcep(const string& message = "");
}; // end PrecondViolatedExcep 
