package main

import "fmt"

func main() {
	t := []int{1, 3, 5, 7, 9}

	for _, a := range t {
		for _, c := range t {
			m := 100*a + 5*(a+c) + c
			fmt.Println(m)
		}
	}
}
