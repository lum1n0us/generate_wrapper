/*
* Copyright (C) 2020 Intel Corporation.  All rights reserved.
* SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
*/

// Type definition for the original data types.
typedef int32_t int32_t;
typedef int32_t uint32_t;
typedef int32_t int16_t;
typedef int32_t uint16_t;
typedef int32_t int8_t;
typedef int32_t uint8_t;
typedef int32_t bool;
typedef int32_t char;
typedef int64_t int64_t;
typedef int64_t uint64_t;
typedef float float;
typedef double double;

typedef int32_t __wasi_errno_t;
typedef int32_t __wasi_fd_t;
typedef int32_t __wasi_preopentype_t;

typedef struct {
  int32_t pr_name_len;
} wrapper___wasi_prestat_u_dir_t;

typedef struct {
  int32_t pr_type;
  union {
    wrapper___wasi_prestat_u_dir_t dir;
  } u;
} wrapper___wasi_prestat_t;

// This is a wrapper for the struct `fd_prestat` in the original code.
// The original struct is defined in `fd_prestat`.
// The original struct has the following signature:
// `struct fd_prestat { const char *dir; };`
typedef struct {
  int32_t dir;
} wrapper_fd_prestat;

// This is a wrapper for the struct `fd_prestats` in the original code.
// The original struct is defined in `fd_prestats`.
// The original struct has the following signature:
// `struct fd_prestats { struct rwlock lock; struct fd_prestat *prestats; size_t size; size_t used; };`
typedef struct {
  int32_t lock;
  int32_t prestats;
  int32_t size;
  int32_t used;
} wrapper_fd_prestats;

// _Static_assert() checks for struct sizes and alignments
_Static_assert(sizeof(wrapper_fd_prestat) == sizeof(struct fd_prestat), "Size mismatch");
_Static_assert(sizeof(wrapper_fd_prestats) == sizeof(struct fd_prestats), "Size mismatch");

// Wrapper function wasm friendly version declarations for the original functions.
// This is a wrapper for the function `fd_prestat_get` in the original code.
// The original function is defined in `libdemo.h`.
// The original function has the following signature:
// `__wasi_errno_t fd_prestat_get(struct fd_prestats *all_prestats, __wasi_fd_t fd, __wasi_prestat_t *out);`
__attribute__((import_module("host"), import_name("fd_prestat_get")))
int32_t wasm_fd_prestat_get(int32_t all_prestats, int32_t fd, int32_t out);

// Wrapper function host friendly version declarations for the original functions.
// This is a wrapper for the function `fd_prestat_get` in the original code.
// The original function is defined in `libdemo.h`.
// The original function has the following signature:
// `__wasi_errno_t fd_prestat_get(struct fd_prestats *all_prestats, __wasi_fd_t fd, __wasi_prestat_t *out);`
int32_t host_fd_prestat_get(wasm_exec_env_t exec_env, int32_t all_prestats, int32_t fd, int32_t out);

// Wrapper function wasm friendly version implementations for the original functions.
// ...existing code...

// Wrapper function host friendly version implementations for the original functions.
int32_t host_fd_prestat_get(wasm_exec_env_t exec_env, int32_t all_prestats, int32_t fd, int32_t out) {
  struct fd_prestats *orig_all_prestats = (struct fd_prestats *)all_prestats;
  __wasi_fd_t orig_fd = (__wasi_fd_t)fd;
  __wasi_prestat_t *orig_out = (__wasi_prestat_t *)out;

  return fd_prestat_get(orig_all_prestats, orig_fd, orig_out);
}
