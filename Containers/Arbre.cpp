#include<stdlib.h>
#include <iostream>

#include "arbre.h"

template<class T>
typename Arbre<T>::Noeud* Arbre<T>::nouveauNoeud(const T& v)
{
    return new Noeud(v);
}

template<typename  T>
void Arbre<T>::libererMemoire(Noeud* n)
{
    if (n != NULL)
    {
        libererMemoire(n->getFilsGauche());
        libererMemoire(n->getFilsDroit());
        delete n;
        n = NULL;
    }
}

template<typename T>
typename Arbre<T>::Noeud* Arbre<T>::trouveValeur(const T& v)
{
    Noeud* n = racine;
    while (n != NULL)
    {
        if (n->getValeur() == v)
        {
            break;
        }
        else n = (v > n->getValeur()) ? n->getFilsDroit() : n->getFilsGauche();
    }

    return n;
}

template<class T>
void Arbre<T>::placer(Noeud* n)
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
            if (courant->getValeur() <= n->getValeur())
            {
                courant = courant->getFilsDroit();
            }
            else
            {
                courant = courant->getFilsGauche();
            }
        }

        if (precedent->getValeur() <= n->getValeur())
        {
            precedent->setFilsDroit(n);
        }
        else
        {
            precedent->setFilsGauche(n);
        }
    }
}

template<typename T>
Arbre<T>::Arbre() :racine(NULL)
{
}

template<typename T>
Arbre<T>::~Arbre()
{
    libererMemoire(racine);
}

template<class T>
void Arbre<T>::ajouterNoeud(const T& v)
{
    Noeud* nouveau = nouveauNoeud(v);

    placer(nouveau);
}

template<typename T>
bool Arbre<T>::valeurDansArbre(const T& v)
{
    return (trouveValeur(v) != NULL) ? true : false;
}

template<typename T>
void Arbre<T>::supprimeValeur(const T& v)
{
    Noeud* n = trouveValeur(v);
    Noeud* fg = NULL;
    Noeud* fd = NULL;
    Noeud* t = NULL;

    if (n != NULL)
    {
        // on recupere les fils
        fg = n->getFilsGauche();
        fd = n->getFilsDroit();


        if (fg == NULL && fd == NULL)
        {
            delete n;
            n = NULL;
        }
        else if (fg == NULL)
        {
            t = n->getFilsDroit();
            n = t;
            delete t;
        }
        else
        {
            t = n->getFilsGauche();
            n = t;
            delete t;
            // on replace le fils droit s'il existe
            if (fd != NULL)
            {
                placer(fd);
            }
        }

    }
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const Arbre<T>& arbre)
{
    //arbre.afficher(out);
    return out;
}
