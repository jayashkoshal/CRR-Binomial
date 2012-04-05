#include "americanontree.h"
#include <algorithm>
using namespace std;

americanontree::americanontree(double finaltime, const payoffbridge& thepayoff_):
productontree(finaltime),thepayoff(thepayoff_)
{
}

productontree* americanontree::clone() const
{ 
return new americanontree(*this);
}

double americanontree::finalpayoff(double spot) const
{
return thepayoff(spot);
}

double americanontree::prefinalvalue(double spot, double time , double discountedfuturevalue) const
{
return max(thepayoff(spot),discountedfuturevalue);
}