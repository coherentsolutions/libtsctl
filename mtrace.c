#ifndef Thread_C
#ifdef THREAD_USE_POSIX
#define __USE_UNIX98
#define _XOPEN_SOURCE 600
#define _GNU_SOURCE
#endif
#endif

#undef malloc
#undef free
#undef realloc
#include <stdio.h>
#include <stdlib.h>

#if 0
int loc;
FILE *mf;
#define malloc_trace(size) ({\
  FILE *mf = fopen("malloclog.txt","a");\
  fprintf(mf,"Malloc(\"" __FILE__ ":%d:%d\",",__LINE__,loc); loc=0;	\
  fprintf(mf, "%d, ", (size));			      \
  void *p = malloc((size));			      \
  fprintf(mf, "%d);\n", p);\
  fclose(mf);\
  p;\
})

#define free_trace(ptr) ({\
  FILE *mf = fopen("malloclog.txt","a");\
  fprintf(mf,"Free(\"" __FILE__ ":%d:%d\",",__LINE__,loc);	\
  fprintf(mf, "%d);\n",(ptr));			   \
  fclose(mf);\
  free((ptr));					\
})

#define realloc_trace(ptr,size) ({\
  FILE *mf = fopen("malloclog.txt","a");				\
  fprintf(mf,"Realloc(\"" __FILE__ ":%d:%d\",",__LINE__,loc); loc=0;	\
  fprintf(mf,"%d,%d, ",(ptr),(size));		      \
  void *p = realloc((ptr),(size));		      \
  fprintf(mf,"%d);\n", p);\
  fclose(mf);\
  p;\
})

/*
void *malloc_trace(size_t size) {
  if (!mf) mf = fopen("malloclog.txt","w");
  fprintf(mf,"Malloc[\"");
  fprintf(mf, "%d, ", size);
  void *p = malloc(size);
  fprintf(mf, "%d];\n", p);
  fflush(mf);
  return p;
}

void free_trace(void *ptr) {
  if (!mf) mf = fopen("malloclog.txt","w");
  fprintf(mf,"Free[\"");
  fprintf(mf, "%d];\n",ptr);
  fflush(mf);
  free(ptr);
}

void trace_flush() { fflush(mf); }

void *realloc_trace(void *ptr, size_t size) {
  if (!mf) mf = fopen("malloclog.txt","w");
  fprintf(mf,"Realloc[\"");
  fprintf(mf,"%d,%d, ",ptr,size);
  void *p = realloc(ptr,size);
  fprintf(mf,"%d];\n", p);
  fflush(mf);
  return p;
}
*/
#define malloc(x) malloc_trace(x)
#define free(x) free_trace(x)
#define realloc(x,y) realloc_trace(x,y)
#endif

