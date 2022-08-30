// =================================================================
//
// File: main.cpp
// Author: Damariz Licea C
// Date: 30/08/22
//
// =================================================================
#include <iostream>
#include <vector>
#include "header.h"
#include "search.h"
#include "bubble.h"
#include "selection.h"
#include "insertion.h"
#include <fstream>

using namespace std;

//argc num de elementos que llegan, argv es un array de los elementos que llegan
//ifstream file in
//ofstream file out

int main(int argc, char* argv[]) {
	ifstream entrada;
	ofstream salidas;

	if (argc != 3){
		cout << "Error al correr el programa";
		return -1;
	}


	entrada.open(argv[1]);
	if (entrada.fail()){
		cout<<"No se pudo abrir el archivo de entrada";
		return -1;
	}

	salidas.open(argv[2]);
	if (salidas.fail()){
		cout<<"No se pudo abrir el archivo de salida";
		return -1;
	}

//n es el numero de datos que hay, q es el numero de datos que voy a buscar , num es para guardar por mientras.
	int n, q, num;
	entrada>>n;

//almacenaje de datos, vector de enteros , desordenados igual a k
	vector<int> k(n);

	//leer numeros 

	for (int i=0; i< n; i++){
		entrada>>num;
		k[i]=num;
	}

	//implementacion de bubble, select e insert

	int bubble, select, insert;

	vector<int> desord=k;

	bubble=bubbleSort(k);
	k=desord;
	select= selectionSort(k);
	k=desord;
	insert= insertionSort(k);

	salidas<<bubble<<' '<<select<<' '<<insert<<'\n'<<'\n';
	entrada>>q;
	pair<int,int>r;
	for(int i=0;i<q;i++){
		entrada>>num;
		r=sequentialSearch(k,num);
		salidas<<r.first<<' '<<r.second<<' ';
		r=binarySearch(k,num);
		salidas<<r.second<<'\n';
	}


	entrada.close();
	salidas.close();




}
