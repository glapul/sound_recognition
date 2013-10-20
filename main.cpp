#include<cstdio>
#include<vector>
#include<cmath>
#include "compute.h"
#include "wav.h"
using namespace std;

int main()
{
	wav Plik("test2.wav");
    vector<double> ssin;
    for(int i=0;i<1<<20;i++)
        ssin.push_back(sin((double)i/128));
    vector<vector<double> > tmp = compute(ssin);
    for(int i=0;i<tmp.size();i++)
    {
        for(int j=0;j<tmp[i].size();j++)
            printf("%lf ",tmp[i][j]);
        printf("\n");
    }


}
