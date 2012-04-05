/* -----------------------------------------*/
/**
 * @file payoff.h
 * @brief An abstract base class defining payoff
 * @author Jayash Koshal <jayashkoshal@gmail.com>
 */
/* -----------------------------------------*/
#ifndef PAYOFF_H
#define PAYOFF_H

class payoff
{
  public:

    payoff(){};

    virtual double operator()(double spot) const=0;
    virtual ~payoff(){}
    virtual payoff* clone() const=0;

  private:
};

class payoffcall : public payoff
{
  public:

    payoffcall(double strike_);

    /* -----------------------------------------*/
    /**
     * @brief pure virtual, overloading of ()
     *
     * @param spot
     *
     * @return 
     */
    /* -----------------------------------------*/
    virtual double operator()(double spot) const;
    virtual ~payoffcall(){}
    virtual payoff* clone() const;

  private:
    double strike;
};

/* -----------------------------------------*/
/**
 * @brief Definition of a put payoff class derived from an abstract base class
 * payoff.
 */
/* -----------------------------------------*/
class payoffput : public payoff
{
  public:

    /// Default constructor: every put option has a strike
    payoffput(double strike_);

    virtual double operator()(double spot) const;
    virtual ~payoffput(){}
    virtual payoff* clone() const;

  private:
    double strike;
};

#endif
