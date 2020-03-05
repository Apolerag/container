#pragma once

typedef struct _Noeud
{
	int valeur;
	//la valeur de filsGauche est sup�rieur � valeur
	// la valeur de filsDroit est inf�rieur � valeur
	_Noeud* filsGauche;
	_Noeud* filsDroit;
} Noeud;

class Arbre
{
private:
	Noeud* racine;

	Noeud* nouveauNoeud(const int v);
public:
	Arbre();
	~Arbre();

	void addNeud(const int v);
};

