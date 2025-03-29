#ifndef LIVRES_H_INCLUDED
#define LIVRES_H_INCLUDED


typedef struct SLivre {
 int liv_Index;
 char liv_Titre[20];
 int liv_Prix;
 int  liv_Duree;
 int  liv_Nbrjour;
int liv_Emprunteur;
} Livre;
FILE *Li;
//*****************************************

void tableauaufichierv(Livre *v,int borne){
    int i;
    Li=fopen("Livres.txt","w");
     if(Li==NULL){
        printf("\n\n\t*************** Imposible d\'ouvrire le fichier***************\n");
        exit(1);
    }
    for(i=0;i<borne;i++){
        fprintf(Li,"%d\n%s\n%d\n%d\n%d\n%d\n",(v+i)->liv_Index,(v+i)->liv_Titre,(v+i)->liv_Emprunteur,(v+i)->liv_Duree,(v+i)->liv_Nbrjour,(v+i)->liv_Prix);
    }
    fclose(Li);
}
//*****************************************

void fichierautableauv(Livre *v,int *pborne){
    int i=0,j;
    Li=fopen("Livres.txt","a+");
     if(Li==NULL){
        printf("\n\n\t*************** Imposible d\'ouvrire le fichier***************\n");
        exit(1);
    }
    while(fscanf(Li,"%d\n%s\n%d\n%d\n%d\n%d\n",&(v+i)->liv_Index,(v+i)->liv_Titre,&(v+i)->liv_Emprunteur,&(v+i)->liv_Duree,&(v+i)->liv_Nbrjour,&(v+i)->liv_Prix)!=EOF){
        i++;
        (*pborne)++;
    }
    fclose(Li);
}

//*****************************************


void ajouterLivre(Livre *v,int *pborne,int taille){
    int index,i,j,l;
    int k=(*pborne);
    int nbr;
    printf("Donner le nombre de livre a ajouter: ");scanf("%d",&nbr);
     if((*pborne)+nbr-1==taille)
        printf("\n\n\t*************** Impossible d'ajouter un livre***************\n");
     else{
            for(int i=k;i<k+nbr;i++){
        printf("------------------------------\n\n");
        do{
        printf("Donner l\'index de livre %d: ",i+1);
        scanf("%d",&index);
         j=0;
         for(l=0;l<k+nbr;l++){
         if(index==(v+l)->liv_Index){
            printf("\n\n\t*************** Le livre est deja existe !!!***************\n");
            j++;
         }}}while(j!=0);
         (v+i)->liv_Index=index;
	printf("Donner le titre de livre %d: ",i+1);
        scanf("%s",(v+i)->liv_Titre);
        printf("Donner le prix de livre par jour%d : ",i+1);
        scanf("%d",&(v+i)->liv_Prix);

        (*pborne)++;}
     }
}

//********************************************************

void modifierLivre(Livre *v,int borne){
    int index,i,j=0;
      printf("Donner l\'index de livre a modifier: ");
      scanf("%d",&index);
      for(i=0;i<borne;i++){
        if((v+i)->liv_Index==index){
           printf("Donner le noveau titre: ");scanf("%s",(v+i)->liv_Titre);
           printf("Donner le noveau prix: ");scanf("%d",&(v+i)->liv_Prix);
           j=1;
        }
      }
      if(j==0)
        printf("\n\n\t*************** Le livre n\'existe pas !!!***************\n");
}

//**********************************************************

void supprimerLivre(Livre *v,int *pborne){
     int i=-1,j,k,index;
     printf("Donner l\'index de livre a supprimer: ");
     scanf("%d",&index);
   for(j=0;j<(*pborne);j++){
    if((v+j)->liv_Index==index)
        i=j;
   }
     if(i==-1){
        printf("\n\n\t*************** Le livre n\'existe pas !!!***************\n");
        getch();
        }
     else{
        for(j=i;j<(*pborne);j++){
            (v+j)->liv_Index=(v+j+1)->liv_Index;
                for(k=0;k<20;k++){
            (v+j)->liv_Titre[k]=(v+j+1)->liv_Titre[k];
                }
            (v+j)->liv_Duree=(v+j+1)->liv_Duree;
            (v+j)->liv_Prix=(v+j+1)->liv_Prix;
            (v+j)->liv_Nbrjour=(v+j+1)->liv_Nbrjour;
            (v+j)->liv_Emprunteur=(v+j+1)->liv_Emprunteur;
        }
        (*pborne)--;
     }
}

//************************************************

void afficherLivre(Livre *v,int borne){
    int i,k=65,l=97,j=0;
    do{
     for (i=0;i<borne;i++){
        if((v+i)->liv_Titre[0]==k || (v+i)->liv_Titre[0]==l ){
            printf("\n\n\t******************Livre %d******************\n",j+1);
            printf("\t\tIndex : %d\n",(v+i)->liv_Index);
            printf("\t\ttitre : %s\n",(v+i)->liv_Titre);
            //printf("\t\tPrix par jour : %d DH\n",(v+i)->liv_Prix);
            j++;
        }
     }
     l++;k++;
}while(l<123 && k<91);
     if(j==0)
        printf("\n\n\t*************** Il n\'existe pas de Livres !!!***************\n");
}



#endif // LIVRES_H_INCLUDED
