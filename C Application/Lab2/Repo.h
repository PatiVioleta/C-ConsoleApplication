#pragma once
#ifndef REPO_H_
#define REPO_H_

#include "Domain.h"

typedef Participant Part;

/*
Struct for the list of participants
*/
typedef struct {
	Part* elem;
	int dim;
	int capac;
}ListaP;

/*
Create an empty list of participants
Output data: return a list of participants
postconditions: l is an empty list of participants
*/
ListaP* creare(int);

/*
Increase the size of the list of participants
Input data: the list of participants
postconditions: the list has doubled capacity
*/
void resize(ListaP*);

/*
Free the memory used by l
Input data: the list of participants
postconditions: the memory is free
*/
void distruge(ListaP *l);

/*
Initialization the list
Postconditions: l is an empty list of participants, the curent is 0
*/
void initializare(ListaP *);

/*
Add an participant to the list
Input data: l- the list, pa- a participant
Preconditions: l is  list of participants
*/
void adauga(ListaP *, Participant );

/*
Update a participant in the list
Input data: l- the list, pa- a participant
Preconditions: l is  list of participants
*/
void actualizare(ListaP *, Participant);

/*
Find out if a participant is in the list or not
Input data: l- the list, pa- a participant
Output data: return 0 if the participant isn't in the list and 1 otherwise
*/
int cautare(ListaP *, Participant);

/*
Delete a participant of the list
Input data: l- the list, pa- a participant
Preconditions: l is  list of participants
*/
int sterge(ListaP *, Participant);

/*
Return the average of the scor of the participant pa
Input data: pa- participant
Preconditions: pa is a participant
Postconditions: medie is a float
*/
float medie(Participant);

/*
Growing sort the list by score
Input data: l- the list
Preconditions: l is  list of participants
Postconditions: the list is scaled up
*/
void sortare(ListaP *);

/*
Growing sort the list by name
Input data: l- the list
Preconditions: l is  list of participants
Postconditions: the list is scaled up
*/
void sortare_nume(ListaP *);

/*
Descending sort the list by score
Input data: l- the list
Preconditions: l is  list of participants
Postconditions: the list is sorted in decreasing order
*/
void sortare_desc(ListaP *);

/*
Descending sort the list by name
Input data: l- the list
Preconditions: l is  list of participants
Postconditions: the list is sorted in decreasing order
*/
void sortare_nume_desc(ListaP *);

/*
Test for add
*/
void testAdauga();

/*
Test for update
*/
void testActualizare();

/*
Test for search
*/
void testCautare();

/*
Test for delete
*/
void testSterge();

/*
Test for avarage
*/
void testMedie();

/*
Test for sort by score
*/
void testSortare();

/*
Test for sort by name
*/
void testSortareNume();

/*
Test for descending sort by score
*/
void testSortareDesc();

/*
Test for descending sort by name
*/
void testSortareNumeDesc();

#endif
