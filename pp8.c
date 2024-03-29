#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

const char VERSIONSNR[] = "0.1";

int suche(int liste[], int suche, int laenge)
{
	for(int i=0; i < laenge; i++){
		if(liste[i] == suche){ //Jedes Element des Arrays mit dem Suchwert abgleichen. 
			return i; 
		}
	}
	return -1;
}

int main(int argc, char* argv[]){
	
	int option;
	int suchwert;
	int ergebnis;
	int liste[] = {8, 5, 10, 6, 3, 9};

	while((option = getopt(argc, argv, "hv"))!=-1)
	switch(option)
	{
		case 'h': 
			printf("-h -> Hilfe aufrufen\n");
			printf("-v -> Version anzeigen\n");
			exit(0);

		case 'v':
			printf("Version %s\n", VERSIONSNR);
			exit(0);

		default:
			printf("Etwas ist schiefgelaufen!\n");
			printf("Benutze -h fuer die Hilfe!\n");
			exit(0);
	}

	printf("Nach welcher Zahl wollen Sie suchen?\n");
	scanf("%d", &suchwert);
	
	if((ergebnis = suche(liste, suchwert, sizeof liste/ sizeof liste[0])) == -1){ //Wenn Suchwert mit keinem Element des Arrays matched
		printf("Die gesuchte Zahl kommt nicht in der Liste vor!\n");
	}	
	else{
		printf("Die gesuchte Zahl %d kommt an Stelle %d der Liste vor!\n", suchwert, ergebnis+1); 
	}
	return 0;
}
