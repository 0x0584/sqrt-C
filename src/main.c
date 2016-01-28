#include <stdio.h>
#include <stdlib.h>
 #define KRED  "\x1B[31m"
 #define RESET "\033[0m"
 #define KYEL  "\x1B[33m"
 #define KBLU  "\x1B[34m" 
int main (int argc, char *argv[]) {
	float val, min, max; 
	float mid;//mid is sqrt()
	float S, _mid;
	int step = 0;
	
	// enter an argument,
	
	if (argc < 2) {
		printf ("Usage: sqrt <number>\n");
		return 1;
	}
	    val = fabs (atof (argv[1]));// <force to non-negative.>
		min = 0;//minimum 
		max = mid = val;//maximum 
		_mid = 1;
		//1e-8 = 10^(-8) = 0.00000001
		while (fabs(_mid - mid) >= 1e-8) {
			_mid = mid;//keep the old sqrt()
			mid = (max + min) / 2;
			S = mid * mid;//S is mid^(2)
			printf("test n(%d)\tsqrt(%f) = %.6f\t",++step,val, mid);
			if (S > val) {
				puts("too high");
				printf(KYEL);
				printf("\t\t=%s %f\n","the old max",max);
				printf("\t\t=%s %f\n","the old min",min);
				max = mid;//setting max to the current mid
				printf("\t\t>%4s %f","the new max",max);
				printf(RESET);
			} else {
				puts("too low");
				printf(KBLU);
				printf("\t\t-%s %f\n","the old max",max);
				printf("\t\t-%s %f\n","the old min",min);
				min = mid;//setting min to the current mid
				printf("\t\t>%4s %f","the new min",min);
				printf(RESET);
			}//end else
			puts("");
		}//end while
		puts("");
		printf(KRED);
		puts("\t====================================================");
		printf ("\tfinal value.\tsqrt(%f) = %.6f\n", val, mid);
		puts("\t====================================================");
		printf(RESET);
	return 0;
}//end main()
