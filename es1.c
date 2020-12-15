#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>

int main(int argc, char **argv){
	/*Creazione di un file vuoto con dimensione 0 byte*/
	FILE *fh = fopen("script.sh", "w");
	fclose(fh);
	
	/*Imposto i permessi a 0755*/
	const char mode[] = "0777"; //imposto i permessi 
    	const char buf[100] = "script.sh"; //imposto il pathname del file
	int i;
    	i = strtol(mode, 0, 8); //conversione di stringa in ottale
   	 if (chmod (buf,i) < 0) //controllo se c'è un errore dopo la conversione
    	{
        	fprintf(stderr, "%s: error in chmod(%s, %s) - %d (%s)\n",
                argv[0], buf, mode, errno, strerror(errno));
   	     	exit(1);
    	}

	return 0;
}
