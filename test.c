/*
 * myshell.c
 *
 *  Created on: 6 abr. 2020
 *      Author: Yago Navarrete Martinez
 */

#include <stdio.h>

#include "parser.h"

int
main(void) {
	char buf[1024];
	tline * line;
	int i,j;

	printf("==> ");
	while (fgets(buf, 1024, stdin)) {

		line = tokenize(buf);
		if (line==NULL) {
			continue;
		}
		if (line->redirect_input != NULL) {
			printf("redirecci�n de entrada: %s\n", line->redirect_input);
		}
		if (line->redirect_output != NULL) {
			printf("redirecci�n de salida: %s\n", line->redirect_output);
		}
		if (line->redirect_error != NULL) {
			printf("redirecci�n de error: %s\n", line->redirect_error);
		}
		if (line->background) {
			printf("comando a ejecutarse en background\n");
		}
		for (i=0; i<line->ncommands; i++) {
			printf("orden %d (%s):\n", i, line->commands[i].filename);
			for (j=0; j<line->commands[i].argc; j++) {
				printf("  argumento %d: %s\n", j, line->commands[i].argv[j]);
			}
		}
		printf("==> ");
	}
	return 0;
}

