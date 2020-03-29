#include<stdlib.h>
#include <iostream>

#include "arbre.h"

template<class T>
Noeud<T>* Arbre<T>::nouveauNoeud(const T& v)
{
    return new Noeud<T>(v);
}

template<typename  T>
void Arbre<T>::libererMemoire(Noeud<T>* n)
{
    if (n != NULL)
    {
        libererMemoire(n->getFilsGauche());
        libererMemoire(n->getFilsDroit());
        delete n;
        n = NULL;
    }
}

template<class T>
typename Noeud<T>* Arbre<T>::trouveValeur(const T& v)
{
    Noeud<T>* n = racine;
    while (n != NULL)
    {
        if (n->getValeur() == v)
        {
            break;
        }
        else
        {
            n = (v > n->getValeur()) ? n->getFilsDroit() : n->getFilsGauche();
        }
    }

    return n;
}

template<class T>
void Arbre<T>::placer(Noeud<T>* n)
{
    Noeud<T>* courant = racine;
    Noeud<T>* precedent = NULL;
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

template<class T>
void Arbre<T>::afficher(std::ostream& out, Noeud<T>* n) const
{
    if (n == NULL)
        return;

    if (n->getFilsGauche() != NULL)
    {
        afficher(out, n->getFilsGauche());
    }
    out << n->getValeur() << std::endl;
    if (n->getFilsDroit() != NULL)
    {
        afficher(out, n->getFilsDroit());
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
    Noeud<T>* nouveau = nouveauNoeud(v);

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
    Noeud<T>* n = trouveValeur(v);
    Noeud<T>* gauche = NULL;
    Noeud<T>* droit = NULL;
    Noeud<T>* courant = racine;

    // si pas trouvé
    if (n == NULL)
    {
        return;
    }
    // on recupere les fils
    gauche = n->getFilsGauche();
    droit = n->getFilsDroit();

    // on supprime la racine
    if (n == racine)
    {
        delete racine;
        racine = gauche;
        if (droit != NULL)
        {
            placer(droit);
        }
        return;
    }

    while (courant) {
        //Si une des branches de ce noeud est celle que l'on recherche, 
        //on sort de la boucle while 
        if (courant->getFilsDroit() == n || courant->getFilsGauche() == n) break;

        //Sinon, on continue
        if (n->getValeur() >= courant->getValeur())
            courant = courant->getFilsDroit();
        else
            courant = courant->getFilsGauche();
    }

    if (courant->getFilsDroit() == n)
        courant->setFilsDroit(droit);
    else
        courant->setFilsGauche(droit);
    //end if

    //Accrochage du fils du Noeud disparu 
    if (gauche) placer(gauche);

    //Enfin, on libère l'objet pNoeud de la mémoire
    delete n;

}

template<typename T>
std::ostream& operator<<(std::ostream& out, const Arbre<T>& arbre)
{
    arbre.afficher(out, arbre.racine);
    return out;
}
