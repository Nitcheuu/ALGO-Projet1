#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int nombreDeChiffres(int valeur)
{
	int compt = 0;

	while (valeur != 0)
	{
		valeur /= 10;
		compt++;
	}

	return compt;
}



int* separer(long long int valeur, int tranche, int* taille) {
    int nombreChiffres = nombreDeChiffres(valeur);
    int* tableau = malloc(nombreChiffres);
    int puissance;
    int i = 0;

	if (tableau == NULL) {
		fprintf(stderr, "Separer:Mémoire indisponible.\n");
		exit(2);
	}

    puissance = pow(10, tranche);
    while(valeur != 0) {
        tableau[i] = valeur % puissance;
        valeur /= puissance;
        i ++;
    }

	*taille = i;
    return tableau;
}

char* joindre(char* separateur, char* chaineUn, char* chaineDeux)
{
	int tailleUn = strlen(chaineUn);
	int tailleDeux = strlen(chaineDeux);
	int tailleSeparateur = strlen(separateur);
	char* chaineJointe = malloc(tailleUn + tailleSeparateur + tailleDeux);

	memcpy(chaineJointe, chaineUn, tailleUn);
	memcpy(chaineJointe + tailleUn, separateur, tailleSeparateur);
	memcpy(chaineJointe + tailleUn + tailleSeparateur, chaineDeux, tailleDeux);
	memcpy(chaineJointe + tailleUn + tailleSeparateur + tailleDeux, "\0", 2); // malloc nous donne plus que ce que on lui demande parfois

	return chaineJointe;
}