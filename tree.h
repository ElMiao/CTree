#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


void treeHelp(){


	printf("ctree.h: dinamyc tree c library\n"
	"This library works with alloc and realloc memory management to make dinamyc trees with more than 2 branches\n"
	"Each tree has a dept, value (int), the parent tree wich will be null for the initial tree and an array of branches that the current tree has\n"
	"\n\nFunctions:\n"
	"\"makeTree()\" -> struct tree*: will return a pointer to a tree with \"dept\":0 and \"value\": 0\n"
	"\"showTreeInfo(struct tree*)\" -> void: shows to the standard input the value,dept and number of branches of the current tree"
	"\"changeValue(struct tree*,int)\" -> void: change the value of the current tree\n"
	"\"moveToTree(struc tree**,int)\" -> void: move to the desired tree based on the direction given as an integer number: 0 to go to the parent, 1,2,3... to go to the desired branch (branch 1, branch 2, branch 3...)\n"
	"\"addTree(struct tree*)\" -> void: add a child tree to the current tree and automatically set the dept as the dept of the current tree + 1, the value is setted to 0\n"
	);

	



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


void removeBranch(struct tree* t, int n){

	
	if(n>=t->nBranches){
		printf("ERROR: branch not defined: %d, there are only %d branches in the current tree\n",n,t->nBranches);
		return;
	}
	
	for(int i=n-1;i<t->nBranches-1;i++){
	
		t->branches[i]=t->branches[i+1];
		
	}


	t->nBranches--;
	t->branches=(struct tree*)realloc(t->branches,sizeof(t)*t->nBranches);




}



void moveToTree(struct tree** tr,int direction){
	
	struct tree* t= *tr;

	if(direction==0&& t->parent!=NULL){
		*tr=t->parent;
	}
	else if (direction-1 <  t->nBranches){

		*tr=&t->branches[direction-1];

	}
	else{
		printf("Direction not allowed: %d\n",direction);
		return;
	}

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
