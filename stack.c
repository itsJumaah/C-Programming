#include <stdio.h>

int stack[1000];
int counter = 0;

void push(int value) {
   stack[counter] = value;
   counter++;
}

void pop(void) {
   counter--;
}

int top(void) {
   return stack[counter-1];
}

int main() {
	int number;
   while (1) {
      scanf("%d", &number);
      if (number == -1) break;
      push(number);
   }
   while(1) {
      if (counter == 0) break;
      printf("%d ",top());
      pop();
   }
}

