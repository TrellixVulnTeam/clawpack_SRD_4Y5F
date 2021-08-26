/* File: euler_hlle_1Dmodule.c
 * This file is auto-generated with f2py (version:2).
 * f2py is a Fortran to Python Interface Generator (FPIG), Second Edition,
 * written by Pearu Peterson <pearu@cens.ioc.ee>.
 * Generation date: Mon Aug 23 14:00:45 2021
 * Do not edit this file directly unless you know what you are doing!!!
 */

#ifdef __cplusplus
extern "C" {
#endif

/*********************** See f2py2e/cfuncs.py: includes ***********************/
#include "Python.h"
#include <stdarg.h>
#include "fortranobject.h"
#include <math.h>

/**************** See f2py2e/rules.py: mod_rules['modulebody'] ****************/
static PyObject *euler_hlle_1D_error;
static PyObject *euler_hlle_1D_module;

/*********************** See f2py2e/cfuncs.py: typedefs ***********************/
/*need_typedefs*/

/****************** See f2py2e/cfuncs.py: typedefs_generated ******************/
/*need_typedefs_generated*/

/********************** See f2py2e/cfuncs.py: cppmacros **********************/
#if defined(PREPEND_FORTRAN)
#if defined(NO_APPEND_FORTRAN)
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) _##F
#else
#define F_FUNC(f,F) _##f
#endif
#else
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) _##F##_
#else
#define F_FUNC(f,F) _##f##_
#endif
#endif
#else
#if defined(NO_APPEND_FORTRAN)
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) F
#else
#define F_FUNC(f,F) f
#endif
#else
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) F##_
#else
#define F_FUNC(f,F) f##_
#endif
#endif
#endif
#if defined(UNDERSCORE_G77)
#define F_FUNC_US(f,F) F_FUNC(f##_,F##_)
#else
#define F_FUNC_US(f,F) F_FUNC(f,F)
#endif

#define rank(var) var ## _Rank
#define shape(var,dim) var ## _Dims[dim]
#define old_rank(var) (PyArray_NDIM((PyArrayObject *)(capi_ ## var ## _tmp)))
#define old_shape(var,dim) PyArray_DIM(((PyArrayObject *)(capi_ ## var ## _tmp)),dim)
#define fshape(var,dim) shape(var,rank(var)-dim-1)
#define len(var) shape(var,0)
#define flen(var) fshape(var,0)
#define old_size(var) PyArray_SIZE((PyArrayObject *)(capi_ ## var ## _tmp))
/* #define index(i) capi_i ## i */
#define slen(var) capi_ ## var ## _len
#define size(var, ...) f2py_size((PyArrayObject *)(capi_ ## var ## _tmp), ## __VA_ARGS__, -1)

#define CHECKSCALAR(check,tcheck,name,show,var)\
    if (!(check)) {\
        char errstring[256];\
        sprintf(errstring, "%s: "show, "("tcheck") failed for "name, var);\
        PyErr_SetString(euler_hlle_1D_error,errstring);\
        /*goto capi_fail;*/\
    } else 
#ifdef DEBUGCFUNCS
#define CFUNCSMESS(mess) fprintf(stderr,"debug-capi:"mess);
#define CFUNCSMESSPY(mess,obj) CFUNCSMESS(mess) \
    PyObject_Print((PyObject *)obj,stderr,Py_PRINT_RAW);\
    fprintf(stderr,"\n");
#else
#define CFUNCSMESS(mess)
#define CFUNCSMESSPY(mess,obj)
#endif

#ifndef max
#define max(a,b) ((a > b) ? (a) : (b))
#endif
#ifndef min
#define min(a,b) ((a < b) ? (a) : (b))
#endif
#ifndef MAX
#define MAX(a,b) ((a > b) ? (a) : (b))
#endif
#ifndef MIN
#define MIN(a,b) ((a < b) ? (a) : (b))
#endif


/************************ See f2py2e/cfuncs.py: cfuncs ************************/
static int f2py_size(PyArrayObject* var, ...)
{
  npy_int sz = 0;
  npy_int dim;
  npy_int rank;
  va_list argp;
  va_start(argp, var);
  dim = va_arg(argp, npy_int);
  if (dim==-1)
    {
      sz = PyArray_SIZE(var);
    }
  else
    {
      rank = PyArray_NDIM(var);
      if (dim>=1 && dim<=rank)
        sz = PyArray_DIM(var, dim-1);
      else
        fprintf(stderr, "f2py_size: 2nd argument value=%d fails to satisfy 1<=value<=%d. Result will be 0.\n", dim, rank);
    }
  va_end(argp);
  return sz;
}

static int int_from_pyobj(int* v,PyObject *obj,const char *errmess) {
    PyObject* tmp = NULL;
    if (PyInt_Check(obj)) {
        *v = (int)PyInt_AS_LONG(obj);
        return 1;
    }
    tmp = PyNumber_Int(obj);
    if (tmp) {
        *v = PyInt_AS_LONG(tmp);
        Py_DECREF(tmp);
        return 1;
    }
    if (PyComplex_Check(obj))
        tmp = PyObject_GetAttrString(obj,"real");
    else if (PyString_Check(obj) || PyUnicode_Check(obj))
        /*pass*/;
    else if (PySequence_Check(obj))
        tmp = PySequence_GetItem(obj,0);
    if (tmp) {
        PyErr_Clear();
        if (int_from_pyobj(v,tmp,errmess)) {Py_DECREF(tmp); return 1;}
        Py_DECREF(tmp);
    }
    {
        PyObject* err = PyErr_Occurred();
        if (err==NULL) err = euler_hlle_1D_error;
        PyErr_SetString(err,errmess);
    }
    return 0;
}


/********************* See f2py2e/cfuncs.py: userincludes *********************/
/*need_userincludes*/

/********************* See f2py2e/capi_rules.py: usercode *********************/


/* See f2py2e/rules.py */
extern void F_FUNC(rp1,RP1)(int*,int*,int*,int*,int*,int*,double*,double*,double*,double*,double*,double*,double*,double*);
/*eof externroutines*/

/******************** See f2py2e/capi_rules.py: usercode1 ********************/


/******************* See f2py2e/cb_rules.py: buildcallback *******************/
/*need_callbacks*/

/*********************** See f2py2e/rules.py: buildapi ***********************/

/************************************ rp1 ************************************/
static char doc_f2py_rout_euler_hlle_1D_rp1[] = "\
wave,s,amdq,apdq = rp1(maxmx,mwaves,mbc,mx,ql,qr,auxl,auxr,[meqn,maux])\n\nWrapper for ``rp1``.\
\n\nParameters\n----------\n"
"maxmx : input int\n"
"mwaves : input int\n"
"mbc : input int\n"
"mx : input int\n"
"ql : input rank-2 array('d') with bounds (meqn,maxmx+mbc-(1-mbc)+1)\n"
"qr : input rank-2 array('d') with bounds (meqn,maxmx+mbc-(1-mbc)+1)\n"
"auxl : input rank-2 array('d') with bounds (maux,maxmx+mbc-(1-mbc)+1)\n"
"auxr : input rank-2 array('d') with bounds (maux,maxmx+mbc-(1-mbc)+1)\n"
"\nOther Parameters\n----------------\n"
"meqn : input int, optional\n    Default: shape(ql,0)\n"
"maux : input int, optional\n    Default: shape(auxl,0)\n"
"\nReturns\n-------\n"
"wave : rank-3 array('d') with bounds (meqn,mwaves,maxmx+mbc-(1-mbc)+1)\n"
"s : rank-2 array('d') with bounds (mwaves,maxmx+mbc-(1-mbc)+1)\n"
"amdq : rank-2 array('d') with bounds (meqn,maxmx+mbc-(1-mbc)+1)\n"
"apdq : rank-2 array('d') with bounds (meqn,maxmx+mbc-(1-mbc)+1)";
/* extern void F_FUNC(rp1,RP1)(int*,int*,int*,int*,int*,int*,double*,double*,double*,double*,double*,double*,double*,double*); */
static PyObject *f2py_rout_euler_hlle_1D_rp1(const PyObject *capi_self,
                           PyObject *capi_args,
                           PyObject *capi_keywds,
                           void (*f2py_func)(int*,int*,int*,int*,int*,int*,double*,double*,double*,double*,double*,double*,double*,double*)) {
  PyObject * volatile capi_buildvalue = NULL;
  volatile int f2py_success = 1;
/*decl*/

  int maxmx = 0;
  PyObject *maxmx_capi = Py_None;
  int meqn = 0;
  PyObject *meqn_capi = Py_None;
  int mwaves = 0;
  PyObject *mwaves_capi = Py_None;
  int maux = 0;
  PyObject *maux_capi = Py_None;
  int mbc = 0;
  PyObject *mbc_capi = Py_None;
  int mx = 0;
  PyObject *mx_capi = Py_None;
  double *ql = NULL;
  npy_intp ql_Dims[2] = {-1, -1};
  const int ql_Rank = 2;
  PyArrayObject *capi_ql_tmp = NULL;
  int capi_ql_intent = 0;
  PyObject *ql_capi = Py_None;
  double *qr = NULL;
  npy_intp qr_Dims[2] = {-1, -1};
  const int qr_Rank = 2;
  PyArrayObject *capi_qr_tmp = NULL;
  int capi_qr_intent = 0;
  PyObject *qr_capi = Py_None;
  double *auxl = NULL;
  npy_intp auxl_Dims[2] = {-1, -1};
  const int auxl_Rank = 2;
  PyArrayObject *capi_auxl_tmp = NULL;
  int capi_auxl_intent = 0;
  PyObject *auxl_capi = Py_None;
  double *auxr = NULL;
  npy_intp auxr_Dims[2] = {-1, -1};
  const int auxr_Rank = 2;
  PyArrayObject *capi_auxr_tmp = NULL;
  int capi_auxr_intent = 0;
  PyObject *auxr_capi = Py_None;
  double *wave = NULL;
  npy_intp wave_Dims[3] = {-1, -1, -1};
  const int wave_Rank = 3;
  PyArrayObject *capi_wave_tmp = NULL;
  int capi_wave_intent = 0;
  double *s = NULL;
  npy_intp s_Dims[2] = {-1, -1};
  const int s_Rank = 2;
  PyArrayObject *capi_s_tmp = NULL;
  int capi_s_intent = 0;
  double *amdq = NULL;
  npy_intp amdq_Dims[2] = {-1, -1};
  const int amdq_Rank = 2;
  PyArrayObject *capi_amdq_tmp = NULL;
  int capi_amdq_intent = 0;
  double *apdq = NULL;
  npy_intp apdq_Dims[2] = {-1, -1};
  const int apdq_Rank = 2;
  PyArrayObject *capi_apdq_tmp = NULL;
  int capi_apdq_intent = 0;
  static char *capi_kwlist[] = {"maxmx","mwaves","mbc","mx","ql","qr","auxl","auxr","meqn","maux",NULL};

/*routdebugenter*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_clock();
#endif
  if (!PyArg_ParseTupleAndKeywords(capi_args,capi_keywds,\
    "OOOOOOOO|OO:euler_hlle_1D.rp1",\
    capi_kwlist,&maxmx_capi,&mwaves_capi,&mbc_capi,&mx_capi,&ql_capi,&qr_capi,&auxl_capi,&auxr_capi,&meqn_capi,&maux_capi))
    return NULL;
/*frompyobj*/
  /* Processing variable maxmx */
    f2py_success = int_from_pyobj(&maxmx,maxmx_capi,"euler_hlle_1D.rp1() 1st argument (maxmx) can't be converted to int");
  if (f2py_success) {
  /* Processing variable mwaves */
    f2py_success = int_from_pyobj(&mwaves,mwaves_capi,"euler_hlle_1D.rp1() 2nd argument (mwaves) can't be converted to int");
  if (f2py_success) {
  /* Processing variable mbc */
    f2py_success = int_from_pyobj(&mbc,mbc_capi,"euler_hlle_1D.rp1() 3rd argument (mbc) can't be converted to int");
  if (f2py_success) {
  /* Processing variable mx */
    f2py_success = int_from_pyobj(&mx,mx_capi,"euler_hlle_1D.rp1() 4th argument (mx) can't be converted to int");
  if (f2py_success) {
  /* Processing variable ql */
  ql_Dims[1]=maxmx+mbc-(1-mbc)+1;
  capi_ql_intent |= F2PY_INTENT_IN;
  capi_ql_tmp = array_from_pyobj(NPY_DOUBLE,ql_Dims,ql_Rank,capi_ql_intent,ql_capi);
  if (capi_ql_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(euler_hlle_1D_error,"failed in converting 5th argument `ql' of euler_hlle_1D.rp1 to C/Fortran array" );
  } else {
    ql = (double *)(PyArray_DATA(capi_ql_tmp));

  /* Processing variable auxl */
  auxl_Dims[1]=maxmx+mbc-(1-mbc)+1;
  capi_auxl_intent |= F2PY_INTENT_IN;
  capi_auxl_tmp = array_from_pyobj(NPY_DOUBLE,auxl_Dims,auxl_Rank,capi_auxl_intent,auxl_capi);
  if (capi_auxl_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(euler_hlle_1D_error,"failed in converting 7th argument `auxl' of euler_hlle_1D.rp1 to C/Fortran array" );
  } else {
    auxl = (double *)(PyArray_DATA(capi_auxl_tmp));

  /* Processing variable s */
  s_Dims[0]=mwaves,s_Dims[1]=maxmx+mbc-(1-mbc)+1;
  capi_s_intent |= F2PY_INTENT_OUT|F2PY_INTENT_HIDE;
  capi_s_tmp = array_from_pyobj(NPY_DOUBLE,s_Dims,s_Rank,capi_s_intent,Py_None);
  if (capi_s_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(euler_hlle_1D_error,"failed in converting hidden `s' of euler_hlle_1D.rp1 to C/Fortran array" );
  } else {
    s = (double *)(PyArray_DATA(capi_s_tmp));

  /* Processing variable meqn */
  if (meqn_capi == Py_None) meqn = shape(ql,0); else
    f2py_success = int_from_pyobj(&meqn,meqn_capi,"euler_hlle_1D.rp1() 1st keyword (meqn) can't be converted to int");
  if (f2py_success) {
  CHECKSCALAR(shape(ql,0)==meqn,"shape(ql,0)==meqn","1st keyword meqn","rp1:meqn=%d",meqn) {
  /* Processing variable maux */
  if (maux_capi == Py_None) maux = shape(auxl,0); else
    f2py_success = int_from_pyobj(&maux,maux_capi,"euler_hlle_1D.rp1() 2nd keyword (maux) can't be converted to int");
  if (f2py_success) {
  CHECKSCALAR(shape(auxl,0)==maux,"shape(auxl,0)==maux","2nd keyword maux","rp1:maux=%d",maux) {
  /* Processing variable qr */
  qr_Dims[0]=meqn,qr_Dims[1]=maxmx+mbc-(1-mbc)+1;
  capi_qr_intent |= F2PY_INTENT_IN;
  capi_qr_tmp = array_from_pyobj(NPY_DOUBLE,qr_Dims,qr_Rank,capi_qr_intent,qr_capi);
  if (capi_qr_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(euler_hlle_1D_error,"failed in converting 6th argument `qr' of euler_hlle_1D.rp1 to C/Fortran array" );
  } else {
    qr = (double *)(PyArray_DATA(capi_qr_tmp));

  /* Processing variable auxr */
  auxr_Dims[0]=maux,auxr_Dims[1]=maxmx+mbc-(1-mbc)+1;
  capi_auxr_intent |= F2PY_INTENT_IN;
  capi_auxr_tmp = array_from_pyobj(NPY_DOUBLE,auxr_Dims,auxr_Rank,capi_auxr_intent,auxr_capi);
  if (capi_auxr_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(euler_hlle_1D_error,"failed in converting 8th argument `auxr' of euler_hlle_1D.rp1 to C/Fortran array" );
  } else {
    auxr = (double *)(PyArray_DATA(capi_auxr_tmp));

  /* Processing variable wave */
  wave_Dims[0]=meqn,wave_Dims[1]=mwaves,wave_Dims[2]=maxmx+mbc-(1-mbc)+1;
  capi_wave_intent |= F2PY_INTENT_OUT|F2PY_INTENT_HIDE;
  capi_wave_tmp = array_from_pyobj(NPY_DOUBLE,wave_Dims,wave_Rank,capi_wave_intent,Py_None);
  if (capi_wave_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(euler_hlle_1D_error,"failed in converting hidden `wave' of euler_hlle_1D.rp1 to C/Fortran array" );
  } else {
    wave = (double *)(PyArray_DATA(capi_wave_tmp));

  /* Processing variable amdq */
  amdq_Dims[0]=meqn,amdq_Dims[1]=maxmx+mbc-(1-mbc)+1;
  capi_amdq_intent |= F2PY_INTENT_OUT|F2PY_INTENT_HIDE;
  capi_amdq_tmp = array_from_pyobj(NPY_DOUBLE,amdq_Dims,amdq_Rank,capi_amdq_intent,Py_None);
  if (capi_amdq_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(euler_hlle_1D_error,"failed in converting hidden `amdq' of euler_hlle_1D.rp1 to C/Fortran array" );
  } else {
    amdq = (double *)(PyArray_DATA(capi_amdq_tmp));

  /* Processing variable apdq */
  apdq_Dims[0]=meqn,apdq_Dims[1]=maxmx+mbc-(1-mbc)+1;
  capi_apdq_intent |= F2PY_INTENT_OUT|F2PY_INTENT_HIDE;
  capi_apdq_tmp = array_from_pyobj(NPY_DOUBLE,apdq_Dims,apdq_Rank,capi_apdq_intent,Py_None);
  if (capi_apdq_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(euler_hlle_1D_error,"failed in converting hidden `apdq' of euler_hlle_1D.rp1 to C/Fortran array" );
  } else {
    apdq = (double *)(PyArray_DATA(capi_apdq_tmp));

/*end of frompyobj*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_call_clock();
#endif
/*callfortranroutine*/
        (*f2py_func)(&maxmx,&meqn,&mwaves,&maux,&mbc,&mx,ql,qr,auxl,auxr,wave,s,amdq,apdq);
if (PyErr_Occurred())
  f2py_success = 0;
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_call_clock();
#endif
/*end of callfortranroutine*/
    if (f2py_success) {
/*pyobjfrom*/
/*end of pyobjfrom*/
    CFUNCSMESS("Building return value.\n");
    capi_buildvalue = Py_BuildValue("NNNN",capi_wave_tmp,capi_s_tmp,capi_amdq_tmp,capi_apdq_tmp);
/*closepyobjfrom*/
/*end of closepyobjfrom*/
    } /*if (f2py_success) after callfortranroutine*/
/*cleanupfrompyobj*/
  }  /*if (capi_apdq_tmp == NULL) ... else of apdq*/
  /* End of cleaning variable apdq */
  }  /*if (capi_amdq_tmp == NULL) ... else of amdq*/
  /* End of cleaning variable amdq */
  }  /*if (capi_wave_tmp == NULL) ... else of wave*/
  /* End of cleaning variable wave */
  if((PyObject *)capi_auxr_tmp!=auxr_capi) {
    Py_XDECREF(capi_auxr_tmp); }
  }  /*if (capi_auxr_tmp == NULL) ... else of auxr*/
  /* End of cleaning variable auxr */
  if((PyObject *)capi_qr_tmp!=qr_capi) {
    Py_XDECREF(capi_qr_tmp); }
  }  /*if (capi_qr_tmp == NULL) ... else of qr*/
  /* End of cleaning variable qr */
  } /*CHECKSCALAR(shape(auxl,0)==maux)*/
  } /*if (f2py_success) of maux*/
  /* End of cleaning variable maux */
  } /*CHECKSCALAR(shape(ql,0)==meqn)*/
  } /*if (f2py_success) of meqn*/
  /* End of cleaning variable meqn */
  }  /*if (capi_s_tmp == NULL) ... else of s*/
  /* End of cleaning variable s */
  if((PyObject *)capi_auxl_tmp!=auxl_capi) {
    Py_XDECREF(capi_auxl_tmp); }
  }  /*if (capi_auxl_tmp == NULL) ... else of auxl*/
  /* End of cleaning variable auxl */
  if((PyObject *)capi_ql_tmp!=ql_capi) {
    Py_XDECREF(capi_ql_tmp); }
  }  /*if (capi_ql_tmp == NULL) ... else of ql*/
  /* End of cleaning variable ql */
  } /*if (f2py_success) of mx*/
  /* End of cleaning variable mx */
  } /*if (f2py_success) of mbc*/
  /* End of cleaning variable mbc */
  } /*if (f2py_success) of mwaves*/
  /* End of cleaning variable mwaves */
  } /*if (f2py_success) of maxmx*/
  /* End of cleaning variable maxmx */
/*end of cleanupfrompyobj*/
  if (capi_buildvalue == NULL) {
/*routdebugfailure*/
  } else {
/*routdebugleave*/
  }
  CFUNCSMESS("Freeing memory.\n");
/*freemem*/
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_clock();
#endif
  return capi_buildvalue;
}
/********************************* end of rp1 *********************************/
/*eof body*/

/******************* See f2py2e/f90mod_rules.py: buildhooks *******************/
/*need_f90modhooks*/

/************** See f2py2e/rules.py: module_rules['modulebody'] **************/

/******************* See f2py2e/common_rules.py: buildhooks *******************/

static FortranDataDef f2py_cparam_def[] = {
  {"gamma",0,{{-1}},NPY_DOUBLE},
  {NULL}
};
static void f2py_setup_cparam(char *gamma) {
  int i_f2py=0;
  f2py_cparam_def[i_f2py++].data = gamma;
}
extern void F_FUNC(f2pyinitcparam,F2PYINITCPARAM)(void(*)(char*));
static void f2py_init_cparam(void) {
  F_FUNC(f2pyinitcparam,F2PYINITCPARAM)(f2py_setup_cparam);
}

/*need_commonhooks*/

/**************************** See f2py2e/rules.py ****************************/

static FortranDataDef f2py_routine_defs[] = {
  {"rp1",-1,{{-1}},0,(char *)F_FUNC(rp1,RP1),(f2py_init_func)f2py_rout_euler_hlle_1D_rp1,doc_f2py_rout_euler_hlle_1D_rp1},

/*eof routine_defs*/
  {NULL}
};

static PyMethodDef f2py_module_methods[] = {

  {NULL,NULL}
};

#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef moduledef = {
  PyModuleDef_HEAD_INIT,
  "euler_hlle_1D",
  NULL,
  -1,
  f2py_module_methods,
  NULL,
  NULL,
  NULL,
  NULL
};
#endif

#if PY_VERSION_HEX >= 0x03000000
#define RETVAL m
PyMODINIT_FUNC PyInit_euler_hlle_1D(void) {
#else
#define RETVAL
PyMODINIT_FUNC initeuler_hlle_1D(void) {
#endif
  int i;
  PyObject *m,*d, *s, *tmp;
#if PY_VERSION_HEX >= 0x03000000
  m = euler_hlle_1D_module = PyModule_Create(&moduledef);
#else
  m = euler_hlle_1D_module = Py_InitModule("euler_hlle_1D", f2py_module_methods);
#endif
  Py_TYPE(&PyFortran_Type) = &PyType_Type;
  import_array();
  if (PyErr_Occurred())
    {PyErr_SetString(PyExc_ImportError, "can't initialize module euler_hlle_1D (failed to import numpy)"); return RETVAL;}
  d = PyModule_GetDict(m);
  s = PyString_FromString("$Revision: $");
  PyDict_SetItemString(d, "__version__", s);
  Py_DECREF(s);
#if PY_VERSION_HEX >= 0x03000000
  s = PyUnicode_FromString(
#else
  s = PyString_FromString(
#endif
    "This module 'euler_hlle_1D' is auto-generated with f2py (version:2).\nFunctions:\n"
"  wave,s,amdq,apdq = rp1(maxmx,mwaves,mbc,mx,ql,qr,auxl,auxr,meqn=shape(ql,0),maux=shape(auxl,0))\n"
"COMMON blocks:\n""  /cparam/ gamma\n"".");
  PyDict_SetItemString(d, "__doc__", s);
  Py_DECREF(s);
  euler_hlle_1D_error = PyErr_NewException ("euler_hlle_1D.error", NULL, NULL);
  /*
   * Store the error object inside the dict, so that it could get deallocated.
   * (in practice, this is a module, so it likely will not and cannot.)
   */
  PyDict_SetItemString(d, "_euler_hlle_1D_error", euler_hlle_1D_error);
  Py_DECREF(euler_hlle_1D_error);
  for(i=0;f2py_routine_defs[i].name!=NULL;i++) {
    tmp = PyFortranObject_NewAsAttr(&f2py_routine_defs[i]);
    PyDict_SetItemString(d, f2py_routine_defs[i].name, tmp);
    Py_DECREF(tmp);
  }

/*eof initf2pywraphooks*/
/*eof initf90modhooks*/

  tmp = PyFortranObject_New(f2py_cparam_def,f2py_init_cparam);
  F2PyDict_SetItemString(d, "cparam", tmp);
  Py_DECREF(tmp);
/*eof initcommonhooks*/


#ifdef F2PY_REPORT_ATEXIT
  if (! PyErr_Occurred())
    on_exit(f2py_report_on_exit,(void*)"euler_hlle_1D");
#endif
  return RETVAL;
}
#ifdef __cplusplus
}
#endif
