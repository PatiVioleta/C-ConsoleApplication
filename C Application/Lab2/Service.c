#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "Service.h"
#include "Validator.h"


int adauga_participant(ListaP* l,char *nume, char *prenume, float *scor)
{
	int ok = 1;
	Participant pa;
	pa=participant_create(nume, prenume, scor);

	if (cautare(l, pa) == -1 && validate(pa) == 1)
		adauga(l, pa);
	else
		ok = 0;

	return ok;
}

int actualizare_participant(ListaP* l, char *nume, char *prenume, float *scor)
{
	Participant pa;
	pa = participant_create(nume, prenume, scor);

	if (cautare(l, pa) != -1)
	{
		actualizare(l, pa);
		return 0;
	}
	return -1;
}

int stergere_participant(ListaP* l, char *nume, char *prenume)
{
	Participant pa;
	float scor[100] = {1,7,7,8,7,8,7,8,7,8};
	pa = participant_create(nume, prenume, scor);

	if (sterge(l, pa) == 0)
		return 0;
	else
		return 1;
}

float medie_participant(Participant pa)
{
	return medie(pa);
}

void sortare_participant(ListaP* l)
{
	sortare(l);
}

void sortare_nume_participant(ListaP* l)
{
	sortare_nume(l);
}

void sortare_participant_desc(ListaP* l)
{
	sortare_desc(l);
}

void sortare_nume_participant_desc(ListaP* l)
{
	sortare_nume_desc(l);
}

void testAdauga_pa()
{
	ListaP* l;
	l = creare(3);
	float lis[11] = { 7,8,7,7,6,8,9,8,8,7 }, lis2[11] = { 8,7,8,9,9,8,9,8,9,8 };
	adauga_participant(l, "Ana", "Pop", lis);
	adauga_participant(l, "Popescu", "Paul", lis2);

	assert(strcmp(l->elem[l->dim - 1].nume, "Popescu") == 0);
	assert(strcmp(l->elem[l->dim - 1].prenume, "Paul") == 0);
	assert(strcmp(l->elem[l->dim - 2].nume, "Ana") == 0);
	assert(strcmp(l->elem[l->dim - 2].prenume, "Pop") == 0);

	assert(adauga_participant(l, "Popescu", "Paul", lis2)==0);

	distruge(l);

}

void testActualizare_pa()
{
	ListaP* l;
	l = creare(3);
	float lis[11] = { 7,8,7,7,6,8,9,8,8,7 }, lis2[11] = { 8,7,8,9,9,8,9,8,9,8 };
	adauga_participant(l, "Ana", "Pop", lis);
	adauga_participant(l, "Popescu", "Paul", lis2);
	Participant pa1, pa2;
	pa1 = participant_create("Ana", "Pop", lis2);
	pa2 = participant_create("Popescu", "Paul", lis2);

	actualizare_participant(l,"Ana", "Pop", lis2);

	assert(l->elem[l->dim - 2].scor[0] == 8);
	assert(l->elem[l->dim - 2].scor[1] == 7);
	assert(l->elem[l->dim - 2].scor[2] == 8);
	assert(l->elem[l->dim - 2].scor[3] == 9);
	assert(l->elem[l->dim - 2].scor[4] == 9);
	assert(l->elem[l->dim - 2].scor[5] == 8);
	assert(l->elem[l->dim - 2].scor[6] == 9);
	assert(l->elem[l->dim - 2].scor[7] == 8);

	assert(actualizare_participant(l, "Anha", "Pop", lis2) == -1);

	distruge(l);

}

void testCautare_pa()
{
	ListaP* l;
	l = creare(3);
	float lis[11] = { 7,8,7,7,6,8,9,8,8,7 }, lis2[11] = { 8,7,8,9,9,8,9,8,9,8 };
	adauga_participant(l, "Ana", "Pop", lis);
	adauga_participant(l, "Popescu", "Paul", lis2);
	Participant pa1, pa2;
	pa1 = participant_create("Ana", "Pop", lis);
	pa2 = participant_create("Popescu", "Paul", lis2);

	assert(cautare(l, pa1) != -1);

	distruge(l);

}

void testSterge_pa()
{
	ListaP* l;
	l = creare(3);
	float lis[11] = { 7,8,7,7,6,8,9,8,8,7 }, lis2[11] = { 8,7,8,9,9,8,9,8,9,8 };
	adauga_participant(l, "Ana", "Pop", lis);
	adauga_participant(l, "Popescu", "Paul", lis2);
	Participant pa1, pa2;
	pa1 = participant_create("Ana", "Pop", lis);
	pa2 = participant_create("Popescu", "Paul", lis2);

	stergere_participant(l, "Ana","Pop");

	assert(l->elem[l->dim - 1].scor[0] == 8);
	assert(l->elem[l->dim - 1].scor[1] == 7);
	assert(l->elem[l->dim - 1].scor[2] == 8);
	assert(l->elem[l->dim - 1].scor[3] == 9);
	assert(l->elem[l->dim - 1].scor[4] == 9);
	assert(l->elem[l->dim - 1].scor[5] == 8);
	assert(l->elem[l->dim - 1].scor[6] == 9);
	assert(l->elem[l->dim - 1].scor[7] == 8);

	assert(stergere_participant(l, "Ana", "Pyop")==1);

	distruge(l);

}

void testMedie_pa()
{
	ListaP* l;
	l = creare(3);
	float lis[11] = { 7,8,7,7,6,8,9,8,8,7 }, lis2[11] = { 8,7,8,9,9,8,9,8,9,8 };
	adauga_participant(l, "Ana", "Pop", lis);
	adauga_participant(l, "Popescu", "Paul", lis2);
	Participant pa1, pa2;
	pa1 = participant_create("Ana", "Pop", lis2);
	pa2 = participant_create("Popescu", "Paul", lis2);

	float med = medie_participant(pa1);
	float med1 =(float)( 8.3);
	assert(med == med1);

	distruge(l);

}

void testSortare_pa()
{
	ListaP* l;
	l = creare(3);
	float lis[11] = { 7,8,7,7,6,8,9,8,8,7 }, lis2[11] = { 8,7,8,9,9,8,9,8,9,8 };
	adauga_participant(l, "Ana", "Pop", lis);
	adauga_participant(l, "Popescu", "Paul", lis2);

	sortare_participant(l);

	assert(strcmp(l->elem[l->dim - 1].nume, "Popescu") == 0);
	assert(strcmp(l->elem[l->dim - 1].prenume, "Paul") == 0);
	assert(strcmp(l->elem[l->dim - 2].nume, "Ana") == 0);
	assert(strcmp(l->elem[l->dim - 2].prenume, "Pop") == 0);

	distruge(l);

}

void testSortareNume_pa()
{
	ListaP* l;
	l = creare(3);
	float lis[11] = { 7,8,7,7,6,8,9,8,8,7 }, lis2[11] = { 8,7,8,9,9,8,9,8,9,8 };
	adauga_participant(l, "Ana", "Pop", lis);
	adauga_participant(l, "Popescu", "Paul", lis2);

	sortare_nume_participant(l);

	assert(strcmp(l->elem[l->dim - 1].nume, "Popescu") == 0);
	assert(strcmp(l->elem[l->dim - 1].prenume, "Paul") == 0);
	assert(strcmp(l->elem[l->dim - 2].nume, "Ana") == 0);
	assert(strcmp(l->elem[l->dim - 2].prenume, "Pop") == 0);

	distruge(l);

}

void testSortareDesc_pa()
{
	ListaP* l;
	l = creare(3);
	float lis[11] = { 7,8,7,7,6,8,9,8,8,7 }, lis2[11] = { 8,7,8,9,9,8,9,8,9,8 };
	adauga_participant(l, "Ana", "Pop", lis);
	adauga_participant(l, "Popescu", "Paul", lis2);

	sortare_participant_desc(l);

	assert(strcmp(l->elem[l->dim - 2].nume, "Popescu") == 0);
	assert(strcmp(l->elem[l->dim - 2].prenume, "Paul") == 0);
	assert(strcmp(l->elem[l->dim - 1].nume, "Ana") == 0);
	assert(strcmp(l->elem[l->dim - 1].prenume, "Pop") == 0);

	distruge(l);

}

void testSortareNumeDesc_pa()
{
	ListaP* l;
	l = creare(3);
	float lis[11] = { 7,8,7,7,6,8,9,8,8,7 }, lis2[11] = { 8,7,8,9,9,8,9,8,9,8 };
	adauga_participant(l, "Ana", "Pop", lis);
	adauga_participant(l, "Popescu", "Paul", lis2);

	sortare_nume_participant_desc(l);

	assert(strcmp(l->elem[l->dim - 2].nume, "Popescu") == 0);
	assert(strcmp(l->elem[l->dim - 2].prenume, "Paul") == 0);
	assert(strcmp(l->elem[l->dim - 1].nume, "Ana") == 0);
	assert(strcmp(l->elem[l->dim - 1].prenume, "Pop") == 0);

	distruge(l);

}