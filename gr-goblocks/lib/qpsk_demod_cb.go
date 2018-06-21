package main

import "C"
import (
 "fmt"
 "sync"
)

type Configuration struct {
  Gray bool
}

var storageMutex sync.Mutex
var Storage []*Configuration

//export Init
func Init(gray bool) int {
  storageMutex.Lock()
  defer storageMutex.Unlock()
  config := &Configuration{
    Gray: gray,
  }
  Storage = append(Storage, config)
  fmt.Println("Initialized from Go!!!")
  return len(Storage) - 1
}

//export Work
func Work(in []float32, out []uint8, confIdx int) int {
  conf := Storage[confIdx]
  for i := 0; i < len(in); i++ {
    if (conf.Gray) {
      out[i] = uint8(in[i]*128)
    } else {
	  out[i] = uint8(in[i]*255)
	}
  }
  return len(in)
}

func main() {}
