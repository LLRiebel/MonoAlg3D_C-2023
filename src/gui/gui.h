//
// Created by sachetto on 11/11/17.
//

#ifndef MONOALG3D_GUI_H
#define MONOALG3D_GUI_H

#include <omp.h>

#include "../alg/grid/grid.h"
#include "../alg/cell/cell.h"
#include "../vtk_utils/vtk_unstructured_grid.h"
#include "../3dparty/raylib/src/raylib.h"
#include "../3dparty/raylib/src/raymath.h"
#include "../config/config_parser.h"

#define MIN_VERTICAL_TICKS 4
#define MAX_VERTICAL_TICKS 20

#define MIN_HORIZONTAL_TICKS 4
#define MAX_HORIZONTAL_TICKS 20

#define SIZEOF(A) (sizeof(A)/sizeof(A[0]))
#define WIDER_TEXT " - Alt + R to restart simulation and the box positions"
#define DOUBLE_CLICK_DELAY 0.7  //seconds

#define TMP_SIZE 128

#define V3_SAME(v) (Vector3){v, v, v}

struct action_potential {
    float v;
    float t;
};

enum draw_simulation_or_file {
    DRAW_SIMULATION,
    DRAW_FILE,
};

struct vector3_voidp_hash_entry {
    Vector3 key;
    void *value;
};

struct ap_graph_config {

    Rectangle graph;
    float max_x;
    float min_y;
    float max_y;
    float min_x;

    Vector2 selected_ap_point;
    Vector2 selected_point_for_apd1;
    Vector2 selected_point_for_apd2;
    struct vector3_voidp_hash_entry *selected_aps;
    Rectangle drag_graph_button;
    bool drag_ap_graph;
    bool move_ap_graph;

};

typedef struct action_potential * action_potential_array;

struct voxel {
    Vector3 position_draw;
    Vector3 position_mesh;
    Vector3 size;
    uint32_t draw_index;
    uint32_t matrix_position;
    float v;
};

struct vector3_voxel_entry {
    Vector3 key;
    struct voxel value;
};

//This strcuct is shared with the main thread
struct gui_shared_info {
    float max_v;
    float min_v;
    bool simulating;
    bool paused;
    bool exit;
    bool adaptive;
    bool restart;
    float time;
    float final_time;
    float dt;
    int step;

    char *config_name;
    char *input;

    uint64_t solver_time;
    uint64_t ode_total_time;
    uint64_t cg_total_time;
    uint64_t total_mat_time;
    uint64_t total_ref_time;
    uint64_t total_deref_time;
    uint64_t total_write_time;
    uint64_t total_cg_it;

    int advance_or_return;
    int draw_type;

    // If we are compiling this file, openmp is available.
    omp_lock_t draw_lock;
    omp_lock_t sleep_lock;

    struct grid_info {
        union {
            struct vtk_unstructured_grid *vtk_grid;
            struct grid *alg_grid;
        };
        char *file_name;
        bool loaded;
    } grid_info;

    char *error_message;
    bool int_scale;
    float ui_scale;
};

struct gui_text_window {
    Rectangle rect;
    bool show;
    bool move;
    char **lines;
    char *title;
    int num_lines;
};

struct gui_state {

    int current_window_width;
    int current_window_height;

    float ui_scale;

    float font_spacing_big;
    float font_spacing_small;

    bool handle_keyboard_input;
    bool show_ap;
    bool c_pressed;
    bool draw_grid_lines;
    bool draw_grid_only;

    struct gui_text_window help_box;
    struct gui_text_window mesh_info_box;
    struct gui_text_window end_info_box;

    bool show_selection_box;

    Rectangle scale_bounds;
    bool show_scale;
    bool move_scale;
    bool calc_scale_bounds;

    Ray ray;
    float ray_hit_distance;
    Ray ray_mouse_over;
    float ray_mouse_over_hit_distance;

    int current_scale;
    int scale_alpha;
    int voxel_alpha;

    struct vector3_voxel_entry *current_selected_volumes;
    struct voxel current_selected_volume;
    struct voxel found_volume;
    struct voxel current_mouse_over_volume;

    float font_size_small;
    float font_size_big;

    double mouse_timer;

    Vector2 mouse_pos;
    Vector2 sub_window_pos;
    bool move_sub_window;

    float box_width;
    float box_height;

    struct ap_graph_config *ap_graph_config;

    Vector3 coordinates_cube;
    bool show_coordinates;

    Vector2 coordinates_label_x_position;
    Vector2 coordinates_label_y_position;
    Vector2 coordinates_label_z_position;

    Font font;

    Camera3D camera;

    bool double_clicked;
};

struct mesh_info {
    bool center_calculated;
    Vector3 max_size;
    Vector3 min_size;
};

void init_and_open_gui_window(struct gui_shared_info *gui_config);

#endif // MONOALG3D_GUI_H
