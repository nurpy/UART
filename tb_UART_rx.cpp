#include<iostream>
#include<VUART_rx.h>
#include<verilated.h>
#include "stdio.h"
#include "stdlib.h"

VUART_rx *tb;

void tick(){
	tb->clk=0;
	tb->eval();
	tb->clk=1;
	tb->eval();
}
void readString(){
	std::cout << "Val read currently is : " << tb->readval << tb->rx_done << std::endl;
	printf("%d\n",tb->rx_done);
	printf("%d\n",tb->readval);
	printf("Current state is %d\n",tb->UART_rx__DOT__stateReg);
}
void reset(){
	tb->rst = 0;
	tb->eval();
	tb->rst = 1;
	tb->eval();
	tb->rst = 0;
}
void testString(int a[],int arrLength){
	tb->rx = 1;
	tb->rst = 0;
	tb->eval();
	int count =0;
	for(int i = 0 ; i < 100000 ; i++){
		tick();
		if((i % (163 *16)) == 0 ){
				
	//		readString();
	//		printf("Current bit is : %d\n", tb->rx);
			tb->rx =a[count];
			count++;
			count = count == arrLength ? 0 : count;
		}
		
		if(tb->rx_done){
			readString();
		}
		
	}
}

int main(){
	

	tb = new VUART_rx;
	int word[] = {1,1,0,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1};
	int arrLength = sizeof(word)/sizeof(word[0]);
	reset();
	testString(word,arrLength);




	return 0;
}
