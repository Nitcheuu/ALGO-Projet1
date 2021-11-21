#include <stdio.h>
#include "AfficherLettres.h"
#include "SaisirNombre.h"
#include "TraitementNombre.h"
#include "Utilitaire.h"

int main()
{
	double nombre;
	char* mots;

	// Test de stress
	for (int i = 0; i < 100; i++)
	{
		mots = traitementNombre((double)i);
		afficherLettres(mots);
	}
	for (int i = 101; i < 1000; i += 100)
	{
		mots = traitementNombre((double)i);
		afficherLettres(mots);
	}
	for (int i = 1001; i < 1000000000000; i *= 1000)
	{
		mots = traitementNombre((double)i);
		afficherLettres(mots);
	}
	return;

	nombre = saisirNombre();
	mots = traitementNombre(nombre);
	afficherLettres(mots);
}