/*
   二つの整数の和と差を求める
 */

#include<stdio.h>

/*--n1とn2の和・差をsumとdiffに格納(間違い) --*/
void sum_diff(int n1,int n2,int *sum,int *diff){
  *sum = n1 + n2;
  *diff = (n1 > n2) ? n1 - n2: n2 - n1;
}

int main(void){
  int na,nb;
  int wa, sa;

  puts("二つの整数を入力してください:");
  printf("整数A:"); scanf("%d",&na);
  printf("整数B:"); scanf("%d",&nb);

  sum_diff(na,nb,&wa,&sa);

  printf("和は%dです。\n差は%dです。\n",wa,sa);

  return 0;
}
