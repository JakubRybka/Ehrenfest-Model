#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include <math.h>
using namespace std;
const int N = 100;
int Flea[N] = {0};
int Hist[N+1] = {0};

int main()
{
    fstream p, t;
    p.open("distribution.txt",ios::out|ios::trunc);
    t.open("trajectory.txt", ios::out|ios::trunc);
    srand(time(NULL));
    double pr = 0.8;
    int n = N;
    int T = 10000;
    for(int i =0;i<T;i++)
    {
        double u = (double)rand()/((double)RAND_MAX+1.0);
        int k = floor(u*N);
        u = (double)rand()/((double)RAND_MAX+1.0);
        if(pr<u)
        {
            if(Flea[k]==0){
                Flea[k]=1;
                n--;
            }
            else{
                Flea[k]=0;
                n++;
            }
        }
        t<<i<<"\t"<<n<<"\t"<<N-n<<endl;
        Hist[n]++;
    }
    for(int i=0;i<=N;i++){
        if(Hist[i]!=0)
            p<<i<<"\t"<<(double)Hist[i]/(double)T<<endl;
    }
    p.close();
    t.close();
    return 0;
}
