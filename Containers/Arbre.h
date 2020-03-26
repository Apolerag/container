#pragma once

template <class T>
class Arbre
{
private:
    struct Noeud
    {
        T valeur;
        // la valeur de filsGauche est inf�rieur � valeur
        // la valeur de filsDroit est sup�rieur � valeur
        Noeud* filsGauche;
        Noeud* filsDroit;
    } * racine;

    Noeud* nouveauNoeud(const T& v);
    void afficher(Noeud* noeud);
    void libererMemoire(Noeud* n);
    Noeud* trouveValeur(const T& v);
    void placer(Noeud* n);
public:
    Arbre();
    ~Arbre();

    void ajouterNoeud(const T& v);
    void afficher();
    bool valeurDansArbre(const T& v);
    void supprimeValeur(const T& v);
};

