#include "Promedio.h"
#include<iostream>
using namespace std;

Promedio::Promedio()
{
	
}


void Promedio::ingresar(){
	float *p = numeros;
	for(int i=0;i<5;i++){
		cout<<"Ingresa numero "<<i+1<<": ";
		cin>>*(p+i);
}
}

void Promedio::calcular(){
	float *p=numeros;
	float promedio=0, maximo=*p, minimo=*p, suma=0;
	
	
	for(int i=0;i<5;i++){
		
		suma+=*(p+i);
		
		if(*(p+i)>maximo){
			maximo=*(p+i);
		}
		if(*(p+i)<minimo){
			minimo=*(p+i);
		}
	}
	promedio=suma/5;
	
	cout<<"Numero maximo: "<<maximo<<endl;
	cout<<"Numero minimo: "<<minimo<<endl;	
	cout<<"Suma total: "<<suma<<endl;
	cout<<"Promedio: "<<promedio<<endl;
}

