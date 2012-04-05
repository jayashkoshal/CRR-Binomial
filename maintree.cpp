#include "binomialtree.h"
#include "americanontree.h"
#include "europeanontree.h"
#include <iostream>
#include <cmath>
#include <ctime>
#include <vector>
using namespace std;

int main()
{

double expiry=1;
double strike=100;
double spot=100;
double volatility=.2;
double rate=.05;
double div=.04;
unsigned long steps;

char option;
char exercise;

/*cout<<"\n Enter option C for call and P for put \n";
cin>>option;

cout<<"\n Enter exercise type A for American and E for European\n";
cin>>exercise;

cout<<"\n Enter Strike \n";
cin>>strike;

cout<<"\n Enter spot\n";
cin>>spot;

cout<<"\n Enter expiry \n";
cin>>expiry;

cout<<"\n Enter volatility\n";
cin>>volatility;
		
cout<<"\n Enter interest rate\n";
cin>>rate;
	
cout<<"\n Enter dividend\n";
cin>>div;
*/	
 cout<<"\n Enter number of steps on tree \n";
 cin>>steps;	

payoffcall thepayoff(strike);

	// payoffput thepayoff_put(strike);

	// americanontree americanoption(expiry,thepayoff_put);

europeanontree europeanoption(expiry,thepayoff);
time_t start,end;
time (&start);

binomialtree thetree(spot,rate,div,volatility,steps,expiry);

double europrice=thetree.getprice(europeanoption);

 cout<<"euro price \t"<< europrice<<"\n";

// double americanprice=thetree.getprice(americanoption);

	// cout<<"american put price \t"<<americanprice<<"\n";
time (&end);
double comp_time=difftime (end,start);
cout<<"comp_time \t"<<comp_time<<endl;	
double d1=(log(spot/strike)+(rate-div+0.5*volatility*volatility)*expiry)
		/volatility/sqrt(expiry);
double d2=(log(spot/strike)+(rate-div-0.5*volatility*volatility)*expiry)
		/volatility/sqrt(expiry);

return 0;

	
}
