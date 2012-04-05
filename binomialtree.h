#ifndef BINOMIALTREE_H
#define BINOMIALTREE_H

#include "productontree.h"
#include <vector>
using namespace std;

class binomialtree
{

  public:
    /* -----------------------------------------*/
    /**
    * @Synopsis  Default constructor
    *
    * @Param spot_
    * @Param r_
    * @Param d_
    * @Param volatility_
    * @Param steps_
    * @Param time_
    */
    /* -----------------------------------------*/
    binomialtree(double spot_, double r_, double d_,double volatility_, unsigned long steps_, double time_);

    /* -----------------------------------------*/
    /**
    * @Synopsis  Pricing method for any product
    *
    * @Param theproduct
    *
    * @Returns  The price of the option using tree method 
    */
    /* -----------------------------------------*/
    double getprice(const productontree& theproduct);

  protected:
    /* -----------------------------------------*/
    /**
    * @Synopsis  A tree building method
    */
    /* -----------------------------------------*/
    void buildtree();

  private:
    double spot;
    double r;
    double d;
    double volatility;
    unsigned long steps;
    double time;
    bool treebuilt;

    /* -----------------------------------------*/
    /**
    * @Synopsis  The spot and price of the option at the nodes
    */
    /* -----------------------------------------*/
    std::vector<std::vector<std::pair<double,double> > > thetree;
    
    /* -----------------------------------------*/
    /**
    * @Synopsis  The discount factor to be applied at various nodes
    */
    /* -----------------------------------------*/
    std::vector<double> discounts;

};

#endif
