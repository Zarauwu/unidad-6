# include <iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<sstream>
using namespace std;
class Busqueda
{
private:
	int A[15];
	int enc[15];
	int i,n;

public:
       Busqueda(){ 
       i=0;
       n=0;
	   
	   }
	   void leerDatos();	
       void Secuencial();
       void Binaria();
       void Ordenar();

}; 
void Busqueda::Binaria()
{
	Ordenar();
	int valor,con,inf,sup,mitad,tam;
    bool encontrado=false;
    tam=sizeof(A)/sizeof(*A);
    regresa:
    con=0;
    inf=0;
    sup=tam;

      
    cout<<"\nIngresa el valor:";
    cin>>valor;
	for(int i=0;i<15;i++)
		cout<<"["<<i<<"]="<<A[i]<<endl;
    while ( (inf<=sup) && con<tam )
    {
        mitad=(inf+sup)/2;
        if(A[mitad]==valor){
            encontrado=true;
            break;
        }
        if(A[mitad]>valor){
            sup=mitad;
            mitad=(inf+sup)/2;
        }
        if(A[mitad]<valor){
            inf=mitad;
            mitad=(inf+sup)/2;
        }
        con++;
    }
    if( encontrado==false ){
        cout<<"No se encontro el numero \n ";
        goto regresa;
    }
    if(encontrado==true){
        cout<<"El valor fue encontrado en la posicion: "<<mitad<<"\n ";
    }

	
}
void Busqueda::leerDatos()
{ 
	string nombreArchivo;
	ifstream archivo ("Datos.csv");
	string linea;
    char delimitador = ',';
    int f=0;
    // Leemos la primer línea para descartarla, pues es el encabezado
    getline(archivo, linea);
	while (getline(archivo, linea))
    {

        stringstream stream(linea); // Convertir la cadena a un stream
        string dato;
        // Extraer todos los valores de esa fila
       	
        getline(stream, dato, delimitador);
        istringstream(dato) >> A[f];
		
        f++;
    }
	cout<<"Se extrajeron los datos del archivo"<<endl;
	for(int i=0;i<15;i++)
	{
		cout<<A[i]<<endl;
	}
}
void Busqueda:: Secuencial()
{
	int num,j=-1;
	cout<<"cu\240l numero deseas buscar"<<endl;
	cin>>num;
	cout<<"datos:"<<endl;
	for( i=0;i<15;i++)
		cout<<"["<<i<<"]="<<A[i]<<endl;

	for(i=0;i<15;i++)
	{
		if(num==A[i])
		{
		j++;
		enc[j]=i;
		
		}
		
	}
//	cout<<j<<endl;
	if(j>=0)
	{
		cout<<"Si se encontro el\t"<<num <<"\t en :"<<endl;
		for(i=0;i<=j;i++)
		{
			cout<<enc[i]<<endl;
		} 
	}
	else
	{
		cout<<"no se encontro \t"<<num <<endl;
	}
}
	void Busqueda:: Ordenar()
	{
		int Temp=0;
		for(int i=0;i<15;i++)
			for(int j=0;j<15-1;j++)
			{
				if(A[j]>A[j+1])
					{
                        Temp=A[j]; 
                        A[j]=A[j+1]; 
                        A[j+1]=Temp;
					}
			}
	}

		
	
		

