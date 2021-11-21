#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void menuPrancipal(){
	printf("-1) Introduire un compte bancaire (CIN, Nom et Prenom, Montant)\n");
	printf("-2) Introduire plusieurs comptes bancaires (CIN, Nom et Prenom, Montant)\n");
	printf("-3) Operations : \n\t\t- Retrait \n\t\t- Depot\n");
	printf("-4) Affichage\n");
	printf("-5) Exit\n");
	
} 
void menuAffichage(){
	printf("-1) Par Ordre Ascendant\n");
	printf("-2) Par Ordre Descendant\n");
	printf("-3) Par Ordre Ascendant (les comptes bancaire ayant un montant superieur à un chiffre introduit)\n");
	printf("-4) Par Ordre Descendant (les comptes bancaire ayant un montant superieur à un chiffre introduit)\n");
	printf("-5) Recherche par CIN\n");
	printf("-6) Fidelisation\n");
	printf("-7) Ajouter 1.3 aux comptes ayant les 3 premiers montants superieurs Quitter l’application\n");
	
} 

int countOfCompt = 0;

typedef struct {
	
	char CIN[10],
	     Nom[50],Prenom[50];
	float montant;
	     
}compte;


compte list_compt[50];


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


void main(){
	int choix,nb_compte;
	

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
	
	
//	do{	
//	
//	}while(choix!=5);
	
	
	
	
	
	
}

