/*
 * ah_activation_f.h
 *
 *  Created on: 1 may. 2019
 *      Author: nicolas
 */

#ifndef AH_ACTIVATION_F_H_
#define AH_ACTIVATION_F_H_

#include <ah_model_arc.h>

/**
 * \brief Sigmoid function
 * @param x input data
 * @return output data
 */
AH_NN_T ah_sigmoid( AH_NN_T x );


/**
 * \brief Softplus function
 * @param x input data
 * @return output data
 */
AH_NN_T ah_softplus( AH_NN_T x );

/**
 * \brief Softplus function
 * @param x input data
 * @return output data
 */
AH_NN_T ah_tanh( AH_NN_T x );

/**
 * \brief Linear function
 * @param x input data
 * @return output data
 */
AH_NN_T ah_linear( AH_NN_T x );

#endif /* AH_ACTIVATION_F_H_ */
