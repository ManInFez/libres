/*
   Copyright (C) 2011  Equinor ASA, Norway.

   The file 'analysis_config.h' is part of ERT - Ensemble based Reservoir Tool.

   ERT is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   ERT is distributed in the hope that it will be useful, but WITHOUT ANY
   WARRANTY; without even the implied warranty of MERCHANTABILITY or
   FITNESS FOR A PARTICULAR PURPOSE.

   See the GNU General Public License at <http://www.gnu.org/licenses/gpl.html>
   for more details.
*/


#ifndef ERT_ANALYSIS_CONFIG_H
#define ERT_ANALYSIS_CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include <ert/util/stringlist.h>

#include <ert/config/config_parser.hpp>
#include <ert/config/config_content.hpp>

#include <ert/analysis/analysis_module.hpp>

#include <ert/enkf/enkf_types.hpp>
#include <ert/enkf/analysis_iter_config.hpp>




typedef struct analysis_config_struct analysis_config_type;

analysis_iter_config_type * analysis_config_get_iter_config( const analysis_config_type * config );
analysis_module_type * analysis_config_get_module(const analysis_config_type * config , const char * module_name );
bool                   analysis_config_has_module(const analysis_config_type * config , const char * module_name );
void                   analysis_config_load_internal_module( analysis_config_type * config , const char * symbol_table );
void                   analysis_config_load_internal_modules( analysis_config_type * analysis );
bool                   analysis_config_get_module_option( const analysis_config_type * config , long flag);
bool                   analysis_config_load_external_module( analysis_config_type * config , const char * lib_name, const char * user_name);
void                   analysis_config_load_all_external_modules_from_config ( analysis_config_type * analysis_config, const config_content_type * config);

PY_USED stringlist_type * analysis_config_alloc_module_names( const analysis_config_type * config );
const char           * analysis_config_get_log_path( const analysis_config_type * config );
void                   analysis_config_init( analysis_config_type * analysis , const config_content_type * config);
PY_USED analysis_config_type * analysis_config_alloc_full(
                            double alpha,
                            bool merge_observations,
                            bool rerun,
                            int rerun_start,
                            const char * log_path,
                            double std_cutoff,
                            bool stop_long_running,
                            bool single_node_update,
                            bool std_scale_correlated_obs,
                            double global_std_scaling,
                            int max_runtime,
                            int min_realisations
);
analysis_config_type * analysis_config_alloc_default(void);
analysis_config_type * analysis_config_alloc_load(const char * user_config_file);
analysis_config_type * analysis_config_alloc(const config_content_type * config_content);
void                   analysis_config_free( analysis_config_type * );
PY_USED bool           analysis_config_get_merge_observations(const analysis_config_type * );
double                 analysis_config_get_alpha(const analysis_config_type * config);
PY_USED bool           analysis_config_get_rerun(const analysis_config_type * config);
PY_USED int            analysis_config_get_rerun_start(const analysis_config_type * config);
void                   analysis_config_set_rerun(analysis_config_type * config , bool rerun);
void                   analysis_config_set_rerun_start( analysis_config_type * config , int rerun_start );
void                   analysis_config_set_alpha( analysis_config_type * config , double alpha);
void                   analysis_config_set_merge_observations( analysis_config_type * config , bool merge_observations);
void                   analysis_config_set_log_path(analysis_config_type * config , const char * log_path );
void                   analysis_config_set_std_cutoff( analysis_config_type * config , double std_cutoff );
double                 analysis_config_get_std_cutoff( const analysis_config_type * config );
void                   analysis_config_add_config_items( config_parser_type * config );

bool                   analysis_config_select_module( analysis_config_type * config , const char * module_name );
analysis_module_type * analysis_config_get_active_module(const analysis_config_type * config );
void                   analysis_config_set_single_node_update(analysis_config_type * config , bool single_node_update);
bool                   analysis_config_get_single_node_update(const analysis_config_type * config);

void                   analysis_config_set_store_PC( analysis_config_type * config , bool store_PC);
bool                   analysis_config_get_store_PC( const analysis_config_type * config );
void                   analysis_config_set_PC_filename( analysis_config_type * config , const char * filename );
const char           * analysis_config_get_PC_filename( const analysis_config_type * config );
void                   analysis_config_set_PC_path( analysis_config_type * config , const char * path );
const char           * analysis_config_get_PC_path( const analysis_config_type * config );
bool                   analysis_config_have_enough_realisations( const analysis_config_type* config, int realisations, int ensemble_size);
void                   analysis_config_set_stop_long_running( analysis_config_type * config, bool stop_long_running );
bool                   analysis_config_get_stop_long_running( const analysis_config_type * config);
void                   analysis_config_set_max_runtime( analysis_config_type * config, int max_runtime  );
PY_USED int            analysis_config_get_max_runtime( const analysis_config_type * config );
int                    analysis_config_get_min_realisations( const analysis_config_type * config );
PY_USED const char *   analysis_config_get_active_module_name( const analysis_config_type * config );
bool                   analysis_config_get_std_scale_correlated_obs( const analysis_config_type * config);
void                   analysis_config_set_std_scale_correlated_obs( analysis_config_type * config, bool std_scale_correlated_obs);

double                 analysis_config_get_global_std_scaling(const analysis_config_type * config);
PY_USED void           analysis_config_set_global_std_scaling(analysis_config_type * config, double global_std_scaling);
PY_USED void           analysis_config_add_module_copy( analysis_config_type * config ,
                                                         const char * src_name ,
                                                         const char * target_name);

  UTIL_IS_INSTANCE_HEADER( analysis_config );

#ifdef __cplusplus
}
#endif

#endif
