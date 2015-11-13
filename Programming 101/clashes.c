//Timetable program
#include <stdio.h>

struct studentRecord {
	int num; //ID number
	int numPapers;
	paperRecord paper[5];
};

//function prototype

studentRecord student;

int main() {
	student=getInfo();
	checkclashes(student);
}

void checkclashes(studentRecord x) {
	int i, j;
	bool clash;
	clash=false;
	for(i=0; i<x.paper[1].numLectures; i++) {
		for(j=0; j<x.paper.numLectures; j++) {
			if(x.paper[0].lecture[i].day==x.paper[1].lecture[j].day) {
				if(x.paper[0].lecture[i].hour==x.paper[1].lecture[j].hour) {
					printf("Clash!");
					clash=true;
				}
			}
		}
	}
}

//159235