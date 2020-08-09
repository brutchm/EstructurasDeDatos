#include <iostream>
using namespace std;


int calcularFactorial(int pnum){
    if (pnum == 0){
        return 1;
    }else{
        return pnum*calcularFactorial(pnum-1);
    }
}

void preguntarNumero(){
    int num;
    cout<<"Digite el numero para averiguar el factorial"<< endl;
    cin>>num;

    cout<<calcularFactorial(num)<<endl;
}

int main() {
    preguntarNumero();
    return 0;
}

