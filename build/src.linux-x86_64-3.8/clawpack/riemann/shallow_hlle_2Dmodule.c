/* File: shallow_hlle_2Dmodule.c
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
static PyObject *shallow_hlle_2D_error;
static PyObject *shallow_hlle_2D_module;

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
        PyErr_SetString(shallow_hlle_2D_error,errstring);\
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
        if (err==NULL) err = shallow_hlle_2D_error;
        PyErr_SetString(err,errmess);
    }
    return 0;
}

static int double_from_pyobj(double* v,PyObject *obj,const char *errmess) {
    PyObject* tmp = NULL;
    if (PyFloat_Check(obj)) {
#ifdef __sgi
        *v = PyFloat_AsDouble(obj);
#else
        *v = PyFloat_AS_DOUBLE(obj);
#endif
        return 1;
    }
    tmp = PyNumber_Float(obj);
    if (tmp) {
#ifdef __sgi
        *v = PyFloat_AsDouble(tmp);
#else
        *v = PyFloat_AS_DOUBLE(tmp);
#endif
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
        if (double_from_pyobj(v,tmp,errmess)) {Py_DECREF(tmp); return 1;}
        Py_DECREF(tmp);
    }
    {
        PyObject* err = PyErr_Occurred();
        if (err==NULL) err = shallow_hlle_2D_error;
        PyErr_SetString(err,errmess);
    }
    return 0;
}


/********************* See f2py2e/cfuncs.py: userincludes *********************/
/*need_userincludes*/

/********************* See f2py2e/capi_rules.py: usercode *********************/


/* See f2py2e/rules.py */
extern void F_FUNC(rpn2,RPN2)(int*,int*,int*,int*,int*,int*,int*,double*,double*,double*,double*,double*,double*,double*,double*);
extern void F_FUNC(rpt2,RPT2)(int*,int*,int*,int*,int*,int*,int*,int*,double*,double*,double*,double*,double*,double*,double*,double*);
/*eof externroutines*/

/******************** See f2py2e/capi_rules.py: usercode1 ********************/


/******************* See f2py2e/cb_rules.py: buildcallback *******************/
/*need_callbacks*/

/*********************** See f2py2e/rules.py: buildapi ***********************/

/************************************ rpn2 ************************************/
static char doc_f2py_rout_shallow_hlle_2D_rpn2[] = "\
wave,s,amdq,apdq = rpn2(ixy,maxm,mwaves,mbc,mx,ql,qr,auxl,auxr,[meqn,maux])\n\nWrapper for ``rpn2``.\
\n\nParameters\n----------\n"
"ixy : input int\n"
"maxm : input int\n"
"mwaves : input int\n"
"mbc : input int\n"
"mx : input int\n"
"ql : input rank-2 array('d') with bounds (meqn,maxm+mbc-(1-mbc)+1)\n"
"qr : input rank-2 array('d') with bounds (meqn,maxm+mbc-(1-mbc)+1)\n"
"auxl : input rank-2 array('d') with bounds (maux,maxm+mbc-(1-mbc)+1)\n"
"auxr : input rank-2 array('d') with bounds (maux,maxm+mbc-(1-mbc)+1)\n"
"\nOther Parameters\n----------------\n"
"meqn : input int, optional\n    Default: shape(ql,0)\n"
"maux : input int, optional\n    Default: shape(auxl,0)\n"
"\nReturns\n-------\n"
"wave : rank-3 array('d') with bounds (meqn,mwaves,maxm+mbc-(1-mbc)+1)\n"
"s : rank-2 array('d') with bounds (mwaves,maxm+mbc-(1-mbc)+1)\n"
"amdq : rank-2 array('d') with bounds (meqn,maxm+mbc-(1-mbc)+1)\n"
"apdq : rank-2 array('d') with bounds (meqn,maxm+mbc-(1-mbc)+1)";
/* extern void F_FUNC(rpn2,RPN2)(int*,int*,int*,int*,int*,int*,int*,double*,double*,double*,double*,double*,double*,double*,double*); */
static PyObject *f2py_rout_shallow_hlle_2D_rpn2(const PyObject *capi_self,
                           PyObject *capi_args,
                           PyObject *capi_keywds,
                           void (*f2py_func)(int*,int*,int*,int*,int*,int*,int*,double*,double*,double*,double*,double*,double*,double*,double*)) {
  PyObject * volatile capi_buildvalue = NULL;
  volatile int f2py_success = 1;
/*decl*/

  int ixy = 0;
  PyObject *ixy_capi = Py_None;
  int maxm = 0;
  PyObject *maxm_capi = Py_None;
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
  static char *capi_kwlist[] = {"ixy","maxm","mwaves","mbc","mx","ql","qr","auxl","auxr","meqn","maux",NULL};

/*routdebugenter*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_clock();
#endif
  if (!PyArg_ParseTupleAndKeywords(capi_args,capi_keywds,\
    "OOOOOOOOO|OO:shallow_hlle_2D.rpn2",\
    capi_kwlist,&ixy_capi,&maxm_capi,&mwaves_capi,&mbc_capi,&mx_capi,&ql_capi,&qr_capi,&auxl_capi,&auxr_capi,&meqn_capi,&maux_capi))
    return NULL;
/*frompyobj*/
  /* Processing variable ixy */
    f2py_success = int_from_pyobj(&ixy,ixy_capi,"shallow_hlle_2D.rpn2() 1st argument (ixy) can't be converted to int");
  if (f2py_success) {
  /* Processing variable maxm */
    f2py_success = int_from_pyobj(&maxm,maxm_capi,"shallow_hlle_2D.rpn2() 2nd argument (maxm) can't be converted to int");
  if (f2py_success) {
  /* Processing variable mwaves */
    f2py_success = int_from_pyobj(&mwaves,mwaves_capi,"shallow_hlle_2D.rpn2() 3rd argument (mwaves) can't be converted to int");
  if (f2py_success) {
  /* Processing variable mbc */
    f2py_success = int_from_pyobj(&mbc,mbc_capi,"shallow_hlle_2D.rpn2() 4th argument (mbc) can't be converted to int");
  if (f2py_success) {
  /* Processing variable mx */
    f2py_success = int_from_pyobj(&mx,mx_capi,"shallow_hlle_2D.rpn2() 5th argument (mx) can't be converted to int");
  if (f2py_success) {
  /* Processing variable ql */
  ql_Dims[1]=maxm+mbc-(1-mbc)+1;
  capi_ql_intent |= F2PY_INTENT_IN;
  capi_ql_tmp = array_from_pyobj(NPY_DOUBLE,ql_Dims,ql_Rank,capi_ql_intent,ql_capi);
  if (capi_ql_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(shallow_hlle_2D_error,"failed in converting 6th argument `ql' of shallow_hlle_2D.rpn2 to C/Fortran array" );
  } else {
    ql = (double *)(PyArray_DATA(capi_ql_tmp));

  /* Processing variable auxl */
  auxl_Dims[1]=maxm+mbc-(1-mbc)+1;
  capi_auxl_intent |= F2PY_INTENT_IN;
  capi_auxl_tmp = array_from_pyobj(NPY_DOUBLE,auxl_Dims,auxl_Rank,capi_auxl_intent,auxl_capi);
  if (capi_auxl_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(shallow_hlle_2D_error,"failed in converting 8th argument `auxl' of shallow_hlle_2D.rpn2 to C/Fortran array" );
  } else {
    auxl = (double *)(PyArray_DATA(capi_auxl_tmp));

  /* Processing variable s */
  s_Dims[0]=mwaves,s_Dims[1]=maxm+mbc-(1-mbc)+1;
  capi_s_intent |= F2PY_INTENT_OUT|F2PY_INTENT_HIDE;
  capi_s_tmp = array_from_pyobj(NPY_DOUBLE,s_Dims,s_Rank,capi_s_intent,Py_None);
  if (capi_s_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(shallow_hlle_2D_error,"failed in converting hidden `s' of shallow_hlle_2D.rpn2 to C/Fortran array" );
  } else {
    s = (double *)(PyArray_DATA(capi_s_tmp));

  /* Processing variable meqn */
  if (meqn_capi == Py_None) meqn = shape(ql,0); else
    f2py_success = int_from_pyobj(&meqn,meqn_capi,"shallow_hlle_2D.rpn2() 1st keyword (meqn) can't be converted to int");
  if (f2py_success) {
  CHECKSCALAR(shape(ql,0)==meqn,"shape(ql,0)==meqn","1st keyword meqn","rpn2:meqn=%d",meqn) {
  /* Processing variable maux */
  if (maux_capi == Py_None) maux = shape(auxl,0); else
    f2py_success = int_from_pyobj(&maux,maux_capi,"shallow_hlle_2D.rpn2() 2nd keyword (maux) can't be converted to int");
  if (f2py_success) {
  CHECKSCALAR(shape(auxl,0)==maux,"shape(auxl,0)==maux","2nd keyword maux","rpn2:maux=%d",maux) {
  /* Processing variable qr */
  qr_Dims[0]=meqn,qr_Dims[1]=maxm+mbc-(1-mbc)+1;
  capi_qr_intent |= F2PY_INTENT_IN;
  capi_qr_tmp = array_from_pyobj(NPY_DOUBLE,qr_Dims,qr_Rank,capi_qr_intent,qr_capi);
  if (capi_qr_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(shallow_hlle_2D_error,"failed in converting 7th argument `qr' of shallow_hlle_2D.rpn2 to C/Fortran array" );
  } else {
    qr = (double *)(PyArray_DATA(capi_qr_tmp));

  /* Processing variable auxr */
  auxr_Dims[0]=maux,auxr_Dims[1]=maxm+mbc-(1-mbc)+1;
  capi_auxr_intent |= F2PY_INTENT_IN;
  capi_auxr_tmp = array_from_pyobj(NPY_DOUBLE,auxr_Dims,auxr_Rank,capi_auxr_intent,auxr_capi);
  if (capi_auxr_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(shallow_hlle_2D_error,"failed in converting 9th argument `auxr' of shallow_hlle_2D.rpn2 to C/Fortran array" );
  } else {
    auxr = (double *)(PyArray_DATA(capi_auxr_tmp));

  /* Processing variable wave */
  wave_Dims[0]=meqn,wave_Dims[1]=mwaves,wave_Dims[2]=maxm+mbc-(1-mbc)+1;
  capi_wave_intent |= F2PY_INTENT_OUT|F2PY_INTENT_HIDE;
  capi_wave_tmp = array_from_pyobj(NPY_DOUBLE,wave_Dims,wave_Rank,capi_wave_intent,Py_None);
  if (capi_wave_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(shallow_hlle_2D_error,"failed in converting hidden `wave' of shallow_hlle_2D.rpn2 to C/Fortran array" );
  } else {
    wave = (double *)(PyArray_DATA(capi_wave_tmp));

  /* Processing variable amdq */
  amdq_Dims[0]=meqn,amdq_Dims[1]=maxm+mbc-(1-mbc)+1;
  capi_amdq_intent |= F2PY_INTENT_OUT|F2PY_INTENT_HIDE;
  capi_amdq_tmp = array_from_pyobj(NPY_DOUBLE,amdq_Dims,amdq_Rank,capi_amdq_intent,Py_None);
  if (capi_amdq_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(shallow_hlle_2D_error,"failed in converting hidden `amdq' of shallow_hlle_2D.rpn2 to C/Fortran array" );
  } else {
    amdq = (double *)(PyArray_DATA(capi_amdq_tmp));

  /* Processing variable apdq */
  apdq_Dims[0]=meqn,apdq_Dims[1]=maxm+mbc-(1-mbc)+1;
  capi_apdq_intent |= F2PY_INTENT_OUT|F2PY_INTENT_HIDE;
  capi_apdq_tmp = array_from_pyobj(NPY_DOUBLE,apdq_Dims,apdq_Rank,capi_apdq_intent,Py_None);
  if (capi_apdq_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(shallow_hlle_2D_error,"failed in converting hidden `apdq' of shallow_hlle_2D.rpn2 to C/Fortran array" );
  } else {
    apdq = (double *)(PyArray_DATA(capi_apdq_tmp));

/*end of frompyobj*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_call_clock();
#endif
/*callfortranroutine*/
        (*f2py_func)(&ixy,&maxm,&meqn,&mwaves,&maux,&mbc,&mx,ql,qr,auxl,auxr,wave,s,amdq,apdq);
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
  } /*if (f2py_success) of maxm*/
  /* End of cleaning variable maxm */
  } /*if (f2py_success) of ixy*/
  /* End of cleaning variable ixy */
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
/******************************** end of rpn2 ********************************/

/************************************ rpt2 ************************************/
static char doc_f2py_rout_shallow_hlle_2D_rpt2[] = "\
rpt2(ixy,imp,maxm,meqn,mwaves,maux,mbc,mx,ql,qr,aux1,aux2,aux3,asdq,bmasdq,bpasdq)\n\nWrapper for ``rpt2``.\
\n\nParameters\n----------\n"
"ixy : input int\n"
"imp : input int\n"
"maxm : input int\n"
"meqn : input int\n"
"mwaves : input int\n"
"maux : input int\n"
"mbc : input int\n"
"mx : input int\n"
"ql : input float\n"
"qr : input float\n"
"aux1 : input float\n"
"aux2 : input float\n"
"aux3 : input float\n"
"asdq : input float\n"
"bmasdq : input float\n"
"bpasdq : input float";
/* extern void F_FUNC(rpt2,RPT2)(int*,int*,int*,int*,int*,int*,int*,int*,double*,double*,double*,double*,double*,double*,double*,double*); */
static PyObject *f2py_rout_shallow_hlle_2D_rpt2(const PyObject *capi_self,
                           PyObject *capi_args,
                           PyObject *capi_keywds,
                           void (*f2py_func)(int*,int*,int*,int*,int*,int*,int*,int*,double*,double*,double*,double*,double*,double*,double*,double*)) {
  PyObject * volatile capi_buildvalue = NULL;
  volatile int f2py_success = 1;
/*decl*/

  int ixy = 0;
  PyObject *ixy_capi = Py_None;
  int imp = 0;
  PyObject *imp_capi = Py_None;
  int maxm = 0;
  PyObject *maxm_capi = Py_None;
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
  double ql = 0;
  PyObject *ql_capi = Py_None;
  double qr = 0;
  PyObject *qr_capi = Py_None;
  double aux1 = 0;
  PyObject *aux1_capi = Py_None;
  double aux2 = 0;
  PyObject *aux2_capi = Py_None;
  double aux3 = 0;
  PyObject *aux3_capi = Py_None;
  double asdq = 0;
  PyObject *asdq_capi = Py_None;
  double bmasdq = 0;
  PyObject *bmasdq_capi = Py_None;
  double bpasdq = 0;
  PyObject *bpasdq_capi = Py_None;
  static char *capi_kwlist[] = {"ixy","imp","maxm","meqn","mwaves","maux","mbc","mx","ql","qr","aux1","aux2","aux3","asdq","bmasdq","bpasdq",NULL};

/*routdebugenter*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_clock();
#endif
  if (!PyArg_ParseTupleAndKeywords(capi_args,capi_keywds,\
    "OOOOOOOOOOOOOOOO:shallow_hlle_2D.rpt2",\
    capi_kwlist,&ixy_capi,&imp_capi,&maxm_capi,&meqn_capi,&mwaves_capi,&maux_capi,&mbc_capi,&mx_capi,&ql_capi,&qr_capi,&aux1_capi,&aux2_capi,&aux3_capi,&asdq_capi,&bmasdq_capi,&bpasdq_capi))
    return NULL;
/*frompyobj*/
  /* Processing variable ixy */
    f2py_success = int_from_pyobj(&ixy,ixy_capi,"shallow_hlle_2D.rpt2() 1st argument (ixy) can't be converted to int");
  if (f2py_success) {
  /* Processing variable imp */
    f2py_success = int_from_pyobj(&imp,imp_capi,"shallow_hlle_2D.rpt2() 2nd argument (imp) can't be converted to int");
  if (f2py_success) {
  /* Processing variable maxm */
    f2py_success = int_from_pyobj(&maxm,maxm_capi,"shallow_hlle_2D.rpt2() 3rd argument (maxm) can't be converted to int");
  if (f2py_success) {
  /* Processing variable meqn */
    f2py_success = int_from_pyobj(&meqn,meqn_capi,"shallow_hlle_2D.rpt2() 4th argument (meqn) can't be converted to int");
  if (f2py_success) {
  /* Processing variable mwaves */
    f2py_success = int_from_pyobj(&mwaves,mwaves_capi,"shallow_hlle_2D.rpt2() 5th argument (mwaves) can't be converted to int");
  if (f2py_success) {
  /* Processing variable maux */
    f2py_success = int_from_pyobj(&maux,maux_capi,"shallow_hlle_2D.rpt2() 6th argument (maux) can't be converted to int");
  if (f2py_success) {
  /* Processing variable mbc */
    f2py_success = int_from_pyobj(&mbc,mbc_capi,"shallow_hlle_2D.rpt2() 7th argument (mbc) can't be converted to int");
  if (f2py_success) {
  /* Processing variable mx */
    f2py_success = int_from_pyobj(&mx,mx_capi,"shallow_hlle_2D.rpt2() 8th argument (mx) can't be converted to int");
  if (f2py_success) {
  /* Processing variable ql */
    f2py_success = double_from_pyobj(&ql,ql_capi,"shallow_hlle_2D.rpt2() 9th argument (ql) can't be converted to double");
  if (f2py_success) {
  /* Processing variable qr */
    f2py_success = double_from_pyobj(&qr,qr_capi,"shallow_hlle_2D.rpt2() 10th argument (qr) can't be converted to double");
  if (f2py_success) {
  /* Processing variable aux1 */
    f2py_success = double_from_pyobj(&aux1,aux1_capi,"shallow_hlle_2D.rpt2() 11st argument (aux1) can't be converted to double");
  if (f2py_success) {
  /* Processing variable aux2 */
    f2py_success = double_from_pyobj(&aux2,aux2_capi,"shallow_hlle_2D.rpt2() 12nd argument (aux2) can't be converted to double");
  if (f2py_success) {
  /* Processing variable aux3 */
    f2py_success = double_from_pyobj(&aux3,aux3_capi,"shallow_hlle_2D.rpt2() 13rd argument (aux3) can't be converted to double");
  if (f2py_success) {
  /* Processing variable asdq */
    f2py_success = double_from_pyobj(&asdq,asdq_capi,"shallow_hlle_2D.rpt2() 14th argument (asdq) can't be converted to double");
  if (f2py_success) {
  /* Processing variable bmasdq */
    f2py_success = double_from_pyobj(&bmasdq,bmasdq_capi,"shallow_hlle_2D.rpt2() 15th argument (bmasdq) can't be converted to double");
  if (f2py_success) {
  /* Processing variable bpasdq */
    f2py_success = double_from_pyobj(&bpasdq,bpasdq_capi,"shallow_hlle_2D.rpt2() 16th argument (bpasdq) can't be converted to double");
  if (f2py_success) {
/*end of frompyobj*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_call_clock();
#endif
/*callfortranroutine*/
        (*f2py_func)(&ixy,&imp,&maxm,&meqn,&mwaves,&maux,&mbc,&mx,&ql,&qr,&aux1,&aux2,&aux3,&asdq,&bmasdq,&bpasdq);
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
    capi_buildvalue = Py_BuildValue("");
/*closepyobjfrom*/
/*end of closepyobjfrom*/
    } /*if (f2py_success) after callfortranroutine*/
/*cleanupfrompyobj*/
  } /*if (f2py_success) of bpasdq*/
  /* End of cleaning variable bpasdq */
  } /*if (f2py_success) of bmasdq*/
  /* End of cleaning variable bmasdq */
  } /*if (f2py_success) of asdq*/
  /* End of cleaning variable asdq */
  } /*if (f2py_success) of aux3*/
  /* End of cleaning variable aux3 */
  } /*if (f2py_success) of aux2*/
  /* End of cleaning variable aux2 */
  } /*if (f2py_success) of aux1*/
  /* End of cleaning variable aux1 */
  } /*if (f2py_success) of qr*/
  /* End of cleaning variable qr */
  } /*if (f2py_success) of ql*/
  /* End of cleaning variable ql */
  } /*if (f2py_success) of mx*/
  /* End of cleaning variable mx */
  } /*if (f2py_success) of mbc*/
  /* End of cleaning variable mbc */
  } /*if (f2py_success) of maux*/
  /* End of cleaning variable maux */
  } /*if (f2py_success) of mwaves*/
  /* End of cleaning variable mwaves */
  } /*if (f2py_success) of meqn*/
  /* End of cleaning variable meqn */
  } /*if (f2py_success) of maxm*/
  /* End of cleaning variable maxm */
  } /*if (f2py_success) of imp*/
  /* End of cleaning variable imp */
  } /*if (f2py_success) of ixy*/
  /* End of cleaning variable ixy */
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
/******************************** end of rpt2 ********************************/
/*eof body*/

/******************* See f2py2e/f90mod_rules.py: buildhooks *******************/
/*need_f90modhooks*/

/************** See f2py2e/rules.py: module_rules['modulebody'] **************/

/******************* See f2py2e/common_rules.py: buildhooks *******************/

static FortranDataDef f2py_cparam_def[] = {
  {"grav",0,{{-1}},NPY_DOUBLE},
  {NULL}
};
static void f2py_setup_cparam(char *grav) {
  int i_f2py=0;
  f2py_cparam_def[i_f2py++].data = grav;
}
extern void F_FUNC(f2pyinitcparam,F2PYINITCPARAM)(void(*)(char*));
static void f2py_init_cparam(void) {
  F_FUNC(f2pyinitcparam,F2PYINITCPARAM)(f2py_setup_cparam);
}

/*need_commonhooks*/

/**************************** See f2py2e/rules.py ****************************/

static FortranDataDef f2py_routine_defs[] = {
  {"rpn2",-1,{{-1}},0,(char *)F_FUNC(rpn2,RPN2),(f2py_init_func)f2py_rout_shallow_hlle_2D_rpn2,doc_f2py_rout_shallow_hlle_2D_rpn2},
  {"rpt2",-1,{{-1}},0,(char *)F_FUNC(rpt2,RPT2),(f2py_init_func)f2py_rout_shallow_hlle_2D_rpt2,doc_f2py_rout_shallow_hlle_2D_rpt2},

/*eof routine_defs*/
  {NULL}
};

static PyMethodDef f2py_module_methods[] = {

  {NULL,NULL}
};

#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef moduledef = {
  PyModuleDef_HEAD_INIT,
  "shallow_hlle_2D",
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
PyMODINIT_FUNC PyInit_shallow_hlle_2D(void) {
#else
#define RETVAL
PyMODINIT_FUNC initshallow_hlle_2D(void) {
#endif
  int i;
  PyObject *m,*d, *s, *tmp;
#if PY_VERSION_HEX >= 0x03000000
  m = shallow_hlle_2D_module = PyModule_Create(&moduledef);
#else
  m = shallow_hlle_2D_module = Py_InitModule("shallow_hlle_2D", f2py_module_methods);
#endif
  Py_TYPE(&PyFortran_Type) = &PyType_Type;
  import_array();
  if (PyErr_Occurred())
    {PyErr_SetString(PyExc_ImportError, "can't initialize module shallow_hlle_2D (failed to import numpy)"); return RETVAL;}
  d = PyModule_GetDict(m);
  s = PyString_FromString("$Revision: $");
  PyDict_SetItemString(d, "__version__", s);
  Py_DECREF(s);
#if PY_VERSION_HEX >= 0x03000000
  s = PyUnicode_FromString(
#else
  s = PyString_FromString(
#endif
    "This module 'shallow_hlle_2D' is auto-generated with f2py (version:2).\nFunctions:\n"
"  wave,s,amdq,apdq = rpn2(ixy,maxm,mwaves,mbc,mx,ql,qr,auxl,auxr,meqn=shape(ql,0),maux=shape(auxl,0))\n"
"  rpt2(ixy,imp,maxm,meqn,mwaves,maux,mbc,mx,ql,qr,aux1,aux2,aux3,asdq,bmasdq,bpasdq)\n"
"COMMON blocks:\n""  /cparam/ grav\n"".");
  PyDict_SetItemString(d, "__doc__", s);
  Py_DECREF(s);
  shallow_hlle_2D_error = PyErr_NewException ("shallow_hlle_2D.error", NULL, NULL);
  /*
   * Store the error object inside the dict, so that it could get deallocated.
   * (in practice, this is a module, so it likely will not and cannot.)
   */
  PyDict_SetItemString(d, "_shallow_hlle_2D_error", shallow_hlle_2D_error);
  Py_DECREF(shallow_hlle_2D_error);
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
    on_exit(f2py_report_on_exit,(void*)"shallow_hlle_2D");
#endif
  return RETVAL;
}
#ifdef __cplusplus
}
#endif
