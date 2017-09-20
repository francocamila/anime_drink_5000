1. Quais são as vantagens e desvantagens em utilizar:

(a) fork?

Vantagens: A aplicação roda vários programas filho, cada filho executa sua própria tarefa, cada filho tem seu espaço de memória protegido, a comunicação é feita por mecanismos: pipes, sinais, etc. Desvantagens: Troca de contexto (Heavyweight). 

(b) threads?

Vantagens: Uma só aplicação pode rodar várias threads, todas as threads compartilham o mesmo espaço de memória, a comunicação é mais simples por usar memória compartilhada, troca de contexto (lightweight). Desvantagens: Risco de corrupção de dados. 

2. Quantas threads serão criadas após as linhas de código a seguir? Quantas coexistirão? Por quê?

(a)

```C
void* funcao_thread_1(void *arg);
void* funcao_thread_2(void *arg);

int main (int argc, char** argv)
{
	pthread_t t1, t2;
	pthread_create(&t1, NULL, funcao_thread_1, NULL);
	pthread_create(&t2, NULL, funcao_thread_2, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return 0;
}
```

Duas threads serão criadas, e duas coexistirão, pois a main espera as duas terminarem para poder terminar.

(b)
```C
void* funcao_thread_1(void *arg);
void* funcao_thread_2(void *arg);

int main (int argc, char** argv)
{
	pthread_t t1, t2;
	pthread_create(&t1, NULL, funcao_thread_1, NULL);
	pthread_join(t1, NULL);
	pthread_create(&t2, NULL, funcao_thread_2, NULL);
	pthread_join(t2, NULL);
	return 0;
}
```
Duas threads serão criadas, mas não coexistiram, pois a função main está esperando somente uma antes de terminar.

3. Apresente as características e utilidades das seguintes funções:

(a) `pthread_setcancelstate()`
Seta o estado de cancelamento da. thread para o valor dado no estado. O argumento de estado deve ter um dos seguintes valores: PTHREAD_CANCEL_ENABLE: a thread é cancelável. Esse é o padrão de cancelamento de estado em todas as novas threads, incluindo a thread inicial. PTHREAD_CANCEL_DISABLE: A thread não é cancelável. Se um pedido de cancelamento é recebido, é cancelado até o cancelamento for ativado.


(b) `pthread_setcanceltype()`
Seta o tipo de cancelamento da thread para um valor dado no tipo. O tipo de cancelamento anterior é retornado pelo buffer apontado por "oldtype". O argumento type deve ter um dos seguintes valores: PTHREAD_CANCEL_DEFERRED: Um pedido de cancelamento é diferido até a thread chamar uma função que é um ponteiro de cancelamento. PTHREAD_CANCEL_ASYNCHRONOUS: A thread pode ser cancelada a qualquer momento. 

(DICA: elas são relacionadas à função pthread_cancel().)
