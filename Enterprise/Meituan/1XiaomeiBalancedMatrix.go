package Meituan

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	matrix := make([][]int, n)
	for i := 0; i < n; i++ {
		matrix[i] = make([]int, n)
		scanner.Scan()
		line := scanner.Text()
		for j := 0; j < n; j++ {
			if line[j] == '0' {
				matrix[i][j] = 0
			} else {
				matrix[i][j] = 1
			}
		}
	}

	prefixSumZero := make([][]int, n+1)
	prefixSumOne := make([][]int, n+1)
	for i := 0; i <= n; i++ {
		prefixSumZero[i] = make([]int, n+1)
		prefixSumOne[i] = make([]int, n+1)
	}

	for i := 1; i <= n; i++ {
		for j := 1; j <= n; j++ {
			prefixSumZero[i][j] = prefixSumZero[i-1][j] + prefixSumZero[i][j-1] - prefixSumZero[i-1][j-1]
			prefixSumOne[i][j] = prefixSumOne[i-1][j] + prefixSumOne[i][j-1] - prefixSumOne[i-1][j-1]
			if matrix[i-1][j-1] == 0 {
				prefixSumZero[i][j]++
			} else {
				prefixSumOne[i][j]++
			}
		}
	}

	result := make([]int, n)

	for size := 1; size <= n; size++ {
		count := 0
		for i := 0; i <= n-size; i++ {
			for j := 0; j <= n-size; j++ {
				totalZero := prefixSumZero[i+size][j+size] - prefixSumZero[i+size][j] - prefixSumZero[i][j+size] + prefixSumZero[i][j]
				totalOne := prefixSumOne[i+size][j+size] - prefixSumOne[i+size][j] - prefixSumOne[i][j+size] + prefixSumOne[i][j]
				if totalZero == totalOne {
					count++
				}
			}
		}
		result[size-1] = count
	}

	for i := 0; i < n; i++ {
		fmt.Println(result[i])
	}
}
