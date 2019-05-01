#ifndef AH_NODE_H_
#define AH_NODE_H_

/** Maximum  number of nodes in a layer */
#define MAX_INPUT	256

/**
 * Node structure
 */
typedef struct
{
	float _i[MAX_INPUT];			/**< INPUT  VECTOR	*/
	float _w[MAX_INPUT];			/**< WEIGHT VECTOR 	*/
	float _o;						/**< OUTPUT 		*/
}t_node;

/**
 *	@brief Initialize node
 *	@param node pointer to node
 *	@param ni number of inputs
 *	@param bi bias
 *	@param we weight vector
 */
int ah_node_init( t_node * node, int ni );


#endif
