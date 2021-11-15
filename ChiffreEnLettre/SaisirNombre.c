#include <stdio.h>
#include "Utilitaire.h"

int VerificationNombre(float nombre) {
    int rangeOK;
    int virguleOK;
    int partieEntiere;
    float partieDecimale;
    partieEntiere = nombre;
    partieDecimale = nombre - partieEntiere;
    // On vérifie que l'intervalle est bien respectée
    rangeOK = nombre > 0 && nombre < 1000000000000 ? 1 : 0;
    // On vérifie que la partie décimale ne dépasse pas le centième
    virguleOK = NombreDeChiffres(partieDecimale * 100) <= 2 ? 1 : 0;
    return rangeOK && virguleOK;
}

float SaisirNombre() {
    float nombre;
    printf("Saisissez un montant à afficher en lettres : ");
    scanf("%f", nombre);
    if (!VerificationNombre(nombre)); // Si le nombre ne passe pas la vérification
    exit(1); // Alors on arrête le programme et on retourne un code d'erreur
    return nombre;
}