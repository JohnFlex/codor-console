#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

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
{https://drive.google.com/drive/folders/1tLULqaErL_ReYMi5eKoIfLC9rRtUj1W9?usp=sharing
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
    return messageDecode;
}

string traduction(string message)
{
    string finale("e");
    int deco(0);
    char TAM('e');
    int longueur(message.size());
    int compt(0);
    char extracteur('e');
    int ij(0);
    string moyenne("e");
    for(compt=0;compt<longueur;compt++)
    {
        ij=compt;
        moyenne.clear();
        do
        {
            extracteur = message[ij];
            ij++;
            if (extracteur!=' ')
                moyenne = moyenne+extracteur;
            //cout << extracteur<< "   " << moyenne << endl;
        }while(extracteur!=' ');
        if(deco==0)
        {
            if(moyenne==".-")
                TAM ='a';
            else if(moyenne=="-...")
                TAM ='b';
            else if(moyenne=="-.-.")
                TAM ='c';
            else if(moyenne=="-..")
                TAM ='d';
            else if(moyenne==".")
                TAM ='e';
            else if(moyenne=="..-.")
                TAM ='f';
            else if(moyenne=="--.")
                TAM ='g';
            else if(moyenne=="....")
                TAM ='h';
            else if(moyenne=="..")
                TAM ='i';
            else if(moyenne==".---")
                TAM ='j';
            else if(moyenne=="-.-")
                TAM ='k';
            else if(moyenne==".-..")
                TAM ='l';
            else if(moyenne=="--")
                TAM ='m';
            else if(moyenne=="-.")
                TAM ='n';
            else if(moyenne=="---")
                TAM ='o';
            else if(moyenne==".--.")
                TAM ='p';
            else if(moyenne=="--.-")
                TAM ='q';
            else if(moyenne==".-.")
                TAM ='r';
            else if(moyenne=="...")
                TAM ='s';
            else if(moyenne=="-")
                TAM ='t';
            else if(moyenne=="..-")
                TAM ='u';
            else if(moyenne=="...-")
                TAM ='v';
            else if(moyenne==".--")
                TAM ='w';
            else if(moyenne=="-..-")
                TAM ='x';
            else if(moyenne=="-.--")
                TAM ='y';
            else if(moyenne=="--..")
                TAM ='z';
            else if(moyenne=="/")
                TAM =' ';
            finale=finale+TAM;
            deco=ij-compt;
        }
        else
            deco--;
    }
    return finale;
}

int main()
{
    string message(" ");
    srand(time(NULL));
    int deco(1);
    cout << "Choisissez la fonction" << endl << "1 : Encodage" << endl << "2 : Decodage" << endl;
    cin >> deco;
    cout << "Entrez votre message" << endl;
    cin.ignore();
    getline(cin, message);
    cout << "Message de base : " << message << endl;
    if (deco==1)
    {
        string messageaMORSe(aMORSage(message));
        string messagechiffre(chiffrage(messageaMORSe));
        cout << "Resultat traduit : DEBUT " << messagechiffre << " FIN" <<endl;
    }
    else if (deco==2)
    {
        string messageCode(decodage(message));
        cout << "Message Code : " << messageCode << endl;
        string messageTraduit(traduction(messageCode));
        cout << "Resultat traduit : DEBUT " << messageTraduit << " FIN" <<endl;
    }


    cout << "Tapez false pour terminer le programme" << endl;
    bool attF(false);
    cin >> attF;
    return 0;
}
