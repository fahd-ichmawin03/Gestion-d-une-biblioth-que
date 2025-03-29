#ifndef ADHERENT_H_INCLUDED
#define ADHERENT_H_INCLUDED
 typedef struct SAdherent {
 int adh_Index;
 char adh_Nom[20];
 int adh_Prenom[20];
 } Adherent;
FILE *cl;
//*****************************************

void tableauaufichier(Adherent *c,int borne){
    int i;
    cl=fopen("Adherents.txt","w");
     if(cl==NULL){
        printf("\n\n\t*************** Imposible d\'ouvrire le fichier***************\n");
        exit(1);
    }
    for(i=0;i<borne;i++){
        fprintf(cl,"%d\n%s\n%s\n",(c+i)->adh_Index,(c+i)->adh_Nom,(c+i)->adh_Prenom);
    }
    fclose(cl);
}
//*****************************************

void fichierautableau(Adherent *c,int *pborne){
    int i=0,j;
    cl=fopen("Adherents.txt","a+");
     if(cl==NULL){
        printf("\n\n\t*************** Imposible d\'ouvrire le fichier***************\n");
        exit(1);
    }

    while(fscanf(cl,"%d\n%s\n%s\n",&(c+i)->adh_Index,(c+i)->adh_Nom,(c+i)->adh_Prenom)!=EOF){
        i++;
        (*pborne)++;
    }
    fclose(cl);
}

//*****************************************

void ajouterAdherent(Adherent *c,int *pborne,int taille){
    int index,i,j,l;
    int k=(*pborne);
    int nbr;
    printf("Donner le nombre des adherents a ajouter: ");scanf("%d",&nbr);
     if((*pborne)+nbr-1==taille)
        printf("\n\n\t*************** Impossible d'ajouter un adherent***************\n");
     else{
            for(int i=k;i<k+nbr;i++){
        printf("------------------------------\n\n");
        do{
        printf("Donner l\'index d\'adherent %d: ",i+1);
        scanf("%d",&index);
         j=0;
         for(l=0;l<k+nbr;l++){
         if(index==(c+l)->adh_Index){
            printf("\n\n\t*************** L\'adherent est deja existe !!!***************\n");
            j++;
         }}}while(j!=0);
         (c+i)->adh_Index=index;
        printf("Donner le nom d\'adherent %d: ",i+1);
        scanf("%s",(c+i)->adh_Nom);
        printf("Donner Le prenom d\'adherent %d: ",i+1);
        scanf("%s",(c+i)->adh_Prenom);
        (*pborne)++;}
     }
}

//********************************************************

void modifierAdherent(Adherent *c,int borne){
    int index,i,j=0;
      printf("Donner l\'index d\'adherent a modifier: ");
      scanf("%d",&index);
      for(i=0;i<borne;i++){
        if((c+i)->adh_Index==index){
           printf("Donner le nouveau nom: ");scanf("%s",(c+i)->adh_Nom);
           printf("Donner le nouveau prenom: ");scanf("%s",(c+i)->adh_Prenom);
           j=1;
        }
      }
      if(j==0)
        printf("\n\n\t*************** l\'adhernt n\'existe pas !!!***************\n");
}

//**********************************************************

void supprimerAdherent(Adherent *c,int *pborne){
     int i=-1,j,k,index;
     printf("Donner l\'index d\'adherent a supprimer: ");
     scanf("%d",&index);
   for(j=0;j<(*pborne);j++){
    if((c+j)->adh_Index==index)
        i=j;
   }
     if(i==-1){
        printf("\n\n\t*************** l\'adherent n\'existe pas !!!***************\n");
        getch();
    }
     else{
        for(j=i;j<(*pborne);j++){
            (c+j)->adh_Index=(c+j+1)->adh_Index;
                for(k=0;k<20;k++){
            (c+j)->adh_Nom[k]=(c+j+1)->adh_Nom[k];
		(c+j)->adh_Prenom[k]=(c+j+1)->adh_Prenom[k];
        }
        }
        (*pborne)--;
     }
}

//**************************************************

void afficherAdherent(Adherent *c,int borne){
    int i,k=65,l=97,j=0;
    do{
     for (i=0;i<borne;i++){
        if((c+i)->adh_Nom[0]==k || (c+i)->adh_Nom[0]==l ){
            printf("\n\n\t******************Adherent %d******************\n",j+1);
            printf("\t\tIndex : %d\n",(c+i)->adh_Index);
            printf("\t\tNom : %s\n",(c+i)->adh_Nom);
            printf("\t\tprenom : %s\n",(c+i)->adh_Prenom);
            j++;
        }
     }
     l++;k++;
}while(l<123 && k<91);
    if(j==0)
        printf("\n\n\t*************** Il n\'existe pas d\'adherents !!!***************\n");
}


#endif // ADHERENT_H_INCLUDED
