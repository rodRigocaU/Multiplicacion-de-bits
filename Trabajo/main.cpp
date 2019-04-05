#include <iostream>
#include <bitset>
#include <vector>

using namespace std;
#define N 4
bitset<N> Comple2(bitset<N> x)
{
    int arc;
    x = ~x;
    if(x[0] == 0)
    {
        return x;
    }
    else
    {
        arc = 1;
    }
    for(int i = 0; i < N; i++)
    {
        if(x[i] == 1 && arc == 1)
        {
            x[i] = 0;
        }
        else if(x[i] == 0 && arc == 1)
        {
            x[i] = 1;
            return x;
        }
    }
    cout << "Se produce un overflow" << '\n';
    return x;
}

void vect(vector<int> A,bitset<N> bar)
{


    for(int i = 0; i < N;i++)
    {
        if(bar[N - i - 1] == 0)
        {
            A.push_back(0);
        }
        else
            A.push_back(1);
    }
}

bitset<N*2> multiplica(bitset<N> x, bitset<N> y)

{
    bitset<N*2> z;
    int aux; int arc = 0;
    int cont = 1;
    int contf = N + 1;
    for(int i = 0; i < N; i++)
    {
        if(i == 0)
        {
            for(int r = 0; r < N; r++)
            {
                z[r] = x[r] * y[0];
            }
        }
        else
        {
            for(int r = cont; r <= contf; r++)
            {
                if(z[r] + x[aux] + arc == 1)
                   {
                       z[r] = 1;
                       arc = 0;
                   }
                else if(z[r] + x[aux] + arc == 2)
                {
                    z[r] = 0;
                    arc = 1;
                }
                else if(z[r] + x[aux] + arc == 3)
                {
                    z[r] = 1;
                    arc = 1;
                }
                else
                {
                    z[r] = 0;
                    arc = 0;
                }
                aux++;
            }
            cont++;
            contf++;
            aux = 0;
        }
    }
    return z;
}

int main()
{
    cout << "Ingrese un numero para comvertir a bits" << endl;
    int num, num2;
    cin >> num;
    bitset<N> bar(num);
    cout << "Ingrese el segundo numero para la operacion" << '\n';
    cin >> num2;
    bitset<N> bar2(num2);
    cout << bar << " " << bar2 << '\n';

    /*cout << bar << '\n';

    bitset<N> barc = Comple2(bar);
    cout << barc << '\n';

    vector<int> A;
    vector<int> S;
    vector<int> P;*/

    cout << multiplica(bar,bar2) ;


    /*for(int i = 0; i < N;i++)
    {
        if(barc[N - i - 1] == 0)
        {
            A.push_back(0);
        }
        else
            A.push_back(1);

        cout << barc[N - i - 1] << " x " << A[i] << " x " << i << '\n';
    }*/




    return 0;
}
