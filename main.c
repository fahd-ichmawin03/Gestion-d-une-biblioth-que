#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "adherent.h"
#include "livres.h"
#include "emprunts.h"
const int taille=200;
int main()
{
    Adherent cl[taille];
    Livre ve[taille];
    int bornec=0,bornev=0;
    int choix1,choix2;

    system("COLOR A");
fichierautableau(cl,&bornec);
fichierautableauv(ve,&bornev);
start:
    printf("\n\n\n\n\n\t\t\t************************** Menu Principale******************************\n\n\n");
    printf("\t\t\t\t\t1- Gestion des adherents\n");
    printf("\t\t\t\t\t2- Gestion des livres\n");
    printf("\t\t\t\t\t3- Gestion des emprunts\n");
    printf("\t\t\t\t\t4- Enregistrer et quitter le programme\n");
    printf("\n\t\t\t\t-Donner votre choix(1,2,3,4): ");scanf("%d",&choix1);
    do{
    system("cls");
    switch(choix1){
    case 1:{
            do{
            printf("\n\n\n\t****************** Menu des adherents******************\n\n");
            printf("\t\t1- Ajouter un adherent\n");
            printf("\t\t2- Modifier un adherent\n");
            printf("\t\t3- Supprimer un adherent\n");
            printf("\t\t4- Afficher la liste des adherents par ordre alphabetique\n");
            printf("\t\t5- Retour en arriere\n");
            printf("\n\t-Donner votre choix(1,2,3,4,5): ");scanf("%d",&choix2);
             system("cls");
            switch(choix2){
              case 1:{ajouterAdherent(cl,&bornec,taille);getch();system("cls");break;}
              case 2:{modifierAdherent(cl,bornec);getch();system("cls");break;}
              case 3:{supprimerAdherent(cl,&bornec);system("cls");break;}
              case 4:{afficherAdherent(cl,bornec);getch();system("cls");break;}
              case 5:{goto start;}
              default:{printf("Donner un nombre entre [1-5]");choix2=10;}
            }}while(choix2==10);
            goto start;
        ;break;}
    case 2:{do{
            printf("\n\n\n\t****************** Menu des livres******************\n\n");
            printf("\t\t1- Ajouter un livre\n");
            printf("\t\t2- Modifier un livre\n");
            printf("\t\t3- Supprimer un livre\n");
            printf("\t\t4- Afficher la liste des livres par ordre alphabetique\n");
            printf("\t\t5- Retour en arriere\n");
            printf("\n\t-Donner votre choix(1,2,3,4,5): ");scanf("%d",&choix2);
            system("cls");
            switch(choix2){
              case 1:{ajouterLivre(ve,&bornev,taille);system("cls");break;}
              case 2:{modifierLivre(ve,bornev);getch();system("cls");break;}
              case 3:{supprimerLivre(ve,&bornev);system("cls");break;}
              case 4:{afficherLivre(ve,bornev);getch();system("cls");break;}
              case 5:{goto start;}
              default:{printf("Donner un nombre entre [1-5]");choix2=10;}
            }}while(choix2==10);

            goto start;
            ;break;}
    case 3:{
            do{
            printf("\n\n\n\t****************** Menu des emprunts******************\n\n");
            printf("\t\t1- Emprunter un livre\n");
            printf("\t\t2- Rendre un livre\n");
            printf("\t\t3- Afficher la liste des livres empruntes\n");
            printf("\t\t4- Afficher l\'emprunteur de livres\n");
            printf("\t\t5- Retour en arriere\n");
            printf("\n\t-Donner votre choix(1,2,3,4,5): ");scanf("%d",&choix2);
            system("cls");
            switch(choix2){
              case 1:{emprunterLivre(cl,ve,bornec,bornev);getch();system("cls");break;}
              case 2:{rendreLivre(cl,ve,bornec,bornev);getch();system("cls");break;}
              case 3:{livresempruntes(ve,bornev);getch();system("cls");break;}
              case 4:{emprunteursLivre(cl,ve,bornec,bornev);getch();system("cls");break;}
              case 5:{goto start;}
              default:{printf("Donner un nombre entre [1-5]");choix2=10;}
            }}while(choix2==10);
            goto start;
            ;break;}
    case 4:{printf("\n\n\n\t******************Fin de traitement !!!******************\n");break;}
    default:{printf("Donner un nombre entre [1-4]");goto start;
    }
    }
    getch();
    }while(choix1!=4);
    tableauaufichier(cl,bornec);
    tableauaufichierv(ve,bornev);
    return 0;
}

