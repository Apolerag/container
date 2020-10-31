// ConsoleApplication2.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <stack>

#include <iostream>
#include <time.h>
#include <Arbre.cpp>
#include <flask.h>

#define RANDINT(A,B)(rand ()%(B-A)+A)
#define MINVAL 0
#define MAXVAL 12

using namespace std;

template<typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        out << v[i] << " ";
    }
    out << std::endl;

    return out;
}
int main()
{
    srand(time(NULL)); // initialisation de rand
   /* std::cout << "Hello World!\n";
    Arbre<int> a;
    Arbre<int> b;

    a += 11;
    a += 6;
    a.ajouterNoeud(7);

    b = a;
    //b += 4;
    //b += 8;
    //a.ajouterNoeud(3);
    //b.ajouterNoeud(1);
    //b.ajouterNoeud(2);
    //b.ajouterNoeud(13);
    //a.ajouterNoeud(5);
    //std::cout << "a " << a << std::endl;
    //std::cout << "b " << b << std::endl;

    //a += b;  //problème si activé et 
   // std::cout << "a " << a << std::endl;
    //a -= 7; // si activé

    //std::cout << "a " << a << std::endl;
  //  std::cout << "a " << a << std::endl;
 //   std::cout << "b " << b << std::endl;
  //  b = a;
    std::cout << "a : " << a << std::endl;
    std::cout << "b : " << b << std::endl;

    Arbre<int> c(a + 100);
    std::cout << "c : " << c << std::endl;
    std::cout << "a + 100 : " << a + 100 << std::endl;
    b = a + 1052;
    std::cout << "b : " << b << std::endl;
    c = b - 1052;
    std::cout << "c : " << c << std::endl;
    a.vider();
    b.vider();
    c.vider();*/

    /*
    std::stack<int> s;
    cout << s.empty() << endl;
    s.push(50);
    s.push(30);
    s.push(20);
    s.push(10);

    cout << s.empty() << endl;
    cout << s.size() << endl;
    cout << s.top() << endl;
    cout << s.size() << endl;
    s.pop();
    cout << s.size() << endl;*/


    flask<int> f(4);
    cout << "full " << f.full() << endl;
    f.push(10);
    f.push(20);
    f.push(30);
    f.push(40);
    cout << "empty " << f.empty() << endl;
    cout << "full " << f.full() << endl;
    cout << "size " << f.size() << endl;
    cout << "full " << f.top() << endl;
    cout << "size " << f.size() << endl;
    f.pop();
    cout << "size " << f.size() << endl;

    _CrtDumpMemoryLeaks();
    return EXIT_SUCCESS;
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
