#include<string.h>
#include<stdio.h>
#include<assert.h>
#include "Domain.h"


Participant participant_create(char *nume, char *prenume, float *scor)
{
	Participant pa;
	strcpy(pa.nume, nume);
	strcpy(pa.prenume, prenume);
	
	int i;
	for (i = 0; i < 10; i++)
		pa.scor[i] = scor[i];
	return pa;
}

char* participant_get_nume(Participant pa)
{
	//return copy_string(pa.nume);
	return pa.nume;
}

char* participant_get_prenume(Participant pa)
{
	//return copy_string(pa.prenume);
	return pa.prenume;
}

/*
float* participant_get_scor(Participant pa)
{
	return pa.scor;
}
*/

void participant_set_nume(Participant* pa, char* nume)
{
	strcpy(pa->nume, nume);
}

void participant_set_prenume(Participant* pa, char* prenume)
{
	strcpy(pa->prenume, prenume);
}

void participant_set_scor(Participant* pa, float* scor)
{
	int i;
	for (i = 0; i < 10; i++)
		pa->scor[i] = scor[i];
}


void testGetter()
{
	float s[11] = { 9, 9, 8, 8, 9, 8, 9, 10, 9, 8 };
	
	Participant pa = participant_create("Popescu", "Alin", s);
	

	char nume[11];
	strcpy(nume, participant_get_nume(pa));
	int ret = strcmp(nume, pa.nume);
	assert(ret == 0);

	char prenume[11];
	strcpy(prenume, participant_get_prenume(pa));
	int ret1 = strcmp(prenume, pa.prenume);
	assert(ret1 == 0);

	//int ok = 0,i;
	//for (i = 0; i < 10; i++)
		//if (participant_get_scor(pa)[i] != s[i])
			//ok = 1;
	//assert(ok == 0);
	
}

void testSetter()
{
	float s[11] = {9, 9, 8, 8, 9, 8, 9, 10, 9, 8};
	Participant pa = participant_create("Popescu", "Alin", s);
	participant_set_nume(&pa, "Pop");
	int ret = strcmp(pa.nume, "Pop");
	assert(ret == 0);

	participant_set_prenume(&pa, "Ana");
	int ret1 = strcmp(pa.prenume, "Ana");
	assert(ret1 == 0);

	float s2[11] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	participant_set_scor(&pa, s2);
	//int i,ok=0;
	//for (i = 0; i < 10; i++)
		//if (pa.scor[i] != s2[i])
			//ok = 1;
	//assert(ok == 0);

}