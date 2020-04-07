#include<stdlib.h>
#include <iostream>
#include <vector>

#include "arbre.h"

template<class T>
Noeud<T>* Arbre<T>::nouveauNoeud(const T& v)
{
    return new Noeud<T>(v);
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
void Arbre<T>::afficher(std::ostream& out,  Noeud<T>* n) const
{
    if (n == NULL)
        return;

    if (n->getFilsGauche() != NULL)
    {
        afficher(out, n->getFilsGauche());
    }
    out << n->getValeur() << " ";
    if (n->getFilsDroit() != NULL)
    {
        afficher(out, n->getFilsDroit());
    }
}

template<class T>
void Arbre<T>::copie(Arbre<T>& a, const Noeud<T>*n) const
{
    if (a.racine == NULL)
    {
        delete a.racine;
        a.racine = NULL;
    }
    a.ajouterNoeud(n->getValeur());
    if (n->getFilsGauche() != NULL) copie(a, n->getFilsGauche());
    if (n->getFilsDroit() != NULL) copie(a, n->getFilsDroit());
}

template<class T>
Arbre<T>::Arbre() :racine(NULL)
{
}

template<class T>
Arbre<T>::Arbre(const Arbre<T>& a): racine(NULL)
{
    copie(*this, a.getRacine());
}

template<class T>
Arbre<T>::~Arbre()
{
    vider();
}

template<class T>
void Arbre<T>::vider()
{
    delete racine;
    racine = NULL;
}

template<class T>
void Arbre<T>::ajouterNoeud(const T& v)
{
    Noeud<T>* nouveau = nouveauNoeud(v);

    placer(nouveau);
}

template<class T>
bool Arbre<T>::valeurDansArbre(const T& v)
{
    return (trouveValeur(v) != NULL) ? true : false;
}

template<class T>
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

    // Si on supprime la racine
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
    n->setFilsDroit(NULL);
    //end if

    //Accrochage du fils du Noeud disparu 
    if (gauche) placer(gauche);

    //Enfin, on libère l'objet pNoeud de la mémoire
    delete n;
    n = NULL;

}

template<class T>
static void arbreAVectorNoeud(std::vector<T>& v, Noeud<T>* n)
{
    v.push_back(n->getValeur());
    if (n->getFilsGauche() != NULL)
    {
        arbreAVectorNoeud(v, n->getFilsGauche());
    }
    if (n->getFilsDroit() != NULL)
    {
        arbreAVectorNoeud(v, n->getFilsDroit());
    }
}

template<class T>
void Arbre<T>::arbreAVector(std::vector<T>& v) const
{
    arbreAVectorNoeud(v, racine);
}

template<class T>
Arbre<T>& Arbre<T>::operator=(const Arbre<T>& a)
{
    if (this->racine != NULL)
    {
        delete this->racine;
        this->racine = NULL;
    }
    copie(*this, a.getRacine());
    return *this;
}

template<class T>
Arbre<T>& Arbre<T>::operator+=(const T& t)
{
    ajouterNoeud(t);
    return *this;
}

template<class T>
Arbre<T>& Arbre<T>::operator+=(const Arbre<T>& a)
{
    std::vector<T> v;
    a.arbreAVector(v);
    for (int i = 0; i < v.size(); i++)
    {
        ajouterNoeud(v[i]);
    }
    return *this;
}

template<class T>
Arbre<T>& Arbre<T>::operator-=(const T& t)
{
    supprimeValeur(t);
    return *this;
}

template<class T>
std::ostream& operator<<(std::ostream& out, const Arbre<T>& arbre)
{
    arbre.afficher(out, arbre.racine);
    return out;
}

template<class T>
Arbre<T> operator+(const Arbre<T>& a, const Arbre<T>& b)
{
    Arbre<T> result(a);
    result += b;
    return result;
}

template<class T>
Arbre<T> operator+(const Arbre<T>& a, const T& t)
{
    //Arbre<T> result(a);
    //result += t;
    return Arbre<T>(a) += t;
}

template<class T>
Arbre<T> operator-(const Arbre<T>& a, const T& t)
{
    return Arbre<T>(a) -= t;
}

