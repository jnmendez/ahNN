#ifndef AH_NODE_H_
#define AH_NODE_H_

#include <ah_model_arc.h>

/**
 * Node structure
 */
typedef struct
{
	AH_NN_T _x[MAX_NODE];			/**< INPUT  VECTOR	*/
	AH_NN_T _w[MAX_NODE];			/**< WEIGHT VECTOR 	*/
	AH_NN_T _o;						/**< OUTPUT 		*/
	AH_NN_T _b;						/**< BIAS			*/
	int     _ni;					/**< NUM INPUTS 	*/

}t_node;

/**
 * \brief Initialize node
 * @param node pointer to node structure
 * @param ni number of inputs
 * @return 1 in case of error
 */
int ah_node_init( t_node * node, int ni );

/**
 * \brief node prediction
 * @param node pointer to node structure
 * @param act pointer to activation function
 */
AH_NN_T ah_node_prediction( t_node * node, AH_NN_T (*act)(AH_NN_T)  );

/**
 * \brief set node inputs
 * @param node pointer to node structure
 * @param inputs input vector
 */
void ah_node_set_input( t_node * node, AH_NN_T * inputs );

/**
 * \brief set node weight
 * @param node pointer to node structure
 * @param weight weight vector
 */
void ah_node_set_weight( t_node * node, AH_NN_T * weight );

/**
 * \brief set node bias
 * @param node pointer to node structure
 * @param bias value
 */
void ah_node_set_bias( t_node * node, AH_NN_T bias );

/**
 * \brief return calculated output
 * @param node pointer to node structure
 * @return calculated output
 */
AH_NN_T ah_node_get_output( t_node * node  );

#endif
