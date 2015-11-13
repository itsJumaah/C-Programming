#include <stdio.h>
#include <string.h>

struct stock {  
	char name[60];		//name of item, eg. pencil
	int amount;			//number of items.
	float price;		//cost of one item.
};		

stock item1, item2;		
stock loaddata(char *n, int a, float p);
void displayitem(stock thing);
int main() {
	int choice;
	item1=loaddata("Pen", 100, 7.35);
	displayitem(item1);
	item2=loaddata("Pencil", 150, 3.90);
	displayitem(item2);
	printf("Select 1 to buy %s or 2 to buy %s", item1.name, item2.name);
	scanf("%d", &choice);
	if(choice==1) {
		printf("You must pay $%1.2f\n", item1.price);
		item1.amount--;
		displayitem(item1);
	}
	if(choice==2) {
		printf("You must pay $%1.2f\n", item2.price);
		item2.amount--;
		displayitem(item2);
	}
}

stock loaddata(char *n, int a, float p) {
	stock temp;
	strcpy(temp.name, n);
	temp.amount=a;
	temp.price=p;
	return temp;
}


void displayitem(stock thing) {
	printf("%d %s @ $%1.2f\n", thing.amount, thing.name, thing.price);
}
	