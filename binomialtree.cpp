#include "binomialtree.h"
#include <cmath>
#include <iostream>
#include <utility>
#if !defined(_MSC_VER)
using namespace std;
#endif

binomialtree::binomialtree(double spot_, double r_, double d_, double volatility_, unsigned long steps_, double time_)
:spot(spot_),r(r_),d(d_),volatility(volatility_),steps(steps_),time(time_)
{
treebuilt=false;
}

void binomialtree::buildtree()
{
treebuilt=true;
thetree.resize(steps+1);

double initiallogspot=log(spot);

for (unsigned long i=0; i<= steps; i++)
{
thetree[i].resize(i+1);
double thistime=(i*time)/steps;

double movedlogspot=initiallogspot+r*thistime-d*thistime;

movedlogspot-=0.5*volatility*volatility*thistime;

double sd=volatility*sqrt(time/steps);

for(long j=-static_cast<long>(i),k=0;j<=static_cast<long>(i);j=j+2,k++)
{
            
	thetree[i][k].first=exp(movedlogspot+j*sd);
}
}
for(unsigned long l=0; l < steps;l++)
{
        double dis=exp(-r*time/steps);
	discounts.push_back(dis);
}
}

double binomialtree::getprice(const productontree& theproduct)
{
	if(!treebuilt)
		buildtree();

	//if(theproduct.getfinaltime()!=time)
		// throw an exception
		
	for (long j = -static_cast<long>(steps), k=0; j<=static_cast<long>(steps); j=j+2,k++)
	{
        thetree[steps][k].second = theproduct.finalpayoff(thetree[steps][k].first);	
    }
        
	for(unsigned long i=1; i <= steps;i++)
	{
		unsigned long index=steps-i;
		double thistime=index*time/steps;

		for(long j=-static_cast<long>(index),k=0;j<=static_cast<long>(index);j=j+2,k++)
		{
			double spot=thetree[index][k].first;
			double futurediscountedvalue=0.5*discounts[index]*
				(thetree[index+1][k+1].second+thetree[index+1][k].second);
			thetree[index][k].second=theproduct.prefinalvalue(spot,thistime,futurediscountedvalue);
		}
	}
	return thetree[0][0].second;
}
