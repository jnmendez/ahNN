#ifndef _ah_node_h_
#define _ah_node_h_

/** Maximum  number of nodes in a layer */
#define MAX_INPUTS_NODE 2048

/**
 * Node structure
 */
typedef struct
{
	float _b;					/**< BIAS 			*/
	float _i[MAX_INPUTS_NODE];	/**< INPUT  VECTOR	*/
	float _w[MAX_INPUTS_NODE];	/**< WEIGHT VECTOR 	*/
	float _o;					/**< OUTPUT 		*/
}t_node;

/**
 *	@brief Initialize node
 *	@param node pointer to node
 *	@param ni number of inputs
 *	@param bi bias
 *	@param we weight vector
 */
int ah_node_init( t_node * node, int ni, float bi, float we[] );


#endif
