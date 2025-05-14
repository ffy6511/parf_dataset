# 数据准备
data = [
    # 01
    {
        "features": {"loc": 62, "num_functions": 4, "nesting_depth": 3, "num_conditional_statements": 9, "num_variables": 9, "function_call_count": 4, "cyclomatic_complexity": 19, "memory_operations": 1},
        "parameters": {"widening_delay": 2, "subdivide_non_linear": 1, "slevel": 16, "plevel": 27, "partition_history": 0, "min_loop_unroll": 0, "ilevel": 19, "equality_through_calls": "none", "auto_loop_unroll": 8, "domains": ["cvalue", "equality", "gauges", "octagon", "symbolic-locations"]}
    },
    # 02
    {
        "features": {"loc": 27, "num_functions": 1, "nesting_depth": 2, "num_conditional_statements": 2, "num_variables": 5, "function_call_count": 0, "cyclomatic_complexity": 5, "memory_operations": 0},
        "parameters": {"widening_delay": 2, "subdivide_non_linear": 11, "slevel": 46, "plevel": 102, "partition_history": 0, "min_loop_unroll": 1, "ilevel": 48, "equality_through_calls": "formals", "auto_loop_unroll": 35, "domains": ["cvalue", "equality", "gauges", "octagon", "symbolic-locations"]}
    },
    # 03
    {
        "features": {"loc": 52, "num_functions": 1, "nesting_depth": 2, "num_conditional_statements": 2, "num_variables": 8, "function_call_count": 14, "cyclomatic_complexity": 5, "memory_operations": 1},
        "parameters": {"widening_delay": 11, "subdivide_non_linear": 8, "slevel": 43, "plevel": 143, "partition_history": 3, "min_loop_unroll": 2, "ilevel": 75, "equality_through_calls": "formals", "auto_loop_unroll": 61, "domains": ["cvalue", "octagon", "symbolic-locations"]}
    },
    # 2048
    {
        "features": {"loc": 512, "num_functions": 21, "nesting_depth": 3, "num_conditional_statements": 52, "num_variables": 92, "function_call_count": 105, "cyclomatic_complexity": 106, "memory_operations": 0},
        "parameters": {"widening_delay": 5, "subdivide_non_linear": 7, "slevel": 27, "plevel": 92, "partition_history": 0, "min_loop_unroll": 0, "ilevel": 43, "equality_through_calls": "none", "auto_loop_unroll": 23, "domains": ["cvalue", "equality", "octagon", "symbolic-locations"]}
    },
    # Analysis for 03-practical_08-nonterm1.c
    {
        "features": {"loc": 30, "num_functions": 2, "nesting_depth": 1, "num_conditional_statements": 0, "num_variables": 2, "function_call_count": 13, "cyclomatic_complexity": 2, "memory_operations": 0},
        "parameters": {"widening_delay": 4, "subdivide_non_linear": 1, "slevel": 20, "plevel": 20, "partition_history": 1, "min_loop_unroll": 0, "ilevel": 16, "equality_through_calls": "none", "auto_loop_unroll": 11, "domains": ["cvalue", "gauges", "octagon", "symbolic-locations"]}
    },
    # Analysis for byte_add_1-1.c
    {
        "features": {"loc": 95, "num_functions": 4, "nesting_depth": 1, "num_conditional_statements": 26, "num_variables": 2, "function_call_count": 33, "cyclomatic_complexity": 28, "memory_operations": 0},
        "parameters": {"widening_delay": 4, "subdivide_non_linear": 2, "slevel": 41, "plevel": 41, "partition_history": 0, "min_loop_unroll": 6, "ilevel": 31, "equality_through_calls": "formals", "auto_loop_unroll": 20, "domains": ["cvalue", "gauges", "octagon"]}
    },
    # Analysis for parity.c
    {
        "features": {"loc": 41, "num_functions": 3, "nesting_depth": 1, "num_conditional_statements": 5, "num_variables": 5, "function_call_count": 9, "cyclomatic_complexity": 7, "memory_operations": 0},
        "parameters": {"widening_delay": 2, "subdivide_non_linear": 1, "slevel": 30, "plevel": 20, "partition_history": 0, "min_loop_unroll": 0, "ilevel": 16, "equality_through_calls": "none", "auto_loop_unroll": 5, "domains": ["cvalue", "octagon"]}
    },
    # Analysis for 2Nested-1.c
    {
        "features": {"loc": 16, "num_functions": 1, "nesting_depth": 1, "num_conditional_statements": 3, "num_variables": 0, "function_call_count": 7, "cyclomatic_complexity": 5, "memory_operations": 0},
        "parameters": {"widening_delay": 3, "subdivide_non_linear": 1, "slevel": 27, "plevel": 21, "partition_history": 0, "min_loop_unroll": 1, "ilevel": 16, "equality_through_calls": "none", "auto_loop_unroll": 9, "domains": ["cvalue", "equality", "gauges", "octagon", "symbolic-locations"]}
    },
    # Analysis for psyco_security.c
    {
        "features": {"loc": 265, "num_functions": 2, "nesting_depth": 1, "num_conditional_statements": 68, "num_variables": 9, "function_call_count": 76, "cyclomatic_complexity": 70, "memory_operations": 0},
        "parameters": {"widening_delay": 2, "subdivide_non_linear": 2, "slevel": 17, "plevel": 23, "partition_history": 0, "min_loop_unroll": 0, "ilevel": 16, "equality_through_calls": "formals", "auto_loop_unroll": 7, "domains": ["cvalue", "symbolic-locations"]}
    },
    # Analysis for psyco_abp_1-2.c
    {
        "features": {"loc": 389, "num_functions": 2, "nesting_depth": 1, "num_conditional_statements": 99, "num_variables": 20, "function_call_count": 116, "cyclomatic_complexity": 101, "memory_operations": 0},
        "parameters": {"widening_delay": 2, "subdivide_non_linear": 1, "slevel": 16, "plevel": 20, "partition_history": 0, "min_loop_unroll": 0, "ilevel": 16, "equality_through_calls": "none", "auto_loop_unroll": 7, "domains": ["cvalue", "equality", "gauges", "octagon", "symbolic-locations"]}
    },
    # Analysis for Primes.c
    {
        "features": {"loc": 74, "num_functions": 6, "nesting_depth": 0, "num_conditional_statements": 18, "num_variables": 4, "function_call_count": 26, "cyclomatic_complexity": 19, "memory_operations": 0},
        "parameters": {"widening_delay": 2, "subdivide_non_linear": 0, "slevel": 19, "plevel": 20, "partition_history": 1, "min_loop_unroll": 1, "ilevel": 16, "equality_through_calls": "formals", "auto_loop_unroll": 11, "domains": ["cvalue", "equality", "gauges"]}
    },
    # Analysis for sum02-2.c
    {
        "features": {"loc": 25, "num_functions": 4, "nesting_depth": 1, "num_conditional_statements": 2, "num_variables": 0, "function_call_count": 13, "cyclomatic_complexity": 4, "memory_operations": 0},
        "parameters": {"widening_delay": 2, "subdivide_non_linear": 1, "slevel": 30, "plevel": 20, "partition_history": 0, "min_loop_unroll": 0, "ilevel": 16, "equality_through_calls": "formals", "auto_loop_unroll": 11, "domains": ["cvalue"]}
    },
    # Analysis for psyco_abp_1-1.c
    {
        "features": {"loc": 392, "num_functions": 2, "nesting_depth": 1, "num_conditional_statements": 100, "num_variables": 20, "function_call_count": 117, "cyclomatic_complexity": 102, "memory_operations": 0},
        "parameters": {"widening_delay": 5, "subdivide_non_linear": 0, "slevel": 47, "plevel": 39, "partition_history": 6, "min_loop_unroll": 0, "ilevel": 35, "equality_through_calls": "formals", "auto_loop_unroll": 16, "domains": ["cvalue", "octagon", "symbolic-locations"]}
    },
    # Analysis for num_conversion_1.c
    {
        "features": {"loc": 29, "num_functions": 3, "nesting_depth": 1, "num_conditional_statements": 2, "num_variables": 5, "function_call_count": 10, "cyclomatic_complexity": 4, "memory_operations": 0},
        "parameters": {"widening_delay": 2, "subdivide_non_linear": 0, "slevel": 16, "plevel": 29, "partition_history": 0, "min_loop_unroll": 1, "ilevel": 16, "equality_through_calls": "none", "auto_loop_unroll": 10, "domains": ["cvalue", "gauges", "octagon", "symbolic-locations"]}
    },

    # === Database from cf ===
    # Analysis for 2062D.c
    {
        "features": {"loc": 53, "num_functions": 4, "nesting_depth": 4, "num_conditional_statements": 4, "num_variables": 4, "function_call_count": 19, "cyclomatic_complexity": 9, "memory_operations": 3},
        "parameters": {"widening_delay": 2, "subdivide_non_linear": 1, "slevel": 12, "plevel": 24, "partition_history": 0, "min_loop_unroll": 0, "ilevel": 20, "equality_through_calls": "none", "auto_loop_unroll": 11, "domains": ["cvalue", "equality"]}
    },
    # Analysis for 2064E.c
    {
        "features": {"loc": 125, "num_functions": 6, "nesting_depth": 9, "num_conditional_statements": 12, "num_variables": 5, "function_call_count": 29, "cyclomatic_complexity": 22, "memory_operations": 0},
        "parameters": {"widening_delay": 2, "subdivide_non_linear": 8, "slevel": 23, "plevel": 53, "partition_history": 0, "min_loop_unroll": 0, "ilevel": 27, "equality_through_calls": "formals", "auto_loop_unroll": 18, "domains": ["cvalue", "gauges"]}
    },
    # Analysis for 2071E.c
    {
        "features": {"loc": 85, "num_functions": 3, "nesting_depth": 4, "num_conditional_statements": 3, "num_variables": 2, "function_call_count": 24, "cyclomatic_complexity": 8, "memory_operations": 3},
        "parameters": {"widening_delay": 1, "subdivide_non_linear": 0, "slevel": 0, "plevel": 10, "partition_history": 0, "min_loop_unroll": 0, "ilevel": 8, "equality_through_calls": "none", "auto_loop_unroll": 0, "domains": ["cvalue"]}
    },
    # Analysis for 2077D.c
    {
        "features": {"loc": 95, "num_functions": 7, "nesting_depth": 7, "num_conditional_statements": 7, "num_variables": 4, "function_call_count": 29, "cyclomatic_complexity": 15, "memory_operations": 0},
        "parameters": {"widening_delay": 4, "subdivide_non_linear": 3, "slevel": 31, "plevel": 107, "partition_history": 2, "min_loop_unroll": 1, "ilevel": 57, "equality_through_calls": "formals", "auto_loop_unroll": 36, "domains": ["cvalue", "equality", "gauges", "octagon", "symbolic-locations"]}
    },
    # Analysis for 2069C.c
    {
        "features": {"loc": 62, "num_functions": 1, "nesting_depth": 2, "num_conditional_statements": 4, "num_variables": 10, "function_call_count": 17, "cyclomatic_complexity": 7, "memory_operations": 0},
        "parameters": {"widening_delay": 7, "subdivide_non_linear": 18, "slevel": 89, "plevel": 164, "partition_history": 0, "min_loop_unroll": 7, "ilevel": 54, "equality_through_calls": "formals", "auto_loop_unroll": 53, "domains": ["cvalue", "equality", "gauges", "octagon", "symbolic-locations"]}
    },
    # Analysis for 2073D.c
    {
        "features": {"loc": 79, "num_functions": 2, "nesting_depth": 1, "num_conditional_statements": 10, "num_variables": 5, "function_call_count": 27, "cyclomatic_complexity": 12, "memory_operations": 0},
        "parameters": {"widening_delay": 2, "subdivide_non_linear": 3, "slevel": 13, "plevel": 24, "partition_history": 0, "min_loop_unroll": 0, "ilevel": 19, "equality_through_calls": "none", "auto_loop_unroll": 9, "domains": ["cvalue", "equality", "gauges", "symbolic-locations"]}
    },
    # Analysis for 2066C.c
    {
        "features": {"loc": 67, "num_functions": 4, "nesting_depth": 5, "num_conditional_statements": 7, "num_variables": 4, "function_call_count": 18, "cyclomatic_complexity": 13, "memory_operations": 0},
        "parameters": {"widening_delay": 7, "subdivide_non_linear": 10, "slevel": 50, "plevel": 129, "partition_history": 0, "min_loop_unroll": 0, "ilevel": 83, "equality_through_calls": "formals", "auto_loop_unroll": 64, "domains": ["cvalue", "gauges", "octagon", "symbolic-locations"]}
    },
    # Analysis for 2077C.c
    {
        "features": {"loc": 46, "num_functions": 2, "nesting_depth": 3, "num_conditional_statements": 6, "num_variables": 2, "function_call_count": 12, "cyclomatic_complexity": 10, "memory_operations": 0},
        "parameters": {"widening_delay": 2, "subdivide_non_linear": 8, "slevel": 47, "plevel": 76, "partition_history": 1, "min_loop_unroll": 1, "ilevel": 39, "equality_through_calls": "none", "auto_loop_unroll": 29, "domains": ["cvalue", "equality", "gauges", "octagon", "symbolic-locations"]}
    },
    # Analysis for 2071B.c
    {
        "features": {"loc": 67, "num_functions": 5, "nesting_depth": 2, "num_conditional_statements": 10, "num_variables": 6, "function_call_count": 22, "cyclomatic_complexity": 13, "memory_operations": 0},
        "parameters": {"widening_delay": 7, "subdivide_non_linear": 18, "slevel": 89, "plevel": 164, "partition_history": 0, "min_loop_unroll": 7, "ilevel": 54, "equality_through_calls": "formals", "auto_loop_unroll": 53, "domains": ["cvalue", "equality", "gauges", "octagon", "symbolic-locations"]}
    },
    # Analysis for 2061B.c
    {
        "features": {"loc": 63, "num_functions": 3, "nesting_depth": 2, "num_conditional_statements": 5, "num_variables": 8, "function_call_count": 22, "cyclomatic_complexity": 8, "memory_operations": 3},
        "parameters": {"widening_delay": 2, "subdivide_non_linear": 3, "slevel": 8, "plevel": 30, "partition_history": 1, "min_loop_unroll": 0, "ilevel": 16, "equality_through_calls": "formals", "auto_loop_unroll": 6, "domains": ["cvalue", "equality", "octagon", "symbolic-locations"]}
    },
    # Analysis for 2067C.c
    {
        "features": {"loc": 55, "num_functions": 2, "nesting_depth": 2, "num_conditional_statements": 5, "num_variables": 7, "function_call_count": 14, "cyclomatic_complexity": 8, "memory_operations": 0},
        "parameters": {"widening_delay": 1, "subdivide_non_linear": 0, "slevel": 0, "plevel": 10, "partition_history": 0, "min_loop_unroll": 0, "ilevel": 8, "equality_through_calls": "none", "auto_loop_unroll": 0, "domains": ["cvalue"]}
    },
    # Analysis for 2066F.c
    {
        "features": {"loc": 150, "num_functions": 2, "nesting_depth": 16, "num_conditional_statements": 20, "num_variables": 1, "function_call_count": 65, "cyclomatic_complexity": 37, "memory_operations": 0},
        "parameters": {"widening_delay": 2, "subdivide_non_linear": 1, "slevel": 7, "plevel": 30, "partition_history": 1, "min_loop_unroll": 0, "ilevel": 20, "equality_through_calls": "formals", "auto_loop_unroll": 14, "domains": ["cvalue", "equality", "gauges", "octagon", "symbolic-locations"]}
    },
    # Analysis for 2075C.c
    {
        "features": {"loc": 65, "num_functions": 3, "nesting_depth": 2, "num_conditional_statements": 7, "num_variables": 7, "function_call_count": 17, "cyclomatic_complexity": 10, "memory_operations": 0},
        "parameters": {"widening_delay": 2, "subdivide_non_linear": 0, "slevel": 8, "plevel": 24, "partition_history": 0, "min_loop_unroll": 0, "ilevel": 16, "equality_through_calls": "formals", "auto_loop_unroll": 15, "domains": ["cvalue", "equality", "gauges", "octagon"]}
    },
    # Analysis for 2071C.c
    {
        "features": {"loc": 185, "num_functions": 11, "nesting_depth": 1, "num_conditional_statements": 16, "num_variables": 15, "function_call_count": 59, "cyclomatic_complexity": 18, "memory_operations": 12},
        "parameters": {"widening_delay": 8, "subdivide_non_linear": 7, "slevel": 32, "plevel": 89, "partition_history": 0, "min_loop_unroll": 3, "ilevel": 37, "equality_through_calls": "formals", "auto_loop_unroll": 24, "domains": ["cvalue", "gauges", "octagon", "symbolic-locations"]}
    },
    # Analysis for 2073F.c
    {
        "features": {"loc": 159, "num_functions": 6, "nesting_depth": 8, "num_conditional_statements": 23, "num_variables": 3, "function_call_count": 55, "cyclomatic_complexity": 32, "memory_operations": 0},
        "parameters": {"widening_delay": 2, "subdivide_non_linear": 3, "slevel": 11, "plevel": 31, "partition_history": 0, "min_loop_unroll": 1, "ilevel": 17, "equality_through_calls": "none", "auto_loop_unroll": 7, "domains": ["cvalue", "equality", "octagon", "symbolic-locations"]}
    },
    # Analysis for 2067B.c
    {
        "features": {"loc": 41, "num_functions": 1, "nesting_depth": 2, "num_conditional_statements": 6, "num_variables": 4, "function_call_count": 16, "cyclomatic_complexity": 9, "memory_operations": 2},
        "parameters": {"widening_delay": 2, "subdivide_non_linear": 2, "slevel": 13, "plevel": 36, "partition_history": 1, "min_loop_unroll": 0, "ilevel": 16, "equality_through_calls": "none", "auto_loop_unroll": 7, "domains": ["cvalue", "gauges", "symbolic-locations"]}
    },
    # Analysis for 2061C.c
    {
        "features": {"loc": 54, "num_functions": 1, "nesting_depth": 2, "num_conditional_statements": 9, "num_variables": 4, "function_call_count": 14, "cyclomatic_complexity": 12, "memory_operations": 0},
        "parameters": {"widening_delay": 16, "subdivide_non_linear": 29, "slevel": 235, "plevel": 418, "partition_history": 5, "min_loop_unroll": 0, "ilevel": 292, "equality_through_calls": "formals", "auto_loop_unroll": 169, "domains": ["cvalue", "equality", "gauges", "octagon", "symbolic-locations"]}
    },
    # Analysis for 2064D.c
    {
        "features": {"loc": 49, "num_functions": 2, "nesting_depth": 8, "num_conditional_statements": 2, "num_variables": 9, "function_call_count": 17, "cyclomatic_complexity": 11, "memory_operations": 0},
        "parameters": {"widening_delay": 4, "subdivide_non_linear": 22, "slevel": 88, "plevel": 141, "partition_history": 0, "min_loop_unroll": 2, "ilevel": 48, "equality_through_calls": "formals", "auto_loop_unroll": 61, "domains": ["cvalue", "equality", "octagon", "symbolic-locations"]}
    },
    # Analysis for 2066E.c
    {
        "features": {"loc": 67, "num_functions": 4, "nesting_depth": 5, "num_conditional_statements": 7, "num_variables": 4, "function_call_count": 18, "cyclomatic_complexity": 13, "memory_operations": 0},
        "parameters": {"widening_delay": 2, "subdivide_non_linear": 3, "slevel": 9, "plevel": 31, "partition_history": 0, "min_loop_unroll": 0, "ilevel": 16, "equality_through_calls": "none", "auto_loop_unroll": 10, "domains": ["cvalue", "equality", "octagon", "symbolic-locations"]}
    },
    # Analysis for 2075D.c
    {
        "features": {"loc": 243, "num_functions": 1, "nesting_depth": 2, "num_conditional_statements": 37, "num_variables": 29, "function_call_count": 64, "cyclomatic_complexity": 40, "memory_operations": 0},
        "parameters": {"widening_delay": 17, "subdivide_non_linear": 28, "slevel": 102, "plevel": 209, "partition_history": 0, "min_loop_unroll": 8, "ilevel": 157, "equality_through_calls": "formals", "auto_loop_unroll": 95, "domains": ["cvalue", "equality", "gauges", "octagon", "symbolic-locations"]}
    },
    # Analysis for 2077A.c
    {
        "features": {"loc": 116, "num_functions": 6, "nesting_depth": 5, "num_conditional_statements": 17, "num_variables": 7, "function_call_count": 27, "cyclomatic_complexity": 23, "memory_operations": 0},
        "parameters": {"widening_delay": 2, "subdivide_non_linear": 4, "slevel": 8, "plevel": 37, "partition_history": 0, "min_loop_unroll": 0, "ilevel": 25, "equality_through_calls": "none", "auto_loop_unroll": 7, "domains": ["cvalue", "gauges", "octagon", "symbolic-locations"]}
    },
    # Analysis for 2063E.c
    {
        "features": {"loc": 56, "num_functions": 3, "nesting_depth": 3, "num_conditional_statements": 6, "num_variables": 4, "function_call_count": 17, "cyclomatic_complexity": 10, "memory_operations": 2},
        "parameters": {"widening_delay": 2, "subdivide_non_linear": 1, "slevel": 9, "plevel": 26, "partition_history": 0, "min_loop_unroll": 0, "ilevel": 22, "equality_through_calls": "formals", "auto_loop_unroll": 5, "domains": ["cvalue", "equality", "gauges"]}
    }
    ]