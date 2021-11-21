#include <stdio.h>
#include "Utilitaire.h"

char* tableauUnite[10] = {"", "un ", "deux ", "trois ", "quatre ", "cinq ", "six ", "sept ", "huit ", "neuf " };
char* tableauDizaine[9] = { "dix ", "vingt ", "trente ",  "quarante ", "cinquante ", "soixante ", "soixante ", "quatre vingt ", "quatre vingt " };
char* tableauDixADixNeuf[10] = { "dix ", "onze ", "douze ", "treize ", "quatorze ", "quinze ", "seize ", "dix sept ", "dix huit ", "dix neuf " };
char* quantifieurSingulier[4] = {"", "mille ", "million ", "milliard "};
char* quantifieurPluriel[4] = {"",  "mille ", "millions ", "milliards "};

char* traitementUnite(int unite)
{
    return tableauUnite[unite];
}

char* traitementDizaine(int nombre)
{
    /*Déclaration des variables*/
    char* dizaine = tableauDizaine[nombre / 10 - 1];
    char* unite = traitementUnite(nombre % 10);
    char* uniteDixADixNeuf = tableauDixADixNeuf[nombre % 10];

    /*****************CODE****************/

    if (nombre < 10)
        return unite;

    if (nombre < 20 && nombre > 9) // 10 à 19
        return uniteDixADixNeuf;
    else
    {
        if ((nombre >= 20 && nombre < 100) && ((nombre > 69 && nombre < 80) || (nombre > 89 && nombre < 100))) // 20 à 100, 70 à 80, 90 à 100
        {
            if (nombre == 71)
                return "soixante et onze ";
            return joindre("", dizaine, uniteDixADixNeuf);
        }
        if (nombre % 10 == 1 && !(80 < nombre && nombre < 90))
            return joindre("et ", dizaine, unite);
        return joindre("", dizaine, unite);
    }
}

int accordCent(int entier)
{
    return entier > 100 && entier % 100 == 0 ? 1 : 0;
}

char* traitementCentaine(int nombre, int imax, int i)
{
    /*Déclaration des variables*/
    char* centaineLettre;
    char* dizaineLettre;
    int centaine = (int)nombre / 100;
    int dizaine = (int)nombre % 100;
    char* cent;

    /*****************CODE****************/
    // Traitement centaine
    switch (centaine)
    {
        case 0: // 000 => 
            centaineLettre = "";
            break;
        case 1: // 100 => cent
            centaineLettre = "cent ";
            break;
        default: // 200, 300, ... => deux cent, trois cent, ... cent
            if(accordCent(nombre) && i == 0)
                centaineLettre = joindre("", tableauUnite[centaine], "cents ");
            else
                centaineLettre = joindre("", tableauUnite[centaine], "cent ");
            break;
    }
   
    centaineLettre = joindre("", centaineLettre, traitementDizaine(dizaine));

    return centaineLettre;
}

char* traitementNombre (double nombre)
{
    /*Déclaration des variables*/
    int partieEntiere;
    double partieDecimale;
    int* tabNombreATraiter;
    int i_max;
    char* motsJoint = ""; //VS aime pas quand on peut utiliser une var sans qu'elle soit initialisé (Si partieEntiere = 0)
    char* nombreEnMots;
    char* quantifieur;
    
    /*****************CODE****************/
    partieEntiere = nombre;
    partieDecimale = nombre - partieEntiere;

    // Traitement euro
    tabNombreATraiter = separer(partieEntiere, 3, &i_max);
    if (partieEntiere > 0) {
        for (int i = 0; i < i_max; i++) // {15} {248} {188} => quinze millions ....
        {
            nombreEnMots = traitementCentaine(tabNombreATraiter[i], i_max, i); // {15}
            quantifieur = tabNombreATraiter[i] < 100 ? quantifieurSingulier[i] : quantifieurPluriel[i]; // millions

            // {nombreEnMots} {quantifieur} {motsJoint}
            nombreEnMots = joindre("", nombreEnMots, quantifieur);
            motsJoint = joindre("", nombreEnMots, motsJoint);
        }
        motsJoint = joindre("", motsJoint, "euros");
    }
   

    // Traitement centime
    
    if (partieDecimale > 0)
    {
        nombreEnMots = traitementDizaine(partieDecimale * 100);
        // {motsJoint} et {nombreEnMots} centimes
        char* separateur = partieEntiere == 0 ? "" : "et ";
        motsJoint = joindre(separateur , motsJoint, nombreEnMots);
        motsJoint = joindre("", motsJoint, "centimes");
    }

    return motsJoint;
}




