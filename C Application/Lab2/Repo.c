#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "Repo.h"
#include "Service.h"


ListaP* creare(int capac)
{
	ListaP* l=(ListaP*)malloc(sizeof(ListaP));
	l->dim = 0;
	l->capac = capac;
	l->elem = (Participant*)malloc(sizeof(Participant)*l->capac);
	return l;
}

void resize(ListaP* l) {
	int ncapac = l->capac * 2;
	Participant* nelems = (Participant*)malloc(sizeof(Participant)*ncapac);
	int i = 0;
	for (i=0; i < l->dim; i++)
		nelems[i] = l->elem[i];
	free(l->elem);
	l->elem = nelems;
	l->capac = ncapac;
}

void distruge(ListaP *l)
{
	//int i;
	//for (i = 0; i < l->capac; i++)
	{
		//distrugep(l->elem[i]);
		//free(l->elem[i]);
	}
	free(l->elem);
	free(l);
}

void adauga(ListaP *l, Participant pa)
{
	if (l->capac == l->dim)
		resize(l);
	
	l->elem[l->dim] = pa;
	l->dim = l->dim+1;
}

void actualizare(ListaP *l, Participant pa)
{
	int i;
	for (i = 0; i < l->dim; i++)
		if (strcmp(participant_get_nume(l->elem[i]), participant_get_nume(pa)) == 0 && strcmp(participant_get_prenume(l->elem[i]), participant_get_prenume(pa)) == 0)
		{
			participant_set_scor(&(l->elem)[i], pa.scor);
		}
}

int cautare(ListaP* l, Participant pa)
{
	int i;
	for (i = 0; i < l->dim; i++)
		if (strcmp(participant_get_nume(l->elem[i]), participant_get_nume(pa)) == 0 && strcmp(participant_get_prenume(l->elem[i]), participant_get_prenume(pa)) == 0)
		{
			return i;
		}
	return -1;
}

int sterge(ListaP *l,Participant pa)
{
	int i;
	if (cautare(l, pa) != -1)
	{
		for (i = cautare(l, pa); i < l->dim - 1; i++)
			l->elem[i] = l->elem[i + 1];

		l->dim = l->dim - 1;
		return 0;
	}
	return 1;
}

float medie(Participant pa)
{
	int j;
	float suma = 0;
		for (j = 0; j < 10; j++)
			suma = suma + pa.scor[j];
	return suma / 10;
}

void sortare(ListaP *l)
{
	int i, j;
	for (i=0;i<l->dim-1;i++)
		for(j=i+1;j<l->dim;j++)
			if (medie(l->elem[i]) > medie(l->elem[j]))
			{
				//char nume[100], prenume[100];
				float s[11];
				int k;
				for (k = 0; k < 10; k++)
					s[k] = l->elem[i].scor[k];

				Participant pa = participant_create(l->elem[i].nume, l->elem[i].prenume, s);

				strcpy(l->elem[i].nume, l->elem[j].nume);
				strcpy(l->elem[i].prenume, l->elem[j].prenume);
				for (k = 0; k < 10; k++)
					l->elem[i].scor[k] = l->elem[j].scor[k];

				strcpy(l->elem[j].nume, pa.nume);
				strcpy(l->elem[j].prenume, pa.prenume);
				for (k = 0; k < 10; k++)
					l->elem[j].scor[k] = pa.scor[k];
			}
}

void sortare_nume(ListaP *l)
{
	int i, j;
	for (i = 0; i<l->dim - 1; i++)
		for (j = i + 1; j<l->dim; j++)
			if (strcmp(l->elem[i].nume,l->elem[j].nume)>0 || (strcmp(l->elem[i].nume, l->elem[j].nume)==0 && strcmp(l->elem[i].prenume, l->elem[j].prenume)>0))
			{
				//char nume[100], prenume[100];
				float s[11];
				int k;
				for (k = 0; k < 10; k++)
					s[k] = l->elem[i].scor[k];

				Participant pa = participant_create(l->elem[i].nume, l->elem[i].prenume, s);

				strcpy(l->elem[i].nume, l->elem[j].nume);
				strcpy(l->elem[i].prenume, l->elem[j].prenume);
				for (k = 0; k < 10; k++)
					l->elem[i].scor[k] = l->elem[j].scor[k];

				strcpy(l->elem[j].nume, pa.nume);
				strcpy(l->elem[j].prenume, pa.prenume);
				for (k = 0; k < 10; k++)
					l->elem[j].scor[k] = pa.scor[k];
			}
}

void sortare_desc(ListaP *l)
{
	int i, j;
	for (i = 0; i<l->dim - 1; i++)
		for (j = i + 1; j<l->dim; j++)
			if (medie(l->elem[i]) < medie(l->elem[j]))
			{
				//char nume[100], prenume[100];
				float s[11];
				int k;
				for (k = 0; k < 10; k++)
					s[k] = l->elem[i].scor[k];

				Participant pa = participant_create(l->elem[i].nume, l->elem[i].prenume, s);

				strcpy(l->elem[i].nume, l->elem[j].nume);
				strcpy(l->elem[i].prenume, l->elem[j].prenume);
				for (k = 0; k < 10; k++)
					l->elem[i].scor[k] = l->elem[j].scor[k];

				strcpy(l->elem[j].nume, pa.nume);
				strcpy(l->elem[j].prenume, pa.prenume);
				for (k = 0; k < 10; k++)
					l->elem[j].scor[k] = pa.scor[k];
			}
}

void sortare_nume_desc(ListaP *l)
{
	int i, j;
	for (i = 0; i<l->dim - 1; i++)
		for (j = i + 1; j<l->dim; j++)
			if (strcmp(l->elem[i].nume, l->elem[j].nume)<0 || (strcmp(l->elem[i].nume, l->elem[j].nume) == 0 && strcmp(l->elem[i].prenume, l->elem[j].prenume)<0))
			{
				//char nume[100], prenume[100];
				float s[11];
				int k;
				for (k = 0; k < 10; k++)
					s[k] = l->elem[i].scor[k];

				Participant pa = participant_create(l->elem[i].nume, l->elem[i].prenume, s);

				strcpy(l->elem[i].nume, l->elem[j].nume);
				strcpy(l->elem[i].prenume, l->elem[j].prenume);
				for (k = 0; k < 10; k++)
					l->elem[i].scor[k] = l->elem[j].scor[k];

				strcpy(l->elem[j].nume, pa.nume);
				strcpy(l->elem[j].prenume, pa.prenume);
				for (k = 0; k < 10; k++)
					l->elem[j].scor[k] = pa.scor[k];
			}
}


void testAdauga()
{
	ListaP* l;
	l = creare(4);
	float lis[11] = { 7,8,7,7,6,8,9,8,8,7 }, lis2[11] = { 8,7,8,9,9,8,9,8,9,8 };
	adauga_participant(l, "Ana", "Pop", lis);
	adauga_participant(l, "Popescu", "Paul", lis2);

	assert(strcmp(l->elem[l->dim - 1].nume, "Popescu")==0);
	assert(strcmp(l->elem[l->dim - 1].prenume, "Paul") == 0);
	assert(strcmp(l->elem[l->dim - 2].nume, "Ana") == 0);
	assert(strcmp(l->elem[l->dim - 2].prenume, "Pop") == 0);

	resize(l);
	distruge(l);

}

void testActualizare()
{
	ListaP *l;
	l = creare(4);
	float lis[11] = { 7,8,7,7,6,8,9,8,8,7 }, lis2[11] = { 8,7,8,9,9,8,9,8,9,8 };
	adauga_participant(l, "Ana", "Pop", lis);
	adauga_participant(l, "Popescu", "Paul", lis2);
	Participant pa1, pa2;
	pa1 = participant_create("Ana", "Pop", lis2);
	pa2 = participant_create("Popescu", "Paul", lis2);

	actualizare(l, pa1);

	assert(l->elem[l->dim - 2].scor[0] == 8);
	assert(l->elem[l->dim - 2].scor[1] == 7);
	assert(l->elem[l->dim - 2].scor[2] == 8);
	assert(l->elem[l->dim - 2].scor[3] == 9);
	assert(l->elem[l->dim - 2].scor[4] == 9);
	assert(l->elem[l->dim - 2].scor[5] == 8);
	assert(l->elem[l->dim - 2].scor[6] == 9);
	assert(l->elem[l->dim - 2].scor[7] == 8);

	distruge(l);
}

void testCautare()
{
	ListaP* l;
	l = creare(3);
	float lis[11] = { 7,8,7,7,6,8,9,8,8,7 }, lis2[11] = { 8,7,8,9,9,8,9,8,9,8 };
	adauga_participant(l, "Ana", "Pop", lis);
	adauga_participant(l, "Popescu", "Paul", lis2);
	Participant pa1, pa2;
	pa1 = participant_create("Ana", "Pop", lis);
	pa2 = participant_create("Popescu", "Paul", lis2);

	assert(cautare(l,pa1)!=-1);

	distruge(l);
}

void testSterge()
{
	ListaP* l;
	l = creare(3);
	float lis[11] = { 7,8,7,7,6,8,9,8,8,7 }, lis2[11] = { 8,7,8,9,9,8,9,8,9,8 };
	adauga_participant(l, "Ana", "Pop", lis);
	adauga_participant(l, "Popescu", "Paul", lis2);
	Participant pa1, pa2;
	pa1 = participant_create("Ana", "Pop", lis);
	pa2 = participant_create("Pope", "Paul", lis2);

	sterge(l, pa1);

	assert(l->elem[l->dim - 1].scor[0] == 8);
	assert(l->elem[l->dim - 1].scor[1] == 7);
	assert(l->elem[l->dim - 1].scor[2] == 8);
	assert(l->elem[l->dim - 1].scor[3] == 9);
	assert(l->elem[l->dim - 1].scor[4] == 9);
	assert(l->elem[l->dim - 1].scor[5] == 8);
	assert(l->elem[l->dim - 1].scor[6] == 9);
	assert(l->elem[l->dim - 1].scor[7] == 8);

	assert(sterge(l, pa2) == 1);

	distruge(l);
}

void testMedie()
{
	ListaP* l;
	l = creare(3);
	float lis[11] = { 7,8,7,7,6,8,9,8,8,7 }, lis2[11] = { 8,7,8,9,9,8,9,8,9,8 };
	adauga_participant(l, "Ana", "Pop", lis);
	adauga_participant(l, "Popescu", "Paul", lis2);
	Participant pa1, pa2;
	pa1 = participant_create("Ana", "Pop", lis2);
	pa2 = participant_create("Popescu", "Paul", lis2);

	float med = medie(pa1);
	float med1 =(float)( 8.3);
	assert(med == med1);

	distruge(l);
}

void testSortare()
{
	ListaP* l;
	l = creare(3);
	float lis[11] = { 7,8,7,7,6,8,9,8,8,7 }, lis2[11] = { 8,7,8,9,9,8,9,8,9,8 };
	
	adauga_participant(l, "Popescu", "Paul", lis2);
	adauga_participant(l, "Ana", "Pop", lis);

	sortare(l);

	assert(strcmp(l->elem[l->dim -1].nume, "Popescu") == 0);
	assert(strcmp(l->elem[l->dim - 1].prenume, "Paul") == 0);
	assert(strcmp(l->elem[l->dim - 2].nume, "Ana") == 0);
	assert(strcmp(l->elem[l->dim - 2].prenume, "Pop") == 0);

	distruge(l);
}

void testSortareNume()
{
	ListaP* l;
	l = creare(3);
	float lis[11] = { 7,8,7,7,6,8,9,8,8,7 }, lis2[11] = { 8,7,8,9,9,8,9,8,9,8 };
	
	adauga_participant(l, "Popescu", "Paul", lis2);
	adauga_participant(l, "Ana", "Pop", lis);

	sortare_nume(l);

	assert(strcmp(l->elem[l->dim - 1].nume, "Popescu") == 0);
	assert(strcmp(l->elem[l->dim - 1].prenume, "Paul") == 0);
	assert(strcmp(l->elem[l->dim - 2].nume, "Ana") == 0);
	assert(strcmp(l->elem[l->dim - 2].prenume, "Pop") == 0);

	distruge(l);

}

void testSortareDesc()
{
	ListaP* l;
	l = creare(3);
	float lis[11] = { 7,8,7,7,6,8,9,8,8,7 }, lis2[11] = { 8,7,8,9,9,8,9,8,9,8 };
	adauga_participant(l, "Ana", "Pop", lis);
	adauga_participant(l, "Popescu", "Paul", lis2);

	sortare_desc(l);

	assert(strcmp(l->elem[l->dim - 2].nume, "Popescu") == 0);
	assert(strcmp(l->elem[l->dim - 2].prenume, "Paul") == 0);
	assert(strcmp(l->elem[l->dim - 1].nume, "Ana") == 0);
	assert(strcmp(l->elem[l->dim - 1].prenume, "Pop") == 0);

	distruge(l);
}

void testSortareNumeDesc()
{
	ListaP* l;
	l = creare(3);
	float lis[11] = { 7,8,7,7,6,8,9,8,8,7 }, lis2[11] = { 8,7,8,9,9,8,9,8,9,8 };
	adauga_participant(l, "Ana", "Pop", lis);
	adauga_participant(l, "Popescu", "Paul", lis2);

	sortare_nume_desc(l);

	assert(strcmp(l->elem[l->dim - 2].nume, "Popescu") == 0);
	assert(strcmp(l->elem[l->dim - 2].prenume, "Paul") == 0);
	assert(strcmp(l->elem[l->dim - 1].nume, "Ana") == 0);
	assert(strcmp(l->elem[l->dim - 1].prenume, "Pop") == 0);

	distruge(l);
}