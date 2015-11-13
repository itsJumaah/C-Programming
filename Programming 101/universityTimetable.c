#include <stdio.h>
#include <string.h>

struct lectureTime {
	char day;
	int hour;
};

struct paperRecord {
	float num;					//paper number
	char name[80];				//paper name
	int numLectures;			//number of lectures
	lectureTime lecture[6];		//lecture times
};

paperRecord paper;
paperRecord getdetails();
lectureTime getTime();
void display();


int main() {
	paper=getdetails();
	display(paper);
}

paperRecord getdetails() {
	paperRecord p;
	char temp[80];
	int i;
	printf("Enter the paper number: ");
	gets(temp);
	sscanf(temp, "%f", &p.num);
	printf("Enter the paper name: ");
	gets(p.name);
	printf("How many lectures? ");
	gets(temp);
	sscanf(temp, "%d", &p.numLectures);
	for(i=0; i<p.numLectures; i++) {
		printf("Enter details of lecture %d", i+1);
		p.lecture[i]=getTime();
	}
	return p;
}

lectureTime getTime() {
	lectureTime c;
	char temp[55];
	int clockk;
	char code;
	printf("Enter the day (eg. Mon, Tues, Wed..): ");
	gets(temp);
	c.day=temp[0];
	if((temp[1]=='h')||(temp[1]=='H')) {
		c.day='H';
	}
	printf("Enter time as 24 hour clock:" );
	gets(temp);
	sscanf(temp, "%d", &p.hour);
	// some checking is missing!
}