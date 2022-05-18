#include <iostream>
using namespace std;

template <class A, class B>    //clasa template pentru a afisa care bautura are concentratia de alcool mai mare
class Concentartie_Alcoolica {
private:
    A bautura1;
    B bautura2;
public:
    Concentartie_Alcoolica(A bautura1, B bautura2) : bautura1(bautura1), bautura2(bautura2) {}

    void concentratie_max()
    {
        if (bautura1 > bautura2)
            cout << "1 cu: " << bautura1 << "% ";
        else
            cout << "2 cu: " << bautura2 << "% ";
    }

};

enum Tipuri_Alcool {
    TA_Vodka, TA_Gin, TA_Rom
};

class Cocktail {
public:
    virtual void printCocktail() = 0;
    static Cocktail* Create(Tipuri_Alcool type);
};

class Cocktail_Vodka : public Cocktail {
public:
    void printCocktail() {
        cout << "Cocktail-ul cu vodka este Blue Lagoon" << '\n';
    }
};

class Cocktail_Gin : public Cocktail {
public:
    void printCocktail() {
        cout << "Cocktail-ul cu gin este Martini" << '\n';
    }
};

class Cocktail_Rom : public Cocktail {
public:
    void printCocktail() {
        cout << "Cocktail-ul cu rom este Mojito" << '\n';
    }
};

//Factory create method ca sa creez obiecte de diferite tipuri
Cocktail* Cocktail::Create(Tipuri_Alcool type) {
    if (type == TA_Vodka)
        return new Cocktail_Vodka();
    else if (type == TA_Gin)
        return new Cocktail_Gin();
    else if (type == TA_Rom)
        return new Cocktail_Rom();
    else return NULL;

}

class Alegere {  //imi atribuie un tip random de alcool pentru care sa afisez cocktailul
public:
    Alegere()
    {
        srand(time(0));
        Tipuri_Alcool type = Tipuri_Alcool(rand() % 3);
        cocktail = Cocktail::Create(type);
    }
    ~Alegere()
    {
        if (cocktail)
        {
            delete[] cocktail;
            cocktail = NULL;
        }
    }
    Cocktail* get_Cocktail() {
        return cocktail;
    }

private:
    Cocktail* cocktail;
};


int main()
{
    Concentartie_Alcoolica<float, float> set1(44.9, 45.3);
    cout << "concentratia maxima o are bautura ";
    set1.concentratie_max();  //exemplu clasa template
    cout << '\n';

    Alegere* alegere = new Alegere();
    Cocktail* cocktail = alegere->get_Cocktail();
    cocktail->printCocktail();
    return 0;
}
