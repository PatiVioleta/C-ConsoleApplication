#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "Domain.h"

int validate(Participant pa)
{
	int ok=1;
	int n = (int)strlen(pa.nume);
	int m = (int)strlen(pa.prenume);

	if (n == 0 || m==0)
		ok=0;

	if (strspn(pa.nume, "0123456789") != 0)
		ok = 0;

	if (strspn(pa.prenume, "0123456789") != 0)
		ok=0;

	for (int i = 0; i < 10; i++)
		if (pa.scor[i] < 0 || pa.scor[i]>10)
			ok=0;

	return ok;
}


void testValidator()
{
	float lis[11] = { 7,8,7,7,6,8,9,8,8,7 };
	Participant pa;
	pa = participant_create("maria", "ana", lis);
	assert(validate(pa) == 1);

	Participant pa1;
	pa1 = participant_create("", "ana", lis);
	assert(validate(pa1) == 0);

	Participant pa2;
	pa2 = participant_create("ana", "", lis);
	assert(validate(pa2) == 0);

	float lis1[11] = { 7,8,7,7,-6,8,9,8,8,7 };
	Participant pa3;
	pa3 = participant_create("maria", "ana", lis1);
	assert(validate(pa3) == 0);

	Participant pa4;
	pa4 = participant_create("ana", "34", lis);
	assert(validate(pa4) == 0);

	Participant pa5;
	pa5 = participant_create("12", "ana", lis);
	assert(validate(pa5) == 0);
}
