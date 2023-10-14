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
	struct tree* branch1;
	struct tree* branch2;
	int dept;
	int value;

};



struct tree* makeTree(int value){

	
	struct tree* t=(struct tree*) malloc(sizeof(struct tree));
	t->parent=NULL;
	t->dept=0;
	t->value=0;
	return t;

}


void showTreeInfo(struct tree* t){

	printf("TREE INFO:\nDEPT: %d\nVALUE: %d\n",t->dept,t->value);
	printf("BRANCH1: ");
	if(!t->branch1)
		printf("NOT ");
	printf("DEFINED\n");
	printf("BRANCH2: ");
	if(!t->branch2)
		printf("NOT ");
	printf("DEFINED\n");


}

void changeValue(struct tree* t,int value){


	t->value=value;

}

void moveToTree(struct tree** tr,int direction){
	
	struct tree* t= *tr;

	if(direction==0&& t->parent!=NULL){
		*tr=t->parent;
	}
	else if (direction==1 && t->branch1!=NULL){

		*tr=t->branch1;

	}
	else if (direction==2 && t->branch2!=NULL){
		*tr=t->branch2;
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
	"Press \"1\" to go to the first tree\n"
	"Press \"2\" to go to the second tree\n");
	printf("Eneter the number: ");
	scanf("%d",&tmp);
	return tmp;

}
struct tree*  makeBranch(int dept){

	struct tree* t=(struct tree *) malloc(sizeof(struct tree));
	t->dept=dept;
	t->value=-1;
	return t;


}
void addTree(struct tree* t){
	
	


	printf("SELECT WICH BRANCH YOU WANT TO USE:\n");
	printf("BRANCH1: ");
	if(t->branch1)
		printf("UNAVAIBLE\n");
	else
		printf("AVAILABLE\n");
	printf("BRANCH2: ");
	if(t->branch2)
		printf("UNAVAILABLE\n");
	else
		printf("AVAILABLE\n");
	int sel;
	scanf("%d",&sel);
	if(sel==1 && !t->branch1)	
		t->branch1=makeBranch(t->dept+1);

	else if(sel==2 && !t->branch2)	
		t->branch2=makeBranch(t->dept+1);
	else{
		printf("SELECTION %d NOT AVAIBLE\n",sel);
		return;	
	}


	struct tree* m;
	if(sel==1){
		
		m=t->branch1;
	}else
		m=t->branch2;
	m->parent=t;
	printf("BRANCH ADDED SUCCESSFULLY\n");
	
	printf("DO YOU WANT TO SET THE VALUE OF THE NEW BRANCH NOW?(y/n): ");
	char op;
	scanf(" %c",&op);
	if(op=='y'){
		int tmp;
		printf("Enter the value: ");
		scanf("%d",&tmp);
		m->value=tmp;
	}




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
				printf("Not implemented yet\n");
				addTree(t);
				break;
			default:
				printf("Option not recognized.\nPress\"h\" to see the available commands.");
				

		}

		printf("\n");



	}
	


}
