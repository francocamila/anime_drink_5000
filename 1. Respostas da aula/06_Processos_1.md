1. Como se utiliza o comando `ps` para:

(a) Mostrar todos os processos rodando na máquina?

```
$ ps -aux | less
```


(b) Mostrar os processos de um usuário?

```
$`ps -u [usuário]
```


(c) Ordenar todos os processos de acordo com o uso da CPU?

```
$ ps aux k-pcpu
```


(d) Mostrar a quanto tempo cada processo está rodando?

```
$ ps -ef
```

2. De onde vem o nome `fork()`?

De bifurcação, quando um projeto independente é criado com base no código de um projeto já existente.

3. Quais são as vantagens e desvantagens em utilizar:

(a) `system()`?

A função não afeta o estado de espera dos processos filhos. Ela retorna em sua saída o status do comando no shell. É uma função de uso simples. A desvantagem é que dá brechas a falhas de execução pois depende muito do sistema. 

(b) `fork()` e `exec()`?

Fork() cria um novo processo, que é uma cópia do processo atual e exec() substitui o conteúdo do novo processo por um novo programa. Se fork() não for utilizado corretamente, a comunicação entre pai e filho se pode se tornar confusa. A possível desvantagem da função exec() é que deve esperar o subprocesso morrer antes de continuar. 

4. É possível utilizar o `exec()` sem executar o `fork()` antes?

Sim, o exec cria um novo processo, um processo filho, mas a função mata o pai e o filho pega sua PID.

5. Quais são as características básicas das seguintes funções:

(a) `execp()`?
A função aceita que o nome ou procura do programa esteja no current path; funções que não possuem o 'p' devem conter o caminho completo do programa a ser executado.

(b) `execv()`?
A função aceita que a lista de argumentos do novo programa seja nula. 

(c) `exece()`?
A função aceita um argumento adicional.

(d) `execvp()`?

Aceita que o nome ou procura do programa esteja no current path e que a lista de argumentos do novo programa seja nula.

(e) `execve()`?
Aceita que a lista de argumentos do novo programa seja nula e aceita um argumento adicional.

(f) `execle()`?
A função aceita em sua lista de arguments a utilização de mecanismos var args e um argumento adicional.
