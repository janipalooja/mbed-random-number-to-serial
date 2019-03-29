#include "mbed.h"

AnalogIn ain(A0);
Serial pc(USBTX, USBRX);

int randomNumber = 0;

uint32_t seed =0;

int main() {

    while (true){ 
 
		for (int i = 0; i < 32; i++) {
			
		  seed ^= ain.read_u16();
		  
		  if (seed & 1 < 31) {
			  seed <<= 1;
			  seed |= 1;
		  }
      		else {
			  seed <<= 1;
		  }
      
		}
		
		srand(seed);
		
		randomNumber = rand() % 30 + 1;
		
		pc.printf("%i\n", randomNumber);
		
		wait(3.0f);
		
    }   
	
}
