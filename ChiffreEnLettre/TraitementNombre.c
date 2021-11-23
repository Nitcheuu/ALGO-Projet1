#include <stdio.h>
#include "Utilitaire.h"
#include "TraitementNombre.h"

struct S_TDC {
    char* tableauUnite[10];
    char* tableauDizaine[9];
    char* tableauDixADixNeuf[10];
    char* quantifieurSingulier[4];
    char* quantifieurPluriel[4];
};

/// <summary>
/// VA : Permet d'intialiser le "vocabulaire"
/// </summary>
/// <returns>structure qui contient tous les tableaux</returns>

struct S_TDC initialisationTableaux() {
    struct S_TDC tc =
    {
        { "", "un ", "deux ", "trois ", "quatre ", "cinq ", "six ", "sept ", "huit ", "neuf " },
        { "dix ", "vingt ", "trente ",  "quarante ", "cinquante ", "soixante ", "soixante ", "quatre vingt ", "quatre vingt " },
        { "dix ", "onze ", "douze ", "treize ", "quatorze ", "quinze ", "seize ", "dix sept ", "dix huit ", "dix neuf " },
        { "", "mille ", "million ", "milliard " },
        { "",  "mille ", "millions ", "milliards " }
    };
    return tc;
}

/// <summary>
/// VA : Permet de connaitre la string d'une unité
/// </summary>
/// <param name="unite">unité</param>
/// <param name="tc">structure qui contient les tableaux</param>
/// <returns>string de l'unité</returns>
char* traitementUnite(int unite, struct S_TDC tc)
{
    return tc.tableauUnite[unite];
}

/// <summary>
/// VA : Permet de connaitre la string d'une dizaine
/// </summary>
/// <param name="nombre">dizaine</param>
/// <param name="tc">structure qui contient les tableaux</param>
/// <returns>string de l'unité</returns>
char* traitementDizaine(int nombre, struct S_TDC tc)
{
    /*Déclaration des variables*/
    char* dizaine = tc.tableauDizaine[nombre / 10 - 1];
    char* unite = traitementUnite(nombre % 10, tc);
    char* uniteDixADixNeuf = tc.tableauDixADixNeuf[nombre % 10];

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

/// <summary>
/// VA : Permet de savoir si le nombre à trois chiffres s'accorde ou non
/// </summary>
/// <param name="entier">Nombre à trois chiffres</param>
/// <returns>Booléen</returns>
int accordCent(int entier)
{
    return entier > 100 && entier % 100 == 0 ? 1 : 0;
}

/// <summary>
/// VA : Permet de connaitre la string d'une centaine
/// </summary>
/// <param name="nombre">centaine</param>
/// <param name="i">position de la centaine dans le chiffre (paquets de 3)</param>
/// <param name="tc">Structure qui contient l'ensemble des tableaux</param>
/// <returns>Chaine de caractères d'une centaine</returns>
char* traitementCentaine(int nombre, int i, struct S_TDC tc)
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
                centaineLettre = joindre("", tc.tableauUnite[centaine], "cents ");
            else
                centaineLettre = joindre("", tc.tableauUnite[centaine], "cent ");
            break;
    }
   
    centaineLettre = joindre("", centaineLettre, traitementDizaine(dizaine, tc));

    return centaineLettre;
}


/// <summary>
/// VA : Permet de gérer les centimes
/// </summary>
/// <param name="partieDecimale">5.24 -> 0.24</param>
/// <param name="partieEntiere">5.24 -> 5</param>
/// <param name="motsJoint">trente euros </param>
/// <param name="tc">structure qui contient tous les tableaux</param>
/// <returns></returns>
char* traitementCentime(double partieDecimale, int partieEntiere, char* motsJoint, struct S_TDC tc) {
    char* nombreEnMots;
    if (partieDecimale > 0)
    {
        nombreEnMots = traitementDizaine(partieDecimale * 100, tc);
        char* separateur = partieEntiere == 0 ? "" : "et ";
        motsJoint = joindre(separateur, motsJoint, nombreEnMots);
        motsJoint = joindre("", motsJoint, "centimes");
    }
    return motsJoint;
}

/// <summary>
/// Permet de connaitre la string d'un nombre
/// </summary>
/// <param name="nombre">Nombre entre 0 et 999 999 999 999</param>
/// <returns></returns>
char* traitementNombre (double nombre)
{
    /*Déclaration des variables*/
    long long int partieEntiere;
    double partieDecimale;
    int* tabNombreATraiter;
    int i_max;
    char* motsJoint = ""; //VS aime pas quand on peut utiliser une var sans qu'elle soit initialisé (Si partieEntiere = 0)
    char* nombreEnMots;
    char* quantifieur;
    struct S_TDC tc;
    
    /*****************CODE****************/
    tc = initialisationTableaux();

    partieEntiere = nombre;
    partieDecimale = nombre - partieEntiere;

    // Traitement euro
    tabNombreATraiter = separer(partieEntiere, 3, &i_max);
    if (partieEntiere > 0) {
        for (int i = 0; i < i_max; i++) // {15} {248} {188} => quinze millions ....
        {
            nombreEnMots = traitementCentaine(tabNombreATraiter[i], i, tc); // {15}
            quantifieur = tabNombreATraiter[i] < 100 ? tc.quantifieurSingulier[i] : tc.quantifieurPluriel[i]; // millions
            quantifieur = tabNombreATraiter[i] == 0 ? "" : quantifieur;
            nombreEnMots = joindre("", nombreEnMots, quantifieur);
            motsJoint = joindre("", nombreEnMots, motsJoint);
        }
        motsJoint = joindre("", motsJoint, "euros ");
    }
   

    // Traitement centime
    
    motsJoint = traitementCentime(partieDecimale, partieEntiere, motsJoint, tc);

    return motsJoint;
}




