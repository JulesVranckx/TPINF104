#include <stdio.h>

int * alloc(int val);
void swap(float*  f1, float* f2);

int main(int argc, char *argv[]) {
  int * ptr = alloc(7);
  int i;
  for (i = 0; i < 20; i++)
  {
    printf("%d \n", ptr[i]);
  }

  float f1=0.7;
  float f2=1.2;
  // use swap to put value of f1 in f2 and vice-versa
  // use printf to display values of f1 and f2
  swap(&f1, &f2);
  printf("%f, f2 : %f\n",f1, f2 );
  return 0;
}

int * alloc (int val){
   int tab[20];
   int * ptr = tab;
   int i;

   for (i = 0; i < 20; i++)
   {
     tab[i] = val;
   }

   return ptr;
}

void swap(float * f1, float * f2)
{
  float * temp = f1;
  f1 = f2;
  f2 = temp;

}
