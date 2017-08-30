1. Considerando a biblioteca-padrão da linguagem C, responda:

(a) Quais são as funções (e seus protótipos) para abrir e fechar arquivos?

fopen

protótipo:
```
FILE *fopen (char *nome_do_arquivo, *modo);
```
fechar: fclose.

int fclose (FILE *ponteiro_para_arquivo);

(b) Quais são as funções (e seus protótipos) para escrever em arquivos?

fwrite

```
size_t fwrite(const void *pointer, size_t size, size_t number_menb, FILE *stream);
```


(c) Quais são as funções (e seus protótipos) para ler arquivos?

fread

```
size_t fread(void *pointer, size_t size, size_t number_menb, FILE *stream);

(d) Quais são as funções (e seus protótipos) para reposicionar um ponteiro para arquivo?

fseek

```
int fseek(FILE *stream, long int offset, int whence);
```

(e) Quais bibliotecas devem ser incluídas no código para poder utilizar as funções acima?
stdio.h
stdlib.h

2. O que é a norma POSIX?

É a norma que especifica as interfaces do utilizador e do software ao sistemas operativo em 15 documentos 

3. Considerando a norma POSIX, responda:

(a) Quais são as funções (e seus protótipos) para abrir e fechar arquivos?

Abrir:
```
open
```
Protótipo:
```
int open(const char* path, int oflag);
```

Fechar:
```
close
```

Protótipo:
```
int close(int file);
```

(b) Quais são as funções (e seus protótipos) para escrever em arquivos?

write

protótipo:
```
ssize_t write(int file, const void *buf, size_t nbyte);
```

(c) Quais são as funções (e seus protótipos) para ler arquivos?

read

protótipo:
```
ssize_t read(int file, void *buf, size_t nbyte);
```


(d) Quais são as funções (e seus protótipos) para reposicionar um ponteiro para arquivo?

lseek

protótipo:
```
off_t lseek(int file, off_t offset, int whence);
```


(e) Quais bibliotecas devem ser incluídas no código para poder utilizar as funções acima?
fcntl.h
unistd.h
stdio.h
stdlib.h
sys/types.h
