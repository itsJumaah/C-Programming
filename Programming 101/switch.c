switch(month) {								 //its like; if month==somthing
	case something:							 //something
		days=leapyear(year);
		break; 								//we have to break after each case
	
	case somehing2: case something3: 		//||something2||something3
		days=30;
		break;

	default:								//its like the final else
		days=31;
}
return days;


switch limitations:
____________________

only for int and char
only works for == 							//dont work for range


Menu
____

bool running;
running=true;
while(running) {
	printf("Select A, B, C or Q");
	choice=getch();
	switch(choice) {
		case 'A': case 'a': search();
							break;
		case 'B': case 'b': display();
							break;
		case 'C': case 'c': entername();
							break;
		case 'Q': case 'q': running=false;
							break;
	}
}
