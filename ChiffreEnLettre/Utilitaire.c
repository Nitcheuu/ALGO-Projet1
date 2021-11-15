#include <math.h>
#include <string.h>
#include <stdlib.h>

void nombreDeChiffres(int valeur)
{
	int compt = 0;

	do
	{
		valeur /= 10;
		compt++;
	} while (valeur != 0);

	return compt;
}



int* separer(int valeur, int taille){
    int nombreChiffres = NombreDeChiffres(valeur);
    int* tableau = malloc(nombreChiffres);
    int puissance;
    int i = 0;
    int n;
    
    puissance = pow(10, taille);
    while(valeur != 0) {
        tableau[i] = valeur % puissance;
        n /= puissance;
        i ++;
    }
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
	memcpy(chaineJointe + tailleUn + tailleDeux, chaineDeux, tailleDeux);

	return chaineJointe;
}