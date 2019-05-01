#include <math.h>
#include <ah_activation_f.h>

float ah_sigmoid( float x )
{
	 float exp_value;
	 float return_value;

	 /*** Exponential calculation ***/
	 exp_value = exp((double) - x);

	 /*** Final sigmoid value ***/
	 return_value = 1 / (1 + exp_value);

	 return return_value;
}

float ah_linear( float x )
{
	 return x;
}
