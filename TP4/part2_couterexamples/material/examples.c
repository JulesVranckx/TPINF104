#include <stdio.h>
#include <stdlib.h>

int * alloc(int val);
void swap(float*  f1, float* f2);

int main(int argc, char *argv[]) {
  int * tab = alloc(7);
  int i;
  for (i = 0; i < 20; i++)
  {
    printf("%d \n", tab[i]);
  }

  float f1=0.7;
  float f2=1.2;
  // use swap to put value of f1 in f2 and vice-versa
  // use printf to display values of f1 and f2
  swap(&f1, &f2);
  printf("f : %f, f2 : %f\n",f1, f2 );
  return 0;
}

int * alloc (int val){

   int * ptr;
   ptr = (int *)malloc(20 * sizeof(int));
   int i;

   for (i = 0; i < 20; i++)
   {
     ptr[i] = val;
   }

   return ptr;
}

void swap(float * f1, float * f2)
{
  static int compteur ;
  compteur ++;
  printf("%d\n", compteur);
  float temp = *f1;
  *f1 = *f2;
  *f2 = temp;

}
