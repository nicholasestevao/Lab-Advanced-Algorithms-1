#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define NUM_PHILOSOPHERS 5
#define NUM_REFEICOES 10

typedef struct monitor {
    pthread_mutex_t mutex;
    enum {THINKING, HUNGRY, EATING} state[5];
    pthread_cond_t self[NUM_PHILOSOPHERS];
    int num_times_eating[NUM_PHILOSOPHERS];
} monitor;

typedef struct {
    monitor *m;
    int indice;
} args;

void test(monitor *m, int i) {
    pthread_mutex_lock(&(m->mutex));
    //printf("Filosodo que menos comeu: %d vezes - atual %d\n", min,m->num_times_eating[i]);
    if ((m->num_times_eating[i] < NUM_REFEICOES ) && (m->state[(i + 4) % 5] != EATING) && (m->state[i] == HUNGRY) && (m->state[(i + 1) % 5] != EATING)) {
        m->state[i] = EATING;
        m->num_times_eating[i]++;
        pthread_cond_signal(&(m->self[i]));
        //printf("Atendeu filosofo %d\n", i);
    }else{
        //printf("Negou filosofo %d\n", i);
    }
    pthread_mutex_unlock(&(m->mutex));
}

void delay(int seconds){	
	int start = clock();
	// wait n seconds
    	while (((clock()-start)/CLOCKS_PER_SEC)<seconds);         
}

void pickup(monitor *m, int i) { 
    m->state[i] = HUNGRY; 
    test(m, i);
    if (m->state[i] != EATING)
        pthread_cond_wait(&m->self[i], &m->mutex);
}

void putdown(monitor *m, int i) { 
    m->state[i] = THINKING; 
    test(m, (i + 4) % 5); 
    test(m, (i + 1) % 5);
}

void initialization_code(monitor *m) {
    for (int i = 0; i < NUM_PHILOSOPHERS; i++){
        m->state[i] = THINKING;
        m->num_times_eating[i] = 0;
    }
}

void *runner(void *param){
    args * a = (args *) param;
    monitor* DiningPhilosophers = a->m;
    int i = a->indice;
    int j = 0;
	while (j <NUM_REFEICOES) { 
        pickup(DiningPhilosophers, i);
        pickup(DiningPhilosophers, (i+1) % 5);
        //printf("Filosofo %d esta comendo \n", i);
        delay(3);
        /* eat for a while */
        putdown(DiningPhilosophers, i);
        putdown(DiningPhilosophers, (i+1) % 5);
        /* think for awhile */
        //printf("Filosofo %d esta pensando \n", i);
        delay(2);
        j++;
    }
    printf("Fim da thread do filosofo %d\n", i);
	pthread_exit(0);
}


int main(int argc, char *argv[])
{
    pthread_t workers[NUM_PHILOSOPHERS]; /* n thread identifiers */

    pthread_attr_t attr; /* set of attributes for the thread */

    /* get the default attributes */
    pthread_attr_init(&attr);
    monitor DiningPhilosophers;
    initialization_code(&DiningPhilosophers);
    args a;
    a.m = &DiningPhilosophers;  
    /* create the thread */
    for(int i = 0; i< NUM_PHILOSOPHERS; i++){
        a.indice = i;
        pthread_create(&workers[i],&attr,runner, &a);
        delay(1);
    }

    /* now wait for the thread to exit */
    for(int i = 0; i< NUM_PHILOSOPHERS; i++){
        pthread_join(workers[i],NULL);
    }

    for(int i=0; i<NUM_PHILOSOPHERS; i++){
        printf("Filosofo %d comeu %d vezes\n", i, DiningPhilosophers.num_times_eating[i]);
    }

}


