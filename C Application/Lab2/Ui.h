#pragma once
#ifndef UI_H_
#define UI_H_

#include "Service.h"
#include "Repo.h"

/*
Print the menu
Output data: the menu
*/
void afisare_meniu();

/*
Print the list of paricipants
Input data: l- the list
Preconditions: l is a list of paricipants
*/
void ui_afisare(ListaP *);

/*
Add an participant to the list
Input data: l- the list
Preconditions: l is  list of participants
*/
void ui_adauga(ListaP *);

/*
Update a participant in the list
Input data: l- the list
Preconditions: l is  list of participants
*/
void ui_actualizare(ListaP *);

/*
Sort the list by score
Input data: l- the list
Preconditions: l is  list of participants
*/
void ui_sortare(ListaP *);

/*
Sort the list by name
Input data: l- the list
Preconditions: l is  list of participants
*/
void ui_sortare_nume(ListaP *);

/*
Run the aplication
*/
int run();
#endif
