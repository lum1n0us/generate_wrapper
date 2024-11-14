#include <stdint.h>

typedef uint16_t __wasi_errno_t;
typedef uint32_t __wasi_fd_t;
typedef uint8_t __wasi_preopentype_t;

struct fd_prestat {
    const char *dir;
};

struct fd_prestats {
    struct rwlock lock;
    struct fd_prestat *prestats;
    size_t size;
    size_t used;
};

typedef struct __wasi_prestat_t {
    __wasi_preopentype_t pr_type;
    union __wasi_prestat_u {
        struct __wasi_prestat_u_dir_t {
            size_t pr_name_len;
        } dir;
    } u;
} __wasi_prestat_t;

__wasi_errno_t
fd_prestat_get(struct fd_prestats *all_prestats, __wasi_fd_t fd, __wasi_prestat_t *out);
