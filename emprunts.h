#ifndef EMPRUNTS_H_INCLUDED
#define EMPRUNTS_H_INCLUDED
#include "livres.h"
#include "adherent.h"


//****************************************************************

void conversionsecondes(int n); // Prototype ajouté

void emprunterLivre(Adherent *c,Livre *v,int bornec,int bornev){
    int index,i,k=0,l=0,em_index,ve,nbrj;
     printf("Donner l\'index de Livre emprunter: ");scanf("%d",&index);
     for(i=0;i<bornev;i++){
        if(index==(v+i)->liv_Index){
           printf("Donner l\'index de l\'emprunteur: ");scanf("%d",&em_index);
           (v+i)->liv_Emprunteur=em_index;
            printf("Donner le nombre de jour emprunte: ");scanf("%d",&nbrj);
            (v+i)->liv_Nbrjour=nbrj;
             time_t t=time(0);
             (v+i)->liv_Duree=t+(nbrj*86400);
            k=1;

}}
     if (k==0)
        printf("\n\n\t*************** Le livre n\'exist pas***************\n");
        else{
     for(i=0;i<bornec;i++){
        if(em_index==(c+i)->adh_Index){
           l=1;
}}
            if(l==0)
                printf("\n\n\t*************** L\'adherent n\'exist pas***************\n");
     }}
//******************************************************

void rendreLivre(Adherent *c,Livre *v,int bornec,int bornev){
    int index_ve,index_cl,k=0,i,j=0,l=0;
    printf("Donner l'index de Livre emprunte: ");scanf("%d",&index_ve);
     for(i=0;i<bornev;i++){
        if(index_ve==(v+i)->liv_Index){
           index_cl=(v+i)->liv_Emprunteur;
           if((v+i)->liv_Nbrjour==0)
            printf("\n\n\t*************** Le livre n\'est pas emprunte !!!***************\n");
           (v+i)->liv_Nbrjour=0;
           (v+i)->liv_Emprunteur=0;
           l=1;
}}
    if(l==0)
        printf("\n\n\t*************** Le livre n\'existe pas !!!***************\n");

   for(i=0;i<bornec;i++){
    if((c+i)->adh_Index==index_cl){
        j=1;
        printf("\n\n\t*************** Le livre est rendre avec succes***************\n");
}}
      if(j==0)
        printf("\n\n\t*************** L\'adherent n\'existe pas !!!***************\n");
}

//*******************************************************

void livresempruntes(Livre *v,int bornev){
    int i,k=0,d;
    printf("\n\n\t******************Les livres empruntes******************\n\n");
      for(i=0;i<bornev;i++){
        if((v+i)->liv_Nbrjour!=0){
            printf("\t\tL\'index de livre: %d\n",(v+i)->liv_Index);
            printf("\t\tLe titre  de livre: %s\n",(v+i)->liv_Titre);
		printf("\t\tLe prix totale de livre: %d DH\n",((v+i)->liv_Prix)*((v+i)->liv_Nbrjour));
             time_t t=time(0);
             if(((v+i)->liv_Duree)>t){
                d=(v+i)->liv_Duree-t;
                printf("\t\tLa duree restant: ");
                conversionsecondes(d);
            }
             else{
                d=t-(v+i)->liv_Duree;
                printf("\t\tLa duree est expire depuis: ");conversionsecondes(d);
             }
            printf("\t\tL\'index de l\'emprunteur est: %d\n",(v+i)->liv_Emprunteur);
            k=1;
        }}
        if(k==0)
            printf("\n\n\n\n\t******************Il n\'exist pas de livres empruntes !!!******************\n");
        }

//*******************************************************

void emprunteursLivre(Adherent *c,Livre *v,int bornec,int bornev){
    int indexv,indexc,i,j,k=0,l=0,d;
    printf("Donner l\'index de livre: ");scanf("%d",&indexv);
     for(i=0;i<bornev;i++){
        if(indexv==(v+i)->liv_Index){
                indexc=(v+i)->liv_Emprunteur;
        if(indexc!=0){
                for(j=0;j<bornec;j++){
                    if(indexc==(c+j)->adh_Index ){
                         printf("\n\t\tL\'index de l\'emprunteur est: %d\n",(c+j)->adh_Index);
                         printf("\t\tLe nom de l\'emprunteur est: %s\n",(c+j)->adh_Nom);

                         printf("\t\tLe prenom de l\'emprunteur est: %s\n",(c+j)->adh_Prenom);
                          printf("\t\tLe prix totale de livre: %d DH\n",((v+i)->liv_Prix)*((v+i)->liv_Nbrjour));
                        time_t t=time(0);
             if(((v+i)->liv_Duree)>t){
                d=(v+i)->liv_Duree-t;
                printf("\t\tLa duree restant: ");conversionsecondes(d);
            }
             else{
                d=t-(v+i)->liv_Duree;
                printf("La duree est expire depuis: ");conversionsecondes(d);
             }
                         l=1;
 }}
        if(l==0)
           printf("\n\n\t*************** L\'adherent n\'exist pas***************\n");
}
        k=1;
}}
       if (k==0)
        printf("\n\n\t*************** Le livre n\'exist pas***************\n");
       if(indexc==0)
        printf("\n\n\t*************** Le livre n\'est pas emprunte !!!***************\n");
}

//************************************************************

void conversionsecondes(int n){
     int r,a;
	if (n>0){
	r=n%86400;
	a=(n-r)/86400;
	if (a != 0){
		if (a==1)
			printf(" %d jour", a);
		else
			printf(" %d jours", a);
		}
	n=r;
	r=n%3600;
	a=(n-r)/3600;
	if (a != 0){
		if (a==1)
			printf(" %d heure", a);
		else
			printf(" %d heures", a);
		}
    n=r;
	r=n%60;
	a=(n-r)/60;
	if (a != 0){
		if (a==1)
			printf(" %d minute", a);
		else
			printf(" %d minutes", a);
		}
	a=r;
	if (a != 0){
		if (a==1)
			printf(" %d seconde\n", a);
		else
			printf(" %d secondes\n", a);
		}
	}
}


#endif // EMPRUNTS_H_INCLUDED
