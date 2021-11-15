#include <stdio.h>
#include "Utilitaire.h"

int VerificationNombre(float nombre) {
    int rangeOK;
    int virguleOK;
    int partieEntiere;
    float partieDecimale;
    partieEntiere = nombre;
    partieDecimale = nombre - partieEntiere;
    // On v�rifie que l'intervalle est bien respect�e
    rangeOK = nombre > 0 && nombre < 1000000000000 ? 1 : 0;
    // On v�rifie que la partie d�cimale ne d�passe pas le centi�me
    virguleOK = NombreDeChiffres(partieDecimale * 100) <= 2 ? 1 : 0;
    return rangeOK && virguleOK;
}

float SaisirNombre() {
    float nombre;
    printf("Saisissez un montant � afficher en lettres : ");
    scanf("%f", nombre);
    if (!VerificationNombre(nombre)); // Si le nombre ne passe pas la v�rification
    exit(1); // Alors on arr�te le programme et on retourne un code d'erreur
    return nombre;
}