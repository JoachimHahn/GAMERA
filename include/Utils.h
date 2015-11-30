#ifndef _UTILS_
#define _UTILS_

#include <math.h>
#include <cmath>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <gsl/gsl_sf_bessel.h>
#include <gsl/gsl_integration.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_spline.h>

/* TeV->erg */
#define TeV_to_erg 1.602
/* GeV->erg */
#define GeV_to_erg 1.602e-3
/* eV->erg */
#define eV_to_erg 1.602e-12
/* Thomson cross section */
#define sigma_T 6.6524e-25
/* classical electron radius (cm) */
#define e_radius 2.8179e-13
/* parsec to cm */
#define pc_to_cm 3.0857e18
/* kiloparsec to cm */
#define kpc_to_cm 3.0857e21
/* proton mass in g */
#define m_p_g 1.6726e-24
/* well... pi! */
#define pi 3.1416
/* year in seconds */
#define yr_to_sec 3.15576e7
/* solar mass */
#define mSol 1.9891e33
/* Thomson cross section */
#define sigma_T 6.6524e-25
/* electron mass in erg */
#define m_e 8.187e-7
/* boltzmann constant (erg/K) */
#define kb 1.380658e-16
/* proton mass in erg */
#define m_p 1.50310854e-3
/* pi0 mass in erg */
#define m_pi 2.1622194e-4
/* parsec to cm */
#define pc_to_cm 3.0857e18
/* well... pi! */
#define pi 3.1416
/* year in seconds */
#define yr_to_sec 3.15576e7
/* solar mass */
#define mSol 1.9891e33
/* speed of light cm/s */
#define c_speed 29979245800.
/* elementary charge */
#define el_charge 4.80320427e-10
/* classical electron radius (cm) */
#define eRadius 2.8179e-13
/* planck's constant */
#define hp 6.62606896e-27
/* fine structure constant */
#define fineStructConst 7.2974e-3
/* hour in seconds */
#define h_to_sec 3.6e3
/* pc to lyr */
#define pc_to_lyr 3.26156

using namespace std;

/**
 * @file Utils.C
 * @author Joachim Hahn
 * @short Class that provides utility functions
 * Provides different things, mainly useful for population studies.
 * This includes spiral galaxy models as well as gas distributions,
 * B-Field distributions, coordinate transformations etc.
 * Also includes more technical functions that are helpful in writing
 * GAMERA programs.
 */

bool sortcriterionfirstcolumn (vector<double> i,vector<double> j);
bool sortcriterionsecondcolumn (vector<double> i,vector<double> j);

class Utils {
 private:
  bool QUIETMODE;
  bool GAMERADESTROYEDTHECONSOLE;
  gsl_rng * r;

 public:
  Utils(bool DRAWLOGO = true);
  ~Utils();
  void ToggleQuietMode() { QUIETMODE = true; }
  int ReadParameterFile(string inputname, vector<string> parameter_names,
                        vector<string> files_names,
                        vector<double> &parameter_values,
                        vector<string> &files);
  void DrawGamera();
  void DrawGappa();
  void WriteOut(vector<vector<double> > sp, string outname);
  void ReadIn(string inname, vector< vector<double> > &sp);
  double Random();
  vector<double>  LinearRandom(double slope, double x_min, double x_max, int n);
  vector<double>  PowerLawRandom(double index, double x_min, double x_max,
                                 int n);
  vector<double>  GaussianRandom(double width, double offset, int n);
  vector<double>  SignRandom(int n);
  vector<double>  ExponentialRandom(double ind_norm, double x_min,
                                    double x_max, int n);
  vector<double>  CustomFunctionRandom(vector< vector<double> > f,
                                       double xmin, double xmax, int n);
  double Integrate(vector< vector<double> > f, double xmin, double xmax);
  vector< vector< double> > IntegratedProfile(vector< vector<double> > f);
  gsl_spline *GSLsplineFromTwoDVector(vector< vector<double> > v);
  vector< vector<double> > SortTwoDVector(vector< vector<double> > v,
                                                 int column);
  void TwoDVectorPushBack(double x, double y, vector< vector<double> > &v);

  double EvalSpline(double x, gsl_spline *s, gsl_interp_accel *a,
                    const char* t, int l);
  void Clear2DVector(vector< vector<double> > &v);



};
#endif
