#include <stdio.h>

#include <ah_activation_f.h>

#define MAX_CAL_SIGM	21

AH_NN_T inOutSigmoid[MAX_CAL_SIGM][2] = {
		{-5.0, (AH_NN_T)0.006692851},
		{-4.5, (AH_NN_T)0.010986943},
		{-4.0, (AH_NN_T)0.017986210},
		{-3.5, (AH_NN_T)0.029312231},
		{-3.0, (AH_NN_T)0.047425873},
		{-2.5, (AH_NN_T)0.075858180},
		{-2.0, (AH_NN_T)0.119202922},
		{-1.5, (AH_NN_T)0.182425524},
		{-1.0, (AH_NN_T)0.268941421},
		{-0.5, (AH_NN_T)0.377540669},
		{ 0.0, (AH_NN_T)0.500000000},
		{ 0.5, (AH_NN_T)0.622459331},
		{ 1.0, (AH_NN_T)0.731058579},
		{ 1.5, (AH_NN_T)0.817574476},
		{ 2.0, (AH_NN_T)0.880797078},
		{ 2.5, (AH_NN_T)0.924141820},
		{ 3.0, (AH_NN_T)0.952574127},
		{ 3.5, (AH_NN_T)0.970687769},
		{ 4.0, (AH_NN_T)0.982013790},
		{ 4.5, (AH_NN_T)0.989013057},
		{ 5.0, (AH_NN_T)0.993307149}
};

AH_NN_T inOutLinear[MAX_CAL_SIGM][2] = {
		{-5.0, -5.0},
		{-4.5, -4.5},
		{-4.0, -4.0},
		{-3.5, -3.5},
		{-3.0, -3.0},
		{-2.5, -2.5},
		{-2.0, -2.0},
		{-1.5, -1.5},
		{-1.0, -1.0},
		{-0.5, -0.5},
		{ 0.0, 0.0},
		{ 0.5, 0.5},
		{ 1.0, 1.0},
		{ 1.5, 1.5},
		{ 2.0, 2.0},
		{ 2.5, 2.5},
		{ 3.0, 3.0},
		{ 3.5, 3.5},
		{ 4.0, 4.0},
		{ 4.5, 4.5},
		{ 5.0, 5.0}
};

void activation_f_T1( void )
{
	
	for (int i = 0; i < MAX_CAL_SIGM ; i++ )
	{
		AH_NN_T result = ah_sigmoid( inOutSigmoid[i][0] );
		if ( result == inOutSigmoid[i][1] )
		{
			printf("ACTF_T1 : %lf - %lf : PASS\n", result, inOutSigmoid[i][1]);
		}
		else
		{
			printf("ACTF_T1 : %lf - %lf : FAIL\n", result, inOutSigmoid[i][1]);
		}
	}
		
}

void activation_f_T2( void )
{
	
	for (int i = 0; i < MAX_CAL_SIGM ; i++ )
	{
		AH_NN_T result = ah_linear( inOutLinear[i][0] );
		if ( result == inOutLinear[i][1] )
		{
			printf("ACTF_T2 : %f - %f : PASS\n", result, inOutLinear[i][1]);
		}
		else
		{
			printf("ACTF_T2 : %f - %f : FAIL\n", result, inOutLinear[i][1]);			
		}
	}
		
}
