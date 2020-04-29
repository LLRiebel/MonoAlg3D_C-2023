#include <stdio.h>
#include "mitchell_shaeffer_2003.h"

GET_CELL_MODEL_DATA(init_cell_model_data) 
{

    if(get_initial_v)
        cell_model->initial_v = INITIAL_V;
    if(get_neq)
        cell_model->number_of_ode_equations = NEQ;
}

SET_ODE_INITIAL_CONDITIONS_CPU(set_model_initial_conditions_cpu) 
{

    static bool first_call = true;

    if(first_call) {
#ifdef _WIN32
        printf("Using Mitchell-Shaeffer 2003 CPU model\n");
#else
        log_to_stdout_and_file("Using Mitchell-Shaeffer 2003 CPU model\n");
#endif

        first_call = false;
    }

    uint32_t num_volumes = solver->original_num_cells;

    OMP(parallel for)
    for(uint32_t i = 0; i < num_volumes; i++) {
        real *sv = &solver->sv[i * NEQ];
        sv[0] = 0.00000820413566106744f; // Vm millivolt
        sv[1] = 0.8789655121804799f;     // h dimensionless
    }
}

SOLVE_MODEL_ODES_CPU(solve_model_odes_cpu) 
{

    uint32_t sv_id;

	int i;

//    uint32_t *mapping = ((uint32_t*)extra_data);

    OMP(parallel for private(sv_id))
    for (i = 0; i < num_cells_to_solve; i++) 
    {
        if(cells_to_solve)
            sv_id = cells_to_solve[i];
        else
            sv_id = (uint32_t )i;

        for (int j = 0; j < num_steps; ++j) 
        {
            solve_model_ode_cpu(dt, sv + (sv_id * NEQ), stim_currents[i]);
        }
    }

}

void solve_model_ode_cpu(real dt, real *sv, real stim_current)  
{

    real rY[NEQ], rDY[NEQ];

    for(int i = 0; i < NEQ; i++)
        rY[i] = sv[i];

    RHS_cpu(rY, rDY, stim_current);

    for(int i = 0; i < NEQ; i++)
        sv[i] = dt*rDY[i] + rY[i];
}

void RHS_cpu(const real *sv, real *rDY_, real stim_current) 
{

    //State variables
    const real V = sv[0];
    const real h = sv[1];

    // Constants
    const real tau_in = 0.3;
    const real tau_out = 6.0;
    const real V_gate = 0.13;
    const real tau_open = 120.0;
    const real tau_close = 150.0;

    // Algebraics
    real J_stim = stim_current;
    real J_in = ( h*( pow(V, 2.00000)*(1.00000 - V)))/tau_in;
    real J_out = - (V/tau_out);

    // Rates
    rDY_[0] = J_out + J_in + J_stim;
    rDY_[1] = (V < V_gate ? (1.00000 - h)/tau_open : - h/tau_close);

}
