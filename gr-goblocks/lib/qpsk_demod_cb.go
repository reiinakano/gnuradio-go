package main

// #cgo LDFLAGS: -L${SRCDIR}/../build/lib/ -lgo-gnuradio-ptr
// #include "go_gnuradio.h"
import "C"
import (
 "fmt"
 "sync"
)

type Configuration struct {
  Gray bool
  set_output_multiple_ptr uint64
}

var storageMutex sync.Mutex
var Storage []*Configuration

//export Init
func Init(gray bool, set_output_multiple_ptr uint64) int {
  storageMutex.Lock()
  defer storageMutex.Unlock()
  C.MyTest()
  config := &Configuration{
    Gray: gray,
    set_output_multiple_ptr: set_output_multiple_ptr,
  }
  Storage = append(Storage, config)
  C._ExecSetOutputMultiple(C.ulonglong(set_output_multiple_ptr), 64)
  fmt.Println("Initialized from Go!!!")
  return len(Storage) - 1
}

//export Work
func Work(in []float32, out []uint8, confIdx int) int {
  conf := Storage[confIdx]
  for i := 0; i < len(in); i++ {
    if (conf.Gray) {
      out[i] = uint8(in[i])
    } else {
      out[i] = uint8(in[i]*255)
    }
  }
  return len(in)
}

func main() {}
