/**
* @file americanontree.h
* @brief  A class defining americanontree derived from productontree
* @author Jayash Koshal <jayashkoshal@gmail.com>
* @version i
* @date 2011-11-28
*/
#ifndef _AMERICANONTREE_H_
#define _AMERICANONTREE_H_

#include "productontree.h"
#include "payoffbridge.h"

/* -----------------------------------------*/
/**
* @Synopsis  This class defines an american option to be priced on the
* tree
*/
/* -----------------------------------------*/
class americanontree: public productontree 
{

  public:
    /* -----------------------------------------*/
    /**
    * @Synopsis  default constructor
    *
    * @Param finaltime
    * @Param thepayoff
    */
    /* -----------------------------------------*/
    americanontree(double finaltime,const payoffbridge& thepayoff);

    /* -----------------------------------------*/
    /**
    * @Synopsis  virtual copy constructor
    *
    * @Returns   
    */
    /* -----------------------------------------*/
    virtual productontree* clone() const;
    
    /* -----------------------------------------*/
    /**
    * @Synopsis  final payoff of the option
    *
    * @Param spot
    *
    * @Returns  final payoff 
    */
    /* -----------------------------------------*/
    virtual double finalpayoff(double spot) const;
    
    /* -----------------------------------------*/
    /**
    * @Synopsis  intrinsic value of the option
    *
    * @Param spot
    * @Param time
    * @Param discountedfuturevalue
    *
    * @Returns  intrinsic value 
    */
    /* -----------------------------------------*/
    virtual double prefinalvalue(double spot, double time, double discountedfuturevalue) const;
    
    /* -----------------------------------------*/
    /**
    * @Synopsis  virtual destructor
    */
    /* -----------------------------------------*/
    virtual ~americanontree(){}

  private:
    /* -----------------------------------------*/
    /**
    * @Synopsis  payoff bridge object
    */
    /* -----------------------------------------*/
    payoffbridge thepayoff;
};

#endif
