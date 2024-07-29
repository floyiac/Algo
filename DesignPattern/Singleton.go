package main

import "sync"

type ConcurrentSingleton struct {
}

var once sync.Once
var concurrentinstance *ConcurrentSingleton

func getConcurrentInstance() *ConcurrentSingleton {
	once.Do(func() {
		println("init only once")
		concurrentinstance = &ConcurrentSingleton{}
	})
	return concurrentinstance
}

func main() {
	var wg sync.WaitGroup
	for i := 0; i < 100; i++ {
		wg.Add(1)
		go func() {
			defer wg.Done()
			instance := getConcurrentInstance()
			println(instance)
		}()
	}
	wg.Wait()
}
