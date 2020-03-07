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

Arbre::Arbre() :racine(NULL)
{
}

Arbre::~Arbre()
{

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
			if (courant->valeur < v)
			{
				courant = courant->filsDroit;
			}
			else
			{
				courant = courant->filsGauche;
			}
		}

		if (v < precedent->valeur)
			precedent->filsGauche = nouveau;
		else
			precedent->filsDroit = nouveau;
	}
}

void Arbre::afficher()
{
	afficher(racine);
}


void Arbre::afficher(Noeud* noeud)
{
	if (noeud->filsGauche) afficher(noeud->filsGauche);
	std::cout << noeud->valeur << std::endl;
	if (noeud->filsDroit) afficher(noeud->filsDroit);
}

bool Arbre::ValeurDansArbre(const int v)
{
	bool resultat = false;
	Noeud* n = racine;
	while (n != NULL)
	{
		if (n->valeur == v)
		{
			resultat = true;
			break;
		}
		else if(v > n->valeur)
		{
			n = n->filsDroit;
		}
		else
		{
			n = n->filsGauche;
		}
	}
	return resultat;
}