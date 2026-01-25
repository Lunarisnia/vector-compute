package main

import (
	"fmt"
	"math/rand"
	"time"
)

func array(length int) []int {
	arr := make([]int, 0)
	for range length {
		arr = append(arr, rand.Intn(10000))
	}

	return arr
}

func main() {
	arrayLength := 30_000_000
	arrayA := array(arrayLength)
	arrayB := array(arrayLength)
	multiplier := 2
	result := make([]int, 0)

	startTime := time.Now()
	for i := range arrayA {
		result = append(result, (arrayA[i]*multiplier)+arrayB[i])
	}
	fmt.Println(result)
	timeDifference := time.Since(startTime)
	fmt.Println("Calculation took:", timeDifference.Seconds())
}
