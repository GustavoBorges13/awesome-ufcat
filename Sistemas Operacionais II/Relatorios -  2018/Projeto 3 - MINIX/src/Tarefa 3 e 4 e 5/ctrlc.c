#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
int 
main(void)
{
	void            sigint_handler(int sig);	/* handler */
	char            s[200];
	/* … */
	if (signal(SIGINT, sigint_handler) == SIG_ERR) {
		perror("signal");
		exit(1);
	}
	printf("Entre uma string:\n");
	if (gets(s) == NULL)
		perror("gets");
	else
		printf("Voce digitou: \"%s\"\n", s);
	return 0;
}
/* handler */
void 
sigint_handler(int sig)
{
	printf("Agora nao!\n");
}
