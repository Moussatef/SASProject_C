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
	printf("-5) Quitter \n");
	
} 



void affichageListCompt(){
	int j;
	for(j=0 ; j < countOfCompt ; j++ ){
		
	 	printf("\n*****************************************{ Compte %d }*****************************************\n \n", (j+1));
	 	printf("\n\t\t\t\tCIN : %s " , list_compt[j].CIN); 
	 	printf("\n\t\t\t\tNom : %s " , list_compt[j].Nom); 
	 	printf("\n\t\t\t\tPrenom : %s " , list_compt[j].Prenom); 
	 	printf("\n\t\t\t\tMontant : %f2 \n" , list_compt[j].montant); 
	 	printf("\n\t_____________________________________________________________________________________________\n");
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
void menuAffichage(){
	int chose ;
	char cin[10];

	printf("-1) Par Ordre Ascendant (les comptes bancaire ayant un montant superieur ï¿½ un chiffre introduit)\n");
	printf("-2) Par Ordre Descendant (les comptes bancaire ayant un montant superieur ï¿½ un chiffre introduit)\n");
	printf("-3) Recherche par CIN\n");
	printf("-4) Fidelisation (Ajouter 1.3 aux comptes ayant les 3 premiers montants superieurs)\n");
	
	scanf("%d",&chose);
	switch(chose){
		case 1 : 
			trierParAsc();
			break;
		
		case 2 :
			trierParDesc();
			break;
		case 3 : 
		printf("Saisir CIN : ");
			scanf("%s",cin );
			Rechercher(cin);
			break;
		case 4 :
			fidelisation();
			break;
	
		default : printf("\n votre chois ne pas en menu!!!");
			
	}
} 


void fidelisation(){
	int i,j;
	float total , benft = 1.3;
	trierParDesc();
	
	for( i=0 ; i< 3; i++){
		total = (benft / 100) * list_compt[i].montant ;
		list_compt[i].montant += total; 
	}
	
	
	for( j=0 ; j< 3; j++){
	 	printf("\n*****************************************{ Compte %d Benfite }*****************************************\n \n", (j+1));
	 	printf("\n\t\t\t\tCIN : %s " , list_compt[j].CIN); 
	 	printf("\n\t\t\t\tNom : %s " , list_compt[j].Nom); 
	 	printf("\n\t\t\t\tPrenom : %s " , list_compt[j].Prenom); 
	 	printf("\n\t\t\t\tMontant : %f2 \n" , list_compt[j].montant); 
	 	printf("\n\t_____________________________________________________________________________________________\n");
	 }
		
	
}






void introduire_compte(){
	
	float montant;
	char cinn[20];
	int cmp= 0;
	
	do{
	
	
	printf("Saisir CIN  : ");
	scanf("%s",cinn);

	cmp = RechercherExist(cinn);

	
	if(cmp == -1){
		
	strcpy(list_compt[countOfCompt].CIN , cinn);
        
    printf("Saisir nom  : ");
    scanf("%s",list_compt[countOfCompt].Nom);
    
	
	printf("Saisir Prenom : ");
    scanf("%s",list_compt[countOfCompt].Prenom);
        
    
    printf("Saisir Montant : ");
    scanf("%f",&montant);
        
    list_compt[countOfCompt].montant = montant;
	countOfCompt++;

	}else
	printf("CIN existe deja  !!! \n");

    }while(cmp== 0);
        
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
	 	printf("\nMontant : %.2f \n" , list_compt[j].montant); 
	 }
	
} 

void afficherCompte(int pos){
		printf("\nCIN : %s " , list_compt[pos].CIN); 
	 	printf("\nNom : %s " , list_compt[pos].Nom); 
	 	printf("\nPrenom : %s " , list_compt[pos].Prenom); 
	 	printf("\nMontant : %.2f \n" , list_compt[pos].montant); 
}

void Rechercher(char CIN[50]){
	int i,cmp=0;
	if(countOfCompt > 0)
	for(i=0 ; i < countOfCompt ; i++){
		if(strcmp(list_compt[i].CIN,CIN)  == 0){
			afficherCompte(i);
			cmp++;
			break;
		}
	}
	else{
		printf("Pas de compte maintenant !!! ");
		
		
	}
	
	if(cmp == 0){
		printf("Ce compte n'existe pas ");
	
	}
	
	
}


int RechercherExist(char CIN[50]){
	int i,cmp=0;
	if(countOfCompt > 0)
	for(i=0 ; i < countOfCompt ; i++){
		if(strcmp(list_compt[i].CIN,CIN)  == 0){
			cmp++;
			return i;
		}
	}
	else{
		return -1;
		
	}
	
	if(cmp == 0){
		return -1;
	}
	
}

void operationMethod(int opr){
	char cin[50];
	int pos ;
	float mnt;
	printf("Sasir CIN pour Retrait :  ");
	scanf("%s",cin);
	pos = RechercherExist(cin);
	afficherCompte(pos);
	if(pos >= 0){
	if(opr==1){
		
		printf("Saisir montante retrait : ");
		scanf("%f",&mnt);
		
		if(mnt > 0 ){
			if(mnt <= list_compt[pos].montant && list_compt[pos].montant > 0  ){
				float montant = list_compt[pos].montant;
				montant =  montant - mnt;
				list_compt[pos].montant = montant;
				printf("Operation terminee avec succes, recevez votre argent : %.2f \n\n",mnt);
				printf("Le reste est dans votre compte : %.2f",list_compt[pos].montant);
			}else
				printf("Votre montant n'est pas suffisant");
				
		}else
		printf("Le montant doit etre positif !!!");
		
	
	}
	if(opr == 2){
		printf("Saisir montante depot : ");
		scanf("%f",&mnt);
		
		if(mnt > 0 ){
			
			float montant = list_compt[pos].montant;
			montant =  montant + mnt;
			list_compt[pos].montant = montant;
			printf("--------------------- Operation terminee avec succes, montante depot est  : %.2f --------------------- \n\n",mnt);
			printf("--------------------- Le montante est dans votre compte : %.2f --------------------- \n\n",list_compt[pos].montant);
				
		}else
		printf("Le montant doit etre positif !!!\n");
	}
	
	}else
		printf("Ce compte n'existe pas \n");
	
	
}


void main(){
	int choix,nb_compte,operation;
	
	do{	
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
		
		while(operation != 1 || operation!=2 ){
			printf("\nOperations : \n1- Retrait \n2- Depot\n");
			scanf("%d",&operation);
			operationMethod(operation);
			
			break;
			
		}
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

