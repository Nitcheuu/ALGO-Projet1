#include "Utilitaire.h"

char* tableauUnite[10] = {"", "un", "deux", "trois", "quatre", "cinq", "six", "sept", "huit", "neuf" };
char* tableauDizaine[9] = { "dix", "vingt", "trente",  "quarante", "cinquante", "soixante", "soixante", "quatre vingt", "quatre vingt" };
char* tableauDixADixNeuf[10] = { "dix", "onze", "douze", "treize", "quatorze", "quinze", "seize", "dix sept", "dix huit", "dix neuf" };
char* quantifieurSingulier[4] = {"", "mille", "million", "milliard"};
char* quantifieurPluriel[4] = {"", "mille", "millions", "milliards"};

char* traitementNombre (int nombre){
    /*Déclaration des variables*/
    int partieEntiere;
    int partieDecimale;
    int compteur;
    int* tabnombreATraiter;
    char* mots;
    int i_max;

    /*Déclaration des tableaux*/
    
    char* groupe3;

    /*****************CODE****************/
    partieEntiere = nombre;
    partieDecimale = nombre - partieEntiere * 100;
    tabnombreATraiter = separer(partieEntiere, 3, &i_max);

    for(int i = 0; i<i_max; i++){
        groupe3 = TraitementCentaine(tabnombreATraiter[i]);
        quantifieur = groupe3 == 1 ? quantifieurSingulier[i] : quantifieurPluriel[i];
        mots = joindre(" ", mots, joindre(" ", centième, quantifieur));
    }

    mots = joindre(" ", mots, "euros");

    return mots
}

char* traitementCentaine(int nombre){
    /*Déclaration des variables*/
    char* centaineLettre;
    int centaine = (int)nombre / 100;
    int dizaine = (int)nombre % 100;

    /*****************CODE****************/
    if (centaine > 1)
        centaineLettre = joindre(" ", traitementUnite(centaine), accordCent(dizaine));
    else
        centaineLettre = accordCent(dizaine);
    centaineLettre = joindre(" ", centaineLettre, traitementDizaine(dizaine));

    return centaineLettre;
}

char* accordCent(int dizaine)
{
    return dizaine > 0 ? "cent" : "cents";
}

/*char* traitementDizaine(int nombre) {
    /*Déclaration des variables*//*
    char* dizaine;

    /*****************CODE****************//*
    if(nombre < 20 && nombre > 9){
        dizaine = tableauDixADixNeuf[nombre%10];
    }else{
        if((nombre >= 20 && nombre < 100) && ((nombre > 69 && nombre < 80) || (nombre > 89 && nombre < 100))){
            dizaine = casParticulier(nombre);
        }else{
            dizaine = casGeneral(nombre);
        }
    }
    return dizaine;
}*/

char* traitementDizaine(int nombre){
    /*Déclaration des variables*/
    char* dizaine = tableauDizaine[nombre / 10 - 1];
    char* unite = traitementUnite(nombre % 10);
    char* uniteDixADixNeuf = tableauDixADixNeuf[nombre % 10];

    /*****************CODE****************/
    if(nombre < 20 && nombre > 9)
        return tableauDixADixNeuf[nombre%10];
    else
    {
        if ((nombre >= 20 && nombre < 100) && ((nombre > 69 && nombre < 80) || (nombre > 89 && nombre < 100)))
        {
            if (nombre == 71)
                return "soixante et onze";
            return joindre(" ", dizaine, uniteDixADixNeuf);
        }
        if (nombre % 10 == 1 && !(80 < nombre && nombre < 90))
            return joindre(" et ", dizaine, unite);
        return joindre(" ", dizaine, unite);
    }
}

/*char* casGeneral(int nombre) // 21 (vingt et un), ..., 81 (quatre-vingt un), ...
{
    char* dizaine = tableauDizaine[nombre / 10 - 1];
    char* unite = traitementUnite(nombre % 10);

    if (nombre % 10 == 1 && !(80 < nombre && nombre < 90))
        return joindre(" et ", dizaine, unite);

    return joindre(" ", dizaine, unite);
}


char* casParticulier(int nombre) // 71 (soixante et onze), ..., 81 (quatre-vingt un), 91 (quatre-vingt onze)
{
    char* dizaine = tableauDizaine[nombre / 10 - 1];
    char* unite = tableauDixADixNeuf[nombre % 10];

    if(nombre == 71)
        return "soixante et onze";

    return joindre(" ", dizaine, unite);
}*/


char* traitementUnite(int unite) {
    return tableauUnite[unite];
}

