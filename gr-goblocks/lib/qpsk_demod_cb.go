package main

// #cgo LDFLAGS: -L${SRCDIR}/../build/lib/ -lgo-gnuradio-ptr
// #include "go_gnuradio.h"
import "C"
import (
 "fmt"
 "sync"
)

// START OF CODE AUTOGENERATED BY GO-GNURADIO. 
// DO NOT MODIFY UNLESS YOU KNOW WHAT YOU ARE DOING.

// Internal struct used by go-gnuradio
type _goGRStruct struct {
  output_multiple_ptr uint64
  set_output_multiple_ptr uint64
  history_ptr uint64
  set_history_ptr uint64
  alignment_ptr uint64
  set_alignment_ptr uint64
  consume_each_ptr uint64
  consume_ptr uint64
  produce_ptr uint64
}

var _QpskDemodCbStorageMutex sync.Mutex
var _QpskDemodCbStorage []*QpskDemodCb

//export QpskDemodCbGoGRInit
func QpskDemodCbGoGRInit(
  output_multiple_ptr, 
  set_output_multiple_ptr, 
  history_ptr, 
  set_history_ptr, 
  alignment_ptr, 
  set_alignment_ptr,
  consume_each_ptr,
  consume_ptr,
  produce_ptr uint64) int {
  _QpskDemodCbStorageMutex.Lock()
  defer _QpskDemodCbStorageMutex.Unlock()
  block := &QpskDemodCb{
    _go: &_goGRStruct{
      output_multiple_ptr: output_multiple_ptr,
      set_output_multiple_ptr: set_output_multiple_ptr,
      history_ptr: history_ptr,
      set_history_ptr: set_history_ptr,
      alignment_ptr: alignment_ptr,
      set_alignment_ptr: set_alignment_ptr,
      consume_each_ptr: consume_each_ptr,
      consume_ptr: consume_ptr,
      produce_ptr: produce_ptr,
    },
  }
  _QpskDemodCbStorage = append(_QpskDemodCbStorage, block)
  fmt.Println("Initialized from Go!!!")
  return len(_QpskDemodCbStorage) - 1
}

//export QpskDemodCbWork
func QpskDemodCbWork(in []complex64, out []uint8, __go_gnuradio_index int) int {
  block := _QpskDemodCbStorage[__go_gnuradio_index]
  return block.Work(in, out) // This could be unnecessary overhead?
}

//export QpskDemodCbStart
func QpskDemodCbStart(__go_gnuradio_index int) bool {
  block := _QpskDemodCbStorage[__go_gnuradio_index]
  return block.Start()
}

//export QpskDemodCbStop
func QpskDemodCbStop(__go_gnuradio_index int) bool {
  block := _QpskDemodCbStorage[__go_gnuradio_index]
  return block.Stop()
}

//export QpskDemodCbDelete
func QpskDemodCbDelete(__go_gnuradio_index int) {
  _QpskDemodCbStorageMutex.Lock()
  defer _QpskDemodCbStorageMutex.Unlock()
  _QpskDemodCbStorage[__go_gnuradio_index] = nil
}

func (block *QpskDemodCb) OutputMultiple() int32 {
  return int32(C._ExecOutputMultiple(C.ulonglong(block._go.output_multiple_ptr)))
}

func (block *QpskDemodCb) SetOutputMultiple(output_multiple int32) {
  C._ExecSetOutputMultiple(C.ulonglong(block._go.set_output_multiple_ptr), C.int(output_multiple))
}

func (block *QpskDemodCb) History() uint32 {
  return uint32(C._ExecHistory(C.ulonglong(block._go.history_ptr)))
}

func(block *QpskDemodCb) SetHistory(history uint32) {
  C._ExecSetHistory(C.ulonglong(block._go.set_history_ptr), C.uint(history))
}

func (block *QpskDemodCb) Alignment() int32 {
  return int32(C._ExecOutputMultiple(C.ulonglong(block._go.alignment_ptr)))
}

func (block *QpskDemodCb) SetAlignment(multiple int32) {
  C._ExecSetOutputMultiple(C.ulonglong(block._go.set_alignment_ptr), C.int(multiple))
}

func (block *QpskDemodCb) ConsumeEach(how_many_items int32) {
  C._ExecSetOutputMultiple(C.ulonglong(block._go.consume_each_ptr), C.int(how_many_items))
}

func (block *QpskDemodCb) Consume(which, how_many_items int32) {
  C._ExecConsume(C.ulonglong(block._go.consume_ptr), C.int(which), C.int(how_many_items))
}

func (block *QpskDemodCb) Produce(which_output, how_many_items int32) {
  C._ExecConsume(C.ulonglong(block._go.produce_ptr), C.int(which_output), C.int(how_many_items))
}

// END OF CODE AUTOGENERATED BY GO-GNURADIO. 
// DO NOT MODIFY UNLESS YOU KNOW WHAT YOU ARE DOING.

type QpskDemodCb struct {
  // Store your user defined parameters here
  GrayCode bool

  _go *_goGRStruct // Leave this member alone. Used by go-gnuradio.
}

// This function is used to initialize member variables for your block.
// Do what you would do in the C++ constructor here. e.g. set_output_multiple, etc.
// When you modify this function's signature, don't forget to modify the same in *_impl.cc
//export QpskDemodCbInit
func QpskDemodCbInit(__go_gnuradio_index int, gray_code bool) {
  block := _QpskDemodCbStorage[__go_gnuradio_index]  // Line autogenerated by go-gnuradio

  // User initialization starts here. e.g.
  // block.MyVariable = myVariable
  // You can also call setup functions such as set_output_multiple e.g.
  // block.SetOutputMultiple(64)
  block.GrayCode = gray_code
}

func (block *QpskDemodCb) Start() bool {
  // Start drivers, etc. here.
  fmt.Println("Starting block!")
  return true
}

func (block *QpskDemodCb) Stop() bool {
  // Stop drivers, etc. here.
  fmt.Println("Stopping block!")
  return true
}

func (block *QpskDemodCb) Work(in []complex64, out []uint8) int {
  // Signal processing is done here. Place your results directly in `out`.
  // Do NOT modify `in` or you will break things! Go does not have const references. 
  for i := 0; i < len(in); i++ {
    out[i] = block.getMinimumDistances(in[i])
  }
  return len(in)
}

func (block *QpskDemodCb) getMinimumDistances(sample complex64) uint8 {
  if (block.GrayCode) {
    var bit0 uint8
    var bit1 uint8
    if (real(sample) < 0) {
      bit0 = 1
    }
    if (imag(sample) < 0) {
      bit1 = 1 << 1
    }
    return bit0 | bit1
  } else {
    if (imag(sample) >= 0 && real(sample) >= 0) {
      return 0
    } else if (imag(sample) >= 0 && real(sample) < 0) {
      return 1
    } else if (imag(sample) < 0 && real(sample) < 0) {
      return 2
    } else if (imag(sample) < 0 && real(sample) >= 0) {
      return 3
    }
  }
  return 0
}

func main() {}
