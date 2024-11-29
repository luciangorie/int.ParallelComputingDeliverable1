#include <iostream>
#include <omp.h>
#include "matrice.h"
#include "timecheck.h"

using namespace std;





int main()
{
    Matrice* array1[10];


    Matrice m1,m2,m3,m4,m5,m6,m7,m8,m9,m10;
    array1[0]=&m1;
    array1[1]=&m2;
    array1[2]=&m3;
    array1[3]=&m4;
    array1[4]=&m5;
    array1[5]=&m6;
    array1[6]=&m7;
    array1[7]=&m8;
    array1[8]=&m9;
    array1[9]=&m10;
   
    
    
    m1.createM();
    m2.createM();
    m3.createM();
    m4.createM();
    m5.createM();
    m6.createM();
    m7.createM();
    m8.createM();
    m9.createM();
    m10.createM();

    Matrice t;
    t.createMsymmetric(1.1);

    Timer* timer= new Timer();


    timer->startTimer();
    bool safety=t.checkSymOMP();
    timer->stopTimer();
    

    cout<<"Time check (symmetry function): "<<timer->getElapsedTimeMicroseconds();
    cout<<"\n";

    int ce=0;
    while(ce<10)
    {
    
    t.copyM((*(array1[ce])));

    timer->startTimer();
    (*(array1[ce])).matTransposeOMP();
    timer->stopTimer();

    cout<<"Effective parallelization with OMP time: "<<timer->getElapsedTimeMicroseconds();
    cout<<"\n";
    //m.stampaMatrice();
    safety=(*(array1[ce])).checkTransposeOf(t);

    if(safety)
    {
        cout<<"Check of process correctly completed n. "<<ce+1;
        t.copyM((*(array1[ce])));
    }
    else "Check of process DID NOT WORK";
    
    cout<<"\n"<<"============================================="<<"\n";
    
    
    ce++;
    
    }


    return 0;


}