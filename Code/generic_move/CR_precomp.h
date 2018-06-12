//generated by Precompiler.ipynb on 2018-04-23 17:28:21.784232
#ifndef __conc_rot_precomputed
#define __conc_rot_precomputed
/**
 * @file
 * @brief Header file for interfacing with intenal concerted rotation functions
 */
 
#include <gsl/gsl_vector.h>
#include <gsl/gsl_matrix.h>
/** @brief EPSIL_DET. */
#define EPSIL_DET (0.0000001)

/**
 * @brief Concerted rotation move state data
 *
 * Structure contain all data nesessary for representation of peptide backbone in space of concerted rotation.
 */
typedef struct cr_input_data {
    gsl_vector *dihed_angles;   /**< Vector of dihedral angles with length \f$(numberOfResidues*2)+1\f$. */
    gsl_vector *bend_angles;    /**< Vector of bending angles with length \f$(numberOfResidues*2)+1\f$. */
    gsl_vector *r;              /**< Vector of displacements along z with length \f$(numberOfResidues*2)+1\f$. */
    gsl_vector *d;              /**< Vector of displacements orthogonal to z with length \f$(numberOfResidues*2)+1\f$. */
} cr_input_data;

void alloc_cr_input_data(cr_input_data *bb);
void free_cr_input_data(cr_input_data *bb);
void memcpy_cr_input_data(cr_input_data *bb_a, const cr_input_data *bb_b);
void print_cr_input_data(const cr_input_data *bb, FILE *stream);
void compare_cr_input_data(const cr_input_data *bb_a, const cr_input_data *bb_b, FILE *stream);
int compare_bend_angles(const cr_input_data *bb_a, const cr_input_data *bb_b);

/**
 * @brief Internal representation of protein backbone for concerted rotation move
 */
struct expl_data{
    double c [7]; /**< cos(phi) and cos(psi) angles. */
    double s [7]; /**< sin(phi) and sin(psi) angles. */
    double ca[7]; /**< alpha = bending angles cos(alpha) and cos(alpha) angles. */
    double sa[7]; /**< alpha = bending angles sin(alpha) and sin(alpha) angles. */
    double d [7]; /**< Vector of displacements orthogonal to z. */
    double r [7]; /**< Vector of displacements along z. */
};
void T7 (gsl_vector *T,const struct cr_input_data bb);
//Tangent vectors
int TmT7_t1 (gsl_vector *T,const struct cr_input_data bb);
int TmT7_t2 (gsl_vector *T,const struct cr_input_data bb);
int TmT7_t3 (gsl_vector *T,const struct cr_input_data bb);
int TmT7_t4 (gsl_vector *T,const struct cr_input_data bb);
int TmT7_t5 (gsl_vector *T,const struct cr_input_data bb);
int TmT7_t6 (gsl_vector *T,const struct cr_input_data bb);
int TmT7_t7 (gsl_vector *T,const struct cr_input_data bb);
//Tangent vectors function array
int (*TmT[7])(gsl_vector *,const struct cr_input_data);
//Derivatives
gsl_vector * DT7_t1 (struct cr_input_data bb);
gsl_vector * DT7_t2 (struct cr_input_data bb);
gsl_vector * DT7_t3 (struct cr_input_data bb);
gsl_vector * DT7_t4 (struct cr_input_data bb);
gsl_vector * DT7_t5 (struct cr_input_data bb);
gsl_vector * DT7_t6 (struct cr_input_data bb);
gsl_vector * DT7_t7 (struct cr_input_data bb);
//Jacobians
gsl_matrix * jac_t1 (struct cr_input_data bb);
gsl_matrix * jac_t2 (struct cr_input_data bb);
gsl_matrix * jac_t3 (struct cr_input_data bb);
gsl_matrix * jac_t4 (struct cr_input_data bb);
gsl_matrix * jac_t5 (struct cr_input_data bb);
gsl_matrix * jac_t6 (struct cr_input_data bb);
gsl_matrix * jac_t7 (struct cr_input_data bb);
//Jacobians function array
gsl_matrix * (*jac[7])(struct cr_input_data);
void T7_explicit (gsl_vector *T,struct expl_data cr_in);
//Tangent vectors
int TmT7_explicit_t1 (struct expl_data cr_in);
int TmT7_explicit_t2 (struct expl_data cr_in);
int TmT7_explicit_t3 (struct expl_data cr_in);
int TmT7_explicit_t4 (struct expl_data cr_in);
int TmT7_explicit_t5 (struct expl_data cr_in);
int TmT7_explicit_t6 (struct expl_data cr_in);
int TmT7_explicit_t7 (struct expl_data cr_in);
//Derivatives
gsl_vector * DT7_explicit_t1 (struct expl_data cr_in);
gsl_vector * DT7_explicit_t2 (struct expl_data cr_in);
gsl_vector * DT7_explicit_t3 (struct expl_data cr_in);
gsl_vector * DT7_explicit_t4 (struct expl_data cr_in);
gsl_vector * DT7_explicit_t5 (struct expl_data cr_in);
gsl_vector * DT7_explicit_t6 (struct expl_data cr_in);
gsl_vector * DT7_explicit_t7 (struct expl_data cr_in);
//Jacobians
gsl_matrix * jac_explicit_t1 (struct expl_data cr_in);
gsl_matrix * jac_explicit_t2 (struct expl_data cr_in);
gsl_matrix * jac_explicit_t3 (struct expl_data cr_in);
gsl_matrix * jac_explicit_t4 (struct expl_data cr_in);
gsl_matrix * jac_explicit_t5 (struct expl_data cr_in);
gsl_matrix * jac_explicit_t6 (struct expl_data cr_in);
gsl_matrix * jac_explicit_t7 (struct expl_data cr_in);
//ll T7 get
double get_T7_12 (struct expl_data cr_in);
double get_T7_13 (struct expl_data cr_in);
double get_T7_23 (struct expl_data cr_in);
double get_T7_14 (struct expl_data cr_in);
double get_T7_24 (struct expl_data cr_in);
double get_T7_34 (struct expl_data cr_in);
double get_T7_33 (struct expl_data cr_in);
//Elements of T7 derivatives
double get_DT7_t1_1 (struct expl_data cr_in);
double get_DT7_t1_2 (struct expl_data cr_in);
double get_DT7_t1_3 (struct expl_data cr_in);
double get_DT7_t1_4 (struct expl_data cr_in);
double get_DT7_t1_5 (struct expl_data cr_in);
double get_DT7_t1_6 (struct expl_data cr_in);
double get_DT7_t2_1 (struct expl_data cr_in);
double get_DT7_t2_2 (struct expl_data cr_in);
double get_DT7_t2_3 (struct expl_data cr_in);
double get_DT7_t2_4 (struct expl_data cr_in);
double get_DT7_t2_5 (struct expl_data cr_in);
double get_DT7_t2_6 (struct expl_data cr_in);
double get_DT7_t3_1 (struct expl_data cr_in);
double get_DT7_t3_2 (struct expl_data cr_in);
double get_DT7_t3_3 (struct expl_data cr_in);
double get_DT7_t3_4 (struct expl_data cr_in);
double get_DT7_t3_5 (struct expl_data cr_in);
double get_DT7_t3_6 (struct expl_data cr_in);
double get_DT7_t4_1 (struct expl_data cr_in);
double get_DT7_t4_2 (struct expl_data cr_in);
double get_DT7_t4_3 (struct expl_data cr_in);
double get_DT7_t4_4 (struct expl_data cr_in);
double get_DT7_t4_5 (struct expl_data cr_in);
double get_DT7_t4_6 (struct expl_data cr_in);
double get_DT7_t5_1 (struct expl_data cr_in);
double get_DT7_t5_2 (struct expl_data cr_in);
double get_DT7_t5_3 (struct expl_data cr_in);
double get_DT7_t5_4 (struct expl_data cr_in);
double get_DT7_t5_5 (struct expl_data cr_in);
double get_DT7_t5_6 (struct expl_data cr_in);
double get_DT7_t6_1 (struct expl_data cr_in);
double get_DT7_t6_2 (struct expl_data cr_in);
double get_DT7_t6_3 (struct expl_data cr_in);
double get_DT7_t6_4 (struct expl_data cr_in);
double get_DT7_t6_5 (struct expl_data cr_in);
double get_DT7_t6_6 (struct expl_data cr_in);
double get_DT7_t7_1 (struct expl_data cr_in);
double get_DT7_t7_2 (struct expl_data cr_in);
double get_DT7_t7_3 (struct expl_data cr_in);
double get_DT7_t7_4 (struct expl_data cr_in);
double get_DT7_t7_5 (struct expl_data cr_in);
double get_DT7_t7_6 (struct expl_data cr_in);
//Elements of T7 derivatives
double get_jac_t1_11 (struct expl_data cr_in);
double get_jac_t1_12 (struct expl_data cr_in);
double get_jac_t1_13 (struct expl_data cr_in);
double get_jac_t1_14 (struct expl_data cr_in);
double get_jac_t1_15 (struct expl_data cr_in);
double get_jac_t1_16 (struct expl_data cr_in);
double get_jac_t1_21 (struct expl_data cr_in);
double get_jac_t1_22 (struct expl_data cr_in);
double get_jac_t1_23 (struct expl_data cr_in);
double get_jac_t1_24 (struct expl_data cr_in);
double get_jac_t1_25 (struct expl_data cr_in);
double get_jac_t1_26 (struct expl_data cr_in);
double get_jac_t1_31 (struct expl_data cr_in);
double get_jac_t1_32 (struct expl_data cr_in);
double get_jac_t1_33 (struct expl_data cr_in);
double get_jac_t1_34 (struct expl_data cr_in);
double get_jac_t1_35 (struct expl_data cr_in);
double get_jac_t1_36 (struct expl_data cr_in);
double get_jac_t1_41 (struct expl_data cr_in);
double get_jac_t1_42 (struct expl_data cr_in);
double get_jac_t1_43 (struct expl_data cr_in);
double get_jac_t1_44 (struct expl_data cr_in);
double get_jac_t1_45 (struct expl_data cr_in);
double get_jac_t1_46 (struct expl_data cr_in);
double get_jac_t1_51 (struct expl_data cr_in);
double get_jac_t1_52 (struct expl_data cr_in);
double get_jac_t1_53 (struct expl_data cr_in);
double get_jac_t1_54 (struct expl_data cr_in);
double get_jac_t1_55 (struct expl_data cr_in);
double get_jac_t1_56 (struct expl_data cr_in);
double get_jac_t1_61 (struct expl_data cr_in);
double get_jac_t1_62 (struct expl_data cr_in);
double get_jac_t1_63 (struct expl_data cr_in);
double get_jac_t1_64 (struct expl_data cr_in);
double get_jac_t1_65 (struct expl_data cr_in);
double get_jac_t1_66 (struct expl_data cr_in);
double get_jac_t2_11 (struct expl_data cr_in);
double get_jac_t2_12 (struct expl_data cr_in);
double get_jac_t2_13 (struct expl_data cr_in);
double get_jac_t2_14 (struct expl_data cr_in);
double get_jac_t2_15 (struct expl_data cr_in);
double get_jac_t2_16 (struct expl_data cr_in);
double get_jac_t2_21 (struct expl_data cr_in);
double get_jac_t2_22 (struct expl_data cr_in);
double get_jac_t2_23 (struct expl_data cr_in);
double get_jac_t2_24 (struct expl_data cr_in);
double get_jac_t2_25 (struct expl_data cr_in);
double get_jac_t2_26 (struct expl_data cr_in);
double get_jac_t2_31 (struct expl_data cr_in);
double get_jac_t2_32 (struct expl_data cr_in);
double get_jac_t2_33 (struct expl_data cr_in);
double get_jac_t2_34 (struct expl_data cr_in);
double get_jac_t2_35 (struct expl_data cr_in);
double get_jac_t2_36 (struct expl_data cr_in);
double get_jac_t2_41 (struct expl_data cr_in);
double get_jac_t2_42 (struct expl_data cr_in);
double get_jac_t2_43 (struct expl_data cr_in);
double get_jac_t2_44 (struct expl_data cr_in);
double get_jac_t2_45 (struct expl_data cr_in);
double get_jac_t2_46 (struct expl_data cr_in);
double get_jac_t2_51 (struct expl_data cr_in);
double get_jac_t2_52 (struct expl_data cr_in);
double get_jac_t2_53 (struct expl_data cr_in);
double get_jac_t2_54 (struct expl_data cr_in);
double get_jac_t2_55 (struct expl_data cr_in);
double get_jac_t2_56 (struct expl_data cr_in);
double get_jac_t2_61 (struct expl_data cr_in);
double get_jac_t2_62 (struct expl_data cr_in);
double get_jac_t2_63 (struct expl_data cr_in);
double get_jac_t2_64 (struct expl_data cr_in);
double get_jac_t2_65 (struct expl_data cr_in);
double get_jac_t2_66 (struct expl_data cr_in);
double get_jac_t3_11 (struct expl_data cr_in);
double get_jac_t3_12 (struct expl_data cr_in);
double get_jac_t3_13 (struct expl_data cr_in);
double get_jac_t3_14 (struct expl_data cr_in);
double get_jac_t3_15 (struct expl_data cr_in);
double get_jac_t3_16 (struct expl_data cr_in);
double get_jac_t3_21 (struct expl_data cr_in);
double get_jac_t3_22 (struct expl_data cr_in);
double get_jac_t3_23 (struct expl_data cr_in);
double get_jac_t3_24 (struct expl_data cr_in);
double get_jac_t3_25 (struct expl_data cr_in);
double get_jac_t3_26 (struct expl_data cr_in);
double get_jac_t3_31 (struct expl_data cr_in);
double get_jac_t3_32 (struct expl_data cr_in);
double get_jac_t3_33 (struct expl_data cr_in);
double get_jac_t3_34 (struct expl_data cr_in);
double get_jac_t3_35 (struct expl_data cr_in);
double get_jac_t3_36 (struct expl_data cr_in);
double get_jac_t3_41 (struct expl_data cr_in);
double get_jac_t3_42 (struct expl_data cr_in);
double get_jac_t3_43 (struct expl_data cr_in);
double get_jac_t3_44 (struct expl_data cr_in);
double get_jac_t3_45 (struct expl_data cr_in);
double get_jac_t3_46 (struct expl_data cr_in);
double get_jac_t3_51 (struct expl_data cr_in);
double get_jac_t3_52 (struct expl_data cr_in);
double get_jac_t3_53 (struct expl_data cr_in);
double get_jac_t3_54 (struct expl_data cr_in);
double get_jac_t3_55 (struct expl_data cr_in);
double get_jac_t3_56 (struct expl_data cr_in);
double get_jac_t3_61 (struct expl_data cr_in);
double get_jac_t3_62 (struct expl_data cr_in);
double get_jac_t3_63 (struct expl_data cr_in);
double get_jac_t3_64 (struct expl_data cr_in);
double get_jac_t3_65 (struct expl_data cr_in);
double get_jac_t3_66 (struct expl_data cr_in);
double get_jac_t4_11 (struct expl_data cr_in);
double get_jac_t4_12 (struct expl_data cr_in);
double get_jac_t4_13 (struct expl_data cr_in);
double get_jac_t4_14 (struct expl_data cr_in);
double get_jac_t4_15 (struct expl_data cr_in);
double get_jac_t4_16 (struct expl_data cr_in);
double get_jac_t4_21 (struct expl_data cr_in);
double get_jac_t4_22 (struct expl_data cr_in);
double get_jac_t4_23 (struct expl_data cr_in);
double get_jac_t4_24 (struct expl_data cr_in);
double get_jac_t4_25 (struct expl_data cr_in);
double get_jac_t4_26 (struct expl_data cr_in);
double get_jac_t4_31 (struct expl_data cr_in);
double get_jac_t4_32 (struct expl_data cr_in);
double get_jac_t4_33 (struct expl_data cr_in);
double get_jac_t4_34 (struct expl_data cr_in);
double get_jac_t4_35 (struct expl_data cr_in);
double get_jac_t4_36 (struct expl_data cr_in);
double get_jac_t4_41 (struct expl_data cr_in);
double get_jac_t4_42 (struct expl_data cr_in);
double get_jac_t4_43 (struct expl_data cr_in);
double get_jac_t4_44 (struct expl_data cr_in);
double get_jac_t4_45 (struct expl_data cr_in);
double get_jac_t4_46 (struct expl_data cr_in);
double get_jac_t4_51 (struct expl_data cr_in);
double get_jac_t4_52 (struct expl_data cr_in);
double get_jac_t4_53 (struct expl_data cr_in);
double get_jac_t4_54 (struct expl_data cr_in);
double get_jac_t4_55 (struct expl_data cr_in);
double get_jac_t4_56 (struct expl_data cr_in);
double get_jac_t4_61 (struct expl_data cr_in);
double get_jac_t4_62 (struct expl_data cr_in);
double get_jac_t4_63 (struct expl_data cr_in);
double get_jac_t4_64 (struct expl_data cr_in);
double get_jac_t4_65 (struct expl_data cr_in);
double get_jac_t4_66 (struct expl_data cr_in);
double get_jac_t5_11 (struct expl_data cr_in);
double get_jac_t5_12 (struct expl_data cr_in);
double get_jac_t5_13 (struct expl_data cr_in);
double get_jac_t5_14 (struct expl_data cr_in);
double get_jac_t5_15 (struct expl_data cr_in);
double get_jac_t5_16 (struct expl_data cr_in);
double get_jac_t5_21 (struct expl_data cr_in);
double get_jac_t5_22 (struct expl_data cr_in);
double get_jac_t5_23 (struct expl_data cr_in);
double get_jac_t5_24 (struct expl_data cr_in);
double get_jac_t5_25 (struct expl_data cr_in);
double get_jac_t5_26 (struct expl_data cr_in);
double get_jac_t5_31 (struct expl_data cr_in);
double get_jac_t5_32 (struct expl_data cr_in);
double get_jac_t5_33 (struct expl_data cr_in);
double get_jac_t5_34 (struct expl_data cr_in);
double get_jac_t5_35 (struct expl_data cr_in);
double get_jac_t5_36 (struct expl_data cr_in);
double get_jac_t5_41 (struct expl_data cr_in);
double get_jac_t5_42 (struct expl_data cr_in);
double get_jac_t5_43 (struct expl_data cr_in);
double get_jac_t5_44 (struct expl_data cr_in);
double get_jac_t5_45 (struct expl_data cr_in);
double get_jac_t5_46 (struct expl_data cr_in);
double get_jac_t5_51 (struct expl_data cr_in);
double get_jac_t5_52 (struct expl_data cr_in);
double get_jac_t5_53 (struct expl_data cr_in);
double get_jac_t5_54 (struct expl_data cr_in);
double get_jac_t5_55 (struct expl_data cr_in);
double get_jac_t5_56 (struct expl_data cr_in);
double get_jac_t5_61 (struct expl_data cr_in);
double get_jac_t5_62 (struct expl_data cr_in);
double get_jac_t5_63 (struct expl_data cr_in);
double get_jac_t5_64 (struct expl_data cr_in);
double get_jac_t5_65 (struct expl_data cr_in);
double get_jac_t5_66 (struct expl_data cr_in);
double get_jac_t6_11 (struct expl_data cr_in);
double get_jac_t6_12 (struct expl_data cr_in);
double get_jac_t6_13 (struct expl_data cr_in);
double get_jac_t6_14 (struct expl_data cr_in);
double get_jac_t6_15 (struct expl_data cr_in);
double get_jac_t6_16 (struct expl_data cr_in);
double get_jac_t6_21 (struct expl_data cr_in);
double get_jac_t6_22 (struct expl_data cr_in);
double get_jac_t6_23 (struct expl_data cr_in);
double get_jac_t6_24 (struct expl_data cr_in);
double get_jac_t6_25 (struct expl_data cr_in);
double get_jac_t6_26 (struct expl_data cr_in);
double get_jac_t6_31 (struct expl_data cr_in);
double get_jac_t6_32 (struct expl_data cr_in);
double get_jac_t6_33 (struct expl_data cr_in);
double get_jac_t6_34 (struct expl_data cr_in);
double get_jac_t6_35 (struct expl_data cr_in);
double get_jac_t6_36 (struct expl_data cr_in);
double get_jac_t6_41 (struct expl_data cr_in);
double get_jac_t6_42 (struct expl_data cr_in);
double get_jac_t6_43 (struct expl_data cr_in);
double get_jac_t6_44 (struct expl_data cr_in);
double get_jac_t6_45 (struct expl_data cr_in);
double get_jac_t6_46 (struct expl_data cr_in);
double get_jac_t6_51 (struct expl_data cr_in);
double get_jac_t6_52 (struct expl_data cr_in);
double get_jac_t6_53 (struct expl_data cr_in);
double get_jac_t6_54 (struct expl_data cr_in);
double get_jac_t6_55 (struct expl_data cr_in);
double get_jac_t6_56 (struct expl_data cr_in);
double get_jac_t6_61 (struct expl_data cr_in);
double get_jac_t6_62 (struct expl_data cr_in);
double get_jac_t6_63 (struct expl_data cr_in);
double get_jac_t6_64 (struct expl_data cr_in);
double get_jac_t6_65 (struct expl_data cr_in);
double get_jac_t6_66 (struct expl_data cr_in);
double get_jac_t7_11 (struct expl_data cr_in);
double get_jac_t7_12 (struct expl_data cr_in);
double get_jac_t7_13 (struct expl_data cr_in);
double get_jac_t7_14 (struct expl_data cr_in);
double get_jac_t7_15 (struct expl_data cr_in);
double get_jac_t7_16 (struct expl_data cr_in);
double get_jac_t7_21 (struct expl_data cr_in);
double get_jac_t7_22 (struct expl_data cr_in);
double get_jac_t7_23 (struct expl_data cr_in);
double get_jac_t7_24 (struct expl_data cr_in);
double get_jac_t7_25 (struct expl_data cr_in);
double get_jac_t7_26 (struct expl_data cr_in);
double get_jac_t7_31 (struct expl_data cr_in);
double get_jac_t7_32 (struct expl_data cr_in);
double get_jac_t7_33 (struct expl_data cr_in);
double get_jac_t7_34 (struct expl_data cr_in);
double get_jac_t7_35 (struct expl_data cr_in);
double get_jac_t7_36 (struct expl_data cr_in);
double get_jac_t7_41 (struct expl_data cr_in);
double get_jac_t7_42 (struct expl_data cr_in);
double get_jac_t7_43 (struct expl_data cr_in);
double get_jac_t7_44 (struct expl_data cr_in);
double get_jac_t7_45 (struct expl_data cr_in);
double get_jac_t7_46 (struct expl_data cr_in);
double get_jac_t7_51 (struct expl_data cr_in);
double get_jac_t7_52 (struct expl_data cr_in);
double get_jac_t7_53 (struct expl_data cr_in);
double get_jac_t7_54 (struct expl_data cr_in);
double get_jac_t7_55 (struct expl_data cr_in);
double get_jac_t7_56 (struct expl_data cr_in);
double get_jac_t7_61 (struct expl_data cr_in);
double get_jac_t7_62 (struct expl_data cr_in);
double get_jac_t7_63 (struct expl_data cr_in);
double get_jac_t7_64 (struct expl_data cr_in);
double get_jac_t7_65 (struct expl_data cr_in);
double get_jac_t7_66 (struct expl_data cr_in);
#endif //__conc_rot_precomputed
