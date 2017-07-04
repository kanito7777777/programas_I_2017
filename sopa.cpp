#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <queue>

using namespace std;

void mostrarPila(stack<string> p)
{
	cout<<"\n--------Palabras para buscar"<<endl;
	while(!p.empty())
	{
		cout<<p.top()<<"\t";
		p.pop();
	}
}

void mostrarMatriz(char M[][100], int f, int c)
{
	cout<<"\n-----Sopa de Letras----"<<endl;
	for (int i = 0; i < f; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cout<<M[i][j]<<" ";
		}
		cout<<endl;
	}
}

void mostrarMatrizDos(char M[][100], int f, int c)
{
	cout<<"\n-----Sopa de Letras columnas----"<<endl;
	for (int i = 0; i < f; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cout<<M[j][i]<<" ";
		}
		cout<<endl;
	}
}
void rellenarMatriz(char M[][100], int f, int c)
{
	srand(time(NULL));

	for (int i = 0; i < f; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if(M[i][j] == '*' || M[i][j] == '\0')
				M[i][j] = (char)(rand()%(90-65) + 65);
		}
	}
}

void iniciarMatriz(char M[][100], int f, int c)
{
	for (int i = 0; i < f; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			M[i][j] = '*';
		}
	}
}

void llenarMatriz(char M[][100], stack<string> p, int f, int c)
{
	iniciarMatriz(M, f, c);

	string dato;
	int i = 0;
	while(!p.empty())
	{
		dato = p.top();
		strcpy(M[i++], dato.c_str());
		p.pop();
	}
	
	rellenarMatriz(M, f, c);
}

int main()
{
	stack<string> pila;
	string letra;
	int n, maxLong = 0;

	cout<<"Ingrese cantidad de letras: "; cin>>n;
	while(n-- > 0)
	{
		cin>>letra;
		transform(letra.begin(), letra.end(), letra.begin(), ::toupper);
		pila.push(letra);

		if(letra.size() > maxLong)
			maxLong = letra.size();
	}
	
	mostrarPila(pila);

	int fil = pila.size();
	int col = maxLong;

	char M[100][100] = {'-'};
	llenarMatriz(M, pila, fil, col);

	//mostrarMatriz(M, fil, col);
	mostrarMatrizDos(M, col, fil);

	return 0;
}