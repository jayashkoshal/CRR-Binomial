/**
* @file europeanontree.h
* @Synopsis A class defining europeanontree derived from productontree
* @author Jayash Koshal <jayashkoshal@gmail.com>
* @version i
* @date 2011-11-28
*/
#ifndef EUROPEANONTREE_H
#define EUROPEANONTREE_H

#include "productontree.h"
#include "payoffbridge.h"

/* -----------------------------------------*/
/**
* @Synopsis  This class defines an european option to be priced on the tree
*/
/* -----------------------------------------*/
class europeanontree : public productontree
{

  public:

    /* -----------------------------------------*/
    /**
    * @Synopsis  Default constructor
    *
    * @Param finaltime
    * @Param thepayoff_
    */
    /* -----------------------------------------*/
    europeanontree(double finaltime, const payoffbridge& thepayoff_);

    /* -----------------------------------------*/
    /**
    * @Synopsis  virtual copy constructor
    *
    * @Returns  pointer to the base class 
    */
    /* -----------------------------------------*/
    virtual productontree* clone() const;
    
    /* -----------------------------------------*/
    /**
    * @Synopsis  payoff of the option
    *
    * @Param spot
    *
    * @Returns   payoff of the european given the spot
    */
    /* -----------------------------------------*/
    virtual double finalpayoff(double spot) const;

    /* -----------------------------------------*/
    /**
    * @Synopsis payoff of option (intrinsic value)
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
    virtual ~europeanontree(){}

  private:
    /* -----------------------------------------*/
    /**
    * @Synopsis  payoff bridge object
    */
    /* -----------------------------------------*/
    payoffbridge thepayoff;
};
#endif
