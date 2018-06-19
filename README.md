Temporary compile steps

```bash
g++ -shared -o libtry.so -fPIC try.cc
go build -o awesome.so -buildmode=c-shared awesome.go
gcc -o awesome awesome.cc ./awesome.so ./libtry.so
```
