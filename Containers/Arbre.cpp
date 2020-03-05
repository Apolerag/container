#include<stdlib.h>

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

void Arbre::addNeud(const int v)
{
	Noeud* n = racine;
	while (n != NULL)
	{
		n = (n->valeur > v) ? n->filsGauche : n->filsDroit;
	}
	n = nouveauNoeud(v);
}
