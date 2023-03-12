#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>


/**
 * infinite_while - sleeps for infinity
 * Return: always 0
 */
int infinite_while(void)
{
	while (1)
	{
		sleep(1);
	}
	return (0);
}

/**
 * main - creates zombie processes
 * Return: always 0
 */
int main(void)
{
	int i, ppid, pid;

	for (i = 0; i < 5; i++)
	{
		ppid = fork();
		if (ppid == 0)
		{
			pid = fork();
			if (pid != 0)
			{
				printf("Zombie process created, PID: %d\n", pid);
				exit(0);
			}
			else
				break;
		}
	}
	infinite_while();
	return (0);
}
