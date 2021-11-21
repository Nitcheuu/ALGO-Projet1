#include <stdio.h>
#include "AfficherLettres.h"
#include "SaisirNombre.h"
#include "TraitementNombre.h"
#include "Utilitaire.h"

int main()
{
	double nombre;
	char* mots;

	nombre = saisirNombre();
	mots = traitementNombre(nombre);
	afficherLettres(mots);
}