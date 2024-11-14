## Create a wrapper

Don't change original files.

Generated code includes five parts:

- Type definition for the original data types.
- Wrapper function wasm friendly version declarations for the original functions.
- Wrapper function host friendly version declarations for the original functions.
- Wrapper function wasm friendly version implementations for the original functions.
- Wrapper function host friendly version implementations for the original functions.

Use a separator line `////////////////////////////////` to separate the above five parts.

### Type conversion and data type mapping

#### Primitive data types

- only use int32_t, int64_t, float, double, v128 to represent the data types.
  Other data types are not allowed.
- use int32_t to represent int32_t, uint32_t, int16_t, uint16_t, int8_t,
  uint8_t, bool, char.
- use int64_t to represent int64_t, uint64_t.
- use float to represent float.
- use double to represent double.

#### Struct data types

- only use int32_t, int64_t, float, double, v128 to represent the data types of members in the struct.
  Other data types are not allowed.

#### Enum data types

- use int32_t to represent the enum data type.

#### Pointer data types

- use int32_t to represent the pointer data type.

#### Array data types

- use int32_t to represent the array data type.
- add a `int32_t length` to represent the length of the array.

#### typedef data types

- follow the above rules to represent the data types.

#### If not sure

if a original data type isn't listed below, please ask me for help.

### Name conversion

- The name of the wrapper struct should be `original_struct_name` with the prefix `wrapper_`.
- The name of the wrapper function wasm friendly version should be `original_function_name` with the prefix `wasm_`.
- The name of the wrapper function host friendly version should be `original_function_name` with the prefix `host_`.

### Generate the wrapper

- Always add a copyright declaration no the top of all wrapper files:

```c
/*
 * Copyright (C) 2020 Intel Corporation.  All rights reserved.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 */
```

### Generate the wrapper for the struct

- please add the following comment before the struct declaration:

```c
// This is a wrapper for the struct `struct_name` in the original code.
// The original struct is defined in `original_struct_name`.
// The original struct has the following signature:
// `original_struct_signature`.

```

- use `_Static_assert()` to check the size of the struct.
- use `_Static_assert()` to check offset of the struct members.
- use `_Static_assert()` and `_Alignof()` to check the alignment of the struct members.

### Generate the wrapper wasm friendly version for the function

- please add the following comment before the function declaration:

```c
// This is a wrapper for the function `function_name` in the original code.
// The original function is defined in `original_file_name`.
// The original function has the following signature:
// `original_function_signature`.
```

- only generate declaration.
- don't generate implementation.
- add the following `__attribute__` to the function declaration:

```c
__attribute__((import_module("host"), import_name("origin_function_name")))
```

### Generate the wrapper host friendly version for the function

- please add the following comment before the function declaration:

```c
// This is a wrapper for the function `function_name` in the original code.
// The original function is defined in `original_file_name`.
// The original function has the following signature:
// `original_function_signature`.
```

- generate declaration and implementation.
- add `wasm_exec_env_t exec_env` as the first parameter.
- Call the original function in the wrapper function.
- do type conversion and data type mapping in the wrapper function before calling the original function.
  convert the input parameters of the wrapper function to the original data type.
- do type conversion and data type mapping in the wrapper function after calling the original function.
  convert the output parameters of the original function to the wrapper data type.

## Style

> https://github.com/MaJerle/c-code-style

- Use C11 standard
- Do not use tabs, use spaces instead
- Use 2 spaces per indent level
- Use 1 space between keyword and opening bracket
- Column limit is 80
- Do not use space between function name and opening bracket
- Use only lowercase characters for variables/functions/types with optional underscore \_ char
- Opening curly bracket is always at the same line as keyword (for, while, do, switch, if, ...)
- Use single space before and after comparison and assignment operators
- Do not initialize global variables to any default value (or NULL), implement it in the dedicated init function (if REQUIRED).
- Declare local variables in order
  - Custom structures and enumerations
  - Integer types, wider unsigned type first
  - Single/Double floating point
