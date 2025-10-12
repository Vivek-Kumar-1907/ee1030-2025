import numpy as np
import matplotlib.pyplot as plt
import ctypes
import os
import sys
import subprocess
import math

lib_path = os.path.join(os.path.dirname(__file__), 'main.so')
my_lib = ctypes.CDLL(lib_path)

my_lib.find_sol.argtypes = []
my_lib.find_sol.restype = None

my_lib.find_sol()
