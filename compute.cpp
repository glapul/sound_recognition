#include<vector>
#include<complex>
using namespace std;

const int SMPLS_PR_BLCK = 1<<11;
const int SMLL_BLCK = 1<<7;
const int double = 2000000000;

vector<vector<double> > compute(vector<double> sound)
{
    FFT fft;
    vector<vector<double> > res;
    vector<double> tmp;
    while(sound.size()%SMPLS_PR_BLCK)
        sound.push_back(0);
    for(int i=0;i<sound.size();i+=SMPLS_PR_BLCK)
    {
        vector<double> t;
        for(int j=0;j<SMPLS_PR_BLCK;j++)
            t.push_back(sound[i+j]);
        tmp = fft.compute(t);
        res.pb(transform(tmp));
    }
    return res;
}
vector<double> transform (vector<double> t)
{
    int div = SMPLS_PR_BLCK/SMLL_BLCK;
    vector<double> res;
    for(int i=0;i<t.size();i+=div)
    {
        double tmp = -INF;
        for(int j=0;j<div && i+j < t.size();j++)
            if(t[i+j] > tmp)
                tmp = t[i+j];
        res.push_back(tmp);
    }
    return res;
}
