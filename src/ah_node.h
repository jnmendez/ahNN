#ifndef _ah_node_h_
#define _ah_node_h_

/** Maximum  number of nodes in a layer */
#define MAX_INPUTS_NODE 2048

/**
 * Node structure
 */
typedef struct
{
	float _b;					/**< BIAS 	*/
	float _i[MAX_INPUTS_NODE];	/**< INPUT 	*/
	float _w[MAX_INPUTS_NODE];	/**< WEIGHT */
	float _o;					/**< OUTPUT */
}t_node;

#endif
