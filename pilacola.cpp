#include <iostream>
#include <stack>
#include <queue>
#include <set>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <list>
#include <iterator>

using namespace std;

void mostrarVector(vector<char> v)
{
	cout<<"\n====== VECTOR ====="<<endl;
	vector<char>::iterator i = v.begin();
	while(i != v.end())
	{
		cout<<*i<<"\t";
		i++;
	}	

	cout<<endl;
}

void mostrarPila(stack<char> p)
{
	cout<<"\n==== PILA ===="<<endl;
	while(!p.empty()) {
	    cout<<p.top()<<"\t";
	  	p.pop();
	}
	cout<<endl;
}

void mostrarCola(queue<char> c)
{
	cout<<"\n==== COLA ===="<<endl;
	while(!c.empty()) {
	    cout<<c.front()<<"\t";
	  	c.pop();
	}	
	cout<<endl;
}

void mostrarlista(list<int> l)
{
	cout<<"\n====== LISTA ====="<<endl;
	list<int>::iterator i = l.begin();
	while(i != l.end())
	{
		cout<<*i<<"\t";
		*i++;
	}
	cout<<endl;
}

void mostrarArbol(multiset<int> m)
{
	cout<<"\n====== ARBOL AVL ====="<<endl;
	multiset<int>::iterator i = m.begin();
	while(i != m.end())
	{
		cout<<*i<<"\t";
		i++;
	}
	cout<<endl;
}

int main()
{
	srand(time(NULL));

	vector<char> v;
	stack<char> p;
	queue<char> cmay;
	queue<char> cmin;
	list<int> l;
	multiset<int> m; 

	int n, dato;
	cout<<"Ingrese n: "; cin>>n;

	//llenado el vector con letras aleatorias
	while(n-- > 0) {
	    dato = rand()%(122-65)+65;
	    
	    if(dato > 90 && dato < 97)
	    	n++;
	    else
	    	v.push_back((char)dato);
	}

	//llenando los datos en la pila
	for (int i = 0; i < v.size(); ++i)
	{
		p.push(v[i]);
	}

	//repartiendo a las listas mayusculas y minusculas
	stack<char> paux = p;
	while(!paux.empty())
	{
		int dato = (int)paux.top();
		if(dato >= 65 && dato <= 90)
			cmay.push((char)dato);
		else
			cmin.push((char)dato);

		paux.pop();
	}

	mostrarVector(v);
	mostrarPila(p);
	mostrarCola(cmay);
	mostrarCola(cmin);

	//sumando las colas y metiendolas en la lista
	int s;
	while(!cmin.empty() || !cmay.empty())
	{
		if(!cmay.empty() && cmin.empty())
		{
			s = (int)cmay.front() + 0;
			cmay.pop(); 
		}
		else if(cmay.empty() && !cmin.empty())
		{
			s = 0 + (int)cmin.front();
			cmin.pop();
		}
		else if(!cmay.empty() && !cmin.empty())
		{
			s = (int)cmay.front() + (int)cmin.front();
			cmay.pop(); 
			cmin.pop();
		}

		l.push_back(s);
	}

	//insertando la lista en el arbol, rbegin
	list<int>::reverse_iterator i = l.rbegin();
	while(i != l.rend())
	{
		m.insert(*i);
		i++;
	}

	mostrarlista(l);
	mostrarArbol(m);
	return 0;
}