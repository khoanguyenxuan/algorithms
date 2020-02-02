package main

import "fmt"

func ucln(a, b int) int {
	var tmp int

	for b > 0 {
		tmp = b
		b = a % b
		a = tmp
	}

	return a
}

func sodao(x int) int {
	return (x%10)*10 + (x / 10)
}

func main() {
	for i := 10; i <= 99; i++ {
		if ucln(i, sodao(i)) == 1 {
			fmt.Println(i)
		}
	}
}
