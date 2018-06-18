package main

import "C"
import (
 "fmt"
 "sync"
)


//export Ma
func Ma(in [][]float32) int {
  return 1;
}

type Configuration struct {
  Scale float32;
  Invert bool;
}

var storageMutex sync.Mutex
var Storage []*Configuration

//export Init
func Init(scale float32, invert bool) int {
  storageMutex.Lock()
  defer storageMutex.Unlock()
  config := &Configuration{
    Scale: scale,
    Invert: invert,
  }
  Storage = append(Storage, config)
  return len(Storage) - 1
}

//export Work
func Work(in []float32, out []float32, confIdx int) int {
  fmt.Println(in)
  fmt.Println(out)
  conf := Storage[confIdx]
  fmt.Println(conf)
  for i := 0; i < len(in); i++ {
    out[i] = in[i]*conf.Scale
    if (conf.Invert) {
      out[i] *= -1
    }
  }
  conf.Scale *= 2
  return len(in)
}

func main() {}
