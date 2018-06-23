package main

// #cgo LDFLAGS: -L${SRCDIR}/../build/lib/ -lgo-gnuradio-ptr
// #include "go_gnuradio.h"
import "C"
import (
 "fmt"
 "sync"
)

// Internal struct used by go-gnuradio
type _goGRStruct struct {
  set_output_multiple_ptr uint64
}

var _QpskDemodCbStorageMutex sync.Mutex
var _QpskDemodCbStorage []*QpskDemodCb

type QpskDemodCb struct {
  Gray bool
  _go *_goGRStruct
}

//export QpskDemodCbGoGRInit
func QpskDemodCbGoGRInit(set_output_multiple_ptr uint64) int {
  _QpskDemodCbStorageMutex.Lock()
  defer _QpskDemodCbStorageMutex.Unlock()
  C.MyTest()
  block := &QpskDemodCb{
    _go: &_goGRStruct{
      set_output_multiple_ptr: set_output_multiple_ptr,
    },
  }
  _QpskDemodCbStorage = append(_QpskDemodCbStorage, block)
  //
  fmt.Println("Initialized from Go!!!")
  return len(_QpskDemodCbStorage) - 1
}

//export QpskDemodCbWork
func QpskDemodCbWork(in []float32, out []uint8, idx int) int {
  block := _QpskDemodCbStorage[idx]
  return block.Work(in, out) // This could be unnecessary overhead?
}

func (block *QpskDemodCb) SetOutputMultiple(output_multiple int32) {
  C._ExecSetOutputMultiple(C.ulonglong(block._go.set_output_multiple_ptr), C.int(output_multiple))
}

//export QpskDemodCbInit
func QpskDemodCbInit(_idx int, gray bool) {
  block := _QpskDemodCbStorage[_idx]
  block.Gray = gray
}

func (block *QpskDemodCb) Work(in []float32, out []uint8) int {
  for i := 0; i < len(in); i++ {
    if (block.Gray) {
      out[i] = uint8(in[i])
    } else {
      out[i] = uint8(in[i]*255)
    }
  }
  return len(in)
}

func main() {}
