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
    if (noeud->filsGauche != NULL) afficher(noeud->filsGauche);
    std::cout << noeud->valeur << std::endl;
    if (noeud->filsDroit != NULL) afficher(noeud->filsDroit);
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

void Arbre::placer(Noeud* n)
{
    Noeud* courant = racine;
    Noeud* precedent = NULL;
    if (racine == NULL)
    {
        racine = n;
    }
    else
    {
        while (courant != NULL)
        {
            precedent = courant;
            if (courant->valeur <= n->valeur)
            {
                courant = courant->filsDroit;
            }
            else
            {
                courant = courant->filsGauche;
            }
        }

        if (precedent->valeur <= n->valeur)
        {
            precedent->filsDroit = n;
        }
        else
        {
            precedent->filsGauche = n;
        }
    }
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
    Noeud* nouveau = nouveauNoeud(v);

    placer(nouveau);
}

void Arbre::afficher()
{
    afficher(racine);
}

bool Arbre::valeurDansArbre(const int v)
{
    return (trouveValeur(v) != NULL) ? true : false;
}

void Arbre::supprimeValeur(const int v)
{
    Noeud* n = trouveValeur(v);
    Noeud* fg = NULL;
    Noeud* fd = NULL;
    Noeud* t = NULL;

    if (n != NULL)
    {
        // on recupere les fils
        fg = n->filsGauche;
        fd = n->filsDroit;


        if (fg == NULL && fd == NULL)
        {
            delete n;
            n = NULL;
        }
        else if (fg == NULL)
        {
            t = n->filsDroit;
            n->valeur = t->valeur;
            n->filsDroit = t->filsDroit;
            n->filsGauche = t->filsGauche;
            delete t;
        }
        else
        {
            t = n->filsGauche;
            n->valeur = t->valeur;
            n->filsDroit = t->filsDroit;
            n->filsGauche = t->filsGauche;
            delete t;
            // on replace le fils droit s'il existe
            if (fd != NULL)
            {
                placer(fd);
            }
        }

    }
}
