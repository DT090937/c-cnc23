/******************************************************************************
Finite State Machine
Project: C-CNC
Description: Finite state machine for C-CNC

Generated by gv_fsm ruby gem, see https://rubygems.org/gems/gv_fsm
gv_fsm version 0.3.4
Generation date: 2023-05-11 12:49:20 +0200
Generated from: src/fsm.dot
The finite state machine has:
  7 states
  5 transition functions
Functions and types have been generated with prefix "ccnc_"
******************************************************************************/

#ifndef FSM_H
#define FSM_H
#include <stdlib.h>
#include "machine.h"
#include "program.h"

// State data object
// By default set to void; override this typedef or load the proper
// header if you need
typedef struct {
  char *ini_file;
  char *prog_file;
  machine_t *machine;
  program_t *program;
  data_t t_tot;
  data_t t_blk;
} ccnc_state_data_t;

// NOTHING SHALL BE CHANGED AFTER THIS LINE!

// List of states
typedef enum {
  CCNC_STATE_INIT = 0,  
  CCNC_STATE_IDLE,  
  CCNC_STATE_STOP,  
  CCNC_STATE_LOAD_BLOCK,  
  CCNC_STATE_NO_MOTION,  
  CCNC_STATE_RAPID_MOTION,  
  CCNC_STATE_INTERP_MOTION,  
  CCNC_NUM_STATES,
  CCNC_NO_CHANGE
} ccnc_state_t;

// State human-readable names
extern const char *ccnc_state_names[];

// State function and state transition prototypes
typedef ccnc_state_t state_func_t(ccnc_state_data_t *data);
typedef void transition_func_t(ccnc_state_data_t *data);

// State functions

// Function to be executed in state init
// valid return states: CCNC_STATE_IDLE, CCNC_STATE_STOP
ccnc_state_t ccnc_do_init(ccnc_state_data_t *data);

// Function to be executed in state idle
// valid return states: CCNC_NO_CHANGE, CCNC_STATE_IDLE, CCNC_STATE_LOAD_BLOCK, CCNC_STATE_STOP
ccnc_state_t ccnc_do_idle(ccnc_state_data_t *data);

// Function to be executed in state stop
// valid return states: CCNC_NO_CHANGE
ccnc_state_t ccnc_do_stop(ccnc_state_data_t *data);

// Function to be executed in state load_block
// valid return states: CCNC_STATE_IDLE, CCNC_STATE_NO_MOTION, CCNC_STATE_RAPID_MOTION, CCNC_STATE_INTERP_MOTION
ccnc_state_t ccnc_do_load_block(ccnc_state_data_t *data);

// Function to be executed in state no_motion
// valid return states: CCNC_STATE_LOAD_BLOCK
ccnc_state_t ccnc_do_no_motion(ccnc_state_data_t *data);

// Function to be executed in state rapid_motion
// valid return states: CCNC_NO_CHANGE, CCNC_STATE_LOAD_BLOCK, CCNC_STATE_RAPID_MOTION
ccnc_state_t ccnc_do_rapid_motion(ccnc_state_data_t *data);

// Function to be executed in state interp_motion
// valid return states: CCNC_NO_CHANGE, CCNC_STATE_LOAD_BLOCK, CCNC_STATE_INTERP_MOTION
ccnc_state_t ccnc_do_interp_motion(ccnc_state_data_t *data);


// List of state functions
extern state_func_t *const ccnc_state_table[CCNC_NUM_STATES];


// Transition functions
void ccnc_reset(ccnc_state_data_t *data);
void ccnc_begin_rapid(ccnc_state_data_t *data);
void ccnc_begin_interp(ccnc_state_data_t *data);
void ccnc_end_rapid(ccnc_state_data_t *data);
void ccnc_end_interp(ccnc_state_data_t *data);

// Table of transition functions
extern transition_func_t *const ccnc_transition_table[CCNC_NUM_STATES][CCNC_NUM_STATES];

// state manager
ccnc_state_t ccnc_run_state(ccnc_state_t cur_state, ccnc_state_data_t *data);

#endif
