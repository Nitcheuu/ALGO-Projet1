#include <stdio.h>
#include "AfficherLettres.h"
#include "SaisirNombre.h"
#include "TraitementNombre.h"
#include "Utilitaire.h"

int main()
{
	double nombre = saisirNombre();
	printf("%f\n", nombre);

	int length;
	int* test = separer(nombre, 3, &length);

	for (int i = 0; i < length; i++)
	{
		printf("%d\n", test[i]);
	}

	char* tets = joindre(" ", "Let's", "go");
	printf("%s\n", tets);

	afficherLettres("Let's go");
}