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

/**_
 *	@brief Initialize node
 *	@param node pointer to node
 *	@param ni number of inputs
 */
int   ah_node_init		( t_node * node, int ni );
void  ah_node_set_input	( t_node * node, float inputs[] );
void  ah_node_set_weight( t_node * node, float weight[] );
void  ah_node_prediction( t_node * node, float (*act)(float)  );
float ah_node_get_output( t_node * node  );


#endif
