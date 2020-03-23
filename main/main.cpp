// ConsoleApplication2.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <Arbre.h>

#define RANDINT(A,B)(rand ()%(B-A)+A)
#define MINVAL 0
#define MAXVAL 12

int main()
{
    srand(time(NULL)); // initialisation de rand
    std::cout << "Hello World!\n";
    Arbre a;
    int i;
    for (i = 10; i > 0; i--)
    {
        int n = RANDINT(MINVAL, MAXVAL);
        std::cout << "n " << n << std::endl;
        a.ajouterNoeud(n);
    }

    a.afficher();
    std::cout << std::endl << a.valeurDansArbre(3) << " " << a.valeurDansArbre(12) << " " << a.valeurDansArbre(5) << std::endl;

    //i = 0;
    //while (a.valeurDansArbre(i) == false)
    //{
    //    i++;
    //}
    a.supprimeValeur(5);
    a.afficher();
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
