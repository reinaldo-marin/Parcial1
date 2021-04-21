#include <QCoreApplication>
#include <iostream>
using namespace std;
int main()
{
    int a;
    int salida = 1;
    int elemento = 0;
    int maxi;
    int suma = 0;
    int sumaco = 0;
    int magico = 0;
    int magicoc = 0;
    int magicod = 0;
    int sumad = 0;
    int sumai = 0;
    int contasuma = 0;
    cout<<"Introduzca el tamano n de la matriz cuadrada nxn:\n"; cin>>maxi;
    int columna = maxi;
    int total = maxi*maxi;
    int filas[total]= { };
    int sumaf[maxi]= { };
    int sumac[maxi] = { };
    while (salida==1)
    {
       cout<<"Introduzca el numero 1 para ingresar los elementos de la matriz o el numero 2 para generar la operacion:\n"; cin>>salida;

       if (salida==1)
       {
           for (int f = 1; f <= maxi; f++)
           {
               for (int c = 1; c <= maxi; c++)
               {
                 cout<<"Introduzca el elemento ("<<f<<","<<c<< ") de la matriz de izquierda a derecha:\n"; cin>>a;
                 filas [elemento] = a;
                 elemento++;
               }

           }
       }
    }

    for (int s = 0; s <= total-1; s++)
    {
        suma += filas[s];
        int comprobante = s+1;
        if (comprobante % maxi == 0)
        {
            sumaf [contasuma] = suma;
            suma = 0;
            contasuma++;
            if (contasuma>1)
            {
                for (int f=0;f <= contasuma-1;f++)
                {
                    if (f+1==maxi)
                    {
                        if (sumaf [f] == sumaf [f-1])
                        {
                          magico = 1;
                        }
                        else
                        {
                          magico = 0;
                        }
                    }
                    else if (f<maxi)
                    {
                        if (sumaf [f] == sumaf [f+1])
                        {
                          magico = 1;
                        }
                        else
                        {
                          magico = 0;
                        }
                    }
                }
            }
        }

    }
    contasuma = 0;
    int ss = maxi;
    for (int s = 0; s <= total; s++)
    {
        if (sumaco==0)
        {
          if (maxi-columna<3)
          {
              sumaco += filas[maxi-columna];
              sumaco += filas[(maxi-columna)+maxi];
              s++;
          }

        }
        else
        {
           if (maxi-columna<3)
           {
               ss += maxi;
               sumaco += filas[(maxi-columna)+ss];
           }
        }
        if (s % maxi == 0 )
        {
            sumac [contasuma] = sumaco;
            sumaco = 0;
            contasuma++;
            columna--;
            ss = maxi;
            if (contasuma>1)
            {
                for (int f=0;f <= contasuma-1;f++)
                {
                    if (f+1==maxi)
                    {
                        if (sumac [f] == sumac [f-1])
                        {
                          magicoc = 1;
                        }
                        else
                        {
                          magicoc = 0;
                        }
                    }
                    else if (f<maxi)
                    {
                        if (sumac [f] == sumac [f+1])
                        {
                          magicoc = 1;
                        }
                        else
                        {
                          magicoc = 0;
                        }
                    }
                }
            }
        }
    }
    ss = maxi;
    int conta = 0;
    int contai = maxi-1;
    for (int s = 0;s+1<=maxi;s++)
    {
        sumad += filas[conta];
        conta += maxi+1;
        sumai += filas[contai];
        contai += maxi-1;
    }
    if (sumad == sumai)
    {
        magicod = 1;
    }
    if (magico == 1 && magicoc == 1 && magicod == 1)
    {
        cout<<"La matriz ingresada es un cuadrado magico"<<endl;
    }
    else
    {
       cout<<"La matriz ingresada no es un cuadrado magico"<<endl;
    }


    return 0;
}
