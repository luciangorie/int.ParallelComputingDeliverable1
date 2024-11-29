#include <iostream>
#include "timecheck.h"  //personal library to check time
#include "matrice.h"
#include <cstring>  //personal library to allocate matrixes(matrice.h)
using namespace std;

int main(int argc, char* argv[])
{

    
  
    

    bool path=false;
    
    
    if (argc > 1 && strcmp(argv[1], "true") == 0) {
        path = true;
    }
    
    if (argc > 1 && strcmp(argv[1], "false") == 0) {
        path = false;
    }
    
    

    
    
    

    
    
    if(!path){
    
    Matrice t;
    t.createMsymmetric(1.1);
    
    Matrice m1,m2,m3,m4,m5,m6;
    m1.createM();
    m2.createM();
    m3.createM();
    m4.createM();
    m5.createM();
    m6.createM();
    
    
    Matrice saved1,saved2,saved3,saved4,saved5,saved6;
    saved1.createM();
    saved2.createM();
    saved3.createM();
    saved4.createM();
    saved5.createM();
    saved6.createM();
    saved1.copyM(m1);
    saved2.copyM(m1);
    saved3.copyM(m3);
    saved4.copyM(m4);
    saved5.copyM(m5);
    saved6.copyM(m6);
    
    
    Timer* tt=new Timer();
    (*tt).startTimer();
    bool safety=t.checkSym();
    (*tt).stopTimer();
    cout<<"Checking Symmetry :"<< (*tt).getElapsedTimeMicroseconds()<<"\n";
    
    
    
    
    (*tt).startTimer();
    m1.matTranspose();
    (*tt).stopTimer();
    cout<<"Time of transposition  (full serial) = "<< (*tt).getElapsedTimeMicroseconds();
    cout<<"\n";

    
     safety= m1.checkTransposeOf(saved1);
  
  if(safety)
  {cout<<"Correctly transposed n.1";
   cout<<"\n";
    saved1.copyM(m1); }  //copying the calculated matrix in the new matrix T
    
    
    
    (*tt).startTimer();
    m2.matTranspose();
    (*tt).stopTimer();
    cout<<"Time of transposition  (full serial) = "<< (*tt).getElapsedTimeMicroseconds();
    cout<<"\n";

    
     safety= m2.checkTransposeOf(saved2);
  
  if(safety)
  {cout<<"Correctly transposed n.2";
   cout<<"\n";
    saved2.copyM(m2); }  //copying the calculated matrix in the new matrix T
    
    
    (*tt).startTimer();
    m3.matTranspose();
    (*tt).stopTimer();
    cout<<"Time of transposition  (full serial) = "<< (*tt).getElapsedTimeMicroseconds();
    cout<<"\n";

    
     safety= m3.checkTransposeOf(saved3);
  
  if(safety)
  {cout<<"Correctly trasnposed n.3";
   cout<<"\n";
    saved2.copyM(m3); }  //copying the calculated matrix in the new matrix T
    
    (*tt).startTimer();
    m4.matTranspose();
    (*tt).stopTimer();
    cout<<"Time of transposition  (full serial) = "<< (*tt).getElapsedTimeMicroseconds();
    cout<<"\n";

    
     safety= m4.checkTransposeOf(saved4);
  
  if(safety)
  {cout<<"Correclty transposed n.4";
   cout<<"\n";
    saved2.copyM(m4); }  //copying the calculated matrix in the new matrix T
    
    (*tt).startTimer();
    m5.matTranspose();
    (*tt).stopTimer();
    cout<<"Time of transposition  (full serial) = "<< (*tt).getElapsedTimeMicroseconds();
    cout<<"\n";

    
     safety= m5.checkTransposeOf(saved5);
  
  if(safety)
  {cout<<"Correctly transposed n.5";
   cout<<"\n";
    saved2.copyM(m5); }  //copying the calculated matrix in the new matrix T
    
    (*tt).startTimer();
    m6.matTranspose();
    (*tt).stopTimer();
    cout<<"Time of transposition  (full serial) = "<< (*tt).getElapsedTimeMicroseconds();
    cout<<"\n";

    
     safety= m6.checkTransposeOf(saved6);
  
  if(safety)
  {cout<<"Correctly trasnposed n.6";
   cout<<"\n";
    saved2.copyM(m6); }  //copying the calculated matrix in the new matrix T

    
  
    
    
    
    }
   
   
    if(path) 
    {
    
    Matrice t;
    t.createMsymmetric(1.1);
    
    Matrice m1,m2,m3,m4,m5,m6;
    m1.createM();
    m2.createM();
    m3.createM();
    m4.createM();
    m5.createM();
    m6.createM();
    
    
    Matrice saved1,saved2,saved3,saved4,saved5,saved6;
    saved1.createM();
    saved2.createM();
    saved3.createM();
    saved4.createM();
    saved5.createM();
    saved6.createM();
    saved1.copyM(m1);
    saved2.copyM(m1);
    saved3.copyM(m3);
    saved4.copyM(m4);
    saved5.copyM(m5);
    saved6.copyM(m6);
    
    Timer* tp=new Timer();
    (*tp).startTimer();
    bool safety=t.checkSymImp();
    (*tp).stopTimer();
    cout<<"Checking Symmetry with implicit parallelism :"<<(*tp).getElapsedTimeMicroseconds()<<"\n";
    
    
    (*tp).startTimer();
     m1.matTransposeImp();
    (*tp).stopTimer();
    cout<<"Time of transposition  (implicitly parallelized) = "<< (*tp).getElapsedTimeMicroseconds();
    cout<<"\n"; 

    safety= m1.checkTransposeOf(saved1);
  
    if(safety)
    {
    cout<<"n.1 Correctly Transposed";
   
    cout<<"\n";
    
    saved1.copyM(m1); //copying the calculated matrix in the new matrix T
    
    }
    
    
    (*tp).startTimer();
     m2.matTransposeImp();
    (*tp).stopTimer();
    cout<<"Time of transposition  (implicitly parallelized) = "<< (*tp).getElapsedTimeMicroseconds();
    cout<<"\n"; 

    safety= m2.checkTransposeOf(saved2);
  
    if(safety)
    {
    cout<<"n.2 Correctly Transposed";
   
    cout<<"\n";
    
    saved2.copyM(m2); //copying the calculated matrix in the new matrix T
    
    }
    
    (*tp).startTimer();
     m3.matTransposeImp();
    (*tp).stopTimer();
    cout<<"Time of transposition  (implicitly parallelized) = "<< (*tp).getElapsedTimeMicroseconds();
    cout<<"\n"; 

    safety= m3.checkTransposeOf(saved3);
  
    if(safety)
    {
    cout<<"n.3 Correctly Transposed";
   
    cout<<"\n";
    
    saved3.copyM(m3); //copying the calculated matrix in the new matrix T
    
    }
    
    (*tp).startTimer();
     m4.matTransposeImp();
    (*tp).stopTimer();
    cout<<"Time of transposition  (implicitly parallelized) = "<< (*tp).getElapsedTimeMicroseconds();
    cout<<"\n"; 

    safety= m4.checkTransposeOf(saved4);
  
    if(safety)
    {
    cout<<"n.4 Correctly Transposed";
   
    cout<<"\n";
    
    saved4.copyM(m4); //copying the calculated matrix in the new matrix T
    
    }
    
    (*tp).startTimer();
     m5.matTransposeImp();
    (*tp).stopTimer();
    cout<<"Time of transposition  (implicitly parallelized) = "<< (*tp).getElapsedTimeMicroseconds();
    cout<<"\n"; 

    safety= m5.checkTransposeOf(saved5);
  
    if(safety)
    {
    cout<<"n.5 Correctly Transposed";
   
    cout<<"\n";
    
    saved5.copyM(m5); //copying the calculated matrix in the new matrix T
    
    }
    
    
    (*tp).startTimer();
     m6.matTransposeImp();
    (*tp).stopTimer();
    cout<<"Time of transposition  (implicitly parallelized) = "<< (*tp).getElapsedTimeMicroseconds();
    cout<<"\n"; 

    safety= m6.checkTransposeOf(saved6);
  
    if(safety)
    {
    cout<<"n.6 Correctly Transposed";
   
    cout<<"\n";
    
    saved6.copyM(m6); //copying the calculated matrix in the new matrix T
    
    }
    
    
    
    
    
    
    }
    
   


    return 0;

}