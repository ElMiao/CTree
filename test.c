#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "tree.h"


void showHelp(){
	printf("\n\n\n---------------------------------------\n");
	printf("TREE MENU OPTIONS:\n"
	"\"h\":obviously to show help\n"
	"\"i\":show the basic informatione of the current tree\n"
	"\"v\":change the value of the current tree\n"
	"\"m\":move to a selected tree\n"
	"\"a\":to add a tree to a branch of the current tree\n"
	"\"r\":remove the desired branch\n"
	"\"q\":quit from menu\n\n\n");


}



int getDirection(){

	int tmp;
	printf("Press \"0\" to go to the parent tree\n"
	"Press any number to go to the desired tree\n");
	printf("Eneter the number: ");
	scanf("%d",&tmp);
	return tmp;

}

int getBranch(){
	
	int tmp;
	printf("Insert the branch that you want to delete (number of the desired branch): ");
	scanf("%d",&tmp);

	return tmp;

}

int main(){
	
	struct tree* t=makeTree(0);

	char op='h';


	printf("TREE MENU:\nPress h for help.\n");
	while(op!='q'){
		printf("ENTER OPTION: ");
		scanf(" %c",&op);
		
		switch(op){


			case 'h':
				showHelp();
				break;
			case 'i':
				showTreeInfo(t);
				break;
			case 'v':
				int tmp;
				printf("Enter new value: ");
				scanf("%d",&tmp);
				changeValue(t,tmp);
				break;
			case 'm':
				moveToTree(&t,getDirection());
				break;
			case 'q':
				printf("Exit from the menu\n");
				break;
			case 'a':
				addTree(t);
				break;
			case 'r':
				removeBranch(t,getBranch());
				break;
			default:
				printf("Option not recognized.\nPress\"h\" to see the available commands.");
				

		}

		printf("\n");



	}
	


}
