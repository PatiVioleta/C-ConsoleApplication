#ifndef DOMAIN_H_
#define DOMAIN_H_
#include "Utils.h"

/*
The struct for the participants
*/
typedef struct {
	char nume[11];
	char prenume[11];
	float scor[11];
}Participant;

/*
Create a participant
Input data: nume- name, prenume- first name, scor- score
*/
Participant participant_create(char *, char*, float*);
void distrugep(Participant);
/*
Return the name of the participant pa
Input data: pa- a participant
Output data: the name of pa
Preconditions: pa is a participant
Postconditions: return pointer to a string
*/
char* participant_get_nume(Participant);

/*
Return the first name of the participant pa
Input data: pa- a participant
Output data: the first name of pa
Preconditions: pa is a participant
Postconditions: return pointer to a string
*/
char* participant_get_prenume(Participant);

/*
Return the score of the participant pa
Input data: pa- a participant
Output data: the score of pa
Preconditions: pa is a participant
Postconditions: return pointer to a list of floats
*/
float* participant_get_scor(Participant);

/*
Set the name of the participant pa
Input data: pa- a participant
Output data: the name of pa
Preconditions: pa is a participant
Postconditions: return pointer to a string
*/
void participant_set_nume(Participant*, char*);

/*
Set the first name of the participant pa
Input data: pa- a participant
Output data: the first name of pa
Preconditions: pa is a participant
Postconditions: return pointer to a string
*/
void participant_set_prenume(Participant*, char*);

/*
Set the score of the participant pa
Input data: pa- a participant
Output data: the score of pa
Preconditions: pa is a participant
Postconditions: return pointer to a list of floats
*/
void participant_set_scor(Participant*, float*);

/*
Test for getter
*/
void testGetter();

/*
Test for setter
*/
void testSetter();

#endif