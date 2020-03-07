#pragma once

typedef struct _Noeud
{
	int valeur;
	//la valeur de filsGauche est inf�rieur � valeur
	// la valeur de filsDroit est sup�rieur � valeur
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

