#pragma once

typedef struct _Noeud
{
    int valeur;
    //la valeur de filsGauche est inférieur à valeur
    // la valeur de filsDroit est supérieur à valeur
    _Noeud* filsGauche;
    _Noeud* filsDroit;
} Noeud;

class Arbre
{
private:
    Noeud* racine;

    Noeud* nouveauNoeud(const int v);
    void afficher(Noeud* racine);
    void libererMemoire(Noeud* n);
    Noeud* trouveValeur(const int v);
    void placer(Noeud* n);
public:
    Arbre();
    ~Arbre();

    void ajouterNoeud(const int v);
    void afficher();
    bool valeurDansArbre(const int v);
    void supprimeValeur(const int v);
};

