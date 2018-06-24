#ifdef __cplusplus
extern "C" {
#endif

extern void ExecVoidPtr(unsigned long long ptr) __attribute__((visibility("default")));

extern void _ExecSetOutputMultiple(unsigned long long ptr, int output_multiple) __attribute__((visibility("default")));

extern unsigned int _ExecHistory(unsigned long long ptr) __attribute__((visibility("default")));

extern void _ExecSetHistory(unsigned long long ptr, unsigned int history) __attribute__((visibility("default")));

extern void MyTest() __attribute__((visibility("default")));

#ifdef __cplusplus
}
#endif
