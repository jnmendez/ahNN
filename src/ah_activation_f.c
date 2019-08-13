#include <math.h>
#include <ah_activation_f.h>

/*
 * \brief Sigmoid function
 * @param x input data
 * @return output data
 */
AH_NN_T ah_sigmoid( AH_NN_T x )
{
	 AH_NN_T exp_value;
	 AH_NN_T return_value;

	 /*** Exponential calculation ***/
	 exp_value = exp((double)-x);

	 /*** Final sigmoid value ***/
	 return_value = 1 / (1 + exp_value);
	 return return_value;
}

/*
 * \brief Softplus function
 * @param x input data
 * @return output data
 */
AH_NN_T ah_softplus( AH_NN_T x )
{
	 AH_NN_T exp_value;
	 AH_NN_T return_value;

	 /*** Exponential calculation ***/
	 exp_value = exp((double)x);

	 /*** Final softplus value ***/
	 return_value = log(1 + exp_value);

	 return return_value;
}

/*
 * \brief Tanh function
 * @param x input data
 * @return output data
 */
AH_NN_T ah_tanh( AH_NN_T x )
{
	 AH_NN_T exp_value;
	 AH_NN_T return_value;

	 /*** Exponential calculation ***/
	 exp_value = exp((double)-2*x);

	 /*** Final tanh value ***/
	 return_value = (2 / (1 + exp_value)) - 1 ;

	 return return_value;
}

/*
 * \brief Linear function
 * @param x input data
 * @return output data
 */
AH_NN_T ah_linear( AH_NN_T x )
{
	 return x;
}
