#include <stdio.h>
#include <malloc.h>
#include <string.h>



char Zamien( int KodZnaku, int *TabKodow, char *TabZnakow, int Rozmiar)
{
  int i;

  for (i = 0;  i < Rozmiar; ++i) 
    if (KodZnaku == TabKodow[i]) return TabZnakow[i];

  return KodZnaku;
}


void KonwertujNapis( char *Napis, int *TabKodow, char *TabZnakow, int Rozmiar)
{
  unsigned int i;
 
  for (i = 0;  i < strlen(Napis); ++i)
    Napis[i] = Zamien(Napis[i],TabKodow,TabZnakow,Rozmiar);
}


int main()
{
  int  IloscKodow = 10;
  int  Rozmiar = IloscKodow * sizeof('¶');

  int  *TabKodow = (int*)malloc(Rozmiar);
  char *TabZnakow = (char*)malloc(IloscKodow*sizeof(char)); 
  char *Napis = strdup("Cze¶æ ¦wiecie!!! ¯yczê mi³ego dnia.");

  TabKodow[0] = 'æ';     TabZnakow[0] = 'c';
  TabKodow[1] = 'ê';     TabZnakow[1] = 'e';
  TabKodow[2] = '³';     TabZnakow[2] = 'l';
  TabKodow[3] = '¶';     TabZnakow[3] = 's';
  TabKodow[4] = '¦';     TabZnakow[4] = 'S';
  TabKodow[5] = '¯';     TabZnakow[5] = 'Z';
  TabKodow[6] = '¯';     TabZnakow[6] = 'Z';
  TabKodow[7] = '¯';     TabZnakow[7] = 'Z';
  TabKodow[8] = '¯';     TabZnakow[8] = 'Z';
  TabKodow[9] = '¯';     TabZnakow[9] = 'Z';    
  
  printf("Napis Latin2:  \"%s\"\n",Napis);

  KonwertujNapis(Napis,TabKodow,TabZnakow,IloscKodow);

  printf("Napis ASCII:   \"%s\"\n",Napis);

  return 0;
}

/*
Na komputerze:

adam@adam-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/Programowanie-obiektowe/zad1-AdamDomachowski/test2$ gcc -Wall -pedantic konwerter.c 
konwerter.c: In function ‘main’:
konwerter.c:30:38: warning: multi-character character constant [-Wmultichar]
   30 |   int  Rozmiar = IloscKodow * sizeof('¶');
      |                                      ^~~~
konwerter.c:36:17: warning: multi-character character constant [-Wmultichar]
   36 |   TabKodow[0] = 'æ';     TabZnakow[0] = 'c';
      |                 ^~~~
konwerter.c:37:17: warning: multi-character character constant [-Wmultichar]
   37 |   TabKodow[1] = 'ê';     TabZnakow[1] = 'e';
      |                 ^~~~
konwerter.c:38:17: warning: multi-character character constant [-Wmultichar]
   38 |   TabKodow[2] = '³';     TabZnakow[2] = 'l';
      |                 ^~~~
konwerter.c:39:17: warning: multi-character character constant [-Wmultichar]
   39 |   TabKodow[3] = '¶';     TabZnakow[3] = 's';
      |                 ^~~~
konwerter.c:40:17: warning: multi-character character constant [-Wmultichar]
   40 |   TabKodow[4] = '¦';     TabZnakow[4] = 'S';
      |                 ^~~~
konwerter.c:41:17: warning: multi-character character constant [-Wmultichar]
   41 |   TabKodow[5] = '¯';     TabZnakow[5] = 'Z';
      |                 ^~~~
konwerter.c:42:17: warning: multi-character character constant [-Wmultichar]
   42 |   TabKodow[6] = '¯';     TabZnakow[6] = 'Z';
      |                 ^~~~
konwerter.c:43:17: warning: multi-character character constant [-Wmultichar]
   43 |   TabKodow[7] = '¯';     TabZnakow[7] = 'Z';
      |                 ^~~~
konwerter.c:44:17: warning: multi-character character constant [-Wmultichar]
   44 |   TabKodow[8] = '¯';     TabZnakow[8] = 'Z';
      |                 ^~~~
konwerter.c:45:17: warning: multi-character character constant [-Wmultichar]
   45 |   TabKodow[9] = '¯';     TabZnakow[9] = 'Z';
      |                 ^~~~
adam@adam-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/Programowanie-obiektowe/zad1-AdamDomachowski/test2$ g++ -Wall -pedantic konwerter.c 
konwerter.c:30:38: warning: multi-character character constant [-Wmultichar]
   30 |   int  Rozmiar = IloscKodow * sizeof('¶');
      |                                      ^~~~
konwerter.c:36:17: warning: multi-character character constant [-Wmultichar]
   36 |   TabKodow[0] = 'æ';     TabZnakow[0] = 'c';
      |                 ^~~~
konwerter.c:37:17: warning: multi-character character constant [-Wmultichar]
   37 |   TabKodow[1] = 'ê';     TabZnakow[1] = 'e';
      |                 ^~~~
konwerter.c:38:17: warning: multi-character character constant [-Wmultichar]
   38 |   TabKodow[2] = '³';     TabZnakow[2] = 'l';
      |                 ^~~~
konwerter.c:39:17: warning: multi-character character constant [-Wmultichar]
   39 |   TabKodow[3] = '¶';     TabZnakow[3] = 's';
      |                 ^~~~
konwerter.c:40:17: warning: multi-character character constant [-Wmultichar]
   40 |   TabKodow[4] = '¦';     TabZnakow[4] = 'S';
      |                 ^~~~
konwerter.c:41:17: warning: multi-character character constant [-Wmultichar]
   41 |   TabKodow[5] = '¯';     TabZnakow[5] = 'Z';
      |                 ^~~~
konwerter.c:42:17: warning: multi-character character constant [-Wmultichar]
   42 |   TabKodow[6] = '¯';     TabZnakow[6] = 'Z';
      |                 ^~~~
konwerter.c:43:17: warning: multi-character character constant [-Wmultichar]
   43 |   TabKodow[7] = '¯';     TabZnakow[7] = 'Z';
      |                 ^~~~
konwerter.c:44:17: warning: multi-character character constant [-Wmultichar]
   44 |   TabKodow[8] = '¯';     TabZnakow[8] = 'Z';
      |                 ^~~~
konwerter.c:45:17: warning: multi-character character constant [-Wmultichar]
   45 |   TabKodow[9] = '¯';     TabZnakow[9] = 'Z';
      |                 ^~~~
      
      
Na diablo:

diablo-bash-3.2$ gcc -Wall -pedantic konwerter.c 
diablo-bash-3.2$ ./a.out
Napis Latin2:  "Cze�� �wiecie!!! �ycz� mi�ego dnia."
Napis ASCII:   "Czesc Swiecie!!! Zycze milego dnia."
diablo-bash-3.2$ 
diablo-bash-3.2$ g++ -Wall -pedantic konwerter.c 
diablo-bash-3.2$ ./a.out
Napis Latin2:  "Cze�� �wiecie!!! �ycz� mi�ego dnia."
Napis ASCII:   "Cze�� �wiecie!!! �ycz� mi�ego dnia."
diablo-bash-3.2$ 

      
      
      
      
*/
