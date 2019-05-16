/*

# caratteri

# Programmi di Laboratorio di Programmazione in Linguaggio "C". Alunno: Bucchianico Enrico Ruggiero, 4^Finf.


- Programa "stampaparole.c": Programma che stampa, una per riga, le parole di un testo fornito allo standard input. Si ipotizza che nel testo in ingresso non siano presenti spazi multipli.

*/

#include <stdio.h>

int main()
{

	/*
	
		STATI:
		1)	"INIZ"=Carattere iniziale;
		2)	"INT"=Interno alla parola;
		3)	"EST"=esterno alla parola.
		TABELLA STATI:
		Stato:		Input:		Output:		Nuovo Stato:
		INIZ		c==' ' or
				c=='\n' or
				c=='\t'				EST
		INIZ		c!=' ' and
				c!='\n' and
				c!='\t'		p++		INT
		INT		c==' ' or
				c=='\n' or
				c=='\t'				EST
		INT		c==' ' and
				c=='\n' and	p++
				c=='\t'
		EST		c==' ' and
				c=='\n' and
				c=='\t'		p++		INT
	*/

	enum Stato{INIZ,INT,EST};

	int stato=INIZ,c;

	while ((c=getchar())!=EOF)
	{

		if(stato==INIZ)
		{
	
			if(c==' '||c=='\n'||c=='\t')
			{

				stato=EST;

			}
			else
			{
    
				putchar(c);
				stato=INT;

			}

		}
		else if(stato==INT)
		{

			if(c==' '||c=='\n'||c=='\t')
			{

				putchar('\n');
				stato=EST;

			}
			else
			{

				putchar(c);

			}

		}
		else if(stato==EST)
		{

			putchar(c);
			stato=INT;

		}
	}

	putchar('\n');

	return 0;
}