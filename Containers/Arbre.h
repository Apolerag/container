#pragma once

template<class T>
class Noeud
{
    T valeur;
    // la valeur de filsGauche est inférieur à valeur
    // la valeur de filsDroit est supérieur à valeur
    Noeud<T>* filsGauche;
    Noeud<T>* filsDroit;

public:
    Noeud() :valeur(0), filsGauche(NULL), filsDroit(NULL)
    {}
    Noeud(Noeud<T>* n)
    {
        valeur = n->valeur;
        filsGauche = new Noeud(n->filsGauche);
        filsDroit = new Noeud(n->filsDroit);
    }
    Noeud(const T& v, Noeud<T>* fg, Noeud<T>* fd) :valeur(v)
    {
        filsGauche = new Noeud(fg);
        filsDroit = new Noeud(fd);
    }
    Noeud(const T& v) :valeur(v), filsGauche(NULL), filsDroit(NULL)
    {}
    ~Noeud()
    {
        delete filsGauche;
        filsGauche = NULL;
        delete filsDroit;
        filsDroit = NULL;
    }
    T& getValeur()
    {
        return valeur;
    }
    const T& getValeur() const
    {
        return valeur;
    }
    Noeud<T>* getFilsGauche()
    {
        return filsGauche;
    }
    const Noeud<T>* getFilsGauche() const
    {
        return filsGauche;
    }
    Noeud<T>* getFilsDroit()
    {
        return filsDroit;
    }
    const Noeud<T>* getFilsDroit() const
    {
        return filsDroit;
    }

    void setFilsGauche(Noeud<T>* n)
    {
        filsGauche = n;
    }

    void setFilsDroit(Noeud<T>* n)
    {
        filsDroit = n;
    }

    Noeud<T>& operator=(Noeud<T>* n)
    {
        if (this == NULL)
        {
            *this = new Noeud<T>(n);
        }
        else
        {
            valeur = n->getValeur();
            filsGauche = n->getFilsGauche();
            filsDroit = n->getFilsDroit();
        }
        return *this;
    }
};

template <class T>
class Arbre
{
private:
    Noeud<T> *racine;

    //fonction interne
    Noeud<T>* nouveauNoeud(const T& v);
    Noeud<T>* trouveValeur(const T& v);
    void placer(Noeud<T>* n);
    void afficher(std::ostream& out, Noeud<T>* n) const;
    void copie(Arbre<T>& a, const Noeud<T>*n) const;
public:
    Arbre();
    Arbre(const Arbre<T> & a);
    ~Arbre();
    void vider();

    Noeud<T>* getRacine()
    {
        return racine;
    }
    const Noeud<T>* getRacine() const
    {
        return racine;
    }

    void ajouterNoeud(const T& v);
    bool valeurDansArbre(const T& v);
    void supprimeValeur(const T& v);
    void arbreAVector(std::vector<T>& v) const ;

    Arbre<T>& operator=(const Arbre<T>& a);
    Arbre<T>& operator+=(const T& t);
    Arbre<T>& operator+=(const Arbre<T>& a);
    Arbre<T>& operator-=(const T& t);

    template<class T>
    friend std::ostream& operator<<(std::ostream& out, const Arbre<T>& arbre);
    template<class T>
    friend Arbre<T> operator+(const Arbre<T>& a, const Arbre<T>& b);
    template<class T>
    friend Arbre<T> operator+(const Arbre<T>& a, const T& t);
    template<class T>
    friend Arbre<T> operator-(const Arbre<T>& a, const T& t);
};


