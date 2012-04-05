#include "europeanontree.h"
#include <algorithm>
using namespace std;

europeanontree::europeanontree(double finaltime, const payoffbridge& thepayoff_):
productontree(finaltime),thepayoff(thepayoff_)
{
}

double europeanontree::finalpayoff(double spot) const
{
return thepayoff(spot);
}

double europeanontree::prefinalvalue(double spot, double time, double discountedfuturevalue) const
{
return discountedfuturevalue;
}

productontree* europeanontree::clone() const
{
return new europeanontree(*this);
}