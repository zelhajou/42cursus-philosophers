// create 5 threads where each one will increment a variable 10 times, using one mutex !
// use pthread_detach and an infinite loop in the main thread where it will check if the value 
//of the variable reached the desired amount

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdbool.h>

typedef struct s_philo_2
{
	int				id;
	pthread_t t;
	pthread_mutex_t *mut;
	int *n;
} t_philo_2;

void *add(void *m)
{
	pthread_mutex_t *o;
	t_philo_2 *p;
	p = (t_philo_2 *)m;
	o = (pthread_mutex_t *)p->mut;
	for (int i = 0; i < 10; i++)
	{
		pthread_mutex_lock(o);
		(*(p->n))++;
		pthread_mutex_unlock(o);
	}
	return NULL;
}

int main ()
{
	int *a = malloc(sizeof(int));
	t_philo_2	*philo_2;
	// pthread_t t1;
	// pthread_t t2;
	pthread_mutex_t *mutww = malloc(sizeof(pthread_mutex_t));
	philo_2 = malloc(sizeof(t_philo_2) * 5);
	int i = 0;
	a = &i;

	for (int i = 0; i < 5; i++)
	{
		philo_2[i].id = i + 1;
		philo_2[i].n = a;
		philo_2[i].mut = mutww;
		pthread_mutex_init(philo_2[i].mut, NULL);
		pthread_create(&philo_2[i].t, NULL, add, &philo_2[i]);
		pthread_detach(philo_2[i].t);
	}
	while (1)
	{
		pthread_mutex_lock(mutww);
		printf("%d\n", *a);
		if (*a == 50)
			break;
		pthread_mutex_unlock(mutww);
	}
	return 0;
}
