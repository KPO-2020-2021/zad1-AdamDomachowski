#include <stdio.h>
#include <math.h>


struct TrojmianKw {
  double  a;
  double  b;
  double  c;
};


typedef struct TrojmianKw  TrojmianKw;



int main() {
  TrojmianKw   TKw;
  double       Delta, Delta_2;
  double       X1, X2;
  int          Ilosc_Pierwiastkow;
  
  printf("Program wylicza rozwiazania trojmianu kwadratowego.\n");
  printf("Podaj wspolczynnik a:\n");
  scanf("%lf", &TKw.a);
  printf("Podaj wspolczynnik b:\n");
  scanf("%lf", &TKw.b);
  printf("Podaj wspolczynnik c:\n");
  scanf("%lf", &TKw.c);


  if (TKw.a == 0) {
    printf("Wprowadzone wsplczynniki a musi byc rozny od zera.\n");
    return 1;
  }


  printf(" Postac trojmianu kwadratowego: %fx^2 + %fx + %f\n",TKw.a,TKw.b,TKw.c);
  
  Delta_2  = (TKw.b*TKw.b) - (4.0*TKw.a*TKw.c);

  
  if (Delta_2 > 0) {

      Delta = sqrt( Delta_2 );
      X1 = (-TKw.b - Delta) / (2*TKw.a);
      X2 = (-TKw.b + Delta) / (2*TKw.a);
      Ilosc_Pierwiastkow = 2;      

  } else if  (Delta_2 == 0) {

      X1 = -TKw.b/(2*TKw.a);
      Ilosc_Pierwiastkow = 1;

  } else { /* czyli d <= 0 */
      Ilosc_Pierwiastkow = 0;
  }


  switch (Ilosc_Pierwiastkow) {
    case 2:
      printf("Istnieja dwa rozwiazania rzeczywiste:\n");
      printf("  x1 = %f\n", X1);
      printf("  x2 = %f\n", X2);
      break;

    case 1:
      printf("Istnieje jedno rozwiazanie: %f\n", X1);
      break;

    case 0:
      printf("Nie istnieje rozwiazanie w zbiorze liczb rzeczywistych\n");      
      break;
  }

  return 0;
}




/* Na komputerze:

adam@adam-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/Programowanie-obiektowe/zad1-AdamDomachowski/test1$ gcc -Wall -pedantic rownanie.c -lm
adam@adam-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/Programowanie-obiektowe/zad1-AdamDomachowski/test1$ ./a.out
Program wylicza rozwiazania trojmianu kwadratowego.
Podaj wspolczynnik a:
1
Podaj wspolczynnik b:
1
Podaj wspolczynnik c:
1
 Postac trojmianu kwadratowego: 1.000000x^2 + 1.000000x + 1.000000
Nie istnieje rozwiazanie w zbiorze liczb rzeczywistych
adam@adam-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/Programowanie-obiektowe/zad1-AdamDomachowski/test1$ g++ -Wall -pedantic rownanie.c -lm
adam@adam-ASUS-TUF-Gaming-A15-FA506II-FA506II:~/Programowanie-obiektowe/zad1-AdamDomachowski/test1$ ./a.out
Program wylicza rozwiazania trojmianu kwadratowego.
Podaj wspolczynnik a:
1
Podaj wspolczynnik b:
1
Podaj wspolczynnik c:
1
 Postac trojmianu kwadratowego: 1.000000x^2 + 1.000000x + 1.000000
Nie istnieje rozwiazanie w zbiorze liczb rzeczywistych

--------------------------------------------------

Na Diablo:

diablo-bash-3.2$ gcc -Wall -pedantic rownanie.c -lm
diablo-bash-3.2$ ./a.out
Program wylicza rozwiazania trojmianu kwadratowego.
Podaj wspolczynnik a:
1
Podaj wspolczynnik b:
1
Podaj wspolczynnik c:
1
 Postac trojmianu kwadratowego: 1.000000x^2 + 1.000000x + 1.000000
Nie istnieje rozwiazanie w zbiorze liczb rzeczywistych
diablo-bash-3.2$ 
diablo-bash-3.2$ g++ -Wall -pedantic rownanie.c -lm
rownanie.c: In function 'int main()':
rownanie.c:37:83: warning: ISO C++98 does not support the '%lf' gnu_printf format [-Wformat=]
   printf(" Postac trojmianu kwadratowego: %lfx^2 + %lfx + %lf\n",TKw.a,TKw.b,TKw.c);
                                                                                   ^
rownanie.c:37:83: warning: ISO C++98 does not support the '%lf' gnu_printf format [-Wformat=]
rownanie.c:37:83: warning: ISO C++98 does not support the '%lf' gnu_printf format [-Wformat=]
rownanie.c:62:32: warning: ISO C++98 does not support the '%lf' gnu_printf format [-Wformat=]
       printf("  x1 = %lf\n", X1);
                                ^
rownanie.c:63:32: warning: ISO C++98 does not support the '%lf' gnu_printf format [-Wformat=]
       printf("  x2 = %lf\n", X2);
                                ^
rownanie.c:67:53: warning: ISO C++98 does not support the '%lf' gnu_printf format [-Wformat=]
       printf("Istnieje jedno rozwiazanie: %lf\n", X1);
       
       
Jak widać wyniki różnią się na diablo w internecie znalazłem artykuł sugerujący zamiast %lf napisać %f w tedy działa. Najprawdopodobniej chodzi o to 
ze ISO C++98 nie wspiera %lf.

*/


