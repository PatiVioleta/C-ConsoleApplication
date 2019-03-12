#include <stdio.h>
#include "Ui.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

void afisare_meniu()
{
	printf("MENIU:\n");
	printf("1.Adauga participant \n");
	printf("2.Modifica participant \n");
	printf("3.Sterge participant \n");
	printf("4.Afisare participanti al caror scor e mai mic decat un nr dat \n");
	printf("5.Sortare dupa scor\n");
	printf("6.Sortare dupa nume\n");
	printf("7.Afisare participanti \n");
	printf("8.Exit \n");
	printf("Apasa 'c' pentru a continua \n\n");
}

int validInt(int *i)
{
	char x[200];
	scanf_s("%s", x, 13);
	*i = atoi(x);
	if (*i == 0)
	{
		if (strcmp(x, "0") == 0)
			return 0;
		else
			return 1;
	}
	return 0;
}

int validFloat(float *p)
{
	char x[200];
	scanf_s("%s", x, 13);
	*p = (float)atof(x);
	if (*p == 0)
	{
		if (strcmp(x, "0") == 0)
			return 0;
		else
			return 1;
	}
	return 0;
}

void ui_adauga(ListaP *l)
{
	char nume[100],prenume[100];
	float scor[100];
	printf("Dati un nume: ");
	scanf_s("%s", nume,60);
	printf("\nDati un prenume: ");
	scanf_s("%s", prenume,60);
	int i;
	printf("\nDati 10 valori pentru scor: ");
	for (i = 0; i < 10; i++)
	{
		validFloat(&scor[i]);
	}

	if(adauga_participant(l, nume, prenume, scor)==1)
		printf("Participant adaugat cu succes!!\n");
	else
		printf("Dati nume valide si valori pozitive pentru scor!!\n");

	
}

void ui_sterge(ListaP *l)
{
	char nume[100], prenume[100];

	printf("Dati un nume: ");
	scanf_s("%s", nume,60);
	printf("\nDati un prenume: ");
	scanf_s("%s", prenume,60);
	int ok = stergere_participant(l, nume, prenume);
	if (ok == 0)
		printf("Participant sters cu succes!!");
	else
		printf("Participantul nu a fost gasit!!");
}

void ui_afisare(ListaP *l)
{	
	if (l->dim == 0)
		printf("Nu exista participanti in lista!!\n");
	else
	{	
		int i;
		for (i = 0; i < l->dim; i++)
		{
			printf("%s %s ", l->elem[i].nume, l->elem[i].prenume);
			int j;
			for (j = 0; j < 10; j++)
				printf("%f ", l->elem[i].scor[j]);
			printf("Medie note: %f", medie(l->elem[i]));
			printf("\n");
		}
	}
}

void ui_actualizare(ListaP *l)
{
	char nume[100], prenume[100];
	float scor[100];
	printf("Dati numele celui care trebuie modificat: ");
	scanf_s("%s", nume,60);
	printf("\nDati prenumele celui care trebuie modificat: ");
	scanf_s("%s", prenume,60);
	int i;
	printf("\nDati 10 valori pentru noul scor: ");
	for (i = 0; i < 10; i++)
	{
		validFloat(&scor[i]);
	}
	if (actualizare_participant(l, nume, prenume, scor) == 0)
		printf("Participant actualizat cu succes!!\n");
	else
		printf("Nu exista un participant cu numele dat!!\n");
}

void ui_medie(ListaP *l)
{
	float sc;
	int ok=-1;
	printf("\nDati scorul:");
	validFloat(&sc);
	int j;
	for(j=0;j<l->dim;j++)
		if(medie_participant(l->elem[j])<sc)
		{
			printf("%s %s ", l->elem[j].nume, l->elem[j].prenume);
			int i;
			for (i = 0; i < 10; i++)
				printf("%f ", l->elem[j].scor[i]);
			printf(" Medie note: %f", medie_participant(l->elem[j]));
			printf("\n");
			ok = 0;
		}
	if (ok == -1)
		printf("Nu exista participanti cu aceasta proprietate!");
}

void ui_sortare(ListaP *l)
{
	int com;
	printf("1.Crescator\n");
	printf("2.Descrescator\n");
	validInt(&com);
	if (com == 1)
	{
		sortare_participant(l);
		ui_afisare(l);
	}
	if (com == 2)
	{
		sortare_participant_desc(l);
		ui_afisare(l);
	}
}

void ui_sortare_nume(ListaP *l)
{
	int com;
	printf("1.Crescator\n");
	printf("2.Descrescator\n");
	validInt(&com);
	if (com == 1)
	{
		sortare_nume_participant(l);
		ui_afisare(l);
	}
	if (com == 2)
	{
		sortare_nume_participant_desc(l);
		ui_afisare(l);
	}
}

int run()
{
	ListaP *l;
	l = creare(10);
	float lis[11] = { 7,8,7,7,6,8,9,8,8,7 }, lis2[11] = { 8,7,8,9,9,8,9,8,9,8 };

	adauga_participant(l, "Ana", "Pop", lis);
	adauga_participant(l, "Popescu", "Paul", lis2);
	adauga_participant(l, "Alina", "Pop",lis);
	adauga_participant(l, "Costea", "Paul", lis2);
	adauga_participant(l, "Ca", "Pa", lis2);

	while (1)
	{
		afisare_meniu();
		int com;
		validInt(&com);
		
		switch (com)
		{
		case 1:
			ui_adauga(l);
			break;
		case 2:
			ui_actualizare(l);
			break;
		case 3:
			ui_sterge(l);
			break;
		case 4:
			ui_medie(l);
			break;
		case 5:
			ui_sortare(l);
			break;
		case 6:
			ui_sortare_nume(l);
			break;
		case 7:
			ui_afisare(l);
			break;
		case 8:
			distruge(l);
			_CrtDumpMemoryLeaks();
			return 0;
			break;
		}
		while(getchar()!='c'){}
	}
}