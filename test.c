#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>



void showHelp(){
	printf("\n\n\n---------------------------------------\n");
	printf("TREE MENU OPTIONS:\n"
	"\"h\":obviously to show help\n"
	"\"i\":show the basic informatione of the current tree\n"
	"\"v\":change the value of the current tree\n"
	"\"m\":move to a selected tree\n"
	"\"a\":to add a tree to a branch of the current tree\n"
	"\"q\":quit from menu\n\n\n");


}

struct tree{
	struct tree* parent;
	struct tree* branches;
	int nBranches;
	int dept;
	int value;

};




struct tree* makeTree(int value){

	
	struct tree* t=(struct tree*) malloc(sizeof(struct tree));
	t->parent=NULL;
	t->dept=0;
	t->value=0;
	t->branches=NULL;
	t->nBranches=0;
	return t;

}



void showTreeInfo(struct tree* t){

	printf("TREE INFO:\nDEPT: %d\nVALUE: %d\n",t->dept,t->value);
	printf("NUMBER OF BRANCHES: %d\n",t->nBranches);

}

void changeValue(struct tree* t,int value){


	t->value=value;

}

void moveToTree(struct tree** tr,int direction){
	
	struct tree* t= *tr;

	if(direction==0&& t->parent!=NULL){
		*tr=t->parent;
	}
	else if (direction <  t->nBranches){

		*tr=&t->branches[direction-1];

	}
	else{
		printf("Direction not allowed: %d\n",direction);
		return;
	}
	printf("Moved successfully\n");

}

int getDirection(){

	int tmp;
	printf("Press \"0\" to go to the parent tree\n"
	"Press any number to go to the desired tree\n");
	printf("Eneter the number: ");
	scanf("%d",&tmp);
	return tmp;

}

void addTree(struct tree* t){
	
	if(t->nBranches==0){//if the tree hasn't branches
		
		t->branches=(struct tree*)malloc(sizeof(*t));
		t->nBranches=1;
		


	}else{
		t->nBranches++;
		t->branches=realloc(t->branches,sizeof(*t)*t->nBranches);


	}
	struct tree* newTree; newTree=&t->branches[t->nBranches-1]; 
	newTree->parent=t;
	
	newTree->value=0;
	
	newTree->branches=NULL;
	newTree->nBranches=0;
	newTree->dept=t->dept+1;
	

}

int main(){
	
	struct tree* t=makeTree(0);

	char op='h';


	printf("TREE MENU:\nPress h for help.");
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
			default:
				printf("Option not recognized.\nPress\"h\" to see the available commands.");
				

		}

		printf("\n");



	}
	


}
