#include <stdio.h>
#include "AfficherLettres.h"
#include "SaisirNombre.h"
#include "TraitementNombre.h"
#include "Utilitaire.h"

int main()
{
	double nombre;
	char* mots;

	for (int i = 0; i < 100; i++) {
		mots = traitementNombre(i);
		afficherLettres(mots);
	}

	nombre = saisirNombre();
	mots = traitementNombre(nombre);
	afficherLettres(mots);
}