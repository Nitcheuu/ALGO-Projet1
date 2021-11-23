#include <stdio.h>
#include <stdlib.h>
#include "Utilitaire.h"

/// <summary>
/// VA : Permet de v�rifier si le nombre saisi par l'utilisateur est
/// support� par le programme ou non
/// </summary>
/// <param name="nombre">Nombre saisi par l'utilisateur</param>
/// <returns>Bool�en</returns>
int verificationNombre(long double nombre) {
    int rangeOK;
    int virguleOK;
    long long int partieEntiere;
    long double partieDecimale;

    partieEntiere = nombre;
    partieDecimale = nombre - partieEntiere;
    // On v�rifie que l'intervalle est bien respect�e
    rangeOK = nombre > 0 && nombre < 1000000000000 ? 1 : 0;
    // On v�rifie que la partie d�cimale ne d�passe pas le centi�me
    virguleOK = nombreDeChiffres((long int)partieDecimale * 100) <= 2 && (partieDecimale * 100 - (long int)(partieDecimale * 100)) == 0 ? 1 : 0;
    return rangeOK && virguleOK;
}

/// <summary>
/// VA : Saisi et controle un nombre saisi par l'utilisateur
/// </summary>
/// <returns>Le nombre saisi par l'utilisateur</returns>
double saisirNombre() {
    long double nombre;

    printf("Saisissez un montant a afficher en lettres : ");
#if defined(_MSC_VER) // MSVC (Visual Studio)
    scanf_s("%Lf", &nombre);
#else // GCC or else
    scanf("%lf", &nombre);
#endif

    if (!verificationNombre(nombre)) // Si le nombre ne passe pas la v�rification
    {
        fprintf(stderr,"Le nombre ne passe pas la verification\n");
        exit(1); // Alors on arr�te le programme et on retourne un code d'erreur
    }

    return nombre;
}