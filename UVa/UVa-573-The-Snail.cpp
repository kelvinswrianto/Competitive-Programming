#include <stdio.h>

int main(){
	while(true){
		float h, u, d, f, pos=0;
		int counter = 1;
		bool status;
		// h height of well
		// u distance climb
		// d distance slide
		// f fatigue factor
		scanf("%f %f %f %f", &h, &u, &d, &f);
		f = u*f/100;
		if(h == 0){
			break;
		}
		else{
			while(true){
				if(u > 0){
					pos = pos + u;	
				}
				
				if(pos > h){
					status = true;
					break;
				}
				else{
					pos = pos - d;
					u = u - f;
					if(pos < 0){
							status = false;
							break;
					}
					counter++;
				}
				//printf("pos : %f, fatigue : %f, climb : %f, slide : %f, day : %d \n", pos, f, u, d, counter);
			}
			if(status == true){
				printf("success on day %d\n", counter);
			}
			else{
				printf("failure on day %d\n", counter);
			}	
		}
	}
	return 0;
}
