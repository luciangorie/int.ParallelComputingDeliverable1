#include <iostream>
#include <omp.h>
#include "matrice.h"
#include "timecheck.h"

using namespace std;





int main()
{
    Matrice m;
    m.createM();
    //m.stampaMatrice();

    Matrice t;
    t.createMsymmetric(1.1);

    Timer* timer= new Timer();


    timer->startTimer();
    bool safety=t.checkSymOMP();
    timer->stopTimer();
    

    cout<<"Time check (symmetry function): "<<timer->getElapsedTimeMicroseconds();
    cout<<"\n";

    t.copyM(m);

    timer->startTimer();
    m.matTransposeOMP();
    timer->stopTimer();

    cout<<"Effective parallelization with OMP time: "<<timer->getElapsedTimeMicroseconds();
    cout<<"\n";
    //m.stampaMatrice();
    safety=m.checkTransposeOf(t);

    if(safety)
    {
        cout<<"Check of process correctly completed";
        t.copyM(m);
    }
    else "Check of process DID NOT WORK";
    
    cout<<"\n"<<"============================================="<<"\n";


    return 0;


}