#ifndef AH_NODE_H_
#define AH_NODE_H_

/** Maximum  number of inputs in for a node */
#define MAX_INPUT	256

/**
 * Node structure
 */
typedef struct
{
	float _x[MAX_INPUT];			/**< INPUT  VECTOR	*/
	float _w[MAX_INPUT];			/**< WEIGHT VECTOR 	*/
	float _o;						/**< OUTPUT 		*/
	float _b;						/**< BIAS			*/
	int   _ni;						/**< NUM INPUTS 	*/

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
void ah_node_prediction( t_node * node, float (*act)(float)  );

/**
 * \brief set node inputs
 * @param node pointer to node structure
 * @param inputs input vector
 */
void ah_node_set_input( t_node * node, float inputs[] );

/**
 * \brief set node weight
 * @param node pointer to node structure
 * @param weight weight vector
 */
void ah_node_set_weight( t_node * node, float * weight );

/**
 * \brief set node bias
 * @param node pointer to node structure
 * @param bias value
 */
void ah_node_set_bias( t_node * node, float bias );

/**
 * \brief return calculated output
 * @param node pointer to node structure
 * @return calculated output
 */
float ah_node_get_output( t_node * node  );

#endif
