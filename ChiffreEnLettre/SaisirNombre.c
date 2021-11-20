#include <stdio.h>
#include <stdlib.h>
#include "Utilitaire.h"

int verificationNombre(double nombre) {
    int rangeOK;
    int virguleOK;
    int partieEntiere;    
    double partieDecimale;

    partieEntiere = nombre;
    partieDecimale = nombre - partieEntiere;

    // On vérifie que l'intervalle est bien respectée
    rangeOK = nombre > 0 && nombre < 1000000000000 ? 1 : 0;
    // On vérifie que la partie décimale ne dépasse pas le centième
    virguleOK = nombreDeChiffres((int)partieDecimale * 100) <= 2 && partieDecimale * 100 - (int)(partieDecimale * 100) == 0 ? 1 : 0;

    return rangeOK && virguleOK;
}

double saisirNombre() {
    double nombre;

    printf("Saisissez un montant a afficher en lettres : ");
#if defined(_MSC_VER) // MSVC (Visual Studio)
    scanf_s("%lf", &nombre);
#else // GCC or else
    scanf("%lf", &nombre);
#endif

    if (!verificationNombre(nombre)) // Si le nombre ne passe pas la vérification
    {
        fprintf(stderr,"Le nombre ne passe pas la verification\n");
        exit(1); // Alors on arrête le programme et on retourne un code d'erreur
    }

    return nombre;
}