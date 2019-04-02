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
    //BUT : Chiffer une chaine de caractères
    //ENTREE : Chaine de caractères en morse
    //SORTIE : Chaine de caractères chiffrée

    //Initialisation des variables
    string chainEntree(chaindentr), chainSortie("");
    string const chiffresPairs("02468");
    string const chiffresImpairs("13579");
    int longeurChaine(chainEntree.size()), randomeur(0);
    char temporiseur(' '), secRandomeur(' ');

    //Debut de l'encodage
    for (int compteur = 0 ; compteur < chainEntree.size() ; compteur++)
    {
        //Selection de la lettre du compteur
        temporiseur = chainEntree[compteur];
        //Sélection du chiffre;;
        randomeur= rand()% 5;
        //Selection du chiffre en fonction de pair ou impair, sinon on recopie la lettre
        if(temporiseur=='.')
            secRandomeur = chiffresPairs[randomeur];
        else if(temporiseur=='-')
            secRandomeur = chiffresImpairs[randomeur];
        else
            secRandomeur = temporiseur;
        //Rajout du chiffre a la chaine
        chainSortie = chainSortie+secRandomeur;
    }
    //Information sur la fin
    cout << "Chiffrage termine" << endl;

    return chainSortie;
}

string aMORSage(string message)
{
    //BUT : Encoder un message normal en morse
    //ENTREE : Phrase (String)
    //SORTIE : Message en morse (String)

    //Initialisation des variables
    char lettreDuMessage(' ');
    string chaineaMorsee(" "), lettreTraduite(" ");

    //Traduction de la lettre
    for (int i = 0; i < message.size() ; i++)
    {
        lettreDuMessage=message[i];
        if(lettreDuMessage=='a')
            lettreTraduite=".-";
        else if(lettreDuMessage=='b')
            lettreTraduite="-...";
        else if(lettreDuMessage=='c')
            lettreTraduite="-.-.";
        else if(lettreDuMessage=='d')
            lettreTraduite="-..";
        else if(lettreDuMessage=='e')
            lettreTraduite=".";
        else if(lettreDuMessage=='f')
            lettreTraduite="..-.";
        else if(lettreDuMessage=='g')
            lettreTraduite="--.";
        else if(lettreDuMessage=='h')
            lettreTraduite="....";
        else if(lettreDuMessage=='i')
            lettreTraduite="..";
        else if(lettreDuMessage=='j')
            lettreTraduite=".---";
        else if(lettreDuMessage=='k')
            lettreTraduite="-.-";
        else if(lettreDuMessage=='l')
            lettreTraduite=".-..";
        else if(lettreDuMessage=='m')
            lettreTraduite="--";
        else if(lettreDuMessage=='n')
            lettreTraduite="-.";
        else if(lettreDuMessage=='o')
            lettreTraduite="---";
        else if(lettreDuMessage=='p')
            lettreTraduite=".--.";
        else if(lettreDuMessage=='q')
            lettreTraduite="--.-";
        else if(lettreDuMessage=='r')
            lettreTraduite=".-.";
        else if(lettreDuMessage=='s')
            lettreTraduite="...";
        else if(lettreDuMessage=='t')
            lettreTraduite="-";
        else if(lettreDuMessage=='u')
            lettreTraduite="..-";
        else if(lettreDuMessage=='v')
            lettreTraduite="...-";
        else if(lettreDuMessage=='w')
            lettreTraduite=".--";
        else if(lettreDuMessage=='x')
            lettreTraduite="-..-";
        else if(lettreDuMessage=='y')
            lettreTraduite="-.--";
        else if(lettreDuMessage=='z')
            lettreTraduite="--..";
        else if(lettreDuMessage==' ')
            lettreTraduite="/";
        else
            lettreTraduite=lettreDuMessage;
        //Ajout de la lettre traduite au message
        chaineaMorsee = chaineaMorsee+ lettreTraduite+ ' ';
    }

    //Information de la fin du message
    cout << "aMORSage termine" << endl;
    //Ajout du / de fin
    chaineaMorsee = chaineaMorsee + "/";
    return chaineaMorsee;
}



string decodage(string message)
{
    //BUT : Traduire un string des chiffres en morse
    //ENTREE : String de chiffres
    //SORTIE : String en morse

    //Initialisationd de variables
    char chiffre(' ');
    string messageDecode(" ");

    //Decodage de chaque lettre
    for(int i=0; i<message.size(); i++)
    {
        //Recuperation de la lettre
        chiffre=message[i];

        //Transformation du chiffre en morse
        if (chiffre=='1'||chiffre=='3'||chiffre=='5'||chiffre=='7'||chiffre=='9')
        {
            messageDecode = messageDecode+'-';
        }
        else if (chiffre=='0'||chiffre=='2'||chiffre=='4'||chiffre=='6'||chiffre=='8')
        {
            messageDecode = messageDecode+'.';
        }
        else
        {
            messageDecode = messageDecode+chiffre;
        }
    }
    //Information de la fin
    cout << "Message Decode" << endl;
    return messageDecode;
}

string traduction(string message)
{
    //BUT : Traduire du morse en français
    //ENTREE : String en morse
    //SORTIE : String en humain

    //Initialisation des variables
    string messageARenvoyer(""), strIndermediaire("");
    char lettreTraduite(' '), extracteur(' ');

    //Extraction du message
    for(int compt=0;(compt<message.size());compt++)
    {
        //Recuperation du caractere en cours
        extracteur = message[compt];

        //Ajout du caractere suivant si =/= d'espace, sinon traduction de ce qui a
        //ete recupere
        if (extracteur!=' ') {
            strIndermediaire = strIndermediaire+extracteur;
        } else {

            if(strIndermediaire==".-")
                lettreTraduite ='A';
            else if(strIndermediaire=="-...")
                lettreTraduite ='B';
            else if(strIndermediaire=="-.-.")
                lettreTraduite ='C';
            else if(strIndermediaire=="-..")
                lettreTraduite ='D';
            else if(strIndermediaire==".")
                lettreTraduite ='E';
            else if(strIndermediaire=="..-.")
                lettreTraduite ='F';
            else if(strIndermediaire=="--.")
                lettreTraduite ='G';
            else if(strIndermediaire=="....")
                lettreTraduite ='H';
            else if(strIndermediaire=="..")
                lettreTraduite ='I';
            else if(strIndermediaire==".---")
                lettreTraduite ='J';
            else if(strIndermediaire=="-.-")
                lettreTraduite ='K';
            else if(strIndermediaire==".-..")
                lettreTraduite ='L';
            else if(strIndermediaire=="--")
                lettreTraduite ='M';
            else if(strIndermediaire=="-.")
                lettreTraduite ='N';
            else if(strIndermediaire=="---")
                lettreTraduite ='O';
            else if(strIndermediaire==".--.")
                lettreTraduite ='P';
            else if(strIndermediaire=="--.-")
                lettreTraduite ='Q';
            else if(strIndermediaire==".-.")
                lettreTraduite ='R';
            else if(strIndermediaire=="...")
                lettreTraduite ='S';
            else if(strIndermediaire=="-")
                lettreTraduite ='T';
            else if(strIndermediaire=="..-")
                lettreTraduite ='U';
            else if(strIndermediaire=="...-")
                lettreTraduite ='V';
            else if(strIndermediaire==".--")
                lettreTraduite ='W';
            else if(strIndermediaire=="-..-")
                lettreTraduite ='X';
            else if(strIndermediaire=="-.--")
                lettreTraduite ='Y';
            else if(strIndermediaire=="--..")
                lettreTraduite ='Z';
            else if(strIndermediaire=="/")
                lettreTraduite =' ';

            //Ajout de ce qui a ete recupere
            messageARenvoyer=messageARenvoyer+lettreTraduite;

            //Reinitialisation du truc intermediaire
            strIndermediaire = "";
        }
    }
    return messageARenvoyer;
}

int init(int zero)
{
    srand(time(NULL));
    //Initialisation des variables
    string message("");
    int recupMenu(0);

    //Afficher Menu
    cout << "Choisissez la fonction" << endl << "1 : Encodage" << endl << "2 : Decodage" << endl << "3 : Effacer l'ecran" << endl << "4 : Fermer le programme" << endl;

    //Recuperation de la valeur du menu
    cin >> recupMenu;

    //Recuperation du message si on ne ferme pas
    if  (recupMenu==1||recupMenu==2)
    {
        cout << "Entrez votre message" << endl;
        cin.ignore();
        getline(cin, message);
        cout << "Message de base : " << message << endl;
    }

    //Traduction en morse
    if (recupMenu==1)
    {
        string messageaMORSe(aMORSage(message));
        string messagechiffre(chiffrage(messageaMORSe));
        cout << "Resultat traduit :" <<endl<< "DEBUT" <<endl<<endl << messagechiffre << endl <<endl<<"FIN" <<endl;
        init(0);
    }

    //Traduction en français
    else if (recupMenu==2)
    {
        string messageCode(decodage(message));
        string messageTraduit(traduction(messageCode));
        cout << "Resultat traduit : DEBUT " << endl << endl<< messageTraduit << endl<<endl<<" FIN" <<endl;
        init(0);
    }

    //Effacer l'ecran
    else if (recupMenu==3)
    {
        system("cls");
        init(0);
    }

    //Quitter le programme
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
