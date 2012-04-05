/**
 * @file payoffbridge.cpp
 * @brief Define the functions to separate abstraction and implementation
 */

#include "payoffbridge.h"

/* -----------------------------------------*/
/**
 * @brief copy constructor with the inner payoff object pointer calling a
 * virtual clone for copying
 *
 * @param original
 */
/* -----------------------------------------*/
payoffbridge::payoffbridge(const payoffbridge& original)
{
  thepayoffptr=original.thepayoffptr->clone();
}

/* -----------------------------------------*/
/**
 * @brief Constructor to initialize the payoff pointer by calling virtual clone
 *
 * @param innerpayoff
 */
/* -----------------------------------------*/
payoffbridge::payoffbridge(const payoff& innerpayoff)
{
  thepayoffptr=innerpayoff.clone();
}

/* -----------------------------------------*/
/**
 * @brief Destructor to delete the payoff pointer
 */
/* -----------------------------------------*/
payoffbridge::~payoffbridge()
{
  delete thepayoffptr;
}

/* -----------------------------------------*/
/**
 * @brief Assingment operator: calls the virtual clone
 *
 * @param original
 *
 * @return Address to the new object created using clone
 */
/* -----------------------------------------*/
payoffbridge& payoffbridge::operator=(const payoffbridge& original)
{
  if (this != &original)
  {
    delete thepayoffptr;
    thepayoffptr=original.thepayoffptr->clone();
  }

  return *this;
}
