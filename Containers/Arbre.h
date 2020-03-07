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
public:
	Arbre();
	~Arbre();

	void ajouterNoeud(const int v);
	void afficher();
	bool ValeurDansArbre(const int v);
};

