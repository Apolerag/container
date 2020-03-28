#pragma once

template <class T>
class Arbre
{
private:
    class Noeud
    {
        T valeur;
        // la valeur de filsGauche est inférieur à valeur
        // la valeur de filsDroit est supérieur à valeur
        Noeud* filsGauche;
        Noeud* filsDroit;

    public:
        Noeud() :valeur(0), filsGauche(NULL), filsDroit(NULL)
        {}
        Noeud(Noeud* n)
        {
            valeur = n->valeur;
            filsGauche = new Noeud(n->filsGauche);
            filsDroit = new Noeud(n->filsDroit);
        }
        Noeud(const T& v, Noeud* fg, Noeud* fd) :valeur(v)
        {
            filsGauche = new Noeud(fg);
            filsDroit = new Noeud(fd);
        }
        Noeud(const T& v) :valeur(v), filsGauche(NULL), filsDroit(NULL)
        {}
        T& getValeur()
        {
            return valeur;
        }
        const T& getValeur() const
        {
            return valeur;
        }
        Noeud* getFilsGauche()
        {
            return filsGauche;
        }
        const Noeud* getFilsGauche() const
        {
            return filsGauche;
        }
        Noeud* getFilsDroit()
        {
            return filsDroit;
        }
        const Noeud* getFilsDroit() const
        {
            return filsDroit;
        }

        void setFilsGauche(Noeud* n)
        {
            filsGauche = n;
        }

        void setFilsDroit(Noeud* n)
        {
            filsDroit = n;
        }

        Noeud& operator=(Noeud* n)
        {
            if (this == NULL)
            {
                *this = new Noeud(n);
            }
            else
            {
                valeur = n->getValeur();
                filsGauche = n->getFilsGauche();
                filsDroit = n->getFilsDroit();
            }
            return *this;
        }
    } *racine;

    Noeud* nouveauNoeud(const T& v);
    void libererMemoire(Noeud* n);
    Noeud* trouveValeur(const T& v);
    void placer(Noeud* n);
public:
    Arbre();
    ~Arbre();

    Noeud* getRacine()
    {
        return racine;
    }
    const Noeud* getRacine() const
    {
        return racine;
    }

    void ajouterNoeud(const T& v);
    bool valeurDansArbre(const T& v);
    void supprimeValeur(const T& v);

    template<typename T>
    friend std::ostream& operator<<(std::ostream& out, const Arbre<T>& arbre);
};


