/*
  cgi-hello.c --簡単な CGI のプログラム
  ~yas/syspro/www/cgi-hello.c
*/

#include <stdlib.h>	/* exit() */
#include <stdio.h>	/* printf() */

extern void print_header();
extern void print_content();

int
main()
{
	print_header();
	print_content();
}

void
print_header()
{
	printf("Content-Type: text/html\n");
	printf("\n");
}

void
print_content()
{
	printf("<HTML><HEAD></HEAD><BODY>\n");
	printf("hello.\n");
	printf("</BODY></HTML>\n");
}
