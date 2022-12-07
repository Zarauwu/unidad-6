# include <iostream>
# include "Busqueda_secuencial.h"

using namespace std;
int main()
{
	int opc=0;
	Busqueda Ob; 	//objeto 
	do
	{
		system("cls");
		cout<<"Proyecto Final de ED"<<endl;
		cout<<"1. ingresar datos"<<endl;
		cout<<"2. b\243squeda secuencial"<<endl;
		cout<<"3. b\243squeda binaria"<<endl;
		cout<<"4. salir"<<endl;
		cin>>opc;
		switch(opc)
		{
			case 1:system("cls");
			Ob.leerDatos();
				break;
			case 2: Ob.Secuencial();
				break;
			case 3:Ob.Binaria();
			    break;
			case 4: cout<<"Hasta pronto!!!"<<endl;
				break;
			default:
				cout<<"no existe la opci\242n"<<endl;
		}
		system ("pause");
	}while(opc!=4);
	return 0;
}
