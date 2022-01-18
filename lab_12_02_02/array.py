import ctypes
import os


lib_array = ctypes.cdll.LoadLibrary(os.path.abspath('array.dll'))

_a_fill_fibonacci = lib_array.a_fill_fibonacci
_a_fill_fibonacci.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_size_t)
_a_fill_fibonacci.restype = ctypes.c_int

def fill_fibonacci(size):
    array = (ctypes.c_int * size)()
    _a_fill_fibonacci(array, size)

    return list(array)


_a_rm_repetitions = lib_array.a_rm_repetitions
_a_rm_repetitions.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_size_t,
    ctypes.POINTER(ctypes.c_int), ctypes.POINTER(ctypes.c_size_t))
_a_rm_repetitions.restype = ctypes.c_int

def rm_repetitions(list_src):
    len_src = len(list_src)
    array_src = (ctypes.c_int * len_src)(*list_src)
    len_dst = ctypes.c_size_t(0)
    
    rc = _a_rm_repetitions(array_src, len_src, None, len_dst)

    if rc == -4:
        array_dst = (ctypes.c_int * len_dst.value)()
        rc = _a_rm_repetitions(array_src, len_src, array_dst, len_dst)

        return list(array_dst)

    return list()
