#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*void drwguide(int inc){
	if(inc < 1){
		for(int f = 0; f < inc; f++){
			printf("      ┌┐┌┐┌┐┌┐┌┐┌┐┌┐┌┐ \n  ┌──┴┘└┘└┘└┘└┘└┘└┘└┘└┴──┐ \n");
			fprintf(outfile, "      ┌┐┌┐┌┐┌┐┌┐┌┐┌┐┌┐ \n  ┌──┴┘└┘└┘└┘└┘└┘└┘└┘└┴──┐ \n");
		}
	}
	else{
		//Todo
	}
}*/
	
int main(int argc, char* argv[]){
	int line = 0;
	int incchar;
	int i;
	char curchar;
	char* outpath;

	FILE* infile;
	FILE* outfile;

	if(argv[1] == NULL){
		printf("Error\n");
		exit(1);
	}
	
	if(argv[2] == NULL){
		outpath = "out.txt";
	}
	else{
		outpath = argv[2];
	}

	infile = fopen(argv[1], "r+");
	outfile = fopen(outpath, "w");
	if(infile != NULL){
		printf("      ┌┐┌┐┌┐┌┐┌┐┌┐┌┐┌┐ \n  ┌──┴┘└┘└┘└┘└┘└┘└┘└┘└┴──┐ \n");
		fprintf(outfile, "      ┌┐┌┐┌┐┌┐┌┐┌┐┌┐┌┐ \n  ┌──┴┘└┘└┘└┘└┘└┘└┘└┘└┴──┐ \n");			//If file exists, get contents.
		while( (incchar = fgetc(infile)) != EOF){
			line++;		//Increase line counter.
			if(incchar == '\n' || incchar == 9){
				printf("  ┼   ");
				fprintf(outfile, "  ┼   ");
			}
			else{
				printf("%c¦┼   ", incchar);
				fprintf(outfile, "%c¦┼   ", incchar);
			}
			for (i = 7; i >= 0; i--){
				curchar = (incchar >> i) & 1;
  				if(curchar == 1){
					printf("██");
					fprintf(outfile, "██");
				}
				else{
					printf("  ");
					fprintf(outfile, "  ");
				}
			}
			printf("   ┼¦%d\n", incchar);
			fprintf(outfile, "   ┼¦%d\n", incchar);
		}
		printf(" ¦└──┬┐┌┐┌┐┌┐┌┐┌┐┌┐┌┐┌┬──┘¦\n     │└┘└┘└┘└┘└┘└┘└┘└┘│\n");
		fprintf(outfile, " ¦└──┬┐┌┐┌┐┌┐┌┐┌┐┌┐┌┐┌┬──┘¦\n     │└┘└┘└┘└┘└┘└┘└┘└┘│\n");
		fclose(infile);
		fclose(outfile);
	}
	else{		//Else, just create a new file.
		printf("Error\n");
		exit(1);
	}
	return 0;
}
