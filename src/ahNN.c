/*
 ============================================================================
 Name        : ahNN.c
 Author      : Nicolas Mendez
 Version     :
 Copyright   :
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ah_node.h>

int main(void) {
	t_node n1;
	float we[3] = {1.3,2.4,3.5};
	int re = ah_node_init( &n1, 3000, 1.2345, we );
	return re;
}
