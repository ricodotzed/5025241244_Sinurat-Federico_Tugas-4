#include <stdio.h>

void get_problem(float *problem){ 
    printf("\nINTRAVENOUS RATE ASSISTANT\n\n");
    printf("Enter the number of the problem you wish to solve.\n");
    printf("    GIVEN A MEDICAL ORDER IN                CALCULATE RATE IN\n");
    printf("(1) ml/hr & tubing drop factor              drops / min\n");
    printf("(2) 1 L for n hr                            ml / hr\n");
    printf("(3) mg/kg/hr & concentration in mg/ml       ml / hr\n");
    printf("(4) units/hr & concentration in units/ml    ml / hr\n");
    printf("(5) QUIT\n\n");

    printf("Problem=> ");
    scanf("%f", problem);

}

void get_rate_drop_factor(float *rate, float *drop){ 
    printf("Enter rate in ml/hr=> ");
    scanf("%f", rate);
    printf("Enter tubing's drop factor(drops/ml)=> ");
    scanf("%f", drop); 
}

void get_hr(float *hour){ 
    printf("Enter number of hours=> ");
    scanf("%f", hour);
}

void get_kg_rate_conc(float *rate, float *weight, float *conc){ 
    printf("Enter rate in mg/kg/hr=> ");
    scanf("%f", rate);
    printf("Enter patient weight in kg=> ");
    scanf("%f", weight);
    printf("Enter concentration in mg/ml=> ");
    scanf("%f", conc);
}

void get_units_conc(float *rate, float *conc){ 
    printf("Enter rate in units/hr=> ");
    scanf("%f", rate);
    printf("Enter concentration in units/ml=> ");
    scanf("%f", conc);
}

void fig_drops_min(float rate, float drop, float result){ 
    result = ((rate * drop) + 0.5) / 60;  
    printf("The drop rate per minute is %.0f.\n", result);
}

void fig_ml_hr(float hr, float result){ 
    result = 1000 / hr;
    printf("The rate in milliliters per hour is %.0f.\n", result);
}

void by_weight(float rate, float weight, float conc, float result){ 
    result = rate * weight * conc;
    printf("The rate in milliliters per hour is %.0f.\n", result);
}

void by_units(float rate, float conc, float result){ 
    result = rate / conc;
    printf("The rate in milliliters per hour is %.0f.\n", result);
}


int main(){
    float rate, drop, problem, hour, weight, conc, result;

    do{
    get_problem(&problem);

    if(problem == 1){
        get_rate_drop_factor(&rate, &drop);
        fig_drops_min(rate, drop, result);
    } else if (problem == 2){
        get_hr(&hour);
        fig_ml_hr(hour, result);
    } else if (problem == 3){
        get_kg_rate_conc(&rate, &weight, &conc);
        by_weight(rate, weight, conc, result);
    } else if (problem == 4){
        get_units_conc(&rate, &conc);
        by_units(rate, conc, result);
    } else if(problem == 5){
        return 0;
    }
    }while(problem != 5);
    
    return 0;
}