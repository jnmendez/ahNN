/***********************************************/
/* GENERATED CODE. DO NOT MODIFY MANUALLY      */
/***********************************************/                   

#include <time.h>
#include <stdio.h>
#include <ah_activation_f.h>
#include <ah_model.h>


/* Pointer to NN model */
extern t_model * _el_model;

/* Bias and weight vectors */
extern float _el_biasLayer_1[];
extern float _el_weightLayer_1[];
extern float _el_biasLayer_2[];
extern float _el_weightLayer_2[];
extern float _el_biasLayer_3[];
extern float _el_weightLayer_3[];

/* Input vector */
float input_el_model[11] =
{
(float)1.3158784417171006,
(float)-0.9197654643113794,
(float)-1.2151285289169167,
(float)0.5573492988234939,
(float)1.5595829326785589,
(float)-0.3690367899810003,
(float)1.6824180382200358,
(float)-0.8817904817800104,
(float)-0.630719717763861,
(float)-1.0354059862690137,
(float)-0.6596852246658311,
};

/* Output vector */
float output_el_model[1];

void _el_init_model( void )
{
     /* Init model */	
     ah_model_init( _el_model );

     /* Setup model */
     ah_model_add_input_layer( _el_model, 32, 11, &ah_sigmoid );
     ah_model_set_bias(_el_model, 0, &_el_biasLayer_1[0]);
     ah_model_set_weight(_el_model, 0, &_el_weightLayer_1[0]);
	
     ah_model_add_layer(_el_model, 16, &ah_sigmoid);
     ah_model_set_bias(_el_model, 1, &_el_biasLayer_2[0]);
     ah_model_set_weight(_el_model, 1, &_el_weightLayer_2[0]);
     ah_model_add_layer(_el_model, 1, &ah_sigmoid);
     ah_model_set_bias(_el_model, 2, &_el_biasLayer_3[0]);
     ah_model_set_weight(_el_model, 2, &_el_weightLayer_3[0]);

#define  _TIME_HOST_ 1
	
#ifdef _TIME_HOST_
     clock_t begin = clock();
#endif
#ifdef _TIME_GPC_
     readStart();
#endif
     /* here, do your time-consuming job */
     ah_model_prediction( _el_model, input_el_model, output_el_model );
     /*printf("output_el_model : %f %f\n",output_el_model[0],0.07364398);*/
#ifdef _TIME_GPC_
     computeEnd();
     printf("PRINT TIME %llu micros\n", avg);
#endif

#ifdef _TIME_HOST_
     clock_t end = clock();
     double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
     printf("TIME microsec : %lf\n",time_spent*1000000);
#endif
}
