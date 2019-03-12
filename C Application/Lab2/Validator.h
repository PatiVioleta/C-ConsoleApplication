#pragma once
#ifndef VALIDATOR_H_
#define VALIDATOR_H_

#include "Domain.h"

/*
Validates a participant
Input data: pa- participant to be validated
Output data: erori- a string of errors
Preconditions: pa is a possible participant
Postconditions: erori is a string
*/
int validate(Participant pa);

/*
Test for validate
*/
void testValidator();

#endif // VALIDATOR