#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
 struct compte{
	char nom[10];
	char prenom[10];
	char cin[10];
	float montant;
};

	struct compte comptes[1000];
	
void add();
void operations();
void retrait(int nb);
void depot(int nb);
void search();
void retour();
void Menu();
void searchCIN();
void afficheAscendant();
void afficheDescendant();

	int id,nb_acc,i;
	
int main()
{
	Menu();

}
/*void afficheAscendant(){
	int i;
	int j;
 	struct compte t;
	for (i=0;i<nb_acc;i++){
		for(j=0;j<nb_acc-i-1;j++){
			if(comptes[i].montant>comptes[i+1].montant){
			t=comptes[i];
			comptes[i]=comptes[i+1];
			comptes[i+1]=t;
			}
		}
	}
	for (i = 0; i <= nb_acc ; i++) {
		printf("les comptes des client est %s %s %s %f \n \n 				",comptes[i].nom,comptes[i].prenom,comptes[i].cin,comptes[i].montant);
	}
}

void afficheDescendant(){
	int i,j;
 	struct compte t;
		for (i=0;i<nb_acc;i++){
		for(j=0;j>nb_acc-i-1;j++){
			if(comptes[i].montant>comptes[i+1].montant){
			t=comptes[i];
			comptes[i]=comptes[i+1];
			comptes[i+1]=t;
			}
		}
	}	for (i = 0; i <= nb_acc ; i++) {
		printf("les comptes des client est %s %s %s %lf \n \n 				",comptes[i].nom,comptes[i].prenom,comptes[i].cin,comptes[i].montant);
	}
}*/
void affichSUP(){
	int i,j;
	float A;
	printf("Entrer un Montant ");
	scanf("%f",&A);
  	struct compte t;
	for (i=0;i<nb_acc;i++){
		for(j=0;j<nb_acc-i-1;j++){
			if(comptes[i].montant>comptes[i+1].montant){
			t=comptes[i];
			comptes[i]=comptes[i+1];
			comptes[i+1]=t;
			}
		}
	}
	for (i = 0; i <= nb_acc ; i++) {
		if (comptes[i].montant>A)
		printf("les comptes des client est %s %s %s %lf \n \n 				",comptes[i].nom,comptes[i].prenom,comptes[i].cin,comptes[i].montant);
	}
}
void affichINF(){
	int i,j;
	float A;
	printf("Entrer un Montant ");
	scanf("%f",&A);
  	struct compte t;
	for (i=0;i<nb_acc;i++){
		for(j=0;j>nb_acc-i-1;j++){
			if(comptes[i].montant>comptes[i+1].montant){
			t=comptes[i];
			comptes[i]=comptes[i+1];
			comptes[i+1]=t;
			}
		}
	}
	for (i = 0; i <= nb_acc ; i++) {
		if (comptes[i].montant<A)
		printf("les comptes des client est %s %s %s %lf \n \n 				",comptes[i].nom,comptes[i].prenom,comptes[i].cin,comptes[i].montant);
	}
}


void add()
{
	printf("entrer your name :");
	scanf("%s",comptes[id].nom);
	__fpurge(stdin);
	
	printf("entrer your first name :");
	scanf("%s",comptes[id].prenom);
	__fpurge(stdin);
	
	printf("entrer your CIN :");
	scanf("%s",comptes[id].cin);
	__fpurge(stdin);
	
	printf("entrer your montant");
	scanf("%f",&comptes[id].montant);
	__fpurge(stdin);
	
	id++;
}
void operations(){
	char cin1[10];
	int i,choix,pos;
	printf("Entrer le CIN que vous chercher");
	scanf("%s",cin1);
	for(i=0;i<id;i++){
		if(strcmp(cin1,comptes[i].cin)==0)
		{
			printf("le montant cherchee est %f",comptes[i].montant);
			pos=i;
		}
	}
	printf("Choisir une operation : 1-retrait 2-depot");
	scanf("%d",&choix);

	if(choix == 1)
		retrait(pos);
	else if(choix == 2)
		depot(pos);
	else 
		printf("entrer 1 ou 2!!!");
}
void searchCIN(){
	char cin2[10];
	int i,pos;
	printf("Entrer le CIN de compte que vous chercher");
	scanf("%s",cin2);
	for(i=0;i<id;i++){
		if(strcmp(cin2,comptes[i].cin)==0)
		{
		printf("le compte cherchee est :\n Nom : %s  Prenom : %s\n CIN : %s  Montant : %f\n",	comptes[pos].nom,comptes[pos].prenom,comptes[pos].cin,&comptes[pos].montant);	
			break;
		}

	}
}
void retrait(int nb){
	float somme;
	printf("Entrer la somme que vous voulez retrait");
	scanf("%f",&somme);
	if(somme <= comptes[nb].montant){
		printf("le montant apres le retrait est : %f",comptes[nb].montant -= somme);
	}
	else
		printf("votre solde est insuffisant");

}
void depot(int nb)
{
	float somme;
	printf("Entrer la somme que vous voulez depose");
	scanf("%f",&somme);
	comptes[nb].montant += somme;
	printf("Votre montant est : %f",comptes[nb].montant);
}
void retour(){
	int c;
	printf("1:retour au menu\n 2: sortir du programme\n");
	scanf("%d",&c);
	switch(c){
		case 1:
			Menu();
			break;
		default :
			printf("vous avez quitter le programme");
	}
}
void aff(){
	int nb;
	printf("Afficher par :\n1-Ordre ascendant\n2-Ordre Descendant\n3-Ordre ascendant 2\n4-Ordre descendant 2\n4-Recherche CIN\n");
	scanf("%d",&nb);
	switch(nb){
		case 1:
			afficheAscendant();
			retour();
			break;
		case 2:
			afficheDescendant();
			retour();
			break;
		case 3:
			affichSUP();
			retour();
			break;
		case 4:
			affichINF();
			retour();
			break;	
		case 5:
			searchCIN();
			retour();
			break;
	
	}

}


void Menu(){
	
	int choix;

	printf("          Menu          \n");
	printf("0-Quitter\n1-Cree un compte\n2-Cree plusieur comptes\n3-Operations\n4-Affichage\n5-Fidelisation");
	scanf("%d",&choix);
	switch(choix)
	{
		case 0:
			exit(1);
		case 1:
			add();
			retour();
			break;
		case 2:
			printf("combien de comptes vous voulez cree?");
			scanf("%d",&nb_acc);
			while(i<nb_acc){
				add();
				i++;
				system("clear");
			}
			retour();
			break;
		case 3:
			operations();
			retour();
			break;
		case 4:
			aff();
			retour();
			break;
		case 5:
			fidelisation();
			retour();
			break;


	}
}
void afficheDescendant()
{

	   int i,k;
	   struct compte t;

	 for (i=0;i<nb_acc;i++){
		 for(k=0;k<nb_acc-i-1;k++){
			if(comptes[k].montant<comptes[k+1].montant)
			{
				t=comptes[k];
				comptes[k]=comptes[k+1];
				comptes[k+1]=t;
			}
		}
	 }
	for (i = 0; i < id ; i++) {
	printf("le compte de client est:\n Nom : %s |Prenom : %s |CIN : %s |Montant : %f \n \n ",comptes[i].nom,comptes[i].prenom,comptes[i].cin,comptes[i].montant);
							     }
}
void fidelisation(){
		int i,k,j;
		struct compte t;

	 for (i=0;i<nb_acc;i++){
		 for(k=0;k<nb_acc-i-1;k++){
			if(comptes[k].montant<comptes[k+1].montant)
			{
				t=comptes[k];
				comptes[k]=comptes[k+1];
				comptes[k+1]=t;
			}
		}
	 }
	 for(j=0;j<3;j++){
		 comptes[j].montant= comptes[j].montant + (comptes[j].montant*0.013);
		 printf("le nouveau montant du compte numero %d est : %f ",j+1,comptes[j].montant);
	 }


}
void afficheAscendant()
{

	   int i,k;
	   struct compte t;

	 for (i=0;i<nb_acc;i++){
		 for(k=0;k<=nb_acc-i-1;k++){
			if(comptes[k].montant>comptes[k+1].montant)
			{
				t=comptes[k];
				comptes[k]=comptes[k+1];
				comptes[k+1]=t;
			}
		}
	 }
	for (i = 0; i < id ; i++) {
	printf("le compte de client est:\n Nom : %s |Prenom : %s |CIN : %s |Montant : %f \n \n ",comptes[i].nom,comptes[i].prenom,comptes[i].cin,comptes[i].montant);
							     }
}

