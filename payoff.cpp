/* -----------------------------------------*/
/**
 * @file payoff.cpp
 * @brief This file defines two classes payoffcall and payoffput  derived from
 * the base class payoff

*/
/* -----------------------------------------*/
#include "payoff.h"
#include <algorithm>

/* -----------------------------------------*/
/**
 * @brief Constructor to initialize the strike
 *
 * @param strike_
 */
/* -----------------------------------------*/
payoffcall::payoffcall(double strike_) : strike(strike_)
{
}

/* -----------------------------------------*/
/**
 * @brief Operator() overloaded to calculate the payoff given a spot price
 *
 * @param spot
 *
 * @return payoff of a call option @f$payoff = (spot - strike)^+ @f$
 */
/* -----------------------------------------*/
double payoffcall::operator()(double spot) const
{ 
  double p= ((spot-strike)>0)?spot-strike:0;
  return p;
}

/* -----------------------------------------*/
/**
 * @brief Virtual copy constructor
 *
 * @return address of derived object as a pointer to the abstract base class
 */
/* -----------------------------------------*/
payoff* payoffcall::clone() const
{
  return new payoffcall(*this);
}

/* -----------------------------------------*/
/**
 * @brief Default constructor to initialize the strike
 *
 * @param strike_
 */
/* -----------------------------------------*/
payoffput::payoffput(double strike_) : strike(strike_)
{
}

/* -----------------------------------------*/
/**
 * @brief Operator () overloaded to calculate the payoff of put option
 *
 * @param spot
 *
 * @return payoff of a put option @f$payoff = (strike - spot)^+ @f$
 */
/* -----------------------------------------*/
double payoffput::operator()(double spot) const
{ 
  return strike-spot>0?strike-spot:0;
}

/* -----------------------------------------*/
/**
 * @brief Virtual copy constructor
 *
 * @return address of derived object as a pointer to the abstract base class
 */
/* -----------------------------------------*/
payoff* payoffput::clone() const
{
  return new payoffput(*this);
}
