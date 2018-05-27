#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <cstdlib>
#include <chrono>
#include <thread>

using namespace std;


string chiffrage(string chaindentr)
{
    string chainEntree(chaindentr);
    string chainSortie("");
    string const chPer("02468");
    string const chImp("13579");
    int longeurChaine(1);
    int compteur(0);
    longeurChaine =chainEntree.size();
    int randomeur(0);
    char temporiseur(' ');
    char secRandomeur(' ');
    for (compteur = 0 ; compteur < longeurChaine ; compteur++)
    {
        //cout << compteur << " : Test" << endl;
        temporiseur = chainEntree[compteur];
        //cout << temporiseur << endl;
        randomeur= rand()% 5;
        if(temporiseur=='.')
            secRandomeur = chPer[randomeur];
        else if(temporiseur=='-')
            secRandomeur = chImp[randomeur];
        else
            secRandomeur = temporiseur;
        chainSortie = chainSortie+secRandomeur;
    }
    cout << "Chiffrage termine" << endl;
    return chainSortie;
}

string aMORSage(string message)
{
    char lae(' ');
    int tailleChaine(message.size()), i(0);
    string chaineaMorsee(" "), lame(" ");
    for (i = 0; i < tailleChaine ; i++)
    {
        lae=message[i];
        if(lae=='a')
            lame=".-";
        else if(lae=='b')
            lame="-...";
        else if(lae=='c')
            lame="-.-.";
        else if(lae=='d')
            lame="-..";
        else if(lae=='e')
            lame=".";
        else if(lae=='f')
            lame="..-.";
        else if(lae=='g')
            lame="--.";
        else if(lae=='h')
            lame="....";
        else if(lae=='i')
            lame="..";
        else if(lae=='j')
            lame=".---";
        else if(lae=='k')
            lame="-.-";
        else if(lae=='l')
            lame=".-..";
        else if(lae=='m')
            lame="--";
        else if(lae=='n')
            lame="-.";
        else if(lae=='o')
            lame="---";
        else if(lae=='p')
            lame=".--.";
        else if(lae=='q')
            lame="--.-";
        else if(lae=='r')
            lame=".-.";
        else if(lae=='s')
            lame="...";
        else if(lae=='t')
            lame="-";
        else if(lae=='u')
            lame="..-";
        else if(lae=='v')
            lame="...-";
        else if(lae=='w')
            lame=".--";
        else if(lae=='x')
            lame="-..-";
        else if(lae=='y')
            lame="-.--";
        else if(lae=='z')
            lame="--..";
        else if(lae==' ')
            lame="/";
        else
            lame=lae;
        chaineaMorsee = chaineaMorsee+ lame+ ' ';
    }
    cout << "aMORSage termine" << endl;
    chaineaMorsee = chaineaMorsee + "/";
    return chaineaMorsee;
}

string decodage(string message)
{
    char deTraducteur(' ');
    int longueurMessage(message.size()), i(0);
    string messageDecode(" ");
    for(i=0; i<longueurMessage; i++)
    {
        deTraducteur=message[i];
        if (deTraducteur=='1'||deTraducteur=='3'||deTraducteur=='5'||deTraducteur=='7'||deTraducteur=='9')
        {
            messageDecode = messageDecode+'-';
        }
        else if (deTraducteur=='0'||deTraducteur=='2'||deTraducteur=='4'||deTraducteur=='6'||deTraducteur=='8')
        {
            messageDecode = messageDecode+'.';
        }
        else
        {
            messageDecode = messageDecode+deTraducteur;
        }
    }
    cout << "Message Decode" << endl;
    return messageDecode;
}

string traduction(string message)
{
    string finale("");
    char TAM(' ');
    int longueur(message.size());
    int compt(0);
    char extracteur(' ');
    string moyenne("e");
    for(compt=0;(compt<longueur);compt++)
    {
        extracteur = message[compt];
        if (extracteur!=' ') {
            moyenne = moyenne+extracteur;
        } else {

            if(moyenne==".-")
                TAM ='A';
            else if(moyenne=="-...")
                TAM ='B';
            else if(moyenne=="-.-.")
                TAM ='C';
            else if(moyenne=="-..")
                TAM ='D';
            else if(moyenne==".")
                TAM ='E';
            else if(moyenne=="..-.")
                TAM ='F';
            else if(moyenne=="--.")
                TAM ='G';
            else if(moyenne=="....")
                TAM ='H';
            else if(moyenne=="..")
                TAM ='I';
            else if(moyenne==".---")
                TAM ='J';
            else if(moyenne=="-.-")
                TAM ='K';
            else if(moyenne==".-..")
                TAM ='L';
            else if(moyenne=="--")
                TAM ='M';
            else if(moyenne=="-.")
                TAM ='N';
            else if(moyenne=="---")
                TAM ='O';
            else if(moyenne==".--.")
                TAM ='P';
            else if(moyenne=="--.-")
                TAM ='Q';
            else if(moyenne==".-.")
                TAM ='R';
            else if(moyenne=="...")
                TAM ='S';
            else if(moyenne=="-")
                TAM ='T';
            else if(moyenne=="..-")
                TAM ='U';
            else if(moyenne=="...-")
                TAM ='V';
            else if(moyenne==".--")
                TAM ='W';
            else if(moyenne=="-..-")
                TAM ='X';
            else if(moyenne=="-.--")
                TAM ='Y';
            else if(moyenne=="--..")
                TAM ='Z';
            else if(moyenne=="/")
                TAM =' ';

            finale=finale+TAM;
            moyenne = "";
        }

    }
    return finale;
}

int init(int zero)
{
    string message("");
    srand(time(NULL));
    int deco(1);
    cout << "Choisissez la fonction" << endl << "1 : Encodage" << endl << "2 : Decodage" << endl << "3 : Fermer le programme" << endl;
    cin >> deco;
    if  (deco!=3)
    {
        cout << "Entrez votre message" << endl;
        cin.ignore();
        getline(cin, message);
        cout << "Message de base : " << message << endl;
    }
    if (deco==1)
    {
        string messageaMORSe(aMORSage(message));
        string messagechiffre(chiffrage(messageaMORSe));
        cout << "Resultat traduit :" <<endl<< "DEBUT" <<endl<<endl << messagechiffre << endl <<endl<<"FIN" <<endl;
        init(0);
    }
    else if (deco==2)
    {
        string messageCode(decodage(message));
        string messageTraduit(traduction(messageCode));
        cout << "Resultat traduit : DEBUT " << endl << endl<< messageTraduit << endl<<endl<<" FIN" <<endl;
        init(0);
    }
    else
    {
        cout << "Fermeture du programme..." << endl ;
        std::this_thread::sleep_for (std::chrono::milliseconds(1250));
    }
    return(zero);
}



int main()
{
    int ru(init(0));
    return 0;
}
