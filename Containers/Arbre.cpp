#include<stdlib.h>
#include <iostream>

#include "arbre.h"

Noeud* Arbre::nouveauNoeud(const int v)
{
    Noeud* n = new Noeud;
    n->valeur = v;
    n->filsDroit = NULL;
    n->filsGauche = NULL;
    return n;
}

void Arbre::afficher(Noeud* noeud)
{
    if (noeud->filsGauche) afficher(noeud->filsGauche);
    std::cout << noeud->valeur << std::endl;
    if (noeud->filsDroit) afficher(noeud->filsDroit);
}

void Arbre::libererMemoire(Noeud* n)
{
    if (n != NULL)
    {
        libererMemoire(n->filsGauche);
        libererMemoire(n->filsDroit);
        delete n;
        n = NULL;
    }
}

Noeud* Arbre::trouveValeur(const int v)
{
    Noeud* n = racine;
    while (n != NULL)
    {
        if (n->valeur == v)
        {
            break;
        }
        else n = (v > n->valeur) ? n->filsDroit : n->filsGauche;
    }

    return n;
}

Arbre::Arbre() :racine(NULL)
{
}

Arbre::~Arbre()
{
    libererMemoire(racine);
}

void Arbre::ajouterNoeud(const int v)
{
    Noeud* courant = racine;
    Noeud* precedent = NULL;
    Noeud* nouveau = nouveauNoeud(v);

    if (racine == NULL)
    {
        racine = nouveau;
    }
    else
    {
        while (courant != NULL)
        {
            precedent = courant;
            if (courant->valeur <= v)
            {
                courant = courant->filsDroit;
            }
            else
            {
                courant = courant->filsGauche;
            }
        }

        if (precedent->valeur <= v)
        {
            precedent->filsDroit = nouveau;
        }
        else
        {
            precedent->filsGauche = nouveau;
        }
    }
}

void Arbre::afficher()
{
    afficher(racine);
}

bool Arbre::valeurDansArbre(const int v)
{
    //bool resultat = false;
    //Noeud* n = trouveValeur(v);

    return (trouveValeur(v)!=NULL)?true:false;
}

void Arbre::supprimeValeur(const int v)
{

}
