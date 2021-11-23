#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int countOfCompt = 0;

typedef struct {
	
	char CIN[10],
	     Nom[50],Prenom[50];
	float montant;
	     
}compte;


compte list_compt[50];

void menuPrancipal(){
	printf("-1) Introduire un compte bancaire (CIN, Nom et Prenom, Montant)\n");
	printf("-2) Introduire plusieurs comptes bancaires (CIN, Nom et Prenom, Montant)\n");
	printf("-3) Operations : \n\t\t- Retrait \n\t\t- Depot\n");
	printf("-4) Affichage\n");
	printf("-5) Exit\n");
	
} 
void menuAffichage(){
	int chose ;
	char cin[10];
	printf("-1) Par Ordre Ascendant\n");
	printf("-2) Par Ordre Descendant\n");
	printf("-3) Par Ordre Ascendant (les comptes bancaire ayant un montant superieur à un chiffre introduit)\n");
	printf("-4) Par Ordre Descendant (les comptes bancaire ayant un montant superieur à un chiffre introduit)\n");
	printf("-5) Recherche par CIN\n");
	printf("-6) Fidelisation\n");
	printf("-7) Ajouter 1.3 aux comptes ayant les 3 premiers montants superieurs Quitter l’application\n");
	scanf("%d",&chose);
	switch(chose){
		case 1 : 
			trierParAsc();
			break;
		
		case 2 :
			trierParDesc();
			break;
		case 3 : 
			break;
		case 4 :
			break;
		case 5 :
			printf("Saisir CIN : ");
			scanf("%s",cin );
			Rechercher(cin);
			
			break;
		case 6 : 
			break;
		case 7 :
			break;
		default : printf("\n votre chois ne pas en menu!!!");
			
	}
	
	
	
} 

void affichageListCompt(){
	int j;
	for(j=0 ; j < countOfCompt ; j++ ){
		
	 	printf("\n*****************************************{ Compte %d }*****************************************\n \n", (j+1));
	 	printf("\n\t\t\t\tCIN : %s " , list_compt[j].CIN); 
	 	printf("\n\t\t\t\tNom : %s " , list_compt[j].Nom); 
	 	printf("\n\t\t\t\tPrenom : %s " , list_compt[j].Prenom); 
	 	printf("\n\t\t\t\tMontant : %f2 \n" , list_compt[j].montant); 
	 	printf("\n______________________________________________________\n");
	 }
}

void trierParDesc(){
	int   i,j;
	compte compt[50];
	
	for(i = 0; i < countOfCompt ; i++){
		for( j = i+1 ; j < countOfCompt ; j++ )
		if(list_compt[i].montant < list_compt[j].montant){
			
			strcpy(compt[0].CIN , list_compt[i].CIN);
			strcpy(compt[0].Nom , list_compt[i].Nom);
			strcpy(compt[0].Prenom , list_compt[i].Prenom);
			compt[0].montant = list_compt[i].montant;
			
			strcpy(list_compt[i].CIN , list_compt[j].CIN);
			strcpy(list_compt[i].Nom , list_compt[j].Nom);
			strcpy(list_compt[i].Prenom , list_compt[j].Prenom);
			list_compt[i].montant = list_compt[j].montant;
			
			
			strcpy(list_compt[j].CIN , compt[0].CIN);
			strcpy(list_compt[j].Nom , compt[0].Nom);
			strcpy(list_compt[j].Prenom , compt[0].Prenom);
			list_compt[j].montant = compt[0].montant;
			
			
			
		}
	}
	
	affichageListCompt();
}

void trierParAsc(){
	int   i,j;
	compte compt[50];
	
	for(i = 0; i < countOfCompt ; i++){
		for( j = i+1 ; j < countOfCompt ; j++ )
		if(list_compt[i].montant > list_compt[j].montant){
			
			strcpy(compt[0].CIN , list_compt[i].CIN);
			strcpy(compt[0].Nom , list_compt[i].Nom);
			strcpy(compt[0].Prenom , list_compt[i].Prenom);
			compt[0].montant = list_compt[i].montant;
			
			strcpy(list_compt[i].CIN , list_compt[j].CIN);
			strcpy(list_compt[i].Nom , list_compt[j].Nom);
			strcpy(list_compt[i].Prenom , list_compt[j].Prenom);
			list_compt[i].montant = list_compt[j].montant;
			
			
			strcpy(list_compt[j].CIN , compt[0].CIN);
			strcpy(list_compt[j].Nom , compt[0].Nom);
			strcpy(list_compt[j].Prenom , compt[0].Prenom);
			list_compt[j].montant = compt[0].montant;
			
			
			
		}
	}
	
	affichageListCompt();
}


void introduire_compte(){
	
	float montant;
	
	printf("Saisir CIN  : ");
    scanf("%s",list_compt[countOfCompt].CIN);
        
		 
    printf("Saisir nom  : ");
    scanf("%s",list_compt[countOfCompt].Nom);
    
	
	printf("Saisir Prenom : ");
    scanf("%s",list_compt[countOfCompt].Prenom);
        
    
    printf("Saisir Montant : ");
    scanf("%f",&montant);
        
    list_compt[countOfCompt].montant = montant;
        
    
    countOfCompt++;
      
	
} 


void introduire_plusieurs_compte(int n){
	
	int i,j ;
	
	for(i=0; i<n ; i++)
	{
		printf("\nCompte %d \n",i+1);
		introduire_compte();
	}
	 
	 
	 for(j=0 ; j < countOfCompt ; j++ ){
	 	printf("\nCompte %d \n",j+1);
	 	printf("\nCIN : %s " , list_compt[j].CIN); 
	 	printf("\nNom : %s " , list_compt[j].Nom); 
	 	printf("\nPrenom : %s " , list_compt[j].Prenom); 
	 	printf("\nMontant : %f.2 \n" , list_compt[j].montant); 
	 }
	
} 

void Rechercher(char CIN[50]){
	int i,cmp=0;
	if(countOfCompt > 0)
	for(i=0 ; i < countOfCompt ; i++){
		if(strcmp(list_compt[i].CIN,CIN)  == 0){
			printf("\nCIN : %s " , list_compt[i].CIN); 
	 		printf("\nNom : %s " , list_compt[i].Nom); 
	 		printf("\nPrenom : %s " , list_compt[i].Prenom); 
	 		printf("\nMontant : %f.2 \n" , list_compt[i].montant); 
			cmp++;
		}
	}
	else{
		printf("Pas de compte maintenant !!! ");
		
	}
	
	if(cmp == 0)
	printf("Ce compte n'existe pas ");
	
}




void main(){
	int choix,nb_compte;
	
	do{	
//	

	menuPrancipal();
	
	printf("\n\n*****************************\nEntree votre chois svp entre (1 / 4) : ");
	scanf("%d",&choix);
	switch(choix){
		
		case 1 : 
			printf("\nIntroduire un compte bancaire (CIN, Nom et Prenom, Montant)\n");
			introduire_compte();
			break;
			
		case 2 : 		
			printf("\nIntroduire plusieurs comptes bancaires (CIN, Nom et Prenom, Montant)\n");
			printf("\nSaisir Nb Compte\n");
			scanf("%d",&nb_compte);
			introduire_plusieurs_compte(nb_compte);
			break;
			
		case 3 : 
			printf("\nOperations : \n\t\t- Retrait \n\t\t- Depot");
			break;
			
		case 4 : 		
			printf("\nAffichage\n");
			menuAffichage();
			break;
		case 5 : 		
			printf("\nExit\n");
			break;	
				
		
			
		default: printf("\n votre chois ne pas en menu!!!");
			
	}

		}while(choix!=5);

	
	
	
	

	
	
	
	
	
	
}

