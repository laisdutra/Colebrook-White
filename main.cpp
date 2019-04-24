#include <iostream>
#include <cmath>

using namespace std;

double f_Colebrook_White(double chute_f, double Re, double rug_relativa){

    double p1, p2, aux, aux2, f;

    do{
        p1 = rug_relativa/3.7;
        p2 = 2.51/(Re*sqrt(chute_f));
        aux = -2*log10(p1 + p2);
        f = 1/pow(aux, 2);

        aux2 = chute_f;
        chute_f = f;

    }while(aux2 != f);

    return f;
}

double V(double Reynolds_Chute, double Pot, double rugosidade){

    double prt1, prt2, f_atri, V = 0, V_ant, Reynolds = Reynolds_Chute;

    do{
        V_ant = V;

        f_atri = f_Colebrook_White(0.04, Reynolds, rugosidade);

        prt1 = Pot/0.7547677;
        prt2 = 1/(f_atri*983.871 + 13.65);
        V = cbrt(prt1*prt2);

        Reynolds = 31000*V;

    }while(V != V_ant);

    return V;
}

int main()
{

    double P, rug;

    double f_CW = f_Colebrook_White(0.04, 1000000, 0.001);
    cout << "Fator de atrito: " << f_CW << endl << endl;

    cout << "Potência da bomba: ";
    cin >> P;
    cout << "Rugosidade relativa: ";
    cin >> rug;

    double Velocidade = V(100000, P, rug);
    cout << "Q = " << Velocidade*M_PI*0.00024025 << " m³/s";

    return 0;
}
