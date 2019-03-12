#include <stdio.h>
#include "Ui.h"
#include "Domain.h"
#include "Repo.h"
#include "Validator.h"

void allTeste()
{
	testGetter();
	testSetter();
	testAdauga();
	testActualizare();
	testCautare();
	testSterge();
	testMedie();
	testSortare();
	testSortareNume();
	testSortareDesc();
	testSortareNumeDesc();
	testAdauga_pa();
	testActualizare_pa();
	testCautare_pa();
	testSterge_pa();
	testMedie_pa();
	testSortare_pa();
	testSortareNume_pa();
	testSortareDesc_pa();
	testSortareNumeDesc_pa();
	testValidator();
}

int main()
{
	allTeste();
	run();
	return 0;
}