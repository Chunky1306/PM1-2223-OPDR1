#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

const int jaar = 2022;
const int maand = 9;
const int dag = 26;
const int bjaar = 1901; //jaar om mee te beginnen voor berekening
const int bmaand = 1; // maand om mee te beginnen voor berekening
const int bdag = 1; // maand om mee te beginnen voor berekening
//nog even kijken naar r84

int main ( ) {
    int gebjaar;
    int gebmaand;
    int gebdag;
    int weekdag;
    cout << "Hallo gebruiker," << endl;


    cout << "Vul alsjeblieft je geboortejaar in als geheel getal." << endl;
    cin >> gebjaar;
    if (jaar - gebjaar > 101 ) {
        cout << "Helaas, u bent te oud." << endl;
        return 1;
    } //if
    if (gebjaar > jaar){
        cout << "Je bent een tijdreiziger." << endl;
        return 1;
    }//if
    if (jaar - gebjaar < 10) {
        cout << "Helaas, je bent te jong." << endl;
        return 1;
    } //if

    cout << "Dankjewel, vul dan nu je geboortemaand in, ook weer"
         << " als geheel getal." << endl;
    cin >> gebmaand;
    if (gebmaand > 12) {
        cout << "Deze maand bestaat niet." << endl;
        return 1;
    }//if
    if (gebjaar == 2012 && gebmaand > maand) {
        cout << "Je bent te jong." << endl;
        return 1;
    }//if
    if (gebjaar == 1921 && gebmaand > maand) {
        cout << "U bent te oud." << endl;
        return 1;
    }
    if (gebmaand == maand) {
        cout << "Gefeliciteerd met je verjaarmaand!" << endl;
    }//if

    int J = jaar - gebjaar;//aantal jaren
    int M = maand - gebmaand;//aantal maanden voor okt
    int O = maand - gebmaand + 12;//aantal maanden na sept
    int Tot = (jaar - gebjaar) * 12 + maand;//maanden totaal voor okt
    int Tol = (jaar - gebjaar -1) * 12 + maand;// maanden totaal na okt

    cout << "Weer bedankt! Zou je nu nog je geboortedag in kunnen vullen?"
         << " Ook graag weer als geheel getal." << endl;
    cin >> gebdag;
    if (gebjaar == 2012 && gebmaand == maand && gebdag > dag) {
        cout << "Je bent te jong." << endl;
        return 1;
    }//if
    if (gebjaar == 1921 && gebmaand == maand && gebdag > dag) {
        cout << "U bent te oud." << endl;
        return 1;
    }//if

    if (gebmaand == maand && gebdag == dag) {
        cout << "Gefeliciteerd met je verjaardag!" << endl;
    }//if

    if ((gebmaand == 4 || 6 || 9 || 11) && gebdag > 30) {
        cout << "Deze datum bestaat niet." << endl;
        return 1;
    }//if
    if ((gebmaand == 1 || 3 || 5 || 7 || 8 || 10 || 12) && gebdag > 31) {
        cout << "Deze datum bestaat niet." << endl;
        return 1;
    }//if
    if (gebmaand == 2 && ((gebdag > 28 && gebjaar % 4 != 0) ||
                          (gebdag < 29 && gebjaar % 4 == 0))) {
        cout << "Deze datum bestaat niet." << endl;
        return 1;
    }//if

    if (gebmaand > 8 && gebdag > dag || gebmaand > 9 && gebdag > 0) {
        cout << "Je bent " << J - 1 << " jaar en " << O
             << " maanden oud." << endl;
    }//if
    if (gebmaand < 10 && gebdag < 27 || gebmaand < maand) {
        cout << "Je bent " << J << " jaar en " << M << " maanden oud." << endl;
    }//if

    if (gebmaand < 10) {
        cout << "Oftewel " << Tot << " maanden." << endl;
    }//if
        else if (gebmaand > 9) {
            cout << "Oftewel " << Tol << " maanden." << endl;
        }//else if

    //cout << "Zou je nu de eerste letter van de dag van de week waarop je "
         //<< "geboren bent in kunnen voeren?" << endl;
    //cin >> weekdag;                         //01-01-1901 is een dinsdag



    //begin 2e deel van de test
    int aantalFouten = 0;
    bool oud = true;
    int tempOriginal;
    double tempInCelcius;
    double tempInFarenheit;
    if (J < 30){
        oud = false
    }
    if (!oud){
        cout << "Je hebt je geboortedag juist ingevuld. Je begint nu aan de "
        "rest van de test"<< endl;

    } else {
        cout << "U hebt uw geboortedag juist ingevuld. U begint nu aan de "
        "rest van de test"<<endl;

    }
    /*Initializes seed and returns random int betweem -40 and 120*/
    srand (time(NULL));
    tempOriginal = rand() % 160;
    tempOriginal = tempOriginal -40;

    tempInFarenheit = ((tempOriginal * 9) / 5) + 32;
    tempInCelcius = ((tempOriginal -32)*5)/9;

    cout << "Reken de volgende temperatuur om naar Fahrenheit." <<endl;
    cout << tempOriginal <<endl;
    //cout << tempInFarenheit <<endl;
    int fahrenheitInput;
    cin >> fahrenheitInput;
    if (abs(fahrenheitInput - tempInFarenheit) <= 1){
        cout << "Correct" <<endl;
    } else {
        cout << "Incorrect" <<endl;
        aantalFouten = aantalFouten + 1;
    }

    cout << "Reken de volgende temperatuur om naar Celcius." <<endl;
    cout << tempOriginal <<endl;
    //cout << tempInCelcius <<endl;
    int celciusInput;
    cin >> celciusInput;
    if (abs(celciusInput - tempInCelcius) <= 1){
        cout << "Correct" <<endl;
    } else {
        cout << "Incorrect" <<endl;
        aantalFouten = aantalFouten + 1;
    }

    if (aantalFouten < 2){
        if (oud){
            cout <<"U mag een betastudie gaan doen!" <<endl;
        } else{
            cout <<"Je mag een betastudie gaan doen!" <<endl;
        }
    } else {
        if (oud){
            cout <<"U heeft helaas te veel fouten gemaakt. "
            "U kunt nog in aanmerking komen voor een alphastudie." <<endl;

            cout <<"Hoeveel Emmys heeft TV-serie Better Call Saul gewonnen in "
            "2022?" <<endl;
            cout <<"a: 3" <<endl;
            cout <<"b: 0" <<endl;
            cout <<"c: 2" <<endl;
            cout <<"d: 1" <<endl;

        } else {
            cout <<"Je hebt helaas te veel fouten gemaakt. "
            "Je kunt nog in aanmerking komen voor een alphastudie." <<endl;

            cout <<"Hoeveel Emmys heeft TV-serie Better Call Saul gewonnen in "
            "2022?" <<endl;
            cout <<"a: 3" <<endl;
            cout <<"b: 0" <<endl;
            cout <<"c: 2" <<endl;
            cout <<"d: 1" <<endl;
        }

        char antwoord;
        cin >> antwoord;
        antwoord = tolower(antwoord);
        if (antwoord == 'b'){
            cout <<"Correct!" <<endl;
        } else cout <<"Incorrect!" <<endl;
    }

    return 0;
}//main
