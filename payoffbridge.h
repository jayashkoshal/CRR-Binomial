/* -----------------------------------------*/
/**
 * @file payoffbridge.cpp
 * @brief A bridge class to decouple the abstraction and implementation of
 * payoff and its derived objects
 */
/* -----------------------------------------*/
#ifndef PAYOFFBRIDGE_H
#define PAYOFFBRIDGE_H

#include "payoff.h"

class payoffbridge
{
  public:

    /* -----------------------------------------*/
    /**
     * @brief bridge copy constructor
     *
     * @param original
     */
    /* -----------------------------------------*/
    payoffbridge(const payoffbridge& original);
    
    /* -----------------------------------------*/
    /**
     * @brief bridge constructor with address to a payoff object
     *
     * @param innerpayoff
     */
    /* -----------------------------------------*/
    payoffbridge(const payoff& innerpayoff);

    /* -----------------------------------------*/
    /**
     * @brief Operator () overloaded to delegate the calculation of the payoff 
     *
     * @param spot
     *
     * @return payoff of the appropriate derived payoff object
     */
    /* -----------------------------------------*/
    inline double operator()(double spot) const;
    
    /* -----------------------------------------*/
    /**
     * @brief Default destructor
     */
    /* -----------------------------------------*/
    ~payoffbridge();
    
    /* -----------------------------------------*/
    /**
     * @brief Assignment operator
     *
     * @param original
     *
     * @return address of bridge object
     */
    /* -----------------------------------------*/
    payoffbridge& operator=(const payoffbridge& original);

  private:
    /* -----------------------------------------*/
    /**
     * @brief pointer to the abstract base class
     */
    /* -----------------------------------------*/
    payoff* thepayoffptr;
};

inline double payoffbridge::operator()(double spot) const
{ 
  return thepayoffptr->operator()(spot);
}

#endif
