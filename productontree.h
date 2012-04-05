/* -----------------------------------------*/
/**
 * @Synopsis  An abstract base class to create a derivative to be priced using
 * CRR binomial model on a tree
 * @file productontree.h
 * @author Jayash Koshal <jayashkoshal@gmail.com>
 */
/* -----------------------------------------*/
#ifndef productontree_h
#define productontree_h

class productontree
{
  public:
    /* -----------------------------------------*/
    /**
     * @Synopsis  Constructor to initialize the expiration time. We only
     * consider derivatives with finite expiration time.
     *
     * @Param finaltime_
     */
    /* -----------------------------------------*/
    productontree(double finaltime_);

    /* -----------------------------------------*/
    /**
     * @Synopsis A pure virtual function to calculate the final payoff 
     *
     * @Param spot
     *
     * @Returns  Final Payoff 
     */
    /* -----------------------------------------*/
    virtual double finalpayoff(double spot) const=0;
    
    /* -----------------------------------------*/
    /**
     * @Synopsis  Function calculates the discounted expected value of the
     * derivative
     *
     * @Param spot
     * @Param time
     * @Param discountedfuturevalue
     *
     * @Returns  Discounted expected value of the derivative 
     */
    /* -----------------------------------------*/
    virtual double prefinalvalue(double spot,double time, double discountedfuturevalue) const=0;
    
    /* -----------------------------------------*/
    /**
     * @Synopsis  Default destructor
     */
    /* -----------------------------------------*/
    virtual ~productontree(){}
    
    /* -----------------------------------------*/
    /**
     * @Synopsis  Virtual copy constructor
     *
     * @Returns   Address to the copy of the derived object
     */
    /* -----------------------------------------*/
    virtual productontree* clone() const=0;
    
    /* -----------------------------------------*/
    /**
     * @Synopsis  Function to access the final expiration time of the
     * derivative
     *
     * @Returns   Expiration time
     */
    /* -----------------------------------------*/
    double getfinaltime() const;

  private:
    double finaltime;
};

#endif
