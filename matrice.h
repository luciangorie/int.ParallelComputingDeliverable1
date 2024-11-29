#ifndef __MATRICE__
#define __MATRICE__
#include "timecheck.h"
#include <iostream>
#include <cstdlib>  // for rand() e srand()
#include <ctime> 

using namespace std;

typedef struct Matrice
{
    static const int size=1000;
    float m[size][size];
    
    Matrice()
    {
        cout<<"Matrix allocated successfully "<<size<<" x "<<size;
        cout<<"\n";
    }

    void createM()
    {
        srand(static_cast<unsigned int>(time(0)));
        int ce=0;
        int i=0;
        //cout<<"Allocating floats";

        while(i<size)
        {
            ce=0;
            while(ce<size)
            {
                int k=rand()%10000+100;
                m[i][ce]=float(float(k)/100.000);
                ++ce;
            }
            ++i;
        }
       
    }
    
    void createMsymmetric(float x)
    {
        int ce=0;
        int i=0;
        //cout<<"Allocating floats";

        while(i<size)
        {
            ce=0;
            while(ce<size)
            {
                m[i][ce]=x;   //a matrix with all the same number x is symmetric
                ++ce;
            }
            ++i;
        }
       
    }
    
    
    

    void stampaMatrice()
    {
        cout<<"\n";
        int i=0;
        int ce=0;
        while(i<size)
        {
            ce=0;
            while(ce<size)
            {
                cout<<m[i][ce]<<" ";
                ++ce;
            }

            cout<<"\n";


            ++i;
        }
    }

    void matTranspose()
    {
    
        //Timer* ty= new Timer();
        //(*ty).startTimer();
        
    
        for (int i = 0; i < size; i++)
        {
        
            
            for (int j = i+1; j < size; j++)
            {
                
                float c = m[i][j];
                m[i][j] = m[j][i];
                m[j][i] = c;                 
                
                
                
                
                
            }
        }
        
        //(*ty).stopTimer();
        
        //cout<<"Internal time: "<<(*ty).getElapsedTimeMilliseconds();
        
        
   

    }

    void matTransposeImp()
    {
    
       // Timer* ty= new Timer();
       // (*ty).startTimer();
    
        float c;
        float e;
        
         for (int i = 0; i < size; ++i)
        {
            for (int j = i+1; j < size; ++j)
            {
                // swapping simple in sequential code quite as before
                c = m[i][j];
                e = m[j][i];
                m[j][i] = c;
                m[i][j]= e;
            }
            //cout<<"get";
        }
        
       // (*ty).stopTimer();
        
      //  cout<<"Internal time: "<<(*ty).getElapsedTimeMilliseconds();
        
       // cout<<"end!"<<"\n";
    

    }
    
    void matTransposeOMP()
    {
        float c;
    
        #pragma omp parallel for private(c)
        for (int i = 0; i < size; i++) {
        for (int j = i+1; j < size; j++) {
            c = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = c;
          }
        }
    }
    
    

    
    bool checkSym()
    {
        for (int i = 0; i < size; ++i)
        {
            for (int ce = i+1; ce < size; ++ce)
            {
                        if (m[i][ce] != m[ce][i])   return false;  
                      
            
            }
        }
        return true; 
    }
    
    bool checkSymImp()
    {
    
      Timer* tb=new Timer();
      (*tb).startTimer();
      
        for (int i = 0; i < size; ++i)
        {
            for (int ce = i+1; ce < size; ++ce)
            {
                        if (m[i][ce] != m[ce][i]) return false;  
                      
            
            }
        }
        (*tb).stopTimer();
        cout<<"Timer internal: "<<(*tb).getElapsedTimeMicroseconds();
        cout<<"\n";
        return true; 
    }
    
    bool checkSymOMP()
    {
    bool symmetric=true;
      #pragma omp parallel for shared(symmetric) 
    for (int i = 0; i < size; ++i) {
        for (int ce = i; ce < size; ++ce) {
            if (m[i][ce] != m[ce][i]) {
                #pragma omp critical // avoiding race condition
                symmetric = false;
                // Interrupting loops
                #pragma omp cancel for
            }
        }
    }

    return symmetric;
    }
    
     bool checkTransposeOf(const Matrice& m2)
    {
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                if (m[i][j] != m2.m[j][i]) 
                {
                    return false; 
                }
            }
        }
        return true; 
    }
    
    void copyM(const Matrice& m2)
    {
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                m[i][j] = m2.m[i][j];  
            }
        }
    }




    







    


}Matrice;

#endif


