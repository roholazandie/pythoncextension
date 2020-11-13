#include <Python.h>
#include <stdio.h>

static PyObject *method_add(PyObject *self, PyObject *args) {
    int a =0;
    int b =0;
    int c =0;

    /* Parse arguments */
    /*ii means the first one is integer and also the second one*/
    if(!PyArg_ParseTuple(args, "ii", &a, &b)) {
        return NULL;
    }

    // the logic goes here
    c = a + b;

    return PyLong_FromLong(c);
}


static PyObject *method_sub(PyObject *self, PyObject *args) {
    int a =0;
    int b =0;
    int c =0;

    /* Parse arguments */
    /*ii means the first one is integer and also the second one*/
    if(!PyArg_ParseTuple(args, "ii", &a, &b)) {
        return NULL;
    }

    // the logic goes here
    c = a - b;

    return PyLong_FromLong(c);
}


static PyObject *method_fibonacci(PyObject *self, PyObject *args) {
    int n =0;

    /* Parse arguments */
    /*ii means the first one is integer and also the second one*/
    if(!PyArg_ParseTuple(args, "i", &n)) {
        return NULL;
    }

    // the logic goes here
    int t1 = 0, t2 = 1;
    int nextTerm =0;
    for (int i = 1; i <= n; ++i) {
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }

    return PyLong_FromLong(t2);
}


static PyObject *method_heavy(PyObject *self, PyObject *args) {
    int n =0;

    /* Parse arguments */
    /*ii means the first one is integer and also the second one*/
    if(!PyArg_ParseTuple(args, "i", &n)) {
        return NULL;
    }

    // the logic goes here
    int x = 1;
    for (int i = 1; i <= n; i++) {
        x = x*i;
    }

    return PyLong_FromLong(x);
}

static PyMethodDef CalculateMethods[] = {
    {"add", method_add, METH_VARARGS, "Python interface for add in C"},
    {"sub", method_sub, METH_VARARGS, "Python interface for sub in C"},
    {"fibonacci", method_fibonacci, METH_VARARGS, "Python interface for fibo in C"},
    {"heavy", method_heavy, METH_VARARGS, "Python interface for heavy in C"},
    {NULL, NULL, 0, NULL}
};


static struct PyModuleDef calculatemodule = {
    PyModuleDef_HEAD_INIT,
    "calculate",
    "Python interface for the fputs C library function",
    -1,
    CalculateMethods
};

PyMODINIT_FUNC PyInit_calculate(void) {
    return PyModule_Create(&calculatemodule);
};

