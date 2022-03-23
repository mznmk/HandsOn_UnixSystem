/*
  fork-hello.c -- 画面に文字列を表示するプログラム
  ~yas/syspro/proc/fork-hello.c
  Start: 2001/05/13 23:19:01
*/

#include <stdio.h>
#include <unistd.h> /* fork() */

int main()
{
	fork();
	fork();
	fork();
	printf("hello\n");
}