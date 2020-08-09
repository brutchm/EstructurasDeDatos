#include <iostream>
#include "Disco.h"

using namespace std;

void torresHanoiRecursivo(int n, int o, int d, int aux){
    if(n>0){
        torresHanoiRecursivo(n-1, o, aux, d);
        cout<<"se mueve anillo desde torre "<< o << " hasta torre "<< d<<endl;
        torresHanoiRecursivo(n-1, aux, d, o);
    }
}

void torresHanoirIterativo(){
    Disco tmpDisco1, tmpDisco2, tmpDisco3;
    tmpDisco1.setNum(3);
    tmpDisco2.setNum(2);
    tmpDisco3.setNum(1);
    tmpDisco1.setPos(1);
    tmpDisco2.setPos(1);
    tmpDisco3.setPos(1);
    int a=1, b=2, c=3;
    int n =7;
    while (n>0){
        if (tmpDisco1.getPos()==1){
            cout<<"El disco 1 se mueve de posicion "<<tmpDisco1.getPos();
            tmpDisco1.setPos(3);
            cout<<" a la posicion "<<tmpDisco1.getPos()<<endl;
            n--;

        }else{
            cout<<"El disco 1 se mueve de posicion "<<tmpDisco1.getPos();
            tmpDisco1.setPos(tmpDisco1.getPos()-1);
            cout<<" a la posicion "<<tmpDisco1.getPos()<<endl;
            n--;
        }
        if(tmpDisco2.getPos()!=3 && tmpDisco1.getPos() != tmpDisco2.getPos()){
            cout<<"El disco 2 se mueve de posicion "<<tmpDisco2.getPos();
            tmpDisco2.setPos(tmpDisco2.getPos()+1);
            cout<<" a la posicion "<<tmpDisco2.getPos()<<endl;
            n--;
        }
        if(tmpDisco3.getPos()==1 && tmpDisco1.getPos()!=3 && tmpDisco2.getPos()!=3){
            cout<<"El disco 3 se mueve de posicion "<<tmpDisco3.getPos();
            tmpDisco3.setPos(3);
            cout<<" a la posicion "<<tmpDisco3.getPos()<<endl;
            n--;
        }
    }
}


/*El metodo recursivo conlleva menos lineas de codigo que uno iterativo debido a que lo que hace es hacer n
 * llamado a sí mismo para evitar extenderse en validaciones de codigo y memoria al utilizar una iteración como por ejemplo
 * un for, while o un do.
 *
 * En el caso del metodo iterativo se necesita realizar una validación para cada disco y para la cantidad de movieminetos
 * que está dado por la formula 2^(cantida de discos)-1 para conocer la cantidad de interaciones necesarias o movimientos de
 * los discos en el juego.
 *
 * En nuestro caso el punto trivial del metodo recursivo es igual al de la condicion del while en el metodo iterativo
 *
 */

int main() {
    int n = 3;

    torresHanoiRecursivo(n, 1, 3,2);
    torresHanoirIterativo();
    return 0;
}