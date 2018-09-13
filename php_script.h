#pragma once


//C interface
#ifdef __cplusplus

#include <cstddef>

extern "C" {
#else
#include <stddef.h>
#endif

#include "common-net-functions.h"

/** script_t **/
typedef struct {
  void (*run)(php_query_data *, void *mem, size_t mem_size);
  void (*clear)(void);
} script_t;

script_t *get_script(const char *name);
void set_script(const char *name, void (*run)(php_query_data *, void *, size_t), void (*clear)(void));

/** script result **/

typedef struct {
  const char *headers;
  int headers_len;
  const char *body;
  int body_len;
  int exit_code;
} script_result;

#ifdef __cplusplus
}
#endif
