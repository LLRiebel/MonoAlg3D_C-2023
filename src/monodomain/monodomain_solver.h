#ifndef MONOALG3D_SOLVER_H
#define MONOALG3D_SOLVER_H

#include "../alg/grid/grid.h"
#include "ode_solver.h"
#include "../config/config_parser.h"

#include <stdbool.h>
#include <stdint.h>

//Forward declarations
struct user_options;
struct ode_solver;

struct monodomain_solver {

    int num_threads;
    real_cpu final_time;

    real_cpu beta, cm; // micrometers

    //TODO: maybe use an extra data variable as we did on the alg cell
    struct point_3d kappa;
    
    int refine_each;
    int derefine_each;
    real_cpu refinement_bound;
    real_cpu derefinement_bound;

    real_cpu start_adapting_at;

    bool abort_on_no_activity;
    real_cpu only_abort_after_dt;

    // Time used for solving wave equation.
    real_cpu dt;

};

struct monodomain_solver *new_monodomain_solver ();

int solve_monodomain(struct monodomain_solver *the_monodomain_solver, struct ode_solver *the_ode_solver,
                      struct grid *the_grid, struct user_options *configs);

void save_old_cell_positions (struct grid *the_grid);
void update_cells_to_solve (struct grid *the_grid, struct ode_solver *solver);

void print_solver_info(struct monodomain_solver *the_monodomain_solver,
                        struct ode_solver *the_ode_solver, struct ode_solver *the_purkinje_ode_solver,
                        struct grid *the_grid, struct user_options *options);

void print_solver_info(struct monodomain_solver *the_monodomain_solver,
                        struct ode_solver *the_ode_solver, struct ode_solver *the_purkinje_ode_solver,
                        struct grid *the_grid, struct user_options *options);

void set_spatial_stim(struct time_info *time_info, struct string_voidp_hash_entry *stim_configs, struct grid *the_grid, bool purkinje);
                    
void configure_monodomain_solver_from_options(struct monodomain_solver *the_monodomain_solver, struct user_options *options);

bool print_result(const struct grid *the_grid, const struct user_options *configs, int count);

bool update_ode_state_vector_and_check_for_activity(real_cpu vm_threshold, struct ode_solver *the_ode_solver, struct ode_solver *the_purkinje_ode_solver, struct grid *the_grid);

void compute_pmj_current_purkinje_to_tissue (struct ode_solver *the_ode_solver, struct grid *the_grid, struct terminal *the_terminals);
void compute_pmj_current_tissue_to_purkinje (struct ode_solver *the_purkinje_ode_solver, struct grid *the_grid, struct terminal *the_terminals);


void debug_print_and_leave ();

#endif // MONOALG3D_SOLVER_H
