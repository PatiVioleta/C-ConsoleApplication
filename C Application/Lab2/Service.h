#pragma once

#ifndef SERVICE_H_
#define SERVICE_H_
#include <stdio.h>
#include "Repo.h"
#include "Domain.h"

/*
Add an participant to the list
Input data: l- the list, nume-the name, prenume- first name, scor- scor
Preconditions: l is  list of participants; nume ,prenume are strings; scor is a list of floats
*/
int adauga_participant(ListaP* , char*, char*, float*);

/*
Update a participant in the list
Input data: l- the list, nume-the name, prenume- first name, scor- scor
Preconditions: l is  list of participants; nume ,prenume are strings; scor is a list of floats
*/
int actualizare_participant(ListaP*, char*, char*, float*);

/*
Delete a participant of the list
Input data: l- the list, nume-the name, prenume- first name
Preconditions: l is  list of participants; nume ,prenume are strings
*/
int stergere_participant(ListaP*, char*, char*);

/*
Return the average of the scor of the participant pa
Input data: pa- participant
Preconditions: pa is a participant
Postconditions: medie is a float
*/
float medie_participant(Participant);

/*
Growing sort the list by score
Input data: l- the list
Preconditions: l is  list of participants
Postconditions: the list is scaled up
*/
void sortare_participant(ListaP*);

/*
Growing sort the list by name
Input data: l- the list
Preconditions: l is  list of participants
Postconditions: the list is scaled up
*/
void sortare_nume_participant(ListaP*);

/*
Descending sort the list by score
Input data: l- the list
Preconditions: l is  list of participants
Postconditions: the list is sorted in decreasing order
*/
void sortare_participant_desc(ListaP*);

/*
Descending sort the list by name
Input data: l- the list
Preconditions: l is  list of participants
Postconditions: the list is sorted in decreasing order
*/
void sortare_nume_participant_desc(ListaP*);


/*
Test for add
*/
void testAdauga_pa();

/*
Test for update
*/
void testActualizare_pa();

/*
Test for search
*/
void testCautare_pa();

/*
Test for delete
*/
void testSterge_pa();

/*
Test for average
*/
void testMedie_pa();

/*
Test for sort by score
*/
void testSortare_pa();

/*
Test for sort by name
*/
void testSortareNume_pa();

/*
Test for descending sort by score
*/
void testSortareDesc_pa();

/*
Test for descending sort by name
*/
void testSortareNumeDesc_pa();

#endif