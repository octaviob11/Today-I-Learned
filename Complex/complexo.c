#include <stdio.h>
#include <math.h>
//Biblioteca de números complexos e filtro FIR


//Parametro ALPHA
// Parametro Alpha = 0.1102(Att−8.7)
// Para Att = 60db -> Alpha = 5.65326

DEFINE H_ALPHA  5.653236



 typedef struct complexo { 
	float real; 
	float img; 
} Complexo ;

Complexo SomaComplexo( Complexo *a,  Complexo *b)
{
	Complexo resultado;
	resultado.real = a->real + b->real;
	resultado.img = a->img + b->img;
	return resultado;

}

 Complexo MultiplicaComplexo( Complexo *a,  Complexo *b)
{
	Complexo resultado;
	resultado.real = a->real*b->real -(a->img*b->img);
	resultado.img = a->img*b->real + a->real*b->img;
	return resultado;
}

 Complexo DivideComplexo( Complexo *a,  Complexo *b)
{
	Complexo resultado;
	resultado.real = (a->real*b->real +a->img*b->img)/(b->real*b->real+b->img*b->img);
	resultado.img = (b->real*a->img -(a->real*b->img))/(b->real*b->real+b->img*b->img);
	return resultado;
}

float Ino(float x)
{
  /*
   * This function calculates the zeroth order Bessel function
   */
  float d = 0;
  float ds = 1;
  float s = 1;
  while (ds > s*0.000001)
  {
    d += 2;
    ds *= x*x/(d*d);
    s += ds;
  }
  return s;
}



//Calculo dos coeficientes para um filtro passa baixa ideal:
//Sin(i*X) = i*sinh
//A[j] = (sin(2*j*pi*freq_corte/freq_amostragem))/(j*pi);


const int freq_amostragem = 8000;
int freq_corte = 2500
int m_number = 15
int np_number = (m_number-1)/2;


float A[15];

A[0] = 2*(freq_corte)/freq_amostragem;


for(int j=1; j<=np_number; j++)
{
  A[j] = (sin(2*j*pi*freq_corte/freq_amostragem))/(j*pi);
}


Complexo num1;
Complexo num2;
Complexo resultado;



int main (){
	num1.real =3;
	num1.img =2;
	num2.real =6;
	num2.img =18;


	resultado = DivideComplexo(&num1, &num2);

	printf("real = %f\n" ,resultado.real);
	printf("img = %f\n" ,resultado.img);

	return 0;

}
