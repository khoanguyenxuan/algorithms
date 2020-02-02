package main

import "fmt"

func main() {
	m := map[int]int{
		1: 3,
		2: 2,
		3: 1,
		4: 1,
		5: 1,
		6: 1,
		7: 1,
		8: 1,
		9: 1,
	}

	for a := 1; a <= 9; a++ {
		for d := 1; d <= m[a]; d++ {
			x := a * (100 + 10*d + d*d)
			fmt.Println(x)
		}
	}
}
